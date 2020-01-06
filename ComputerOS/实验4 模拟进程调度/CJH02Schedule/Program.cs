using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace CJH02Schedule
{
    //陈君豪
    class Program
    {
        public enum State
        {
            // 进程状态
            ready, // 就绪
            run, // 运行
            finish // 完成
        }i

        // 定义PCB结点
        public class PCB
        {
            public string name; // 进程名
            public State state; // 进程状态
            public double priority; // 优先数
            public int needTime; // 需要运行时间
            public int runTime; // 已运行时间
            public PCB next; // 链接到下一个PCB
            public int waitTime;//等待时间
            public override string ToString()
            {
                string s = string.Format("进程名：{0}，优先数：{1}，等待时间{2}，还需时间{3}",
                    name,
                    priority,
                    waitTime,
                    needTime - runTime);
                return s;
            }
        }

        // 就绪队列，队列中每个结点是一个进程项PCB信息。
        // 就绪队列按照PCB的优先数排列PCB结点
        public class PCBList
        {

            // 就绪队列长度
            private int count;
            public int Count
            {
                get { return count; }
                set { count = value; }
            }

            internal PCB Head { get => head; set => head = value; }

            private PCB head = null; // 就绪队列头结点

            // 将pcb按其优先数大小插入至就绪队列中
            public void Insert(PCB pcb)
            {
                // 如果就绪队列为空，则令头结点指向pcb
                if (Head == null)
                {
                    Head = pcb;
                    count++;
                    return;
                }

                // pcb插入位置不在队列之首，下面依次查找pcb插入位置
                PCB previous = Head;
                PCB current = Head.next;
                // 从就绪队列第二个结点开始比较
                while (current != null)
                {
                    // 从队列第二个结点开始，
                    // 依次遍历队列中每个结点的优先数与pcb的优先数
                    // 直到碰到第一个结点的优先数<pcb的优先数为止
                    if (current.priority < pcb.priority) break;
                    // 遍历下一个结点
                    previous = current;
                    current = current.next;
                }
                // 跳出循环，应该在previous结点和current结点之间插入pcb
                previous.next = pcb;
                pcb.next = current;
                count++;
            }

            // 摘取就绪队列首结点
            public PCB GetFirst()
            {
                PCB pcb = Head;
                return pcb;
            }

            public void DeleteFirst()
            {
                PCB pcb = Head;
                Head = Head.next;
                pcb.next = null;
                count--;
            }

            public void PrintList()
            {
                // 输出就绪队列里所有结点的信息
                PCB current = Head.next;
                while (current != null)
                {
                    Console.WriteLine(current.ToString());
                    current = current.next;
                }
            }



            public void Caculate()
            {

                PCB pcb = Head;
                pcb.priority = (pcb.waitTime + pcb.needTime) / (pcb.needTime * 1.0);
                pcb = Head.next;
                PCB current = pcb;

                while (current != null)
                {
                    current.priority = (current.waitTime + current.needTime) / (current.needTime * 1.0);
                    current.waitTime++;
                    current = current.next;
                }

                current = pcb;

                PCB teil = null;
                PCB cur = current;

                while (cur != teil)
                {
                    while (cur.next != teil)
                    {
                        if (cur.priority < cur.next.priority)
                        {
                            double tmp = cur.priority;
                            cur.priority = cur.next.priority;
                            cur.next.priority = tmp;

                            string nmp = cur.name;
                            cur.name = cur.next.name;
                            cur.next.name = nmp;

                            int imp = cur.needTime;
                            cur.needTime = cur.next.needTime;
                            cur.next.needTime = imp;

                            imp = cur.runTime;
                            cur.runTime = cur.next.runTime;
                            cur.next.runTime = imp;

                            imp = cur.waitTime;
                            cur.waitTime = cur.next.waitTime;
                            cur.next.waitTime = imp;

                            State smp = cur.state;
                            cur.state = cur.next.state;
                            cur.next.state = smp;

                        }
                        cur = cur.next;
                    }
                    teil = cur;
                    cur = current;
                }



                Head.next = null;
                count = 1;
                

                while (current != null)
                {
                    PCB pcb1 = new PCB();
                    pcb1.name = current.name;
                    pcb1.state = State.ready;
                    pcb1.needTime = current.needTime;
                    pcb1.runTime = current.runTime;
                    pcb1.waitTime = current.waitTime;
                    pcb1.priority = current.priority;
                    pcb1.next = null;
                    ready.Insert(pcb1);
                    current = current.next;
                }

            }


            public void Run()
            {
                PCB pcb = Head;
                // 已执行时间+1
                pcb.runTime++;
                if (pcb.runTime == pcb.needTime)
                {
                    // 如果已执行时间等于进程执行所需时间，进程执行完毕
                    pcb.state = State.finish;
                }
                else
                {
                    // 还没执行完，需要将pcb重新插入就绪队列
                    pcb.state = State.ready;
                }
                Caculate();
            }
        }
        static PCBList ready = new PCBList(); // 就绪进程队列
        static PCBList eList = new PCBList();//结束进程队列
        static void InputFromFile(string fileName)
        {
            try
            {
                FileStream fs = new FileStream(fileName, FileMode.Open);
                StreamReader sr = new StreamReader(fs);
                // 读取进程数
                int n = Convert.ToInt32(sr.ReadLine());
                string[] pcbInfo;
                // 依次读取每个进程
                for (int i = 0; i < n; i++)
                {
                    pcbInfo = sr.ReadLine().Split(' ');
                    // 建立、初始化PCB
                    PCB pcb = new PCB();
                    pcb.name = pcbInfo[0];
                    pcb.state = State.ready;
                    pcb.needTime = Convert.ToInt32(pcbInfo[1]);
                    pcb.runTime = 0;
                    pcb.waitTime = 0;
                    pcb.next = null;
                    // 将新PCB插入就绪队列
                    ready.Insert(pcb);
                }
                sr.Close();
                fs.Close();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        static void insertEnd(PCB pcb)
        {
            // 如果就绪队列为空，则令头结点指向pcb
            if (eList.Head == null)
            {
                eList.Head = pcb;
                eList.Count++;
                return;
            }

            PCB current = eList.Head;
            while (current != null)
            {
                if (current.next == null)
                {
                    current.next = pcb;
                    break;
                }
                current = current.next;
            }
            eList.Count++;
        }

        static void EndList()
        {
            // 输出所有进程的信息
            PCB pcb = eList.Head;
            PCB current = pcb;

            double averZhou = 0.0;//平均周转时间
            double averDai = 0.0;//平均带权周转时间
            while (current != null)
            {
                averZhou += current.waitTime + current.needTime;
                averDai += (current.waitTime + current.needTime) * 1.0 / current.needTime;
                current = current.next;
            }
            averZhou /= eList.Count;
            averDai /= eList.Count;

            current = pcb;
            while (current != null)
            {
                string s = string.Format("进程名：{0}，周转时间：{1}，带权周转时间{2}，平均周转时间{3}，平均带权周转时间{4}",
                current.name,
                current.waitTime + current.needTime,
                (current.waitTime + current.needTime) * 1.0 / current.needTime,
                averZhou,
                averDai);
                Console.WriteLine(s);
                current = current.next;
            }
        }


        static void Main(string[] args)
        {
            InputFromFile("pcblist.txt"); // 从pcblist.txt读入待调度进程信息

            // 模拟调度
            while (ready.Count != 0) // 就绪队列非空
            {
                // 从就绪队列摘取队首进程（优先数最高）运行
                PCB currentPCB = ready.GetFirst();
                ready.Run();
                Console.WriteLine("当前运行进程信息：");
                Console.WriteLine(currentPCB);
                Console.WriteLine("就绪队列列表：");
                ready.PrintList();
                if (currentPCB.state == State.finish)
                {
                    Console.WriteLine("进程{0}执行完毕", currentPCB.name);
                    ready.DeleteFirst();
                    insertEnd(currentPCB);
                    if (ready.GetFirst() == null)
                    {
                        Console.WriteLine("所有进程已完成");
                        EndList();
                    }
                }
                Console.WriteLine("按任意键继续");
                Console.ReadKey();
            }
            Console.WriteLine("所有进程执行完毕");
        }
    }
}
