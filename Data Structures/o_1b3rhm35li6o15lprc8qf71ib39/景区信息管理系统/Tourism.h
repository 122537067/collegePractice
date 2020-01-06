#pragma once
#include"Graph.h"
class CTourism
{
public:
	CTourism(void);
	~CTourism(void);

private:
	//��������ͼ
	CGraph m_Graph;
public:
	//������������ͼ
	void CreateGraph(void);
	//��ѯ������Ϣ
	void GetSpotInfo(void);
	//���ξ��㵼��
	void TravelPath(void);
	//��ѯ���·��
	void FindShortPath(void);
};

