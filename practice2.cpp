/*
 *功能：输入复制到输出，每行一个单词输出
 *标注：若最后输入字符为空格或制表符，将多输出一个换行符
 *作者：K&R
 *日期：2014/5/16 0:40
*/

#include <stdio.h>

#define IN 1
#define OUT 0

void main()
{
	int c = 0;
	int state = OUT;
	while ((c=getchar()) != '\n')
	{
		if (c==' ' || c=='\t')
		{
			if (state == IN)
			{
				putchar('\n');
				state = OUT;
			}
		}
		else if (state == OUT)
		{
			state = IN;
			putchar(c);
		}
		else 
			putchar(c);
	}
	putchar('\n');
}