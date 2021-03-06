﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;

namespace Reader_Writer
{
    class Reader_Writer
    {
        static Random rnd = new Random(unchecked((int)DateTime.Now.Ticks));
        //缓冲区模拟有100页的书
        static byte[] buffer = new byte[100];
        static ReaderWriterLock rwlock = new ReaderWriterLock();
        static Thread[] writers = new Thread[2];
        static Thread[] readers = new Thread[4];

        static void Main(string[] args)
        {
            string[] writerNames = { "W1", "W2" };
            string[] readerNames = { "R1", "R2", "R3", "R4" };
            //初始化书本内容
            for (int i = 0; i < 100; i++)
            {
                buffer[i] = (byte)(i + 1);
            }
            //初始化2个写者线程
            for (int i = 0; i < 2; i++)
            {
                writers[i] = new Thread(new ThreadStart(WriteMethod));
                writers[i].Name = writerNames[i];
            }
            //初始化4个读者线程
            for (int i = 0; i < 4; i++)
            {
                readers[i] = new Thread(new ThreadStart(ReadMethod));
                readers[i].Name = readerNames[i];
            }

            //指定线程开始执行的顺序,可调整
            readers[0].Start();
            writers[0].Start();
            readers[1].Start();
            writers[1].Start();
            readers[2].Start();
            readers[3].Start();
        }

        static void ReadMethod()
        {
            //申请读者锁,在此期间允许其他读者但阻止任何写者
            rwlock.AcquireReaderLock(Timeout.Infinite);
            try
            {
                int page = rnd.Next(1, 101);
                Console.WriteLine("读者线程 {0} 正在读第 {1} 页...", Thread.CurrentThread.Name, page);
                //模拟读过程
                Thread.Sleep(rnd.Next(3000, 6000));
                Console.WriteLine("读者线程 {0} 完成读操作.", Thread.CurrentThread.Name);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                //释放读者锁
                rwlock.ReleaseReaderLock();
            }
        }

        static void WriteMethod()
        {
            //申请写者锁,在此期间阻止任何读者和写者
            rwlock.AcquireWriterLock(Timeout.Infinite);
            try
            {
                Console.WriteLine(" 写者线程 {0} 开始工作...", Thread.CurrentThread.Name);
                int page = rnd.Next(1, 101);
                Console.WriteLine("写者线程 {0} 正在改写第 {1} 页的内容", Thread.CurrentThread.Name, page);
                Thread.Sleep(rnd.Next(3000, 6000));
                Console.WriteLine("写者线程 {0} 完成工作... ", Thread.CurrentThread.Name);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }
            finally
            {
                //释放写者锁
                rwlock.ReleaseWriterLock();
            }
        }
    }
}
