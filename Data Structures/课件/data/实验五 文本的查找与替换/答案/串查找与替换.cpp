#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SOURCEFILE "source.data"
#define MaxSize 100000
char inpaper[MaxSize];
char outpaper[MaxSize];
 
 
char t1[MaxSize]; //���Ҵ� 
char t2[MaxSize]; //�滻�� 
int Getdata(char paper[]);
int Outputdata(int data[],int n);
int main()
{
	
	char *current;
	int i=0;
	int j=0;
	Getdata(inpaper);
	while(1)
	{
        
		printf("%s\n",inpaper);
		printf("��������ַ�����");
		scanf("%s",t1);
		printf("�����滻�ַ�����");
		scanf("%s",t2); 
		current=strstr(inpaper,t1);//���Ҵ�t1���ֵĵ�һ��λ�� 
	    while(current!=NULL)//��Դ�ļ��в���t1�� 
		{   
			while(&inpaper[i]!=current)//����t1��ǰ���ַ�����outpaper 
			{
				outpaper[j]=inpaper[i];
			    //printf("%c",current[0]);
				//printf("%c",outpaper[j]);
				i++;
				j++;
			}
			outpaper[j]='\0';
			strcat(outpaper, t2);//����t2����outpaper 
			current=strstr(current+strlen(t1),t1);//��������t1�� 
			i=i+strlen(t1);
			j=j+strlen(t2);
		}
		strcat(outpaper,&inpaper[i]+strlen(t1));//��inpaper������ַ������Ƶ�Ż��paper��	
		printf("%s",outpaper) ;
		strcpy(inpaper,outpaper);
	}	
}

int Getdata(char paper[])
{   
	FILE *fp;
    if ((fp = fopen(SOURCEFILE,"r")) == NULL) /* �Զ���ʽ���ı��ļ� */
	{
		printf("Failure to open score.txt!\n");
		return 0;//������ʧ�� 
	}
	int i=0	; 
	while(!feof(fp))
	{
	   fscanf(fp,"%c",&paper[i]);
	   i++; 
	} 
	fclose(fp); 
    return 1;  //�ɹ�������                          
}

int Outputdata(int paper[])
{
	FILE *fp;
	if ((fp = fopen("out.data","w")) == NULL) /* ��д��ʽ���ı��ļ� */
	{
		printf("Failure to open score.txt!\n");
		return 0;//д����ʧ�� 
	}
	for(int i=0;paper[i]!='\n';i++)  
        fprintf(fp,"%c",paper[i]);
	fclose(fp);
	return 1;
	
}


