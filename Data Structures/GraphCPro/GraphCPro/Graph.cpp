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
	//��ʼ��ͼ�Ķ������
	m_nVexNum = 0; //Ȩֵ��Ϣ��ʼ��Ϊ0����ʶ���еĶ���֮�䶼�����ڱ�
	for(int i=0;i<MAX_VERTEX_NUM;i++) //��ʼ���ڽӾ���
	{
		for (int j = 0; j < MAX_VERTEX_NUM; j++)
		{
			m_aAdjMatrix[i][j] = 0;  //��ʼ�������ľ���Ϊ0����ʶ�������㲻����
		}
	}
}

//���붥��
bool CGraph::InsertVex(Vex sVex)
{
	if (m_nVexNum == MAX_VERTEX_NUM)
	{
		return false;    //��������
	} 
	m_aVexs[m_nVexNum++] = sVex;  //���붥����Ϣ
	return true;
}

//�����
bool CGraph::InsertEdge(Edge sEdge)
{
	if (sEdge.vex1 < 0 || sEdge.vex1 >= m_nVexNum || sEdge.vex2 < 0 || sEdge.vex2 >= m_nVexNum)
	{
		return false;  //�±�Խ��
	}
	m_aAdjMatrix[sEdge.vex1][sEdge.vex2] = sEdge.weight;
	m_aAdjMatrix[sEdge.vex2][sEdge.vex1] = sEdge.weight;  //����ߵ���Ϣ
	return true;
}

int CGraph::GetVexNum()     //�õ��������
{
	return m_nVexNum;
}

Vex CGraph::GetVex(int v)    //�õ�������Ϣ
{
	return m_aVexs[v];
}

int CGraph::FindEdge(int nVex, Edge aEdge[])    //���ұߵ���Ϣ
{
	int k = 0;
	for (int i = 0; i < m_nVexNum; i++)
	{
		aEdge[i].vex1 = nVex;
		aEdge[i].vex2 = i;
		aEdge[i].weight = m_aAdjMatrix[nVex][i];
		k++;
	}
	return k;  //���رߵ�����
}

void CGraph::DFSTraverse(int nVex, PathList &pList)
{
	bool aVisted[MAX_VERTEX_NUM] = { false };//��¼�����Ƿ񱻷��ʹ�
	int nIndex = 0;//��¼��ǰ·�����
	DFS(nVex, aVisted, nIndex, pList);//�ݹ����DFS������������ȱ���ͼ����¼����·��
}

void CGraph::DFS(int nVex, bool aVisited[], int &nIndex, PathList &pList)
{
	aVisited[nVex] = true;    //��Ϊ�Ѿ�����
	pList->vexs[nIndex++] = nVex;    //���ʶ���

									 //�ж��Ƿ����ж��㶼�Ѿ������ʹ�
	int nVexNum = 0;
	for (int i = 0; i < m_nVexNum; i++)
	{
		if (aVisited[i])	nVexNum++;
	}

	//���ж��㶼�����ʹ�

	if (nVexNum == m_nVexNum)
	{
		//��������ڵ㣬���汾�α�����·��
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
		//������洢��˳�򣬲��ҵ�ǰ���������Ķ���
		for (int i = 0; i < m_nVexNum; i++)
		{
			//��û�б������������뵱ǰ���������Ķ���
			if ((!aVisited[i]) && (m_aAdjMatrix[nVex][i]>0))
			{
				//�Ըö���Ϊ��ʼ�������ʣ�µĶ���
				DFS(i, aVisited, nIndex, pList);
				aVisited[i] = false;//����״̬�ÿ�
				nIndex--;  //���ݣ�
			}
		}
	}
}

int CGraph::FindShortPath(int nVexStart, int nVexEnd, Edge aPath[])
{
	int nShortPath[MAX_VERTEX_NUM][MAX_VERTEX_NUM];   //�������·��
	int nShortDistance[MAX_VERTEX_NUM];              //������̾���
	bool aVisited[MAX_VERTEX_NUM];                    //�ж�ĳ�����Ƿ��Ѽ��뵽���·��
	int v;

	//��ʼ��
	for (v = 0; v < m_nVexNum; v++)
	{
		aVisited[v] = false;
		if (m_aAdjMatrix[nVexStart][v])
		{
			//��ʼ���ö��㵽�����������̾��룬Ĭ��Ϊ�������ľ���
			nShortDistance[v] = m_aAdjMatrix[nVexStart][v];
		}
		else
		{
			//�������v��nVexStart������������̾�����Ϊ���ֵ
			nShortDistance[v] = 0x7FFFFFFF;
		}
		nShortPath[v][0] = nVexStart;  //��ʼ��ΪnVexStart
		for (int w = 1; w < m_nVexNum; w++)
		{
			nShortPath[v][w] = -1;   //��ʼ�����·��
		}
	}

	//��ʼ����nVexStart������뵽������
	aVisited[nVexStart] = true;
	int min;
	for (int i = 1; i < m_nVexNum; i++)
	{
		min = 0x7FFFFFFF;
		bool bAdd = false;   //�ж��Ƿ��ж�����Լ��뵽����
		for (int w = 0; w < m_nVexNum; ++w)
		{
			if (!aVisited[w])
			{
				if (nShortDistance[w] < min)    //nShortDistance[w]=D[w]
				{
					v = w;   //w������nVexStart�������
					min = nShortDistance[w];    //w��nVexStart����̾���Ϊmin
					bAdd = true;
				}
			}
		}
		//���û�ж�����Լ��뵽���ϣ�������ѭ��
		if (!bAdd)
		{
			break;
		}
		aVisited[v] = true;    //��w������뵽����
		nShortPath[v][i] = v;   //������w���浽nVexStart��w�����·����
		for (int w = 0; w < m_nVexNum; ++w)
		{
			//��w��Ϊ���ɵ����nVexStartͨ��w��ÿ������ľ���
			if (!aVisited[w] && (min + m_aAdjMatrix[v][w]<nShortDistance[w]) && m_aAdjMatrix[v][w] != NULL)
			{
				nShortDistance[w] = min + m_aAdjMatrix[v][w];
				for (int i = 0; i < m_nVexNum; ++i)
				{
					//���ͨ��W���ﶥ��i�ľ���Ƚ϶̣���w�����·�����Ƹ�i��
					nShortPath[w][i] = nShortPath[v][i];
				}
			}


		}
	}
	int nIndex = 0;
	int nVex1 = nVexStart;
	//�����·������Ϊ�ߵĽṹ������
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
	bool aVisited[MAX_VERTEX_NUM];     //�ж�ĳ�����Ƿ�����С����������ļ�����
	for (int i = 0; i < MAX_VERTEX_NUM; i++)
	{
		aVisited[i] = false;    //��ʼ������
	}
	aVisited[0] = true;   //0������뵽������
	int min;
	int nVex1, nVex2;
	for (int k = 0; k < m_nVexNum; k++)   //�����ҳ�m_nVexNum�������еĶ��㵽���ڶ������̵ı߲���¼����
	{
		min = 0x7FFFFFFF;
		for (int i = 0; i < m_nVexNum; i++)
		{
			if (aVisited[i])     //�Ӽ�����ȡһ������
			{
				for (int j = 0; j < m_nVexNum; j++)
				{
					if (!aVisited[j])     //�Ӳ��ڼ��ϵĶ�����ȡ��һ������
					{
						if ((m_aAdjMatrix[i][j] < min) && (m_aAdjMatrix[i][j] != NULL))
						{
							nVex1 = i;
							nVex2 = j;
							min = m_aAdjMatrix[i][j];    //��¼��̵ı�
						}
					}
				}

			}
		}
		//������̱߶��㣻
		aPath[k].vex1 = nVex1;
		aPath[k].vex2 = nVex2;
		aPath[k].weight = m_aAdjMatrix[nVex1][nVex2];
		//������������뵽������
		aVisited[nVex1] = true;
		aVisited[nVex2] = true;
	}
}





