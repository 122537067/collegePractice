#pragma once
#define MAX_VERTEX_NUM 20   //��󶥵���
#define MAX_NAME_LEN 20    //�������Ƴ���
#define MAX_DESC_LEN 1024   //������������


typedef struct Path
{
	int vexs[MAX_VERTEX_NUM];     //����һ��·��
	Path *next;   //��һ��·��
}*PathList;


//������Ϣ
struct Vex
{
	int num;      //���
	char name[MAX_NAME_LEN];   //�������֣�
	char desc[MAX_DESC_LEN];   //������ܣ�
};

struct Edge
{
	int vex1;   //��һ������ı��
	int vex2;   //�ڶ�������ı��
	int weight;  //�ߵ�Ȩֵ
};
class CGraph
{
public:
	CGraph();
	~CGraph();
private:
	int m_aAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];    //�ڽӾ���
	Vex m_aVexs[MAX_VERTEX_NUM];             //��������
	int m_nVexNum;               //��ǰͼ�Ķ������
public:
	void setVex(Vex sVex);
	//��ʼ��ͼ
	void Init(void);
	//���붥��
	bool InsertVex(Vex sVex);
	//�����
	bool InsertEdge(Edge sEdge);
	//�õ��������
	int GetVexNum();
	//�õ�������Ϣ
	Vex GetVex(int nVex);
	//���ұߵ���Ϣ
	int FindEdge(int nVex, Edge aEdge[]);
	//������ȱ�����������ͼ
	void DFSTraverse(int nVex, PathList &pList);

private:       //�����������
	void DFS(int nVex, bool aVisited[], int &nIndex, PathList &pList);
public:    //�������·����Dijkstra�㷨��
	int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);    //���ղ�����nVexStart nVexEnd    �����Edge aPath���� �����������������ʾ���շ��ʵ�·�����׾����˼����ߡ����������˵Ķ���ͱߵ�Ȩֵ��
public:    //������С��������Prim�㷨
	void FindMinTree(Edge aPath[]);
};

