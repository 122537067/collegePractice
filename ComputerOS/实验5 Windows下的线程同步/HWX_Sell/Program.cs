using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace HWX_Sell
{
    class Program
    {
        private static int n = 10;   //缓冲区大小

        //缓冲区
        private static int[] buffer = new int[n];
        private static int inPtr = 0;
        private static int outPtr = 0;

        private static Semaphore full = new Semaphore(0, n);  //信号量full,初始值是0，最大n
        private static Semaphore empty = new Semaphore(n, n); //信号量empty,初始n,最大n

        private static Mutex mutex = new Mutex(); //互斥信号量

        private static Random random = new Random(); //产生随机数

        private static void producer()
        {
            int data; //产品
            while(true)
            {
                empty.WaitOne();
                mutex.WaitOne();
                data = random.Next() % 1000;
                buffer[inPtr] = data;
                inPtr = (inPtr + 1) % n;
                Console.WriteLine("{0}生产{1}", Thread.CurrentThread.Name, data);
                mutex.ReleaseMutex();
                full.Release();
                Thread.Sleep(1000);
            }
        }

        private static void consumer()
        {
            while(true)
            {
                //mutex.WaitOne();
                full.WaitOne();
                mutex.WaitOne();
                Console.WriteLine("{0} 消费 {1}", Thread.CurrentThread.Name, buffer[outPtr]);
                outPtr = (outPtr + 1) % n;
                empty.Release();
                mutex.ReleaseMutex();
                //empty.Release();
                Thread.Sleep(1000);
            }
        }

        static void Main(string[] args)
        {
            Thread[] threads = new Thread[6];
            for (int i = 0; i < 3; i++)
            {
                threads[i] = new Thread(producer);
                threads[i].Name = string.Format("producer{0}", i);
            }
            for (int i = 3; i < 6; i++)
            {
                threads[i] = new Thread(consumer);
                threads[i].Name = string.Format("consumer{0}", i - 3);
            }
            for (int i = 0; i < 6; i++)
            {
                threads[i].Start();
            }
        }
    }
}
