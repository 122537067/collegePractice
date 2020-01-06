using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 计划生育
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {

            //18岁
            if(comboBox_age.Text=="18")
            {
                if(comboBox_month.Text == "1"|| comboBox_month.Text == "3")
                {
                    label_answer.Text = "女";
                }
                else
                {
                    label_answer.Text = "男";
                }
            }


            //19岁
            if (comboBox_age.Text == "19")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "3"
                    || comboBox_month.Text == "6" || comboBox_month.Text == "12")
                {
                    label_answer.Text = "男";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }

            //20岁
            if (comboBox_age.Text == "20")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "10")
                {
                    label_answer.Text = "女";
                }
                else
                {
                    label_answer.Text = "男";
                }
            }

            //21岁
            if (comboBox_age.Text == "21")
            {
                if (comboBox_month.Text == "1")
                {
                    label_answer.Text = "男";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }


            //22岁
            if (comboBox_age.Text == "22")
            {
                if (comboBox_month.Text == "2" || comboBox_month.Text == "3" ||
                    comboBox_month.Text == "8" )
                {
                    label_answer.Text = "男";
                }
                else if(comboBox_month.Text=="5")
                {
                    label_answer.Text = "女双胞胎";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }


            //23岁
            if (comboBox_age.Text == "23")
            {
                if (comboBox_month.Text == "3" || comboBox_month.Text == "5" || comboBox_month.Text == "6" ||
                    comboBox_month.Text == "8" || comboBox_month.Text == "12" )
                {
                    label_answer.Text = "女";
                }
                else
                {
                    label_answer.Text = "男";
                }
            }

            //24岁
            if (comboBox_age.Text == "24")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "3" ||
                    comboBox_month.Text == "4" ||comboBox_month.Text == "7")
                {
                    label_answer.Text = "男";
                }
                else if (comboBox_month.Text == "6")
                {
                    label_answer.Text = "男双胞胎";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }

            //25岁
            if (comboBox_age.Text == "25")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "3" || comboBox_month.Text == "4" ||
                    comboBox_month.Text == "6" || comboBox_month.Text == "7")
                {
                    label_answer.Text = "女";
                }
                else
                {
                    label_answer.Text = "男";
                }
            }


            //26岁
            if (comboBox_age.Text == "26")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "2" ||
                    comboBox_month.Text == "3" || comboBox_month.Text == "8")
                {
                    label_answer.Text = "男";
                }
                else if (comboBox_month.Text == "5")
                {
                    label_answer.Text = "女双胞胎";
                }
                else if (comboBox_month.Text == "6")
                {
                    label_answer.Text = "男双胞胎";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }


            //27岁
            if (comboBox_age.Text == "27")
            {
                if (comboBox_month.Text == "4" || comboBox_month.Text == "7" || comboBox_month.Text == "8" ||
                    comboBox_month.Text == "9" || comboBox_month.Text == "11" || comboBox_month.Text == "12")
                {
                    label_answer.Text = "男";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }

            //28岁
            if (comboBox_age.Text == "28")
            {
                if (comboBox_month.Text == "4" || comboBox_month.Text == "5" || comboBox_month.Text == "6" ||
                    comboBox_month.Text == "11" || comboBox_month.Text == "12")
                {
                    label_answer.Text = "女";
                }
                else
                {
                    label_answer.Text = "男";
                }
            }

            //29岁
            if (comboBox_age.Text == "29")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "10" || comboBox_month.Text == "11" ||
                    comboBox_month.Text == "12")
                {
                    label_answer.Text = "女";
                }
                else
                {
                    label_answer.Text = "男";
                }
            }

            //30岁
            if (comboBox_age.Text == "30")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "10" || comboBox_month.Text == "12")
                {
                    label_answer.Text = "男";
                }
                else if(comboBox_month.Text=="2")
                {
                    label_answer.Text = "龙凤胎";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }

            //31\32岁
            if (comboBox_age.Text == "31"||comboBox_age.Text=="32")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "2" || comboBox_month.Text == "3" ||
                    comboBox_month.Text == "11" || comboBox_month.Text == "12")
                {
                    label_answer.Text = "男";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }

            //33岁
            if (comboBox_age.Text == "33")
            {
                if (comboBox_month.Text == "4" || comboBox_month.Text == "12")
                {
                    label_answer.Text = "男";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }

            //34岁
            if (comboBox_age.Text == "34")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "12")
                {
                    label_answer.Text = "男";
                }
                else if(comboBox_month.Text=="4")
                {
                    label_answer.Text = "男双胞胎";
                }
                else
                {
                    label_answer.Text = "男";
                }
            }

            //35岁
            if (comboBox_age.Text == "35")
            {
                if (comboBox_month.Text == "1" || comboBox_month.Text == "2" || comboBox_month.Text == "4" ||
                    comboBox_month.Text == "12")
                {
                    label_answer.Text = "男";
                }
                else
                {
                    label_answer.Text = "女";
                }
            }
        }






        //part2
        private void button2_Click(object sender, EventArgs e)
        {
            //18岁
            if (comboBox_age2.Text == "18")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "2、4、5、6、7、8、9、10、11、12月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "1、3月 生孩子";
                }
            }


            //19岁
            if (comboBox_age2.Text == "19")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "1、3、6、12月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "2、4、5、7、8、9、10、11月 生孩子";
                }
            }

            //20岁
            if (comboBox_age2.Text == "20")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "2、3、4、5、6、7、8、9、11、12月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "1、10月 生孩子";
                }
            }

            //21岁
            if (comboBox_age2.Text == "21")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "1月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "2、3、4、5、6、7、8、9、10、11、12月 生孩子";
                }
            }


            //22岁
            if (comboBox_age2.Text == "22")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "2、3、5、8月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "1、4、6、7、9、10、11、12月 生孩子";
                }
            }


            //23岁
            if (comboBox_age2.Text == "23")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "1、2、4、7、9、10、11月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "4、5、6、8、12月 生孩子";
                }
            }

            //24岁
            if (comboBox_age2.Text == "24")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "1、3、4、6、7月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "2、5、8、9、10、11、12月 生孩子";
                }
            }

            //25岁
            if (comboBox_age2.Text == "25")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "2、5、8、9、10、11、12月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "1、3、4、6、7月 生孩子";
                }
            }


            //26岁
            if (comboBox_age2.Text == "26")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "1、2、3、6、8月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "4、5、7、9、10、11、12月 生孩子";
                }
            }


            //27岁
            if (comboBox_age2.Text == "27")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "4、7、8、9、10月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "1、2、3、5、6、11、12月 生孩子";
                }
            }

            //28岁
            if (comboBox_age2.Text == "28")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "1、2、3、7、8、9、10月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "4、5、6、11、12月 生孩子";
                }
            }

            //29岁
            if (comboBox_age2.Text == "29")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "2、3、4、5、6、7、8、9月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "1、10、11、12月 生孩子";
                }
            }

            //30岁
            if (comboBox_age2.Text == "30")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "1、2、12月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "2、3、4、5、6、7、8、9、10、11月 生孩子";
                }
            }

            //31\32岁
            if (comboBox_age2.Text == "31" || comboBox_age2.Text == "32")
            {
                if (comboBox_month.Text == "男")
                {
                    label_answer_month.Text = "1、2、3、11、12月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "4、5、6、7、8、9、10月 生孩子";
                }
            }

            //33岁
            if (comboBox_age2.Text == "33")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "4、12月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "1、2、3、5、6、7、8、9、10、11月 生孩子";
                }
            }

            //34岁
            if (comboBox_age2.Text == "34")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "1、4、12月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "2、3、5、6、7、8、9、10、11月 生孩子";
                }
            }

            //35岁
            if (comboBox_age2.Text == "35")
            {
                if (comboBox_sex.Text == "男")
                {
                    label_answer_month.Text = "1、2、4、12月 生孩子";
                }
                else
                {
                    label_answer_month.Text = "3、5、6、7、8、9、10、11月 生孩子";
                }
            }
        }
    }
}
