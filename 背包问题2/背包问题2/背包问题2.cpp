// ��������2.cpp : �������̨Ӧ�ó������ڵ㡣
//
//�и������ɳ�������N������T����Ʒ
//ÿ����Ʒ����ΪWi, ��ֵΪVi, ÿ����Ʒ�������������, �����������װ����Ʒ������ֵ�Ƕ��� ?
#include "stdafx.h"
#include<stdio.h>
#include<cstdlib>
int a, b,c,n;
int zhu[101][3],cun[101][101],bi[100];
int main()
{
	zhu[0][0] = 0;
	scanf("%d%d", &a, &b);
	for (int i = 1; i <= b; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			scanf("%d",&zhu[i][j]);
		}
	}
	for (int k = 1; k <= a; k++)
	{
		cun[1][k] = (k / zhu[1][1])*zhu[1][2];
	}
	for (int l = 2; l <= b; l++)
	{
		for (int m = 1; m <= a; m++)//mΪ����
		{
			n = m / zhu[l][1];//nΪ�������������
			int x=-1;
			for (int o = 1; o <= n; o++)
			{
				if (zhu[l][2] * o + cun[l-1][m - (o*zhu[l][1])] > x)
				{
					x = zhu[l][2] * o + cun[l-1][m - o*(zhu[l][1])];
				}
			}
			cun[l][m] = x;
			if (cun[l][m] < cun[l - 1][m])
			{
				cun[l][m] = cun[l - 1][m];
			}
		}
	}
	printf("%d", cun[b][a]);
	system("pause");
	return 0;
}

