/*
 *功能：统计各数字，空白符，其他字符出现次数
 *作者：K&R
 *日期：2014/5/18 22:00
*/

#include <stdio.h>

void main()
{
	int c = 0;
	int i = 0;
	int nwhite = 0;
	int nother = 0;
	int ndigit[10];
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;

	while ((c = getchar()) != '\n')
	{
		if (c >= '0' && c <= '9')       //多路判定
			ndigit[c-'0']++;            //
		else if (c==' ' || c=='\t')     //
			nwhite++;                   //
		else                            //
			nother++;                   //
	}

	printf("digit =");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf("\nwhite space = %d\nother = %d\n", nwhite, nother);
}