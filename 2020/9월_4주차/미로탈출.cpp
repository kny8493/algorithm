#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <deque>
#include <stack>
#include <vector>
#include<cstdio>
#include<algorithm>
#include<queue>
#define MAX 201
using namespace std;
int N, M;
int num[MAX][MAX];
bool visit[MAX][MAX];
int ans = 0;

void bfs(int a, int b) {
	if (num[a - 1][b] >1 && num[a][b - 1] >1) {
			num[a][b] += min(num[a - 1][b], num[a][b - 1]);
			num[a][b]++;

	}
	else if (num[a - 1][b] >1) {
		num[a][b] = num[a - 1][b] + 1;
	}
	else if (num[a][b - 1] > 1) {
		num[a][b] = num[a][b - 1] + 1;
	}

}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> num[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i == 2 && j == 1 && num[i][j] == 1) {
				num[i][j]++;
			}
			else if (i == 1 && j == 2 && num[i][j] == 1) {
				num[i][j]++;
			}else if (num[i][j]) {
				bfs(i, j);
			}
		}
	}
	cout << num[N][M];

}