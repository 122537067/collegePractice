#include<iostream>
#include<cstring>
#include<cmath>
#include"Tourism.h"
using namespace std;

int main(void)
{
	CTourism tourism;

	bool bRunning = true; //程序运行标识
	char key[10] = { 0 }; //用户输入的选项

	while (bRunning)
	{
		cout << "====景区信息管理系统====" << endl;
		cout << "1.创建景区景点图" << endl;
		cout << "2.查询景点信息" << endl;
		cout << "3.旅游景点导航" << endl;
		cout << "4.搜索最短路劲" << endl;
		cout << "5.铺设电路规划" << endl;
		cout << "0.退出" << endl;      //输出界面

		//输入
		cout << "请输入操作编号(0~5)：";
		cin >> key;

		//判断用户输入
		switch (key[0])
		{
		case'1':
			tourism.CreateGraph();  //创建景区景点图
			break;
		case'2':
			tourism.GetSpotInfo(); //查询景点信息
			break;
		case'3':
			tourism.TravelPath(); //旅游景点导航
			break;
		case'4':
			tourism.FindShortPath();  //查询最短路径
			break;
		case'5':
			tourism.DesignPath(); //查询铺设电路规划图
			break;
		case'0':
			cout << "886" << endl;
			return 0;
		}
	}
}