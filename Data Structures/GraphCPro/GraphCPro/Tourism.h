#pragma once
#include"Graph.h"
//���ι����࣬ʵ�־�������ϵͳ����
class CTourism
{
public:
	CTourism();
	~CTourism();

private:
	CGraph m_Graph;    //��������ͼ

public:
	void CreateGraph(void);   //������������ͼ
	void GetSpotInfo(void);   //��ѯ������Ϣ
	void TravelPath(void);  //���ξ��㵼��
	void FindShortPath(void);  //��ѯ���·��
	void DesignPath(void);//��ѯ�����·�滮ͼ
};

