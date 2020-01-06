using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Dynamic_allocation
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //进程状态
        public enum State
        {
            ready, // 就绪
            run, // 运行
            finish // 完成
        }

        //创建进程数组
        public class Pro
        {
            public State state;
            public string name;
            public int size;
        }public Pro[] proList = new Pro[20];

        //创建进程处理
        public class Pro_deal
        {
            public Pro pro;
        }public Pro_deal[] dealList = new Pro_deal[40];

        int LocationX = 20;  //初始化TextBox x位置
        int LocationY = 60;  //初始化TextBox y位置
        int count = 1;   //初始化进程个数排序


        //增加进程
        private void button_add_Click(object sender, EventArgs e)
        {
            //将进程排序

            //增加进程名字输入框
            TextBox textbox_name = new TextBox();
            textbox_name.Name = "textBox_Proc" + "_name"+count;
            textbox_name.Location = new Point(30, LocationY);
            groupBox.Controls.Add(textbox_name);

            //增加进程大小输入框
            TextBox textbox_size = new TextBox();
            textbox_size.Name = "textBox_Proc" + "_size"+count;
            textbox_size.Location = new Point(160, LocationY);
            textbox_size.KeyPress += new KeyPressEventHandler(textBox_KeyPress);
            groupBox.Controls.Add(textbox_size);

            //增加进程序号
            Label label = new Label();
            label.Name = "label" + count.ToString();
            label.Text = count.ToString();
            label.Size = new Size(10, 10);
            label.Location = new Point(15, LocationY + 3);
            groupBox.Controls.Add(label);

            //增加禁用按钮
            Button button_delete = new Button();
            button_delete.Text = "禁用" + count.ToString() + "进程";
            button_delete.Name = "buuton_delete" + count.ToString();
            button_delete.Location = new Point(260, LocationY);
            button_delete.Click += new System.EventHandler(button_delete_Click);
            groupBox.Controls.Add(button_delete);

            //定位下一个控件
            LocationY=LocationY+30;
            count++;
        }

        //恢复启用进程
        private void button_enable_Click(object sender,EventArgs e)
        {
            Button button = (Button)sender;
            string num;
            num = button.Name.Substring(button.Name.Length - 1, 1);  //通过最后一个字符获取控件序号

            //遍历groupBox的所有控件
            foreach (Control control in this.groupBox.Controls)
            {
                //最后一个字符作为判断标准
                if (control.Name.Substring(control.Name.Length - 1, 1) == num)
                {
                    //修改Button为禁用
                    if (control is Button)
                    {
                        control.Text = "禁用" + num.ToString() + "进程";
                        control.Name = "buuton_delete" + num.ToString();
                        control.Click -= new System.EventHandler(button_enable_Click);  //注销启用事件
                        control.Click += new System.EventHandler(button_delete_Click);  //增加禁用事件
                    }
                    else
                    {
                        control.Enabled = true;
                    }
                }
            }
        }

        //禁用进程
        private void button_delete_Click(object sender,EventArgs e)
        {
            Button button = (Button)sender;
            string num;
            num = button.Name.Substring(button.Name.Length - 1, 1);  //通过最后一个字符获取控件序号

            //遍历groupBox的所有控件
            foreach(Control control in this.groupBox.Controls)
            {
                //最后一个字符作为判断标准
                if(control.Name.Substring(control.Name.Length-1,1) == num)
                {
                    //修改Button为释放
                    if (control is Button)
                    {
                        control.Text = "启动" + num.ToString() + "进程";
                        control.Name = "buuton_enable" + num.ToString();
                        control.Click -= new System.EventHandler(button_delete_Click);   //注销禁用事件
                        control.Click += new System.EventHandler(button_enable_Click);   //增加启用事件
                    }
                    else
                    {
                        control.Enabled = false;
                    }
                }
            }
        }

        //textBox_size的输入规则（只能输入数字）
        private void textBox_KeyPress(object sender,KeyPressEventArgs e)
        {
            if ((e.KeyChar < '0') || (e.KeyChar > '9'))//允许输入0-9数字  
            {
                e.Handled = true;
            }
        }

        //生成随机顺序
        private void button_random_Click(object sender, EventArgs e)
        {
            for(int i =1;count>i-1;i++)
            {
                proList[i] = new Pro();
                proList[i].name = null;
                proList[i].size = 0;
                proList[i].state = State.ready;
            }
            textBox_check.Text = "   进程名    "+ "进程大小" + "\r\n";
            //遍历groupBox的所有控件
            foreach (Control control in this.groupBox.Controls)
            {
                //找到启用的Textbox
                if (control is TextBox && control.Enabled == true)
                {
                    //判断值是否为空
                    if(control.Text == "")
                    {
                        MessageBox.Show(control.Name + "值空");
                        return;
                    }
                    //获取控件的序号
                    int num = Convert.ToInt32(control.Name.Substring(control.Name.Length - 1, 1));
                    //获取进程名字
                    if(control.Name.Contains("name"))
                    {
                        proList[num].name = control.Text.Trim();
                    }
                    //获取进程大小
                    if(control.Name.Contains("size"))
                    {
                        proList[num].size = Convert.ToInt32(control.Text.Trim());
                    }
                }
            }

            //打印进程数组
            int real_count=1;  //启用的进程数
            for(int i = 1;count>i;i++)
            {
                if (proList[i].size != 0)
                {
                    string msg =real_count +"  "+ proList[i].name + "         " + proList[i].size + "\r\n";
                    textBox_check.Text += msg;
                    msg = null;
                    real_count++;
                }
            }
            textBox_check.Text += "---------------\r\n";

            Random ran = new Random();
            int count_check = 1;   //有效数组个数
            int RandKey = ran.Next(1, count);  //产生随机数

            //初始化给处理数组
            dealList = new Pro_deal[40];
            for (int i = 1; count*2 > i; i++)
            {
                dealList[i] = new Pro_deal();
                dealList[i].pro = new Pro();
                dealList[i].pro.name = null;
                dealList[i].pro.state = State.ready;
                dealList[i].pro.size = 0;
            }

            while (count_check != (real_count-1)*2)
            {
                RandKey = ran.Next(1, count);  //产生随机数
                //string test = proList[RandKey].name;  //调试用
                if(proList[RandKey].name == null || proList[RandKey].name == "")
                {
                    continue;
                }
                //当程序的状态为ready时则录入处理进程数组中，并另其状态变成run
                else
                {
                    if (proList[RandKey].state == State.ready)
                    {
                        dealList[count_check].pro.name = proList[RandKey].name;
                        dealList[count_check].pro.size = proList[RandKey].size;
                        dealList[count_check].pro.state = State.run;
                        proList[RandKey].state = State.run;
                        //textBox_check.Text += dealList[count_check].pro.name + "占用" + dealList[count_check].pro.size + "KB" + "\r\n";
                        count_check++;
                    }
                    else if(proList[RandKey].state == State.run)
                    {
                        proList[RandKey].state = State.finish;
                        dealList[count_check].pro.name = proList[RandKey].name;
                        dealList[count_check].pro.size = proList[RandKey].size;
                        dealList[count_check].pro.state = State.finish;
                        //textBox_check.Text += dealList[count_check].pro.name + "释放" + dealList[count_check].pro.size + "KB" + "\r\n";
                        count_check++;
                    }
                }
            }

            textBox_check.Text +=  "------------" + "\r\n";

            //输出处理进程数组
            for (int i = 1; count_check >= i; i++)
            {
                if(dealList[i].pro.state == State.run)
                {
                    textBox_check.Text += dealList[i].pro.name + "占用" + dealList[i].pro.size + "KB" + "\r\n";
                }
                else if(dealList[i].pro.state == State.finish)
                {
                    textBox_check.Text += dealList[i].pro.name + "释放" + dealList[i].pro.size + "KB" + "\r\n";
                }
            }
        }

        private void button_submit_Click(object sender, EventArgs e)
        {
            Graphics gg = panel_draw.CreateGraphics();
            //  Rectangle r=new Rectangle ();  
            Pen p = new Pen(Brushes.Black);

            int iSeed = 10;
            Random ro = new Random(10);
            long tick = DateTime.Now.Ticks;
            Random ran = new Random((int)(tick & 0xffffffffL) | (int)(tick >> 32));

            int R = ran.Next(255);
            int G = ran.Next(255);
            int B = ran.Next(255);
            B = (R + G > 400) ? R + G - 400 : B;//0 : 380 - R - G;
            B = (B > 255) ? 255 : B;
            Color rand = Color.FromArgb(R, G, B);

            gg.DrawRectangle(p, 10, 10, 100, 210);
            gg.FillRectangle(new SolidBrush(rand), 30, 30, 30, 30);
        }
    }
}
