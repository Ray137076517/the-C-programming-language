/*
 *功能：输入复制到输出，多个连续空格用一个空格代替
 *作者：Ray
 *日期：2014/5/15 23:10
*/

#include <stdio.h>

void main()
{
	int c = getchar();
	int lastc = 0;
	while (c != '\n')
	{
		if ((c!=' ') || (lastc!=' '))	//输出字符的条件集合
			putchar(c);
		lastc = c;
		c = getchar();
	}
	putchar('\n');
}