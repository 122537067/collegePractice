#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SOURCEFILE "4.data"
const int LineLenght=20;//控制屏幕打印时，每行元素个数 
const int MaxSize=30000; 
void Printdata(int data[],int n);//打印数组中个的各个元素 
int Getdata(int *data,int &n); 
void creatdata(int &n);//产生n个0~1000之间的随机整数，并写入source.data  
void insertsort(int data[],int n);//直接插入排序 
int Outputdata(int data[],int n); 
void shellsort(int data[],int n);//希尔排序 
void bubllesort(int data[],int n);//冒泡排序 
void quicksort(int data[],int n);//快速排序 
void selectsort(int data[],int n);//简单选择排序 
void heapsort(int data[],int n);//堆排序 
void mergesort(int data[],int n);//合并排序
void radixsort(int data[],int n);//基数排序

int main()
{
	int n;	
	int data[MaxSize];
	char SORCEFILE[10]; 
    clock_t start,end; 
 	printf("输入待排序序列所在文件名，例：1.data:");
    //scanf("%s",&SORCEFILE);      
    Getdata( data, n); //读取文件的数据存放在data数组中  
	int menu;
    printf("请选择排序方式:\n");
	while(1)
    {
	    
	    printf("1.  直接插入排序\n");
	    printf("2.  希尔插排序\n");
	    printf("3.  冒泡排序\n");
	    printf("4.  快速排序\n");
	    printf("5.  简单选择插入排序\n");
	    printf("6.  堆排序\n");
	    printf("7.  归并排序\n");
	    printf("8.  基数排序\n");
	    scanf("%d",&menu);
	    switch(menu)
	    {
	    	case 1:{
	    		
	    		start = clock();
	    		insertsort(data, n);
	    		end = clock();
	    		//Printdata(data ,n);//输出数据 
	    		//Outputdata(data ,n);
	    		printf("排序时间为%d毫秒",end-start);
	    		printf("您可以尝试一下其它的排序方法:\n");
	    		break;
	    	}	    		
         /* 请在此处补充完整main函数*/				
			default: {
				printf("没有这种排序方式，请选择正确的排序方法:\n");
			   
			}
	    
	    }
    }
    return 0;
}

void Printdata(int data[],int n)
{
    for(int i=0;i<n;i++)
	{
       printf("%4d",data[i]);
	   if(i%LineLenght==LineLenght-1)
	      printf("\n");	
    } 
    printf("\n");	
	return;                           
}
int Getdata(int data[], int &n)
{   
    
	FILE *fp;
    if ((fp = fopen(SOURCEFILE,"r")) == NULL) /* 以读方式打开文本文件 */
	{
		printf("Failure to open score.txt!\n");
		return 0;//读数据失败 
	}
	int i=0;
	fscanf(fp,"%6d",&n);//获取文件中的元素个数 
	 
	while(!feof(fp)&&i<n)
	{
	   fscanf(fp,"%4d",&data[i]);
	   i++; 
	} 
	fclose(fp); 
    return 1;  //成功读数据                          
}
void insertsort(int data[],int n)//直接插入排序 
{   int i,j,x;
	for( i=1;i<n;i++) 
	{    x=data[i];
		for(j=i-1;j>=0;j--)
		{
		   if(data[j]>x)
		     data[j+1]=data[j];
		   else break;
		}
		if(j!=i) data[j+1]=x;
	}
} 
int Outputdata(int data[],int n)
{
	FILE *fp;
	if ((fp = fopen("out.data","w")) == NULL) /* 以写方式打开文本文件 */
	{
		printf("Failure to open score.txt!\n");
		return 0;//写数据失败 
	}
	for(int i=0;i<n;i++)  
        fprintf(fp,"%4d",data[i]);
	fclose(fp);
	return 1;
	
}
void shellsort(int data[],int n)//希尔排序 
{  
 /*把函数的实现代码粘贴在此处*/
}
void bubllesort(int data[],int n)//冒泡排序 
{ 
 /*把函数的实现代码粘贴在此处*/
}
void quicksort(int data[],int n)//快速排序 
{  
 /*把函数的实现代码粘贴在此处*/
}
void selectsort(int data[],int n)//简单选择排序 
{  
 /*把函数的实现代码粘贴在此处*/
}
void heapsort(int data[],int n)//堆排序 
{  
 /*把函数的实现代码粘贴在此处*/
}
void mergesort(int data[],int n)//合并排序
{  
 /*把函数的实现代码粘贴在此处*/
}
void radixsort(int data[],int n)//基数排序
{  
 /*把函数的实现代码粘贴在此处*/
}


