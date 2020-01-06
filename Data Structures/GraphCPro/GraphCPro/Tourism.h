#pragma once
#include"Graph.h"
//旅游功能类，实现景区旅游系统功能
class CTourism
{
public:
	CTourism();
	~CTourism();

private:
	CGraph m_Graph;    //景区景点图

public:
	void CreateGraph(void);   //创建景区景点图
	void GetSpotInfo(void);   //查询景点信息
	void TravelPath(void);  //旅游景点导航
	void FindShortPath(void);  //查询最短路径
	void DesignPath(void);//查询铺设电路规划图
};

