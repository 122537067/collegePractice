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
}a[1005] = { { "ǿ���ļ���", 4586 }, { "�Ƿ�Сħ", 5624 }, { "����˧����", 2330 }, { "���", 6666 } };
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
void start()                                                                     //��ʼ����
{
	printf("\n");
	printf("\n");
	printf("       ");
	printf("��ǰʱ��\n");
	printf("       ");
	system("date /T");											//������ʾ
	printf("       ");
	system("TIME /T");											//ʱ����ʾ
	printf("     ��������������������������������������\n");	//�˵�����
	printf("     ��             2 0 4 8              ��\n");
	printf("     ��                                  ��\n");
	printf("     ��                                  ��\n");
	printf("     ��            1.��ʼ��Ϸ            ��\n");
	printf("     ��                                  ��\n");
	printf("     ��            2.��Ϸ����            ��\n");
	printf("     ��                                  ��\n");
	printf("     ��            3.����˵��            ��\n");
	printf("     ��                                  ��\n");
	printf("     ��            4.��ɫ����            ��\n");
	printf("     ��                                  ��\n");
	printf("     ��            5.���а�              ��\n");
	printf("     ��������������������������������������\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("             ������ж�Ӧ���ּ�����Ϸ      \n");
}
void color(int b, int a)															  //��ɫѡ����
{
	if (b == 0)                                                                   //������ɫΪ��ɫʱ
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
	if (b == 1)                                                                   //������ɫΪ��ɫʱ
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
	if (b == 2)                                                                   //������ɫΪ��ɫʱ
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
	if (b == 3)                                                                   //������ɫΪ����ɫʱ
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
	if (b == 4)                                                                   //������ɫΪ��ɫʱ
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
	if (b == 5)                                                                   //������ɫΪ��ɫʱ
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
	if (b == 6)                                                                   //������ɫΪ��ɫʱ
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
	if (b == 7)                                                                   //������ɫΪ��ɫʱ
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
	if (b == 8)                                                                   //������ɫΪ��ɫʱ
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
	if (b == 9)                                                                   //������ɫΪ����ɫʱ
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
	if (b == 10)                                                                   //������ɫΪ����ɫʱ
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
	if (b == 11)                                                                   //������ɫΪ��ǳ��ɫʱ
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
	if (b == 12)                                                                   //������ɫΪ����ɫʱ
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
	if (b == 13)                                                                   //������ɫΪ����ɫʱ
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
	if (b == 14)                                                                   //������ɫΪ����ɫʱ
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
	if (b == 15)                                                                   //������ɫΪ����ɫʱ
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
void colorchosen()                                 //��ɫѡ�����
{
	int a, b;
	char judge;
	int c = 1;
	printf("\n");
	printf("\n");
	printf("       ");
	printf("��ǰʱ��\n");
	printf("       ");
	system("date /T");											//������ʾ
	printf("       ");
	system("TIME /T");											//ʱ����ʾ
	printf("     ��������������������������������������\n");	//�˵�����
	printf("     ��             2 0 4 8              ��\n");
	printf("     ��           �� ɫ ѡ ��            ��\n");
	printf("     ��                                  ��\n");
	printf("     ����ɫ���� 0.��ɫ     1.��ɫ        ��\n");
	printf("     ��         2.��ɫ     3.����ɫ      ��\n");
	printf("     ��         4.��ɫ     5.��ɫ        ��\n");
	printf("     ��         6.��ɫ     7.��ɫ        ��\n");
	printf("     ��         8.��ɫ     9.����ɫ      ��\n");
	printf("     ��         10.����ɫ  11.ǳ��ɫ     ��\n");
	printf("     ��         12.����ɫ  13.����ɫ     ��\n");
	printf("     ��         14.����ɫ  15.����ɫ     ��\n");
	printf("     ��(ע�⣺������ɫ��������ɫ������ͬ)��\n");
	printf("     ��������������������������������������\n");
	printf("\n");
	printf("\n");
	printf("\n");
	while (c == 1)
	{
		printf("������ɫ:");
		cin >> a;
		while (a > 16 || a < 0)
		{
			printf("�������� ����������\n");
			printf("������ɫ:");
			cin >> a;
		}
		printf("\n");
		printf("������ɫ:");
		cin >> b;
		while (b > 16 || b < 0)
		{
			printf("�������� ����������\n");
			printf("������ɫ:");
			cin >> b;
		}
		if (a == b)
		{
			printf("������ɫ��������ɫ������ͬ\n");
			printf("����������\n");
			continue;
		}
		printf("\n");
		printf("\n");
		printf("ȷ��ѡ�� Y������ѡ��N");
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
			printf("�����д� ����������\n");
			c = 1;
		}

	}
}
void games_introduce()               //��Ϸ���ܽ���
{
	printf("��Ϸ���ܣ�\n");
	printf("��2048���ǱȽ����е�һ��������Ϸ��ԭ��2048������github�Ϸ�����\n");
	printf("ԭ������Gabriele Cirulli�����ǻ��ڡ�1024���͡�С3���桷���淨\n");
	printf("�������ɵ�����������Ϸ�����2048����ָ��ְ汾���߸���ƽ̨��\n");
	printf("2048����һ��������(4*4�������θ���)�н��еģ�һ��ʼ��Ŀ����\n");
	printf("Ϸ�����2�����֣�����Ϸ��ϵͳ����ֻ�����2��4��2�����ֵġ���\n");
	printf("2048����ʼ��ʼ�����Ҫͨ���ƶ����ֽ��кϲ����ﵽ2048������\n");
	printf("����Ϸ����ҽ������ƶ�һ�����������������Ե�����Ҳ��ͬ����\n");
	printf("����ͨ���������ƶ�����Ҫ�ϳ�2048�ģ�����2��2�ϳ�4��4��4�ϳ�\n");
	printf("8�Դ����ƣ�ֻ��ͬ��ֵ�����ֲ��ܺϳɡ�����ҳɹ��ϳ�2048��\n");
	printf("��Ϸ��˳��ͨ���ˣ�������������еĸ���ȫ�������������ڵĸ�\n");
	printf("�Ӷ�����ͬҲ�����޷��ƶ��Ļ�����ô���ź���gameover��\n");
	printf("\n");
	printf("\n");
	printf("�����������");
	_getch();
	system("cls");
	start();
}
void games_explain()                 //��Ϸ��������
{
	printf("����˵��\n");
	printf("�������������������ƶ�\n");
	printf("�������������������ƶ�\n");
	printf("�������������������ƶ�\n");
	printf("�������������������ƶ�\n");
	printf("�����������");
	_getch();
	system("cls");
	start();
}
int maxscore()//������Ϸ�����ֵ
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
int score()//������Ϸ����
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
void Newpane() //��ʾ����  
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
				cout << setw(3) << "��" << "       ";
			}
			else
			{
				cout << setw(3) << "��" << "       ";
			}
			if (j == 3)
			{
				cout << setw(3) << "��" << endl;
				cout << setw(55) << " ��________��________��________��________��" << endl;
			}
		}
	}
}
void num()//��ӡ��������
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
	cout << setw(20) << "���ֵ��" << maxscore() << endl;
	cout << setw(20) << "��߷֣�" << score() << setw(56) << "2048 by 326" << endl;
}
void rank2() //����
{
	ifstream OpenFile("1.txt");

	char ch;
	printf("			  2 0 4 8���а�\n\n");
	while (!OpenFile.eof())
	{
		OpenFile.get(ch);
		cout << ch;
	}
	OpenFile.close();
	printf("�����������");
	_getch();
	system("cls");
	start();
}
void rank1()//���а�
{
	int num = t;
	ifstream infile;
	ofstream outfile;
	sort(a, a + num, cmp);
	system("cls");
	printf("			  2 0 4 8���а�\n\n");
	outfile.open("1.txt");
	for (int i = 0; i<num; i++)
	{
		outfile << "		 " << i + 1 << ':' << "  " << a[i].name << "  " << a[i].score<<endl<<endl;
		cout << "		 " << i + 1 << ':' << "  " << a[i].name << "  " << a[i].score<<endl;
		cout << endl;
		if (i == 9)break;
	}
	outfile.close();
	printf("�����������");
	_getch();
	system("cls");
	start();

}
void Newgame() //��ʼ��Ϸ  
{
	for (int i = 0; i < 4; i++) //��ʼ������  
	{
		for (int j = 0; j < 4; j++)
		{
			pane[i][j] = 0;
		}
	}
	srand((unsigned)time(NULL));//���������������������
	int m = rand() % 4;
	int n = rand() % 4;
	int p = rand() % 4;
	int q = rand() % 4;
	pane[m][n] = pane[p][q] = 2;
	Newpane();
	num();
}
void add(int n)//�������
{
	int num = rand();												//���������
	int would = num % 2;											//ȡ����2�����������������
	int x, y, i;
	srand((unsigned int)time(0));									//srand������������������ĳ�ʼ������
	x = num % 4;													//ȡ����4������
	srand((unsigned int)time(0) + (unsigned int)num);				//srand()��������rand()���������ʱ����������ӣ��ı�α���������
	y = rand();
	y %= 4;															//y��4����
	if (would)														//�����Ϊ����
		num = 2;
	else															//�����Ϊż��
		num = 4;													//����õ� 2 �� 4	
	if (n == 0)
	{
		pane[x][y] = num;											//��Ϸ��ʼ �������2 �� 4
	}
	else if (n == 1)												//����ֻ�ڵ����ŷ���
	{
		if (pane[3][y] == 0)
			pane[3][y] = num;										//�������		
		else
			for (i = 0; i < 4; i++)									//˳�����
				if (pane[3][i] == 0)
				{
					pane[3][i] = num;
					break;
				}
	}
	else if (n == 2)												//����
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
	else if (n == 3)												//����
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
	else if (n == 4)												//����
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
	int i, k, t;												//��Ϸ������־
	for (k = 0; k < 4; k++)
	{
		int n = 4;
		while (n--)
		{
			for (i = 0; i < 3; i++)
			{
				if (pane[i][k] == 0)									//����Ϸ��п�λ
				{
					for (t = i; t < 3; t++)
					{
						pane[t][k] = pane[t + 1][k];					//����һ����
						pane[t + 1][k] = 0;							//ԭλ������
					}
				}
			}
		}
		for (i = 0; i < 3; i++)
		{
			if (pane[i][k] == pane[i + 1][k])							//�����������������ͬ
			{
				pane[i][k] *= 2;										//�ϲ�����
				pane[i + 1][k] = 0;
				for (t = i + 1; t < 3; t++)							//�ϲ����ݺ��ٴ��ж����޿�λ
				{
					pane[t][k] = pane[t + 1][k];						//���λ
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
	int i, k, t;													//��Ϸ������־
	for (k = 0; k < 4; k++)
	{
		int n = 4;
		while (n--)
		{
			for (i = 3; i >0; i--)
			{
				if (pane[i][k] == 0)									//����·��п�λ
				{
					for (t = i; t > 0; t--)
					{
						pane[t][k] = pane[t - 1][k];					//����һ����
						pane[t - 1][k] = 0;							//ԭλ������
					}
				}
			}
		}
		for (i = 3; i > 0; i--)
		{
			if (pane[i][k] == pane[i - 1][k])							//�����������������ͬ
			{
				pane[i][k] *= 2;										//�ϲ�����
				pane[i - 1][k] = 0;
				for (t = i - 1; t > 0; t--)							//�ϲ����ݺ��ٴ��ж����޿�λ
				{
					pane[t][k] = pane[t - 1][k];						//���λ
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
	int i, k, t;												//��Ϸ������־
	for (i = 0; i < 4; i++)
	{
		int n = 4;
		while (n--)
		{
			for (k = 0; k < 3; k++)
			{
				if (pane[i][k] == 0)									//������п�λ
				{
					for (t = k; t < 3; t++)
					{
						pane[i][t] = pane[i][t + 1];					//����һ����
						pane[i][t + 1] = 0;
					}
				}
			}
		}
		for (k = 0; k < 3; k++)
		{
			if (pane[i][k] == pane[i][k + 1])							//�����������������ͬ
			{
				pane[i][k] *= 2;										//�ϲ�����
				pane[i][k + 1] = 0;
				for (t = k + 1; t < 3; t++)							//�ϲ����ݺ��ٴ��ж����޿�λ
				{
					pane[i][t] = pane[i][t + 1];						//���λ
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
	int i, k, t;												//��Ϸ������־
	for (i = 0; i <4; i++)
	{
		int n = 4;
		while (n--)
		{
			for (k = 3; k > 0; k--)
			{
				if (pane[i][k] == 0)									//����ҷ��п�λ
				{
					for (t = k; t > 0; t--)
					{
						pane[i][t] = pane[i][t - 1];					//����һ����
						pane[i][t - 1] = 0;
					}
				}
			}
		}
		for (k = 3; k > 0; k--)
		{
			if (pane[i][k] == pane[i][k - 1])							//�����������������ͬ
			{
				pane[i][k] *= 2;										//�ϲ�����
				pane[i][k - 1] = 0;
				for (t = k - 1; t > 0; t--)							//�ϲ����ݺ��ٴ��ж����޿�λ
				{
					pane[i][t] = pane[i][t - 1];						//���λ
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
		for (k = 1; k < 4; k++)										//�ж������Ƿ�����ͬ
			if (pane[i][k - 1] == pane[i][k])
				return 0;
	}
	for (i = 0; i < 4; i++)											//�ж������Ƿ�����ͬ
	{
		for (k = 1; k < 4; k++)
			if (pane[k - 1][i] == pane[k][i])
				return 0;
	}
	for (i = 0; i < 4; i++)											//�ж��Ƿ����п�λ
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
int  game()//��Ϸ������������
{
	system("CLS");
	int flag = 1;
	Newgame();//��ʼ������
	while (1)//����Ϸ������ʱ����Ϸʼ��ѭ��
	{
		int ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			switch (ch)
			{
			case 72://����
			{
				if (move_up() == 1)
				{
					num();
					if (win() == 1)
					{
						printf("��ϲ�㣬���2048��\n");
						flag = 0;
					}
					else if (judge() == 1)
					{
						printf("��Ϸ������\n");
						flag = 0;
					}
				}
				break;
			}
			case 75://����
			{
				if (move_left() == 1)
				{
					num();
					if (win() == 1)
					{
						printf("��ϲ�㣬���2048��\n");
						flag = 0;
					}
					else if (judge() == 1)
					{
						printf("��Ϸ������\n");
						flag = 0;
					}
				}
				break;
			}
			case 77://����
			{
				if (move_right() == 1)
				{
					num();
					if (win() == 1)
					{
						printf("��ϲ�㣬���2048��\n");
						flag = 0;
					}
					else if (judge() == 1)
					{
						printf("��Ϸ������\n");
						flag = 0;
					}
					break;
				}
				break;
			}
			case 80://����
			{
				if (move_down() == 1)
				{
					num();
					if (win() == 1)
					{
						printf("��ϲ�㣬���2048��\n");
						flag = 0;
					}
					else if (judge() == 1)
					{
						printf("��Ϸ������\n");
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
	if (flag == 0)//����Ϸ����ʱ
	{
		char save;
		printf("�Ƿ񱣴��¼������1ȷ�ϱ����¼�������������������¼\n");
		cin >> save;
		if (save == '1')
		{
			string name1;
			int Score = score();
			printf("����������ǳ�\n");
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
	start();//��ʼ������
	string startchosen = "0";//��ʼ����Ϸѡ��
	while (startchosen == "0")
	{
		cin >> startchosen;
		if (startchosen =="1")//������Ϸ
		{
			system("cls");
			game();
			startchosen = "0";
		}
		else if (startchosen == "2")//������Ϸ����
		{
			system("cls");
			games_introduce();
			startchosen = "0";
		}
		else if (startchosen == "3")//������Ϸ˵��
		{
			system("cls");
			games_explain();
			startchosen = "0";
		}
		else if (startchosen == "4")//������Ϸ����ѡ��
		{
			system("cls");
			colorchosen();
			startchosen = "0";
		}
		else if (startchosen == "5")//������Ϸ������
		{
			system("cls");
			rank2();
			startchosen = "0";
		}
		else
		{
			printf("�������� ����������\n");
			printf("�����������\n");
			_getch();
			system("cls");
			startchosen = "0";
			start();
		}
	}

	printf("\n");
	printf("\n");
}