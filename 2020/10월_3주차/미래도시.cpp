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

int ans;
int K, X;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	// N - 회사 갯수, M - 경로 갯수
	cin >> N >> M;
	fill(&num[0][0], &num[MAX-1][MAX], INF);
	for (int i = 1; i <= N; i++) {
		num[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		num[a][b] = 1;
		num[b][a] = 1;
	}
	cin >> X>> K ;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				num[i][j] = min(num[i][j], num[i][k] + num[k][j]);
			}
		}
	}
	ans = num[1][K] + num[K][X];
	if (ans >= INF) {
		cout << "-1";
	}
	else {
		cout << ans;
	}
}