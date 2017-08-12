// 背包问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int main() {//8
	//0 0 2 3 3 3 5 5 5//前i物品  容量
	//8 8 8 10 10 10 10 13      //4-1=3
	int w[5]={3,4,1,2,5};
	int v[5]={2,3,8,3,4};
	int c=10;
	/*FILE *in = fopen("bag.in", "r");
	FILE *out = fopen("bag.out", "w");*/
	int n, max;
	//fscanf(in, "%d %d", &max, &n);
	int m[1024][1024];
	int w[1024], v[1024];/*
	for (int i = 0; i<n; i++) 
	{
		fscanf(in, "%d %d", &w[i], &v[i]);
	}*//*
	 for(int i=0;i<n;i++){
	 fscanf(in,"%d",&v[i]);
	 }*/
	for (int i = 0; i<n; i++) {
		memset(m[i], 0, sizeof(m[i]));
	}
	/*
	*初始化第一行   放入第一个物品（如果能放下）
	*/
	for (int j = 1; j <= max; j++) {
		if (j >= w[0]) {
			m[0][j] = v[0];//前i+1
		}
	}
	/*
	* 依次放入其他物品
	*/
	for (int i = 1; i<n; i++) {
		for (int j = 1; j <= max; j++) {
			if (j<w[i])	m[i][j] = m[i - 1][j];//不放入 取上一价值
			else {
				/*
				* m[i-1][j-w[i]]=>  在能塞入的情况下 除去当前重量的最大价值
				* 		     加上v[i]后即当前重量的最大价值
				* 		     如果m[i-1][j-w[i]]+v[i] > m[i-1][j]
				* 		     即加入此物品价值比同重量的情况价值大，则加入该物品，否则取另一种情况
				*/
				if (m[i - 1][j - w[i]]+v[i] > m[i - 1][j]) {
					m[i][j] = m[i - 1][j - w[i]];
				}
				else {
					m[i][j] = m[i-1][j];
				}
				//m[i][j] = m[i - 1][j - w[i]] + v[i]>m[i - 1][j] ? m[i - 1][j - w[i]] + v[i] : m[i - 1][j];
			}
		}
	}
	/*	cout << "For Testing: " << endl;
	for(int i=0;i<n;i++){
	for(int j=0;j<max+1;j++){
	cout << m[i][j] << "\t" ;
	}
	cout << endl;
	}
	cout << endl;
	*/	cout << m[n - 1][max];
	return 0;
}



