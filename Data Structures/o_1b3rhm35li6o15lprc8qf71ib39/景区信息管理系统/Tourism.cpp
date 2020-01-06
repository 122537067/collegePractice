#include<iostream>
#include"Graph.h"
#include "Tourism.h"
using namespace std;


//文件名
#define VEX_FILE_NAME "Vex.txt"  //记录顶点信息
#define EDGE_FILE_NAME "Edge.txt" //记录边信息

CTourism::CTourism(void)
{
}


CTourism::~CTourism(void)
{
}

void CTourism::CreateGraph(void)
{
	cout << "====创建景区景点图" << endl;
	//1.初始化图
	m_Graph.Init();

	//2.设置图的顶点
	//打开文件
	FILE *pVex = fopen(VEX_FILE_NAME, "r");
	if (!pVex)
	{
		cout << "打开文件失败！" << endl;
		return;
	}
	//读取景点数目
	int nSpotCount = 0;
	fscanf(pVex, "%d\n", &nSpotCount);
	cout << "顶点数目：" << endl;

	//读取顶点信息
	cout << "----顶点----" << endl;
	Vex sVex;
	while (fscanf(pVex, "%d\n%s\n%s\n", &sVex.num, sVex.name, sVex.desc) != -1)
	{
		//显示顶点信息
		cout << sVex.num << "-" << sVex.name << endl;

		//新增顶点
		if (!m_Graph.InsertVex(sVex))
		{
			cout << "新增顶点失败！" << endl;
			continue;
		}
	}

	//关闭文件
	fclose(pVex);
	pVex = NULL;

	//3.设置图的边
	//打开文件
	FILE *pEdge = fopen(EDGE_FILE_NAME, "r");
	if (!pEdge)
	{
		cout << "打开文件失败！" << endl;
		return;
	}
	//读取边的信息
	cout << "----边----" << endl;
	Edge sEdge;
	while (fscanf(pEdge, "%d\t%d\t%d\n", &sEdge.vex1, &sEdge.vex2, &sEdge.weight) != -1)
	{
		//显示道路信息
		cout << "(v" << sEdge.vex1 << ",v" << sEdge.vex2 << ") " << sEdge.weight << endl;

		//新增边
		if (!m_Graph.InsertEdge(sEdge))
		{
			cout << "新增边失败！" << endl;
			continue;
		}
	}
	//关闭文件
	fclose(pEdge);
	pEdge = NULL;
}

void CTourism::GetSpotInfo(void)
{
	cout << "====查询景点信息====" << endl;
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
	cout << "请输入想要查询的景点编号：";
	cin >> nVex;
	if (nVex < 0 || nVex >= nVexNum)
	{
		cout << "输入错误！\n";
		return;
	}

	//查询景点信息
	Vex sVex = m_Graph.GetVex(nVex);
	cout << sVex.name << endl;  //输出景点名字
	cout << sVex.desc << endl;  //输出景点介绍信息

								//查询周边景点信息
	Edge aEdge[MAX_VERTEX_NUM];
	int nEdgeNum = m_Graph.FindEdge(nVex, aEdge);

	cout << "---- 周边景区 ----" << endl;
	for (int i = 0; i < nEdgeNum; i++)
	{
		Vex v1 = m_Graph.GetVex(aEdge[i].vex1);
		Vex v2 = m_Graph.GetVex(aEdge[i].vex2);
		//输出周边景点及距离
		cout << v1.name << "->" << v2.name << " " << aEdge[i].weight << "m" << endl;
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