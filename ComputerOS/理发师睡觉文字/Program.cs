using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace 理发师睡觉文字
{
    class Program
    {
        static int empty_chair = 5;
        static Semaphore mutex = new Semaphore(1, 1);
        static Semaphore customers = new Semaphore(5, 5);
        static Semaphore barber = new Semaphore(1, 1);

        static void Work()
        {
            while(true)
            {
                customers.WaitOne();
                mutex.WaitOne();
                empty_chair++;
                Console.WriteLine("剪完了下一个");
                barber.Release();
                mutex.Release();
            }
        }

        static void Cus()
        {
            while (true)
            {
                Random rand = new Random();
                int r = rand.Next(0, 100);
                if (r < 80)
                {
                    Console.WriteLine("客人进来了");
                    mutex.WaitOne();
                    if(empty_chair>0)
                    {
                        Console.WriteLine("客人坐下了");
                        empty_chair--;
                        customers.Release();
                        Console.WriteLine("客人剪头发了");
                        mutex.Release();
                        barber.WaitOne();
                        Console.WriteLine("剪完了");
                    }
                    else
                    {
                        Console.WriteLine("没位置");
                        mutex.WaitOne();
                    }
                }
            }
        }

        static void Main(string[] args)
        {
            Thread w = new Thread(Work);
            Thread c = new Thread(Cus);
            c.Start();
            w.Start();
        }    
    }
}
