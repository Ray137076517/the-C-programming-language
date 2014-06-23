/*
 *功能：打印输入中单词长度的直方图（水平）
 *标注：最后一个单词后必须有空白符（空格/制表符），否则将统计不到该单词
 *作者：Ray
 *日期：2014/5/19 0:50
*/

#include <stdio.h>

#define MAXHIST 20	//直方图最长长度
#define MAXLEN 10	//可测的最大单词长度
#define IN 1
#define OUT 0

void main()
{
	int i = 0;
	int j = 0;
	int c = 0;
	int count = 0;
	int overflow = 0;
	int state = OUT;
	int wlenth[MAXLEN];
	for (i = 0; i < MAXLEN; i++)
	{
		wlenth[i] = 0;
	}

	while ((c = getchar()) != '\n')	//输入并统计各长度及超出长度的单词数
	{
		if (c == ' ' || c == '\t')
		{
			state = OUT;
			if (count > 0)	//单词结束
			{
				if (count <= MAXLEN)
					wlenth[count - 1]++;
				else
					overflow++;
				count = 0;
			}
		}
		else if (state == OUT)	//进入新单词
		{
			state = IN;
			count = 1;	//置1，开始计数
		}
		else
			count++;	//仍在单词内，继续计数
	}

	printf("overflow - %2d: ", overflow);	//输出超出可测长度的单词数直方图
	if (overflow > MAXHIST)
		printf("OVER THE MAXHIST");
	else
	{
		for (i = 0; i < overflow; i++)
		{
			putchar('*');
		}
	}
	putchar('\n');

	for (i = 0; i < MAXLEN; i++)	//输出各长度的单词数直方图
	{
		printf("lenth%3d - %2d: ", i + 1, wlenth[i]);
		if (wlenth[i] >= MAXHIST)
			printf("OVER THE MAXHIST");
		else
		{
			for (j = 0; j < wlenth[i]; j++)
				putchar('*');
		}
		putchar('\n');
	}
}