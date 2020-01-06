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
int Outputdata(char paper[]);
int main()
{
	int i = 0;
	int j = 0;
	Getdata(inpaper);
	int len = strlen(inpaper);
	printf("请输入需要替换的单词或句子：");
	scanf("%s", t1);
	int len1 = strlen(t1);
	printf("请输入替换的单词或句子：");
	scanf("%s", t2);
	int len2 = strlen(t2);
	int count = 0;
	for (int i = 0; i<len; i++)
	{
		int j = 0;
		int tt = i;
		int flag = 0;
		while (inpaper[tt] == t1[j] && j<len1)
		{
			if (j == len1 - 1)
			{
				int ss = 0;
				for (int k = count; k<count + len2; k++)
				{
					outpaper[k] = t2[ss];
					ss++;
				}
				i += len1 - 1;
				count += len2;
				flag = 1;
			}
			tt++;
			j++;
		}
		if (flag == 0)
		{
			outpaper[count] = inpaper[i];
			count++;
		}
	}
	Outputdata(outpaper);
	int lenn = strlen(outpaper);
	for (int i = 0; i<lenn; i++)
	{
		printf("%c", outpaper[i]);
	}
	printf("\n");
	/*在此补充代码，实现文本的查找与替换*/
}
int Getdata(char paper[])
{
	FILE *fp;
	if ((fp = fopen(SOURCEFILE, "r")) == NULL) /* 以读方式打开文本文件 */
	{
		printf("Failure to open score.txt!\n");
		return 0;//读数据失败 
	}
	int i = 0;
	while (!feof(fp))       //字符读文件
	{

		fscanf(fp, "%c", &paper[i]);
		printf("%c", paper[i]);
		i++;
	}
	printf("\n");
	fclose(fp);             //释放文件（内存）
	return 1;  //成功读数据                          
}

int Outputdata(char paper[])
{
	FILE *fp;
	int len = strlen(paper);
	if ((fp = fopen("out.data", "w")) == NULL) /* 以写方式打开文本文件 */
	{
		printf("Failure to open score.txt!\n");
		return 0;//写数据失败 
	}
	for (int i = 0; i < len; i++)
	{
		fprintf(fp, "%c", paper[i]);
	}
	fclose(fp);
	return 1;

}