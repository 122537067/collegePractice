using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Station
{
    class Program
    {
        static Semaphore captain = new Semaphore(0,1);
        static Semaphore ticket = new Semaphore(1, 1);

        static void Captain()
        {
            while (true)
            {
                captain.WaitOne();
                Console.WriteLine("开车啦！坐稳别开门！");
                Thread.Sleep(1000);
                Console.WriteLine("到站啦！芝麻开门!");
                ticket.Release();
            }
        }

        static void Ticket()
        {
            while (true)
            {
                ticket.WaitOne();
                Console.WriteLine("开门");
                Thread.Sleep(500);
                Console.WriteLine("关门");
                captain.Release();
            }
        }
        static void Main(string[] args)
        {
            Thread c = new Thread(Captain);
            Thread d = new Thread(Ticket);
            c.Start();
            d.Start();
        }
    }
}
