#include<iostream>
#include<cstring>
#include<cmath>
#include"Tourism.h"
using namespace std;

int main(void)
{
	CTourism tourism;
	bool bRunning = true;
	char key[10] = { 0 };
	while (bRunning)
	{
		//输出界面
		cout << "====景区信息管理系统====" << endl;
		cout << "1.创建景区景点图" << endl;
		cout << "2.查询景点信息" << endl;
		cout << "3.旅游景点导航" << endl;
		cout << "4.搜索最短路径" << endl;
		cout << "5.铺设电路规划" << endl;
		cout << "0.退出" << endl;
		//输入选项
		cout << "请输入操作编号（0-5）" << endl;
		cin >> key;
		//处理用户输入
		switch (key[0])
		{
		case '1': //创建景区景点图
			tourism.CreateGraph();
			break;
		case'2':  //查询景点信息
			tourism.GetSpotInfo();
			break;
		case'3':   //旅游景点导航
			tourism.TravelPath();
			break;
		case'4':
			tourism.FindShortPath();
			break;
		case'5':
			
			break;
		case'0'://退出；
			bRunning = false;
			cout << "导航结束，谢谢使用" << endl;
			break;
		}
	}
}