// try.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<cstdlib>
int main()
{
	int n=5;//nΪ��������
	int w[5] = { 3, 4, 1, 2, 5 };
	int v[5] = { 2,3,8,3,4 };
	int chun[10][10];
	for (int i = 1; i < n; i++)
	{
		if (w[0] < i)
		{
			chun[0][i] = v[0];
		}
	}
	for (int h = 1; h < n; h++)//hΪ����ĸ�
	{
		for (int k = 0; k < 8; k++)
		{
			if (w[h] <=k)//��d��
			{
				chun[h][k] = v[h]+chun[h-1][k-w[h]];
				if (chun[h][k] < chun[h - 1][k])
				{
					chun[h][k] = chun[h - 1][k];
				}

			}
			else
			{
				chun[h][k] = chun[h - 1][k];
			}
		}
	}
	printf("%d", chun[4][5]);
	system("pause");
	return 0;
}

