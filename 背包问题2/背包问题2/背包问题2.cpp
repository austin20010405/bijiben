// 背包问题2.cpp : 定义控制台应用程序的入口点。
//
//有个背包可承受重量N，现有T件物品
//每件物品重量为Wi, 价值为Vi, 每件物品的数量是无穷的, 这个背包可以装载物品的最大价值是多少 ?
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
		for (int m = 1; m <= a; m++)//m为长度
		{
			n = m / zhu[l][1];//n为能塞进的最大倍数
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

