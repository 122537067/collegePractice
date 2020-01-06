#pragma once

#define MAX_VERTEX_NUM 20   //最大顶点数
#define MAX_NAME_LEN 20    //景点名称长度
#define MAX_DESC_LEN 1024  //景点描述长度

struct Vex    //顶点信息
{
	int num;				  //景点编号
	char name[MAX_NAME_LEN];  //景点名称
	char desc[MAX_DESC_LEN];  //景点介绍
};

struct Edge
{
	int vex1;  //第一个顶点的编号
	int vex2;  //第二个顶点的编号
	int weight;//边的权值
};

typedef struct Path
{
	int vexs[MAX_VERTEX_NUM];     //保存一条路径
	Path *next;   //下一条路径
}*PathList;

class CGraph
{
public:
	CGraph();
	~CGraph();

private:
	Vex m_aVexs[MAX_VERTEX_NUM];  //顶点数组
	int m_aAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接矩阵
	int m_nVexNum; //当前图的顶点数
	void DFS(int nVex, bool aVisited[], int &nIndex, PathList &pList);  //深度优先搜索

public:
	void Init(void);  //初始化图
	bool InsertVex(Vex sVex);  //插入顶点
	bool InsertEdge(Edge sEdge); //插入边
	int GetVexNum();    //得到顶点个数
	Vex GetVex(int nVex);   //得到顶点信息
	int FindEdge(int nVex, Edge aEdge[]);  //查找边的信息			
	void setVex(Vex sVex);  //析构
	void DFSTraverse(int nVex, PathList &pList); //深度优先遍历景区景点图
	//接收参数：nVexStart nVexEnd输出：Edge aPath数组 是输出参数，用来表示最终访问的路径到底经过了几条边。（包括两端的顶点和边的权值）
	int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);    
	void FindMinTree(Edge aPath[]);//构建最小生成树；Prim算法
};

