#include "Tourism.h"
#include"Graph.h"
#include<iostream>
using namespace std;

#define VEX_FILE_NAME "Vex.txt"     //��¼������Ϣ���ļ�
#define EDGE_FILE_NAME "Edge.txt"   //��¼����Ϣ���ļ�

CTourism::CTourism()
{
}


CTourism::~CTourism()
{
}

//������������ͼ
void CTourism::CreateGraph()
{
	cout << "=====������������ͼ====" << endl;
	m_Graph.Init();  //��ʼ��ͼ

	//����ͼ�����
	FILE *pVex = fopen(VEX_FILE_NAME, "r");
	if (!pVex)
	{
		cout << "���ļ�ʧ��!" << endl;
		return;
	}

	//��ȡ������Ŀ
	int nSpotCount = 0;
	fscanf(pVex, "%d\n", &nSpotCount);
	cout << "������Ŀ��" << nSpotCount << endl;
	
	//��ȡ������Ϣ
	cout << "-----����-----" << endl;
	Vex sVex;
	while (fscanf(pVex, "%d\n%s\n%s\n", &sVex.num, sVex.name, sVex.desc) != -1)
	{
		cout << sVex.num << "-" << sVex.name << endl;  //��ʾ������Ϣ

		if (!m_Graph.InsertVex(sVex))   //��������
		{
			cout << "��������ʧ��" << endl;
			continue;
		}
	}
	fclose(pVex);  //�ر��ļ�
	pVex = NULL;

	//����ͼ�ı�
	FILE *pEdge = fopen(EDGE_FILE_NAME, "r");  //���ļ�
	if (!pEdge)
	{
		cout << "���ļ�ʧ��" << endl;
		return;
	}

	//��ȡ�ߵ���Ϣ
	cout << "----��----" << endl;
	Edge sEdge;
	while (fscanf(pEdge, "%d\t%d\t%d\n", &sEdge.vex1, &sEdge.vex2, &sEdge.weight)!=-1)
	{
		cout << "(v" << sEdge.vex1 << "��v" << sEdge.vex2 << ")" << sEdge.weight << endl;  //��ʾ��·��Ϣ
		if (!m_Graph.InsertEdge(sEdge))   //������
		{
			cout << "������ʧ��" << endl;
			continue;
		}
	}
	fclose(pEdge);//�ر��ļ�
	pEdge = NULL;  
}

//��ѯ������Ϣ
void CTourism::GetSpotInfo()
{
	cout << "====��ѯ������Ϣ====" << endl;
	int nVexNum = m_Graph.GetVexNum();  //��þ�����

	for (int i = 0; i < nVexNum; i++)
	{
		Vex sVex = m_Graph.GetVex(i);  //��ѯ������Ϣ
		cout << sVex.num << "-" << sVex.name << endl;
		//�г����о����ź�����
	}

	int nVex;
	cout << "��������Ҫ��ѯ�ľ�����;";
	cin >> nVex;
	if (nVex < 0 || nVex >= nVexNum)
	{
		cout << "��������\n";
		return;
	}

	Vex sVex = m_Graph.GetVex(nVex);//��ѯ������Ϣ
	cout << sVex.name << endl; //�����������
	cout << sVex.desc << endl;//������������Ϣ

	Edge aEdge[MAX_VERTEX_NUM];
	int nEdgeNum = m_Graph.FindEdge(nVex, aEdge);//��ѯ�ܱ߾�����Ϣ

	cout << "----�ܱ߾���-----" << endl;
	for (int i = 0; i < nEdgeNum; i++)
	{
		Vex v1 = m_Graph.GetVex(aEdge[i].vex1);
		Vex v2 = m_Graph.GetVex(aEdge[i].vex2);
		if (aEdge[i].weight != 0)
		{
			cout << v1.name << "->" << v2.name << "" << aEdge[i].weight << "m" << endl; //����ܱ߾��㼰����
		}
	}
}

void CTourism::TravelPath(void)
{
	cout << "====���ξ��㵼��====" << endl;
	//��þ�����
	int nVexNum = m_Graph.GetVexNum();

	//�г����о���ı�ź�����
	for (int i = 0; i < nVexNum; i++)
	{
		Vex sVex = m_Graph.GetVex(i);   //��ѯ������Ϣ
		cout << sVex.num << "-" << sVex.name << endl;
	}

	//���뾰����
	int nVex;
	cout << "��������ʼ���ţ�";
	cin >> nVex;
	if (nVex < 0 || nVex >= nVexNum)
	{
		cout << "�������\n";
		return;
	}

	//��ѯ��nVex���㿪ʼ������·��
	PathList pList = (PathList)malloc(sizeof(Path));    //�����������������·��
	PathList pHead = pList;   //��¼ͷָ��

							  //��ѯ���ε���·��
	m_Graph.DFSTraverse(nVex, pList);
	//�������·��
	cout << "����·��Ϊ��" << endl;
	int i = 1;

	pList = pHead;
	while (pList->next)
	{
		//���һ��·��
		Vex sVex = m_Graph.GetVex(pList->vexs[0]);
		cout << "·��" << i++ << "��" << sVex.name;   //������
		for (int j = 1; j < nVexNum; j++)
		{
			sVex = m_Graph.GetVex(pList->vexs[j]);   //�������N������
			cout << "->" << sVex.name;
		}
		cout << endl;

		//�ͷſռ�
		Path *temp = pList;
		pList = pList->next;
		free(temp);
	}

	//�ͷſռ�
	free(pList);
	pList = NULL;
	pHead = NULL;

}
void CTourism::FindShortPath(void)
{
	cout << "====�������·��====" << endl;
	//��þ�����
	int nVexNum = m_Graph.GetVexNum();

	//�г����о���ı�ź�����
	for (int i = 0; i < nVexNum; i++)
	{
		Vex sVex = m_Graph.GetVex(i);   //��ѯ������Ϣ
		cout << sVex.num << "-" << sVex.name << endl;
	}

	//���뾰���ţ���ʼ����յ㣩
	int nVexStart, nVexEnd;
	cout << "��������ʼ���ţ�";
	cin >> nVexStart;
	cout << "�������յ��ţ�";
	cin >> nVexEnd;

	if (nVexStart < 0 || nVexStart >= nVexNum || nVexEnd<0 || nVexEnd >= nVexNum)
	{
		cout << "�������\n";
		return;
	}
	Edge aPath[MAX_VERTEX_NUM];
	int nNum = m_Graph.FindShortPath(nVexStart, nVexEnd, aPath);
	Vex sVex;
	int nLength = 0;
	cout << "���·��Ϊ��";
	cout << m_Graph.GetVex(aPath[0].vex1).name;
	for (int i = 0; i < nNum; i++)
	{

		sVex = m_Graph.GetVex(aPath[i].vex2);
		cout << "->" << sVex.name;
		nLength += aPath[i].weight;
	}
	cout << endl;
	cout << "��̾���Ϊ��" << nLength << endl;
}

void CTourism::DesignPath(void)
{
	cout << "====�����·�滮====" << endl;
	Edge aPath[MAX_VERTEX_NUM];    //����߽ṹ���������������������·
	m_Graph.FindMinTree(aPath);    //�õ��滮����·
	int nVexNum = m_Graph.GetVexNum();
	if (nVexNum == 0)
	{
		cout << "���ȴ���ͼ��" << endl;
		return;
	}
	int nAllLength = 0;
	cout << "��������������֮�������·��" << endl;
	for (int i = 0; i < nVexNum - 1; i++)
	{
		Vex sVex1 = m_Graph.GetVex(aPath[i].vex1);
		Vex sVex2 = m_Graph.GetVex(aPath[i].vex2);

		//����������·
		cout << sVex1.name << " - " << sVex2.name << "  " << aPath[i].weight << "m" << endl;
		nAllLength += aPath[i].weight;
	}
	cout << "�����·���ܳ���Ϊ��" << nAllLength << endl;
}