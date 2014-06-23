/*
 *���ܣ����븴�Ƶ������ÿ��һ���������
 *��ע������������ַ�Ϊ�ո���Ʊ�����������һ�����з�
 *���ߣ�K&R
 *���ڣ�2014/5/16 0:40
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