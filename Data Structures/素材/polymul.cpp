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
	int coef; //系数 
	int exp;  //指数 
	Polynode *next;
}Polynode, *Polylist;
void outputPolylist(Polylist poly); //输出多项式 
void polyadd(Polylist poly,int coef,int exp);//多项式中增加一项 
void polycreate(Polylist head);//按升序的方式输入多项式各项的系数和指数，输入0 0结束 
void  polyadd(Polylist polya, Polylist polyb); /*两个多项式相加，然后将和多项式存放在多项式polya中，并将多项式ployb删除*/
void  polyadd(const Polylist polya, const Polylist polyb,Polylist polyc);/*两个多项式相加的和存放在polyc*/
void  polymul(Polylist polya, Polylist polyb,Polylist polyc); /*两个多项式相称，返回多项式乘积链表的头节点指针*/
int main()
{
	Polylist polya,polyb,polyc;
	Polynode *p;
	int coef,exp;
	cout<<"请输入多项式A中各项指数和系数:(以0,0结束!)\n";
	polya=(Polynode *)malloc(sizeof(Polynode));
	polya->next=NULL; 
	polycreate(polya);
	outputPolylist(polya);
    cout<<"请输入多项式B中各项指数和系数:(以0,0结束!)\n";
	polyb=(Polynode *)malloc(sizeof(Polynode));
	polyb->next=NULL; 
	polycreate(polyb);    
    outputPolylist(polyb);
    polyc=(Polynode *)malloc(sizeof(Polynode));
    polyc->next=NULL;
    //polyadd( polya,polyb,polyc); 
   polymul( polya,polyb,polyc); 
    outputPolylist(polyc);
    return 0;
}       
void polyadd(Polylist poly,int coef,int exp)//多项式中增加一项 
{
    /*填充完整本函数*/
}


void outputPolylist(Polylist poly) //输出多项式 
{
    Polylist	p = poly->next;
	while(p!=NULL)
	{
		cout<<p->exp<<" "<<p->coef<<endl;
		p=p->next;
	}
	cout<<endl;	
	return;
}

void polycreate(Polylist poly)
{
	
	int c,e;
    cin>>e>>c;                   /*键入多项式的指数和系数*/
	while(c!=0)	        /*若c=0，则代表多项式的输入结束*/
	{
       polyadd( poly,c,e);
       cin>>e>>c; 
	}
}
 
void  polyadd(Polylist polya, Polylist polyb) //多项式B加入到多项式A中，并删除B中的结点 
{
	Polynode *p=polyb->next;
	while(p!=NULL)
	{
		polyadd(polya,p->coef,p->exp);//把polyb的第一项插入到polya中 
		polyb->next=p->next;// polyb多项式删除第1项 		
		free(p); 
		p=polyb->next; //p指向polyb的新的第一个节点 
	}
	free(polyb);//释放polyb的头结点 
	
}

void  polyadd(const Polylist polya, const Polylist polyb,Polylist polyc) 
{
	Polynode *p=polya->next;
	while(p!=NULL)
	{
		polyadd(polyc,p->coef,p->exp);
		p=p->next; 
	}
	p=polyb->next;
	while(p!=NULL)
	{
		polyadd(polyc,p->coef,p->exp);	 
		p=p->next; 
	}	
}

void  polymul(Polylist polya, Polylist polyb,Polylist polyc) /*两个多项式相乘，返回多项式乘积链表的头节点指针*/
{
   	/* 填充完整本函数*/
}
