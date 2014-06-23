/*
 *���ܣ���ӡ�����е��ʳ��ȵ�ֱ��ͼ��ˮƽ��
 *��ע�����һ�����ʺ�����пհ׷����ո�/�Ʊ����������ͳ�Ʋ����õ���
 *���ߣ�Ray
 *���ڣ�2014/5/19 0:50
*/

#include <stdio.h>

#define MAXHIST 20	//ֱ��ͼ�����
#define MAXLEN 10	//�ɲ����󵥴ʳ���
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

	while ((c = getchar()) != '\n')	//���벢ͳ�Ƹ����ȼ��������ȵĵ�����
	{
		if (c == ' ' || c == '\t')
		{
			state = OUT;
			if (count > 0)	//���ʽ���
			{
				if (count <= MAXLEN)
					wlenth[count - 1]++;
				else
					overflow++;
				count = 0;
			}
		}
		else if (state == OUT)	//�����µ���
		{
			state = IN;
			count = 1;	//��1����ʼ����
		}
		else
			count++;	//���ڵ����ڣ���������
	}

	printf("overflow - %2d: ", overflow);	//��������ɲⳤ�ȵĵ�����ֱ��ͼ
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

	for (i = 0; i < MAXLEN; i++)	//��������ȵĵ�����ֱ��ͼ
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