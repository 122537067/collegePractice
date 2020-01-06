#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SOURCEFILE "source.data"
#define MaxSize 100000
char inpaper[MaxSize];
char outpaper[MaxSize];
 
 
char t1[MaxSize]; //查找串 
char t2[MaxSize]; //替换串 
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
		printf("输入查找字符串：");
		scanf("%s",t1);
		printf("输入替换字符串：");
		scanf("%s",t2); 
		current=strstr(inpaper,t1);//查找串t1出现的第一个位置 
	    while(current!=NULL)//在源文件中查找t1串 
		{   
			while(&inpaper[i]!=current)//复制t1串前的字符串到outpaper 
			{
				outpaper[j]=inpaper[i];
			    //printf("%c",current[0]);
				//printf("%c",outpaper[j]);
				i++;
				j++;
			}
			outpaper[j]='\0';
			strcat(outpaper, t2);//复制t2串到outpaper 
			current=strstr(current+strlen(t1),t1);//继续查找t1串 
			i=i+strlen(t1);
			j=j+strlen(t2);
		}
		strcat(outpaper,&inpaper[i]+strlen(t1));//把inpaper串后的字符串复制到呕吐paper串	
		printf("%s",outpaper) ;
		strcpy(inpaper,outpaper);
	}	
}

int Getdata(char paper[])
{   
	FILE *fp;
    if ((fp = fopen(SOURCEFILE,"r")) == NULL) /* 以读方式打开文本文件 */
	{
		printf("Failure to open score.txt!\n");
		return 0;//读数据失败 
	}
	int i=0	; 
	while(!feof(fp))
	{
	   fscanf(fp,"%c",&paper[i]);
	   i++; 
	} 
	fclose(fp); 
    return 1;  //成功读数据                          
}

int Outputdata(int paper[])
{
	FILE *fp;
	if ((fp = fopen("out.data","w")) == NULL) /* 以写方式打开文本文件 */
	{
		printf("Failure to open score.txt!\n");
		return 0;//写数据失败 
	}
	for(int i=0;paper[i]!='\n';i++)  
        fprintf(fp,"%c",paper[i]);
	fclose(fp);
	return 1;
	
}


