#include<iostream>
#include<cstring>
#include<cmath>
#include"Tourism.h"
using namespace std;

int main(void)
{
	CTourism tourism;

	bool bRunning = true; //�������б�ʶ
	char key[10] = { 0 }; //�û������ѡ��

	while (bRunning)
	{
		cout << "====������Ϣ����ϵͳ====" << endl;
		cout << "1.������������ͼ" << endl;
		cout << "2.��ѯ������Ϣ" << endl;
		cout << "3.���ξ��㵼��" << endl;
		cout << "4.�������·��" << endl;
		cout << "5.�����·�滮" << endl;
		cout << "0.�˳�" << endl;      //�������

		//����
		cout << "������������(0~5)��";
		cin >> key;

		//�ж��û�����
		switch (key[0])
		{
		case'1':
			tourism.CreateGraph();  //������������ͼ
			break;
		case'2':
			tourism.GetSpotInfo(); //��ѯ������Ϣ
			break;
		case'3':
			tourism.TravelPath(); //���ξ��㵼��
			break;
		case'4':
			tourism.FindShortPath();  //��ѯ���·��
			break;
		case'5':
			tourism.DesignPath(); //��ѯ�����·�滮ͼ
			break;
		case'0':
			cout << "886" << endl;
			return 0;
		}
	}
}