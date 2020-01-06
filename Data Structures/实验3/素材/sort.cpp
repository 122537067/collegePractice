#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SOURCEFILE "4.data"
const int LineLenght=20;//������Ļ��ӡʱ��ÿ��Ԫ�ظ��� 
const int MaxSize=30000; 
void Printdata(int data[],int n);//��ӡ�����и��ĸ���Ԫ�� 
int Getdata(int *data,int &n); 
void creatdata(int &n);//����n��0~1000֮��������������д��source.data  
void insertsort(int data[],int n);//ֱ�Ӳ������� 
int Outputdata(int data[],int n); 
void shellsort(int data[],int n);//ϣ������ 
void bubllesort(int data[],int n);//ð������ 
void quicksort(int data[],int n);//�������� 
void selectsort(int data[],int n);//��ѡ������ 
void heapsort(int data[],int n);//������ 
void mergesort(int data[],int n);//�ϲ�����
void radixsort(int data[],int n);//��������

int main()
{
	int n;	
	int data[MaxSize];
	char SORCEFILE[10]; 
    clock_t start,end; 
 	printf("������������������ļ���������1.data:");
    //scanf("%s",&SORCEFILE);      
    Getdata( data, n); //��ȡ�ļ������ݴ����data������  
	int menu;
    printf("��ѡ������ʽ:\n");
	while(1)
    {
	    
	    printf("1.  ֱ�Ӳ�������\n");
	    printf("2.  ϣ��������\n");
	    printf("3.  ð������\n");
	    printf("4.  ��������\n");
	    printf("5.  ��ѡ���������\n");
	    printf("6.  ������\n");
	    printf("7.  �鲢����\n");
	    printf("8.  ��������\n");
	    scanf("%d",&menu);
	    switch(menu)
	    {
	    	case 1:{
	    		
	    		start = clock();
	    		insertsort(data, n);
	    		end = clock();
	    		//Printdata(data ,n);//������� 
	    		//Outputdata(data ,n);
	    		printf("����ʱ��Ϊ%d����",end-start);
	    		printf("�����Գ���һ�����������򷽷�:\n");
	    		break;
	    	}	    		
         /* ���ڴ˴���������main����*/				
			default: {
				printf("û����������ʽ����ѡ����ȷ�����򷽷�:\n");
			   
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
    if ((fp = fopen(SOURCEFILE,"r")) == NULL) /* �Զ���ʽ���ı��ļ� */
	{
		printf("Failure to open score.txt!\n");
		return 0;//������ʧ�� 
	}
	int i=0;
	fscanf(fp,"%6d",&n);//��ȡ�ļ��е�Ԫ�ظ��� 
	 
	while(!feof(fp)&&i<n)
	{
	   fscanf(fp,"%4d",&data[i]);
	   i++; 
	} 
	fclose(fp); 
    return 1;  //�ɹ�������                          
}
void insertsort(int data[],int n)//ֱ�Ӳ������� 
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
	if ((fp = fopen("out.data","w")) == NULL) /* ��д��ʽ���ı��ļ� */
	{
		printf("Failure to open score.txt!\n");
		return 0;//д����ʧ�� 
	}
	for(int i=0;i<n;i++)  
        fprintf(fp,"%4d",data[i]);
	fclose(fp);
	return 1;
	
}
void shellsort(int data[],int n)//ϣ������ 
{  
 /*�Ѻ�����ʵ�ִ���ճ���ڴ˴�*/
}
void bubllesort(int data[],int n)//ð������ 
{ 
 /*�Ѻ�����ʵ�ִ���ճ���ڴ˴�*/
}
void quicksort(int data[],int n)//�������� 
{  
 /*�Ѻ�����ʵ�ִ���ճ���ڴ˴�*/
}
void selectsort(int data[],int n)//��ѡ������ 
{  
 /*�Ѻ�����ʵ�ִ���ճ���ڴ˴�*/
}
void heapsort(int data[],int n)//������ 
{  
 /*�Ѻ�����ʵ�ִ���ճ���ڴ˴�*/
}
void mergesort(int data[],int n)//�ϲ�����
{  
 /*�Ѻ�����ʵ�ִ���ճ���ڴ˴�*/
}
void radixsort(int data[],int n)//��������
{  
 /*�Ѻ�����ʵ�ִ���ճ���ڴ˴�*/
}


