#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>	
#include<cstdlib>
#include<string>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<iomanip>
#include <fstream>
using namespace std;
int pane[4][4];   //4*4
int t = 4;
struct Rank
{
	string name;
	int score;
}a[1005] = { { "强健的肌腱", 4586 }, { "颓废小魔", 5624 }, { "比你帅的人", 2330 }, { "清风", 6666 } };
int cmp(struct Rank a, struct Rank b)
{
	return a.score>b.score;
}
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void start()                                                                     //开始界面
{
	printf("\n");
	printf("\n");
	printf("       ");
	printf("当前时间\n");
	printf("       ");
	system("date /T");											//日期显示
	printf("       ");
	system("TIME /T");											//时间显示
	printf("     ┏━━━━━━━━━━━━━━━━━┓\n");	//菜单界面
	printf("     ┃             2 0 4 8              ┃\n");
	printf("     ┃                                  ┃\n");
	printf("     ┃                                  ┃\n");
	printf("     ┃            1.开始游戏            ┃\n");
	printf("     ┃                                  ┃\n");
	printf("     ┃            2.游戏介绍            ┃\n");
	printf("     ┃                                  ┃\n");
	printf("     ┃            3.操作说明            ┃\n");
	printf("     ┃                                  ┃\n");
	printf("     ┃            4.颜色设置            ┃\n");
	printf("     ┃                                  ┃\n");
	printf("     ┃            5.排行榜              ┃\n");
	printf("     ┗━━━━━━━━━━━━━━━━━┛\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("             输入表中对应数字继续游戏      \n");
}
void color(int b, int a)															  //颜色选择函数
{
	if (b == 0)                                                                   //背景颜色为黑色时
	{
		if (a == 1)  system("color 01");
		else if (a == 2)  system("color 02");
		else if (a == 3)  system("color 03");
		else if (a == 4)  system("color 04");
		else if (a == 5)  system("color 05");
		else if (a == 6)  system("color 06");
		else if (a == 7)  system("color 07");
		else if (a == 8)  system("color 08");
		else if (a == 9)  system("color 09");
		else if (a == 10)  system("color 0A");
		else if (a == 11)  system("color 0B");
		else if (a == 12)  system("color 0C");
		else if (a == 13)  system("color 0D");
		else if (a == 14)  system("color 0E");
		else if (a == 15)  system("color 0F");
	}
	if (b == 1)                                                                   //背景颜色为蓝色时
	{
		if (a == 0)  system("color 10");
		else if (a == 2)  system("color 12");
		else if (a == 3)  system("color 13");
		else if (a == 4)  system("color 14");
		else if (a == 5)  system("color 15");
		else if (a == 6)  system("color 16");
		else if (a == 7)  system("color 17");
		else if (a == 8)  system("color 18");
		else if (a == 9)  system("color 19");
		else if (a == 10)  system("color 1A");
		else if (a == 11)  system("color 1B");
		else if (a == 12)  system("color 1C");
		else if (a == 13)  system("color 1D");
		else if (a == 14)  system("color 1E");
		else if (a == 15)  system("color 1F");
	}
	if (b == 2)                                                                   //背景颜色为绿色时
	{
		if (a == 1)  system("color 21");
		else if (a == 0)  system("color 20");
		else if (a == 3)  system("color 23");
		else if (a == 4)  system("color 24");
		else if (a == 5)  system("color 25");
		else if (a == 6)  system("color 26");
		else if (a == 7)  system("color 27");
		else if (a == 8)  system("color 28");
		else if (a == 9)  system("color 29");
		else if (a == 10)  system("color 2A");
		else if (a == 11)  system("color 2B");
		else if (a == 12)  system("color 2C");
		else if (a == 13)  system("color 2D");
		else if (a == 14)  system("color 2E");
		else if (a == 15)  system("color 2F");
	}
	if (b == 3)                                                                   //背景颜色为湖蓝色时
	{
		if (a == 1)  system("color 31");
		else if (a == 2)  system("color 32");
		else if (a == 0)  system("color 30");
		else if (a == 4)  system("color 34");
		else if (a == 5)  system("color 35");
		else if (a == 6)  system("color 36");
		else if (a == 7)  system("color 37");
		else if (a == 8)  system("color 38");
		else if (a == 9)  system("color 39");
		else if (a == 10)  system("color 3A");
		else if (a == 11)  system("color 3B");
		else if (a == 12)  system("color 3C");
		else if (a == 13)  system("color 3D");
		else if (a == 14)  system("color 3E");
		else if (a == 15)  system("color 3F");
	}
	if (b == 4)                                                                   //背景颜色为红色时
	{
		if (a == 1)  system("color 41");
		else if (a == 2)  system("color 42");
		else if (a == 3)  system("color 43");
		else if (a == 0)  system("color 40");
		else if (a == 5)  system("color 45");
		else if (a == 6)  system("color 46");
		else if (a == 7)  system("color 47");
		else if (a == 8)  system("color 48");
		else if (a == 9)  system("color 49");
		else if (a == 10)  system("color 4A");
		else if (a == 11)  system("color 4B");
		else if (a == 12)  system("color 4C");
		else if (a == 13)  system("color 4D");
		else if (a == 14)  system("color 4E");
		else if (a == 15)  system("color 4F");
	}
	if (b == 5)                                                                   //背景颜色为紫色时
	{
		if (a == 1)  system("color 51");
		else if (a == 2)  system("color 52");
		else if (a == 3)  system("color 53");
		else if (a == 4)  system("color 54");
		else if (a == 0)  system("color 50");
		else if (a == 6)  system("color 56");
		else if (a == 7)  system("color 57");
		else if (a == 8)  system("color 58");
		else if (a == 9)  system("color 59");
		else if (a == 10)  system("color 5A");
		else if (a == 11)  system("color 5B");
		else if (a == 12)  system("color 5C");
		else if (a == 13)  system("color 5D");
		else if (a == 14)  system("color 5E");
		else if (a == 15)  system("color 5F");
	}
	if (b == 6)                                                                   //背景颜色为黄色时
	{
		if (a == 1)  system("color 61");
		else if (a == 2)  system("color 62");
		else if (a == 3)  system("color 63");
		else if (a == 4)  system("color 64");
		else if (a == 5)  system("color 65");
		else if (a == 0)  system("color 60");
		else if (a == 7)  system("color 67");
		else if (a == 8)  system("color 68");
		else if (a == 9)  system("color 69");
		else if (a == 10)  system("color 6A");
		else if (a == 11)  system("color 6B");
		else if (a == 12)  system("color 6C");
		else if (a == 13)  system("color 6D");
		else if (a == 14)  system("color 6E");
		else if (a == 15)  system("color 6F");
	}
	if (b == 7)                                                                   //背景颜色为白色时
	{
		if (a == 1)  system("color 71");
		else if (a == 2)  system("color 72");
		else if (a == 3)  system("color 73");
		else if (a == 4)  system("color 74");
		else if (a == 5)  system("color 75");
		else if (a == 6)  system("color 76");
		else if (a == 0)  system("color 77");
		else if (a == 8)  system("color 78");
		else if (a == 9)  system("color 79");
		else if (a == 10)  system("color 7A");
		else if (a == 11)  system("color 7B");
		else if (a == 12)  system("color 7C");
		else if (a == 13)  system("color 7D");
		else if (a == 14)  system("color 7E");
		else if (a == 15)  system("color 7F");
	}
	if (b == 8)                                                                   //背景颜色为灰色时
	{
		if (a == 1)  system("color 81");
		else if (a == 2)  system("color 82");
		else if (a == 3)  system("color 83");
		else if (a == 4)  system("color 84");
		else if (a == 5)  system("color 85");
		else if (a == 6)  system("color 86");
		else if (a == 7)  system("color 87");
		else if (a == 0)  system("color 80");
		else if (a == 9)  system("color 89");
		else if (a == 10)  system("color 8A");
		else if (a == 11)  system("color 8B");
		else if (a == 12)  system("color 8C");
		else if (a == 13)  system("color 8D");
		else if (a == 14)  system("color 8E");
		else if (a == 15)  system("color 8F");
	}
	if (b == 9)                                                                   //背景颜色为淡蓝色时
	{
		if (a == 1)  system("color 91");
		else if (a == 2)  system("color 92");
		else if (a == 3)  system("color 93");
		else if (a == 4)  system("color 94");
		else if (a == 5)  system("color 95");
		else if (a == 6)  system("color 96");
		else if (a == 7)  system("color 97");
		else if (a == 8)  system("color 98");
		else if (a == 0)  system("color 90");
		else if (a == 10)  system("color 9A");
		else if (a == 11)  system("color 9B");
		else if (a == 12)  system("color 9C");
		else if (a == 13)  system("color 9D");
		else if (a == 14)  system("color 9E");
		else if (a == 15)  system("color 9F");
	}
	if (b == 10)                                                                   //背景颜色为淡绿色时
	{
		if (a == 1)  system("color A1");
		else if (a == 2)  system("color A2");
		else if (a == 3)  system("color A3");
		else if (a == 4)  system("color A4");
		else if (a == 5)  system("color A5");
		else if (a == 6)  system("color A6");
		else if (a == 7)  system("color A7");
		else if (a == 8)  system("color A8");
		else if (a == 9)  system("color A9");
		else if (a == 0)  system("color 0A");
		else if (a == 11)  system("color AB");
		else if (a == 12)  system("color AC");
		else if (a == 13)  system("color AD");
		else if (a == 14)  system("color AE");
		else if (a == 15)  system("color AF");
	}
	if (b == 11)                                                                   //背景颜色为淡浅绿色时
	{
		if (a == 1)  system("color B1");
		else if (a == 2)  system("color B2");
		else if (a == 3)  system("color B3");
		else if (a == 4)  system("color B4");
		else if (a == 5)  system("color B5");
		else if (a == 6)  system("color B6");
		else if (a == 7)  system("color B7");
		else if (a == 8)  system("color B8");
		else if (a == 9)  system("color B9");
		else if (a == 10)  system("color BA");
		else if (a == 0)  system("color B0");
		else if (a == 12)  system("color BC");
		else if (a == 13)  system("color BD");
		else if (a == 14)  system("color BE");
		else if (a == 15)  system("color BF");
	}
	if (b == 12)                                                                   //背景颜色为淡红色时
	{
		if (a == 1)  system("color C1");
		else if (a == 2)  system("color C2");
		else if (a == 3)  system("color C3");
		else if (a == 4)  system("color C4");
		else if (a == 5)  system("color C5");
		else if (a == 6)  system("color C6");
		else if (a == 7)  system("color C7");
		else if (a == 8)  system("color C8");
		else if (a == 9)  system("color C9");
		else if (a == 10)  system("color CA");
		else if (a == 11)  system("color CB");
		else if (a == 0)  system("color C0");
		else if (a == 13)  system("color CD");
		else if (a == 14)  system("color CE");
		else if (a == 15)  system("color CF");
	}
	if (b == 13)                                                                   //背景颜色为淡紫色时
	{
		if (a == 1)  system("color D1");
		else if (a == 2)  system("color D2");
		else if (a == 3)  system("color D3");
		else if (a == 4)  system("color D4");
		else if (a == 5)  system("color D5");
		else if (a == 6)  system("color D6");
		else if (a == 7)  system("color D7");
		else if (a == 8)  system("color D8");
		else if (a == 9)  system("color D9");
		else if (a == 10)  system("color DA");
		else if (a == 11)  system("color DB");
		else if (a == 12)  system("color DC");
		else if (a == 0)  system("color D0");
		else if (a == 14)  system("color DE");
		else if (a == 15)  system("color DF");
	}
	if (b == 14)                                                                   //背景颜色为淡黄色时
	{
		if (a == 1)  system("color E1");
		else if (a == 2)  system("color E2");
		else if (a == 3)  system("color E3");
		else if (a == 4)  system("color E4");
		else if (a == 5)  system("color E5");
		else if (a == 6)  system("color E6");
		else if (a == 7)  system("color E7");
		else if (a == 8)  system("color E8");
		else if (a == 9)  system("color E9");
		else if (a == 10)  system("color EA");
		else if (a == 11)  system("color EB");
		else if (a == 12)  system("color EC");
		else if (a == 13)  system("color ED");
		else if (a == 0)  system("color EE");
		else if (a == 15)  system("color EF");
	}
	if (b == 15)                                                                   //背景颜色为亮白色时
	{
		if (a == 1)  system("color F1");
		else if (a == 2)  system("color F2");
		else if (a == 3)  system("color F3");
		else if (a == 4)  system("color F4");
		else if (a == 5)  system("color F5");
		else if (a == 6)  system("color F6");
		else if (a == 7)  system("color F7");
		else if (a == 8)  system("color F8");
		else if (a == 9)  system("color F9");
		else if (a == 10)  system("color FA");
		else if (a == 11)  system("color FB");
		else if (a == 12)  system("color FC");
		else if (a == 13)  system("color FD");
		else if (a == 14)  system("color FE");
		else if (a == 0)  system("color F0");
	}

}
void colorchosen()                                 //颜色选择界面
{
	int a, b;
	char judge;
	int c = 1;
	printf("\n");
	printf("\n");
	printf("       ");
	printf("当前时间\n");
	printf("       ");
	system("date /T");											//日期显示
	printf("       ");
	system("TIME /T");											//时间显示
	printf("     ┏━━━━━━━━━━━━━━━━━┓\n");	//菜单界面
	printf("     ┃             2 0 4 8              ┃\n");
	printf("     ┃           颜 色 选 择            ┃\n");
	printf("     ┃                                  ┃\n");
	printf("     ┃颜色代码 0.黑色     1.蓝色        ┃\n");
	printf("     ┃         2.绿色     3.湖蓝色      ┃\n");
	printf("     ┃         4.红色     5.紫色        ┃\n");
	printf("     ┃         6.黄色     7.白色        ┃\n");
	printf("     ┃         8.灰色     9.淡蓝色      ┃\n");
	printf("     ┃         10.淡绿色  11.浅绿色     ┃\n");
	printf("     ┃         12.淡红色  13.淡紫色     ┃\n");
	printf("     ┃         14.淡黄色  15.亮白色     ┃\n");
	printf("     ┃(注意：背景颜色与字体颜色不能相同)┃\n");
	printf("     ┗━━━━━━━━━━━━━━━━━┛\n");
	printf("\n");
	printf("\n");
	printf("\n");
	while (c == 1)
	{
		printf("字体颜色:");
		cin >> a;
		while (a > 16 || a < 0)
		{
			printf("输入有误 请重新输入\n");
			printf("字体颜色:");
			cin >> a;
		}
		printf("\n");
		printf("背景颜色:");
		cin >> b;
		while (b > 16 || b < 0)
		{
			printf("输入有误 请重新输入\n");
			printf("背景颜色:");
			cin >> b;
		}
		if (a == b)
		{
			printf("背景颜色与字体颜色不能相同\n");
			printf("请重新输入\n");
			continue;
		}
		printf("\n");
		printf("\n");
		printf("确定选择按 Y，重新选择按N");
		printf("\n");
		cin >> judge;
		if (judge == 'y' || judge == 'Y')
		{
			c = 0;
			color(b, a);
			system("cls");
			start();
		}
		else if (judge == 'n' || judge == 'N')
		{
			c = 1;
		}
		else
		{
			printf("输入有错 请重新输入\n");
			c = 1;
		}

	}
}
void games_introduce()               //游戏介绍界面
{
	printf("游戏介绍：\n");
	printf("《2048》是比较流行的一款数字游戏，原版2048首先在github上发布，\n");
	printf("原作者是Gabriele Cirulli。它是基于《1024》和《小3传奇》的玩法\n");
	printf("开发而成的新型数字游戏。随后2048便出现各种版本，走各大平台。\n");
	printf("2048是在一个正宫格(4*4的正方形格子)中进行的，一开始游目标是\n");
	printf("戏会出现2个数字，在游戏中系统本身只会给出2跟4这2个数字的。而\n");
	printf("2048，开始开始后，玩家要通过移动数字进行合并来达到2048。我们\n");
	printf("在游戏中玩家将数字移动一个方向，正宫格中所以的数字也会同样移\n");
	printf("动，通过这样的移动我们要合成2048的，就是2跟2合成4，4跟4合成\n");
	printf("8以此类推，只有同数值的数字才能合成。当玩家成功合成2048后，\n");
	printf("游戏就顺利通关了，而如果正宫格中的格子全部填满并且相邻的格\n");
	printf("子都不相同也就是无法移动的话，那么很遗憾，gameover。\n");
	printf("\n");
	printf("\n");
	printf("按任意键返回");
	_getch();
	system("cls");
	start();
}
void games_explain()                 //游戏操作界面
{
	printf("操作说明\n");
	printf("按“↑”将数字向上移动\n");
	printf("按“↓”将数字向下移动\n");
	printf("按“←”将数字向左移动\n");
	printf("按“→”将数字向右移动\n");
	printf("按任意键返回");
	_getch();
	system("cls");
	start();
}
int maxscore()//本次游戏的最大值
{
	int max = pane[0][0], i, j;
	for (i = 0; i<4; i++)
	{
		for (j = 0; j<4; j++)
		{
			max = max>pane[i][j] ? max : pane[i][j];
		}
	}
	return max;
}
int score()//本次游戏分数
{
	int sum = 0;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j<4; j++)
		{
			sum += pane[i][j];
		}
	}
	return sum;
}
void Newpane() //显示棋盘  
{
	gotoxy(0, 0);
	cout << setw(53) << "_______________________________________" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setw(12) << "";
		for (int j = 0; j < 4; j++)
		{
			if (pane[i][j] == 0)
			{
				cout << setw(3) << "┃" << "       ";
			}
			else
			{
				cout << setw(3) << "┃" << "       ";
			}
			if (j == 3)
			{
				cout << setw(3) << "┃" << endl;
				cout << setw(55) << " ┃________┃________┃________┃________┃" << endl;
			}
		}
	}
}
void num()//打印棋盘数字
{
	gotoxy(0, 0);
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (pane[i][j] != 0)
			{
				if (j == 0)
				{
					gotoxy(15, 2 * (i + 1) - 1);
				}
				else if (j == 1)
				{
					gotoxy(25, 2 * (i + 1) - 1);
				}
				else if (j == 2)
				{
					gotoxy(35, 2 * (i + 1) - 1);
				}
				else if (j == 3)
				{
					gotoxy(45, 2 * (i + 1) - 1);
				}
				cout << pane[i][j] << "   ";
			}
			else
			{
				if (j == 0)
				{
					gotoxy(15, 2 * (i + 1) - 1);
				}
				else if (j == 1)
				{
					gotoxy(25, 2 * (i + 1) - 1);
				}
				else if (j == 2)
				{
					gotoxy(35, 2 * (i + 1) - 1);
				}
				else if (j == 3)
				{
					gotoxy(45, 2 * (i + 1) - 1);
				}
				cout << "    ";
			}
			if (j == 3)
			{
				cout << endl;
				cout << endl;
			}
		}
	}
	cout << endl;
	cout << setw(20) << "最大值：" << maxscore() << endl;
	cout << setw(20) << "最高分：" << score() << setw(56) << "2048 by 326" << endl;
}
void rank2() //读档
{
	ifstream OpenFile("1.txt");

	char ch;
	printf("			  2 0 4 8排行榜\n\n");
	while (!OpenFile.eof())
	{
		OpenFile.get(ch);
		cout << ch;
	}
	OpenFile.close();
	printf("按任意键返回");
	_getch();
	system("cls");
	start();
}
void rank1()//排行榜
{
	int num = t;
	ifstream infile;
	ofstream outfile;
	sort(a, a + num, cmp);
	system("cls");
	printf("			  2 0 4 8排行榜\n\n");
	outfile.open("1.txt");
	for (int i = 0; i<num; i++)
	{
		outfile << "		 " << i + 1 << ':' << "  " << a[i].name << "  " << a[i].score<<endl<<endl;
		cout << "		 " << i + 1 << ':' << "  " << a[i].name << "  " << a[i].score<<endl;
		cout << endl;
		if (i == 9)break;
	}
	outfile.close();
	printf("按任意键返回");
	_getch();
	system("cls");
	start();

}
void Newgame() //开始游戏  
{
	for (int i = 0; i < 4; i++) //初始化棋盘  
	{
		for (int j = 0; j < 4; j++)
		{
			pane[i][j] = 0;
		}
	}
	srand((unsigned)time(NULL));//随机生成棋盘两格的随机数
	int m = rand() % 4;
	int n = rand() % 4;
	int p = rand() % 4;
	int q = rand() % 4;
	pane[m][n] = pane[p][q] = 2;
	Newpane();
	num();
}
void add(int n)//随机生成
{
	int num = rand();												//产生随机数
	int would = num % 2;											//取除以2的余数，均分随机数
	int x, y, i;
	srand((unsigned int)time(0));									//srand函数是随机数发生器的初始化函数
	x = num % 4;													//取除以4的余数
	srand((unsigned int)time(0) + (unsigned int)num);				//srand()用来设置rand()产生随机数时的随机数种子，改变伪随机数序列
	y = rand();
	y %= 4;															//y对4求余
	if (would)														//随机数为奇数
		num = 2;
	else															//随机数为偶数
		num = 4;													//随机得到 2 或 4	
	if (n == 0)
	{
		pane[x][y] = num;											//游戏开始 随机放置2 或 4
	}
	else if (n == 1)												//上移只在第四排放置
	{
		if (pane[3][y] == 0)
			pane[3][y] = num;										//随机放置		
		else
			for (i = 0; i < 4; i++)									//顺序放置
				if (pane[3][i] == 0)
				{
					pane[3][i] = num;
					break;
				}
	}
	else if (n == 2)												//下移
	{
		if (pane[0][y] == 0)
			pane[0][y] = num;
		else
			for (i = 0; i < 4; i++)
				if (pane[0][i] == 0)
				{
					pane[0][i] = num;
					break;
				}
	}
	else if (n == 3)												//左移
	{
		if (pane[x][3] == 0)
			pane[x][3] = num;
		else
			for (i = 0; i < 4; i++)
				if (pane[i][3] == 0)
				{
					pane[i][3] = num;
					break;
				}
	}
	else if (n == 4)												//右移
	{
		if (pane[x][0] == 0)
			pane[x][0] = num;
		else
			for (i = 0; i < 4; i++)
				if (pane[i][0] == 0)
				{
					pane[i][0] = num;
					break;
				}
	}
}
int move_up(void)
{
	int i, k, t;												//游戏继续标志
	for (k = 0; k < 4; k++)
	{
		int n = 4;
		while (n--)
		{
			for (i = 0; i < 3; i++)
			{
				if (pane[i][k] == 0)									//如果上方有空位
				{
					for (t = i; t < 3; t++)
					{
						pane[t][k] = pane[t + 1][k];					//上移一个数
						pane[t + 1][k] = 0;							//原位置清零
					}
				}
			}
		}
		for (i = 0; i < 3; i++)
		{
			if (pane[i][k] == pane[i + 1][k])							//如果上下相邻数字相同
			{
				pane[i][k] *= 2;										//合并数字
				pane[i + 1][k] = 0;
				for (t = i + 1; t < 3; t++)							//合并数据后再次判断有无空位
				{
					pane[t][k] = pane[t + 1][k];						//填补空位
					pane[t + 1][k] = 0;
				}
			}
		}
	}
	add(1);
	return 1;
}
int move_down(void)
{
	int i, k, t;													//游戏继续标志
	for (k = 0; k < 4; k++)
	{
		int n = 4;
		while (n--)
		{
			for (i = 3; i >0; i--)
			{
				if (pane[i][k] == 0)									//如果下方有空位
				{
					for (t = i; t > 0; t--)
					{
						pane[t][k] = pane[t - 1][k];					//下移一个数
						pane[t - 1][k] = 0;							//原位置清零
					}
				}
			}
		}
		for (i = 3; i > 0; i--)
		{
			if (pane[i][k] == pane[i - 1][k])							//如果上下相邻数字相同
			{
				pane[i][k] *= 2;										//合并数字
				pane[i - 1][k] = 0;
				for (t = i - 1; t > 0; t--)							//合并数据后再次判断有无空位
				{
					pane[t][k] = pane[t - 1][k];						//填补空位
					pane[t - 1][k] = 0;
				}
			}
		}
	}
	add(2);
	return 1;
}
int move_left(void)
{
	int i, k, t;												//游戏继续标志
	for (i = 0; i < 4; i++)
	{
		int n = 4;
		while (n--)
		{
			for (k = 0; k < 3; k++)
			{
				if (pane[i][k] == 0)									//如果左方有空位
				{
					for (t = k; t < 3; t++)
					{
						pane[i][t] = pane[i][t + 1];					//左移一个数
						pane[i][t + 1] = 0;
					}
				}
			}
		}
		for (k = 0; k < 3; k++)
		{
			if (pane[i][k] == pane[i][k + 1])							//如果左右相邻数字相同
			{
				pane[i][k] *= 2;										//合并数字
				pane[i][k + 1] = 0;
				for (t = k + 1; t < 3; t++)							//合并数据后再次判断有无空位
				{
					pane[i][t] = pane[i][t + 1];						//填补空位
					pane[i][t + 1] = 0;
				}
			}
		}
	}
	add(3);
	return 1;
}
int move_right(void)
{
	int i, k, t;												//游戏继续标志
	for (i = 0; i <4; i++)
	{
		int n = 4;
		while (n--)
		{
			for (k = 3; k > 0; k--)
			{
				if (pane[i][k] == 0)									//如果右方有空位
				{
					for (t = k; t > 0; t--)
					{
						pane[i][t] = pane[i][t - 1];					//右移一个数
						pane[i][t - 1] = 0;
					}
				}
			}
		}
		for (k = 3; k > 0; k--)
		{
			if (pane[i][k] == pane[i][k - 1])							//如果左右相邻数字相同
			{
				pane[i][k] *= 2;										//合并数字
				pane[i][k - 1] = 0;
				for (t = k - 1; t > 0; t--)							//合并数据后再次判断有无空位
				{
					pane[i][t] = pane[i][t - 1];						//填补空位
					pane[i][t - 1] = 0;
				}
			}
		}
	}
	add(4);
	return 1;
}
int judge(void)
{
	int i, k;
	for (i = 0; i < 4; i++)
	{
		for (k = 1; k < 4; k++)										//判断左右是否有相同
			if (pane[i][k - 1] == pane[i][k])
				return 0;
	}
	for (i = 0; i < 4; i++)											//判断上下是否有相同
	{
		for (k = 1; k < 4; k++)
			if (pane[k - 1][i] == pane[k][i])
				return 0;
	}
	for (i = 0; i < 4; i++)											//判断是否仍有空位
	{
		for (k = 0; k < 4; k++)
			if (pane[k][i] == 0)
				return 0;
	}
	return 1;
}
int win()
{
	int flag = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (pane[i][j] == 2048)
			{
				flag = 1;
				break;
			}
		}
	}
	return flag;
}
int  game()//游戏具体运行流程
{
	system("CLS");
	int flag = 1;
	Newgame();//初始化棋盘
	while (1)//当游戏不结束时，游戏始终循环
	{
		int ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			switch (ch)
			{
			case 72://上移
			{
				if (move_up() == 1)
				{
					num();
					if (win() == 1)
					{
						printf("恭喜你，达成2048！\n");
						flag = 0;
					}
					else if (judge() == 1)
					{
						printf("游戏结束！\n");
						flag = 0;
					}
				}
				break;
			}
			case 75://左移
			{
				if (move_left() == 1)
				{
					num();
					if (win() == 1)
					{
						printf("恭喜你，达成2048！\n");
						flag = 0;
					}
					else if (judge() == 1)
					{
						printf("游戏结束！\n");
						flag = 0;
					}
				}
				break;
			}
			case 77://右移
			{
				if (move_right() == 1)
				{
					num();
					if (win() == 1)
					{
						printf("恭喜你，达成2048！\n");
						flag = 0;
					}
					else if (judge() == 1)
					{
						printf("游戏结束！\n");
						flag = 0;
					}
					break;
				}
				break;
			}
			case 80://下移
			{
				if (move_down() == 1)
				{
					num();
					if (win() == 1)
					{
						printf("恭喜你，达成2048！\n");
						flag = 0;
					}
					else if (judge() == 1)
					{
						printf("游戏结束！\n");
						flag = 0;
					}
				}
				break;
			}
			default:break;
			}
		}
		if (flag == 0) { break; }
	}
	if (flag == 0)//当游戏结束时
	{
		char save;
		printf("是否保存记录，输入1确认保存记录，输入其他键不保存记录\n");
		cin >> save;
		if (save == '1')
		{
			string name1;
			int Score = score();
			printf("请输入你的昵称\n");
			cin >> name1;
			a[t].name = name1; a[t].score = Score;
			t++;
			rank1();
		}
		else
		{
			system("cls");
			rank2();
		}
	}
	return 0;
}
int main()
{
	start();//初始化界面
	string startchosen = "0";//初始化游戏选择
	while (startchosen == "0")
	{
		cin >> startchosen;
		if (startchosen =="1")//进入游戏
		{
			system("cls");
			game();
			startchosen = "0";
		}
		else if (startchosen == "2")//进入游戏介绍
		{
			system("cls");
			games_introduce();
			startchosen = "0";
		}
		else if (startchosen == "3")//进入游戏说明
		{
			system("cls");
			games_explain();
			startchosen = "0";
		}
		else if (startchosen == "4")//进入游戏界面选择
		{
			system("cls");
			colorchosen();
			startchosen = "0";
		}
		else if (startchosen == "5")//进入游戏排名榜
		{
			system("cls");
			rank2();
			startchosen = "0";
		}
		else
		{
			printf("输入有误 请重新输入\n");
			printf("按任意键返回\n");
			_getch();
			system("cls");
			startchosen = "0";
			start();
		}
	}

	printf("\n");
	printf("\n");
}