// ���·�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<cstdlib>
#include<iostream>
using namespace std;

int a, b[500001], c, d, temp, g, h, cun, he;//cΪ��Ȼ��λʱ�����ɵ�����dΪ����������ˮƽ;

void han(int l)
{
	if (b[l] == 0 || b[l] < 0)
	{
		return;
	}
	else
	{
		if (b[l] % (c + d) == 0)
		{
			g = b[l] / (c + d);//��¼����
			h = g*c;//��¼��Ȼ���ɵ���
			he += g;//��¼����
			b[l - 1] -= h;
		}
		else
		{
			g = b[l] / (c + d) + 1;
			h = g*c;
			he += g;
			b[l - 1] -= h;
		}
		han(l - 1);
	}
}
int main()
{
	scanf("%d%d%d", &a, &c, &d);
	for (int i = 1; i <= a; i++)
	{
		scanf("%d",&b[i]);
	}
	if (a == 1)
	{
		if (b[1] % (c + d) == 0)
		{
			printf("%d", b[1] / (c + d));
			return 0;
		}
		else
		{
			printf("%d", b[1] / (c + d) + 1);
			return 0;
		}
	}
	for (int j = 1; j <= a; j++)
	{
		for (int k = 1; k<a; k++)
		{
			if (b[k] > b[k + 1])
			{
				temp = b[k];
				b[k] = b[k + 1];
				b[k + 1] = temp;
			}
		}
	}
	han(a);
	printf("%d", he);
	system("pause");
	return 0;
}

