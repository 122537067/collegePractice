#include<iostream>
#include"Graph.h"
#include "Tourism.h"
using namespace std;


//�ļ���
#define VEX_FILE_NAME "Vex.txt"  //��¼������Ϣ
#define EDGE_FILE_NAME "Edge.txt" //��¼����Ϣ

CTourism::CTourism(void)
{
}


CTourism::~CTourism(void)
{
}

void CTourism::CreateGraph(void)
{
	cout << "====������������ͼ" << endl;
	//1.��ʼ��ͼ
	m_Graph.Init();

	//2.����ͼ�Ķ���
	//���ļ�
	FILE *pVex = fopen(VEX_FILE_NAME, "r");
	if (!pVex)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}
	//��ȡ������Ŀ
	int nSpotCount = 0;
	fscanf(pVex, "%d\n", &nSpotCount);
	cout << "������Ŀ��" << endl;

	//��ȡ������Ϣ
	cout << "----����----" << endl;
	Vex sVex;
	while (fscanf(pVex, "%d\n%s\n%s\n", &sVex.num, sVex.name, sVex.desc) != -1)
	{
		//��ʾ������Ϣ
		cout << sVex.num << "-" << sVex.name << endl;

		//��������
		if (!m_Graph.InsertVex(sVex))
		{
			cout << "��������ʧ�ܣ�" << endl;
			continue;
		}
	}

	//�ر��ļ�
	fclose(pVex);
	pVex = NULL;

	//3.����ͼ�ı�
	//���ļ�
	FILE *pEdge = fopen(EDGE_FILE_NAME, "r");
	if (!pEdge)
	{
		cout << "���ļ�ʧ�ܣ�" << endl;
		return;
	}
	//��ȡ�ߵ���Ϣ
	cout << "----��----" << endl;
	Edge sEdge;
	while (fscanf(pEdge, "%d\t%d\t%d\n", &sEdge.vex1, &sEdge.vex2, &sEdge.weight) != -1)
	{
		//��ʾ��·��Ϣ
		cout << "(v" << sEdge.vex1 << ",v" << sEdge.vex2 << ") " << sEdge.weight << endl;

		//������
		if (!m_Graph.InsertEdge(sEdge))
		{
			cout << "������ʧ�ܣ�" << endl;
			continue;
		}
	}
	//�ر��ļ�
	fclose(pEdge);
	pEdge = NULL;
}

void CTourism::GetSpotInfo(void)
{
	cout << "====��ѯ������Ϣ====" << endl;
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
	cout << "��������Ҫ��ѯ�ľ����ţ�";
	cin >> nVex;
	if (nVex < 0 || nVex >= nVexNum)
	{
		cout << "�������\n";
		return;
	}

	//��ѯ������Ϣ
	Vex sVex = m_Graph.GetVex(nVex);
	cout << sVex.name << endl;  //�����������
	cout << sVex.desc << endl;  //������������Ϣ

								//��ѯ�ܱ߾�����Ϣ
	Edge aEdge[MAX_VERTEX_NUM];
	int nEdgeNum = m_Graph.FindEdge(nVex, aEdge);

	cout << "---- �ܱ߾��� ----" << endl;
	for (int i = 0; i < nEdgeNum; i++)
	{
		Vex v1 = m_Graph.GetVex(aEdge[i].vex1);
		Vex v2 = m_Graph.GetVex(aEdge[i].vex2);
		//����ܱ߾��㼰����
		cout << v1.name << "->" << v2.name << " " << aEdge[i].weight << "m" << endl;
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