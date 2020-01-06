#pragma once
#define MAX_VERTEX_NUM 20   //最大顶点数
#define MAX_NAME_LEN 20    //景点名称长度
#define MAX_DESC_LEN 1024   //景点描述长度


typedef struct Path
{
	int vexs[MAX_VERTEX_NUM];     //保存一条路径
	Path *next;   //下一条路径
}*PathList;


//顶点信息
struct Vex
{
	int num;      //编号
	char name[MAX_NAME_LEN];   //景点名字；
	char desc[MAX_DESC_LEN];   //景点介绍；
};

struct Edge
{
	int vex1;   //第一个顶点的编号
	int vex2;   //第二个顶点的编号
	int weight;  //边的权值
};
class CGraph
{
public:
	CGraph();
	~CGraph();
private:
	int m_aAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //邻接矩阵
	Vex m_aVexs[MAX_VERTEX_NUM];             //顶点数组
	int m_nVexNum;               //当前图的顶点个数
public:
	void setVex(Vex sVex);
	//初始化图
	void Init(void);
	//插入顶点
	bool InsertVex(Vex sVex);
	//插入边
	bool InsertEdge(Edge sEdge);
	//得到顶点个数
	int GetVexNum();
	//得到顶点信息
	Vex GetVex(int nVex);
	//查找边的信息
	int FindEdge(int nVex, Edge aEdge[]);
	//深度优先遍历景区景点图
	void DFSTraverse(int nVex, PathList &pList);

private:       //深度优先搜索
	void DFS(int nVex, bool aVisited[], int &nIndex, PathList &pList);
public:    //搜索最短路径（Dijkstra算法）
	int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);    //接收参数：nVexStart nVexEnd    输出：Edge aPath数组 是输出参数，用来表示最终访问的路径到底经过了几条边。（包括两端的顶点和边的权值）
public:    //构建最小生成树；Prim算法
	void FindMinTree(Edge aPath[]);
};

