#pragma once
#include"Graph.h"
class CTourism
{
public:
	CTourism(void);
	~CTourism(void);

private:
	//景区景点图
	CGraph m_Graph;
public:
	//创建景区景点图
	void CreateGraph(void);
	//查询景点信息
	void GetSpotInfo(void);
	//旅游景点导航
	void TravelPath(void);
	//查询最短路径
	void FindShortPath(void);
};

