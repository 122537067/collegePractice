#include "Graph.h"
#include<iostream>


CGraph::CGraph()
{
}


CGraph::~CGraph()
{
}

void CGraph::setVex(Vex sVex)
{
	m_aVexs[m_nVexNum].num = sVex.num;
	strcpy(m_aVexs[m_nVexNum].name, sVex.name);
	strcpy(m_aVexs[m_nVexNum].desc, sVex.desc);
}

void CGraph::Init(void)
{
	//初始化图的顶点个数
	m_nVexNum = 0; //权值信息初始化为0，标识所有的顶点之间都不存在边
	for(int i=0;i<MAX_VERTEX_NUM;i++) //初始化邻接矩阵
	{
		for (int j = 0; j < MAX_VERTEX_NUM; j++)
		{
			m_aAdjMatrix[i][j] = 0;  //初始化顶点间的距离为0，标识两个顶点不相连
		}
	}
}

//插入顶点
bool CGraph::InsertVex(Vex sVex)
{
	if (m_nVexNum == MAX_VERTEX_NUM)
	{
		return false;    //顶点已满
	} 
	m_aVexs[m_nVexNum++] = sVex;  //插入顶点信息
	return true;
}

//插入边
bool CGraph::InsertEdge(Edge sEdge)
{
	if (sEdge.vex1 < 0 || sEdge.vex1 >= m_nVexNum || sEdge.vex2 < 0 || sEdge.vex2 >= m_nVexNum)
	{
		return false;  //下标越界
	}
	m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;  //插入边的信息
	return true;
}

int CGraph::GetVexNum()     //得到顶点个数
{
	return m_nVexNum;
}

Vex CGraph::GetVex(int v)    //得到顶点信息
{
	return m_aVexs[v];
}

int CGraph::FindEdge(int nVex, Edge aEdge[])    //查找边的信息
{
	int k = 0;
	for (int i = 0; i < m_nVexNum; i++)
	{
		aEdge[i].vex1 = nVex;
		aEdge[i].vex2 = i;
		aEdge[i].weight = m_aAdjMatrix[nVex][i];
		k++;
	}
	return k;  //返回边的条数
}

void CGraph::DFSTraverse(int nVex, PathList &pList)
{
	bool aVisted[MAX_VERTEX_NUM] = { false };//记录顶点是否被访问过
	int nIndex = 0;//记录当前路径深度
	DFS(nVex, aVisted, nIndex, pList);//递归调用DFS函数，深度优先遍历图，记录所有路径
}

void CGraph::DFS(int nVex, bool aVisited[], int &nIndex, PathList &pList)
{
	aVisited[nVex] = true;    //改为已经访问
	pList->vexs[nIndex++] = nVex;    //访问顶点

									 //判断是否所有顶点都已经被访问过
	int nVexNum = 0;
	for (int i = 0; i < m_nVexNum; i++)
	{
		if (aVisited[i])	nVexNum++;
	}

	//所有顶点都被访问过

	if (nVexNum == m_nVexNum)
	{
		//新增链表节点，保存本次遍历的路径
		pList->next = (PathList)malloc(sizeof(Path));
		for (int i = 0; i < m_nVexNum; i++)
		{
			pList->next->vexs[i] = pList->vexs[i];
		}
		pList = pList->next;
		pList->next = NULL;
	}
	else
	{
		//按顶点存储的顺序，查找当前顶点相连的顶点
		for (int i = 0; i < m_nVexNum; i++)
		{
			//既没有被遍历过，又与当前顶点相连的顶点
			if ((!aVisited[i]) && (m_aAdjMatrix[nVex][i]>0))
			{
				//以该顶点为起始顶点遍历剩下的顶点
				DFS(i, aVisited, nIndex, pList);
				aVisited[i] = false;//访问状态置空
				nIndex--;  //回溯；
			}
		}
	}
}

int CGraph::FindShortPath(int nVexStart, int nVexEnd, Edge aPath[])
{
	int nShortPath[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   //保存最短路径
	int nShortDistance[MAX_VERTEX_NUM];              //保存最短距离
	bool aVisited[MAX_VERTEX_NUM];                    //判断某顶点是否已加入到最短路径
	int v;

	//初始化
	for (v = 0; v < m_nVexNum; v++)
	{
		aVisited[v] = false;
		if (m_aAdjMatrix[nVexStart][v])
		{
			//初始化该顶点到其他顶点的最短距离，默认为两顶点间的距离
			nShortDistance[v] = m_aAdjMatrix[nVexStart][v];
		}
		else
		{
			//如果顶点v和nVexStart不相连，则最短距离设为最大值
			nShortDistance[v] = 0x7FFFFFFF;
		}
		nShortPath[v][0] = nVexStart;  //起始点为nVexStart
		for (int w = 1; w < m_nVexNum; w++)
		{
			nShortPath[v][w] = -1;   //初始化最短路径
		}
	}

	//初始化，nVexStart顶点加入到集合中
	aVisited[nVexStart] = true;
	int min;
	for (int i = 1; i < m_nVexNum; i++)
	{
		min = 0x7FFFFFFF;
		bool bAdd = false;   //判断是否还有顶点可以加入到集合
		for (int w = 0; w < m_nVexNum; ++w)
		{
			if (!aVisited[w])
			{
				if (nShortDistance[w] < min)    //nShortDistance[w]=D[w]
				{
					v = w;   //w顶点离nVexStart顶点最近
					min = nShortDistance[w];    //w到nVexStart的最短距离为min
					bAdd = true;
				}
			}
		}
		//如果没有顶点可以加入到集合，则跳出循环
		if (!bAdd)
		{
			break;
		}
		aVisited[v] = true;    //将w顶点加入到集合
		nShortPath[v][i] = v;   //将顶点w保存到nVexStart到w的最短路径里
		for (int w = 0; w < m_nVexNum; ++w)
		{
			//将w作为过渡点计算nVexStart通过w到每个顶点的距离
			if (!aVisited[w] && (min + m_aAdjMatrix[v][w]<nShortDistance[w]) && m_aAdjMatrix[v][w] != NULL)
			{
				nShortDistance[w] = min + m_aAdjMatrix[v][w];
				for (int i = 0; i < m_nVexNum; ++i)
				{
					//如果通过W到达顶点i的距离比较短，则将w的最短路径复制给i；
					nShortPath[w][i] = nShortPath[v][i];
				}
			}


		}
	}
	int nIndex = 0;
	int nVex1 = nVexStart;
	//将最短路径保存为边的结构体数组
	for (int i = 1; i < m_nVexNum; i++)
	{
		if (nShortPath[nVexEnd][i] != -1)
		{
			aPath[nIndex].vex1 = nVex1;
			aPath[nIndex].vex2 = nShortPath[nVexEnd][i];
			aPath[nIndex].weight = m_aAdjMatrix[aPath[nIndex].vex1][aPath[nIndex].vex2];
			nVex1 = nShortPath[nVexEnd][i];
			nIndex++;
		}
	}
	return nIndex;
}

void CGraph::FindMinTree(Edge aPath[])
{
	bool aVisited[MAX_VERTEX_NUM];     //判断某顶点是否在最小生成树顶点的集合里
	for (int i = 0; i < MAX_VERTEX_NUM; i++)
	{
		aVisited[i] = false;    //初始化集合
	}
	aVisited[0] = true;   //0顶点加入到集合中
	int min;
	int nVex1, nVex2;
	for (int k = 0; k < m_nVexNum; k++)   //依次找出m_nVexNum条集合中的顶点到相邻顶点的最短的边并记录下来
	{
		min = 0x7FFFFFFF;
		for (int i = 0; i < m_nVexNum; i++)
		{
			if (aVisited[i])     //从集合中取一个顶点
			{
				for (int j = 0; j < m_nVexNum; j++)
				{
					if (!aVisited[j])     //从不在集合的顶点中取出一个顶点
					{
						if ((m_aAdjMatrix[i][j] < min) && (m_aAdjMatrix[i][j] != NULL))
						{
							nVex1 = i;
							nVex2 = j;
							min = m_aAdjMatrix[i][j];    //记录最短的边
						}
					}
				}

			}
		}
		//保存最短边顶点；
		aPath[k].vex1 = nVex1;
		aPath[k].vex2 = nVex2;
		aPath[k].weight = m_aAdjMatrix[nVex1][nVex2];
		//将两个顶点加入到集合里
		aVisited[nVex1] = true;
		aVisited[nVex2] = true;
	}
}





