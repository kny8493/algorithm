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
#include<map>
#define MAX 501
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;
int N, M;
int num[MAX][MAX];
int ans[MAX][MAX];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	fill(&num[0][0], &num[N][N + 1], INF);
	for (int i = 1; i <= N; i++) {
		num[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		num[a][b] = c;
	}
	// k = 거쳐가는 노드
	for (int k = 1; k <= N; k++) {
		// i = 출발노드
		for (int i = 1; i <= N; i++) {
			// j = 도착 노드
			for (int j = 1; j <= N; j++) {
				if (num[i][j] > num[i][k] + num[k][j]) {
					num[i][j] = num[i][k] + num[k][j];
				}
			}
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (num[i][j] == INF) {
				cout << "INF" << " ";
			}
			else {
				cout << num[i][j] << " ";
			}
		}
		cout << "\n";
	}

}