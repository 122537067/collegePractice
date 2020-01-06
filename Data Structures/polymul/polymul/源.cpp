#include<iostream> 
#include <stdlib.h>
#include <malloc.h>
using namespace std;

#define OK   1
#define ERROR  0
#define TRUE 1
#define FALSE 0

typedef struct Polynode
{
	int coef; //ϵ�� 
	int exp;  //ָ�� 
	Polynode *next;
}Polynode, *Polylist;
void outputPolylist(Polylist poly); //�������ʽ 
void polyadd(Polylist poly, int coef, int exp);//����ʽ������һ�� 
void polycreate(Polylist head);//������ķ�ʽ�������ʽ�����ϵ����ָ��������0 0���� 
void  polyadd(Polylist polya, Polylist polyb); /*��������ʽ��ӣ�Ȼ�󽫺Ͷ���ʽ����ڶ���ʽpolya�У���������ʽploybɾ��*/
void  polyadd(const Polylist polya, const Polylist polyb, Polylist polyc);/*��������ʽ��ӵĺʹ����polyc*/
void  polymul(Polylist polya, Polylist polyb, Polylist polyc); /*��������ʽ��ƣ����ض���ʽ�˻������ͷ�ڵ�ָ��*/
int main()
{
	Polylist polya, polyb, polyc;
	Polynode *p;
	int coef, exp;
	cout << "���������ʽA�и���ָ����ϵ��:(��0,0����!)\n";
	polya = (Polynode *)malloc(sizeof(Polynode));
	polya->next = NULL;
	polycreate(polya);
	outputPolylist(polya);
	cout << "���������ʽB�и���ָ����ϵ��:(��0,0����!)\n";
	polyb = (Polynode *)malloc(sizeof(Polynode));
	polyb->next = NULL;
	polycreate(polyb);
	outputPolylist(polyb);
	polyc = (Polynode *)malloc(sizeof(Polynode));
	polyc->next = NULL;
	//polyadd( polya,polyb,polyc); 
	polymul(polya, polyb, polyc);
	outputPolylist(polyc);
	return 0;
}
void polyadd(Polylist poly, int coef, int exp)
{
	Polynode *pre;
	pre = (Polynode *)malloc(sizeof(Polynode));
	while (poly->next != NULL&&poly->exp<exp)
	{
		if (exp == poly->next->exp)
		{
			poly->next->exp = exp;
			poly->next->coef += coef;
			if (poly->next->coef == 0)
			{
				pre = poly->next;
				poly->next = pre->next;
				free(pre);
			}
			return;
		}
		poly = poly->next;
	}
	if (coef == 0)
	{
		return;
	}
	pre->coef = coef;
	pre->exp = exp;
	pre->next = poly->next;
	poly->next = pre;
}


void outputPolylist(Polylist poly) //�������ʽ 
{
	Polylist	p = poly->next;
	while (p != NULL)
	{
		cout << p->exp << " " << p->coef << endl;
		p = p->next;
	}
	cout << endl;
	return;
}

void polycreate(Polylist poly)
{

	int c, e;
	cin >> e >> c;                   /*�������ʽ��ָ����ϵ��*/
	while (c != 0)	        /*��c=0����������ʽ���������*/
	{
		polyadd(poly, c, e);
		cin >> e >> c;
	}
}

void  polyadd(Polylist polya, Polylist polyb) //����ʽB���뵽����ʽA�У���ɾ��B�еĽ�� 
{
	Polynode *p = polyb->next;
	while (p != NULL)
	{
		polyadd(polya, p->coef, p->exp);//��polyb�ĵ�һ����뵽polya�� 
		polyb->next = p->next;// polyb����ʽɾ����1�� 		
		free(p);
		p = polyb->next; //pָ��polyb���µĵ�һ���ڵ� 
	}
	free(polyb);//�ͷ�polyb��ͷ��� 

}

void  polyadd(const Polylist polya, const Polylist polyb, Polylist polyc)
{
	Polynode *p = polya->next;
	while (p != NULL)
	{
		polyadd(polyc, p->coef, p->exp);
		p = p->next;
	}
	p = polyb->next;
	while (p != NULL)
	{
		polyadd(polyc, p->coef, p->exp);
		p = p->next;
	}
}

void  polymul(Polylist polya, Polylist polyb,Polylist polyc)
{  
 Polylist pre;
	pre=polyb;
   	int coef,exp;
	while(polya->next!=NULL)
	{
		polya=polya->next;
		while(polyb->next!=NULL)
		{
			polyb=polyb->next;
			exp=polya->exp+polyb->exp;
			coef=polya->coef*polyb->coef;
			polyadd(polyc,coef,exp);
		}
		polyb=pre;
	}
}
