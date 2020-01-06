#include "Tourism.h"
#include"Graph.h"
#include<iostream>
using namespace std;

#define VEX_FILE_NAME "Vex.txt"     //记录顶点信息的文件
#define EDGE_FILE_NAME "Edge.txt"   //记录边信息的文件

CTourism::CTourism()
{
}


CTourism::~CTourism()
{
}

//创建景区景点图
void CTourism::CreateGraph()
{
	cout << "=====创建景区景点图====" << endl;
	m_Graph.Init();  //初始化图

	//设置图的起点
	FILE *pVex = fopen(VEX_FILE_NAME, "r");
	if (!pVex)
	{
		cout << "打开文件失败!" << endl;
		return;
	}

	//读取景点数目
	int nSpotCount = 0;
	fscanf(pVex, "%d\n", &nSpotCount);
	cout << "顶点数目：" << nSpotCount << endl;
	
	//读取顶点信息
	cout << "-----顶点-----" << endl;
	Vex sVex;
	while (fscanf(pVex, "%d\n%s\n%s\n", &sVex.num, sVex.name, sVex.desc) != -1)
	{
		cout << sVex.num << "-" << sVex.name << endl;  //显示顶点信息

		if (!m_Graph.InsertVex(sVex))   //新增顶点
		{
			cout << "新增顶点失败" << endl;
			continue;
		}
	}
	fclose(pVex);  //关闭文件
	pVex = NULL;

	//设置图的边
	FILE *pEdge = fopen(EDGE_FILE_NAME, "r");  //打开文件
	if (!pEdge)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	//读取边的信息
	cout << "----边----" << endl;
	Edge sEdge;
	while (fscanf(pEdge, "%d\t%d\t%d\n", &sEdge.vex1, &sEdge.vex2, &sEdge.weight)!=-1)
	{
		cout << "(v" << sEdge.vex1 << "，v" << sEdge.vex2 << ")" << sEdge.weight << endl;  //显示道路信息
		if (!m_Graph.InsertEdge(sEdge))   //新增边
		{
			cout << "新增边失败" << endl;
			continue;
		}
	}
	fclose(pEdge);//关闭文件
	pEdge = NULL;  
}

//查询景点信息
void CTourism::GetSpotInfo()
{
	cout << "====查询景点信息====" << endl;
	int nVexNum = m_Graph.GetVexNum();  //获得景点数

	for (int i = 0; i < nVexNum; i++)
	{
		Vex sVex = m_Graph.GetVex(i);  //查询景点信息
		cout << sVex.num << "-" << sVex.name << endl;
		//列出所有景点编号和名称
	}

	int nVex;
	cout << "请输入想要查询的景点编号;";
	cin >> nVex;
	if (nVex < 0 || nVex >= nVexNum)
	{
		cout << "输入有误\n";
		return;
	}

	Vex sVex = m_Graph.GetVex(nVex);//查询景点信息
	cout << sVex.name << endl; //输出景点名字
	cout << sVex.desc << endl;//输出景点介绍信息

	Edge aEdge[MAX_VERTEX_NUM];
	int nEdgeNum = m_Graph.FindEdge(nVex, aEdge);//查询周边景点信息

	cout << "----周边景区-----" << endl;
	for (int i = 0; i < nEdgeNum; i++)
	{
		Vex v1 = m_Graph.GetVex(aEdge[i].vex1);
		Vex v2 = m_Graph.GetVex(aEdge[i].vex2);
		if (aEdge[i].weight != 0)
		{
			cout << v1.name << "->" << v2.name << "" << aEdge[i].weight << "m" << endl; //输出周边景点及距离
		}
	}
}

void CTourism::TravelPath(void)
{
	cout << "====旅游景点导航====" << endl;
	//获得景点数
	int nVexNum = m_Graph.GetVexNum();

	//列出所有景点的编号和名称
	for (int i = 0; i < nVexNum; i++)
	{
		Vex sVex = m_Graph.GetVex(i);   //查询景点信息
		cout << sVex.num << "-" << sVex.name << endl;
	}

	//输入景点编号
	int nVex;
	cout << "请输入起始点编号：";
	cin >> nVex;
	if (nVex < 0 || nVex >= nVexNum)
	{
		cout << "输入错误！\n";
		return;
	}

	//查询从nVex顶点开始的旅游路线
	PathList pList = (PathList)malloc(sizeof(Path));    //创建链表保存多条旅游路线
	PathList pHead = pList;   //记录头指针

							  //查询旅游导航路线
	m_Graph.DFSTraverse(nVex, pList);
	//输出旅游路线
	cout << "旅游路线为：" << endl;
	int i = 1;

	pList = pHead;
	while (pList->next)
	{
		//输出一个路线
		Vex sVex = m_Graph.GetVex(pList->vexs[0]);
		cout << "路线" << i++ << "：" << sVex.name;   //输出起点
		for (int j = 1; j < nVexNum; j++)
		{
			sVex = m_Graph.GetVex(pList->vexs[j]);   //输出后面N个顶点
			cout << "->" << sVex.name;
		}
		cout << endl;

		//释放空间
		Path *temp = pList;
		pList = pList->next;
		free(temp);
	}

	//释放空间
	free(pList);
	pList = NULL;
	pHead = NULL;

}
void CTourism::FindShortPath(void)
{
	cout << "====搜索最短路径====" << endl;
	//获得景点数
	int nVexNum = m_Graph.GetVexNum();

	//列出所有景点的编号和名称
	for (int i = 0; i < nVexNum; i++)
	{
		Vex sVex = m_Graph.GetVex(i);   //查询景点信息
		cout << sVex.num << "-" << sVex.name << endl;
	}

	//输入景点编号（起始点和终点）
	int nVexStart, nVexEnd;
	cout << "请输入起始点编号：";
	cin >> nVexStart;
	cout << "请输入终点编号：";
	cin >> nVexEnd;

	if (nVexStart < 0 || nVexStart >= nVexNum || nVexEnd<0 || nVexEnd >= nVexNum)
	{
		cout << "输入错误！\n";
		return;
	}
	Edge aPath[MAX_VERTEX_NUM];
	int nNum = m_Graph.FindShortPath(nVexStart, nVexEnd, aPath);
	Vex sVex;
	int nLength = 0;
	cout << "最短路线为：";
	cout << m_Graph.GetVex(aPath[0].vex1).name;
	for (int i = 0; i < nNum; i++)
	{

		sVex = m_Graph.GetVex(aPath[i].vex2);
		cout << "->" << sVex.name;
		nLength += aPath[i].weight;
	}
	cout << endl;
	cout << "最短距离为：" << nLength << endl;
}

void CTourism::DesignPath(void)
{
	cout << "====铺设电路规划====" << endl;
	Edge aPath[MAX_VERTEX_NUM];    //定义边结构体数组用来保存铺设的线路
	m_Graph.FindMinTree(aPath);    //得到规划的线路
	int nVexNum = m_Graph.GetVexNum();
	if (nVexNum == 0)
	{
		cout << "请先创建图！" << endl;
		return;
	}
	int nAllLength = 0;
	cout << "在以下两个景点之间铺设电路：" << endl;
	for (int i = 0; i < nVexNum - 1; i++)
	{
		Vex sVex1 = m_Graph.GetVex(aPath[i].vex1);
		Vex sVex2 = m_Graph.GetVex(aPath[i].vex2);

		//输出铺设的线路
		cout << sVex1.name << " - " << sVex2.name << "  " << aPath[i].weight << "m" << endl;
		nAllLength += aPath[i].weight;
	}
	cout << "铺设电路的总长度为：" << nAllLength << endl;
}