using System;
using System.Threading;

namespace SellTicket
{
    class Program
    {
        static volatile int ticket = 100;
        static Mutex mutex = new Mutex();
        static void Sell()
        {
            while (true)
            {
                mutex.WaitOne();
                if (ticket > 0)
                {
                    ticket--;
                    Console.WriteLine("{0}售票，剩余{1}张票。", Thread.CurrentThread.Name, ticket);
                    mutex.ReleaseMutex();
                }
                else
                {
                    mutex.ReleaseMutex();
                    break;
                }
            }
        }
        static void Main(string[] args)
        {
            Thread t1 = new Thread(Sell);
            t1.Name = "售卖点1";
            Thread t2 = new Thread(Sell);
            t2.Name = "售卖点2";
            t1.Start();
            t2.Start();
        }
    }
}
