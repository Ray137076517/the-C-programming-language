/*
 *���ܣ����븴�Ƶ��������������ո���һ���ո����
 *���ߣ�Ray
 *���ڣ�2014/5/15 23:10
*/

#include <stdio.h>

void main()
{
	int c = getchar();
	int lastc = 0;
	while (c != '\n')
	{
		if ((c!=' ') || (lastc!=' '))	//����ַ�����������
			putchar(c);
		lastc = c;
		c = getchar();
	}
	putchar('\n');
}