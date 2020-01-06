#pragma once

#define MAX_VERTEX_NUM 20   //��󶥵���
#define MAX_NAME_LEN 20    //�������Ƴ���
#define MAX_DESC_LEN 1024  //������������

struct Vex    //������Ϣ
{
	int num;				  //������
	char name[MAX_NAME_LEN];  //��������
	char desc[MAX_DESC_LEN];  //�������
};

struct Edge
{
	int vex1;  //��һ������ı��
	int vex2;  //�ڶ�������ı��
	int weight;//�ߵ�Ȩֵ
};

typedef struct Path
{
	int vexs[MAX_VERTEX_NUM];     //����һ��·��
	Path *next;   //��һ��·��
}*PathList;

class CGraph
{
public:
	CGraph();
	~CGraph();

private:
	Vex m_aVexs[MAX_VERTEX_NUM];  //��������
	int m_aAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //�ڽӾ���
	int m_nVexNum; //��ǰͼ�Ķ�����
	void DFS(int nVex, bool aVisited[], int &nIndex, PathList &pList);  //�����������

public:
	void Init(void);  //��ʼ��ͼ
	bool InsertVex(Vex sVex);  //���붥��
	bool InsertEdge(Edge sEdge); //�����
	int GetVexNum();    //�õ��������
	Vex GetVex(int nVex);   //�õ�������Ϣ
	int FindEdge(int nVex, Edge aEdge[]);  //���ұߵ���Ϣ			
	void setVex(Vex sVex);  //����
	void DFSTraverse(int nVex, PathList &pList); //������ȱ�����������ͼ
	//���ղ�����nVexStart nVexEnd�����Edge aPath���� �����������������ʾ���շ��ʵ�·�����׾����˼����ߡ����������˵Ķ���ͱߵ�Ȩֵ��
	int FindShortPath(int nVexStart, int nVexEnd, Edge aPath[]);    
	void FindMinTree(Edge aPath[]);//������С��������Prim�㷨
};

