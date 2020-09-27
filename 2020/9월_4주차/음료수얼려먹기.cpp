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
#define MAX 1001
using namespace std;
int N, M;
int num[MAX][MAX];
bool visit[MAX][MAX];
int ans = 0;

bool dfs(int a, int b) {
	if (a < 0 || b < 0 || a >= N || b >= M) return false;
	if (num[a][b] == 0) {
		num[a][b] = 1;
		dfs(a - 1, b);
		dfs(a, b - 1);
		dfs(a + 1, b);
		dfs(a, b + 1);
		return true;
	}
	return false;

}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> num[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (dfs(i, j)) {
				ans++;
			}
		}
	}
	cout << ans << endl;

}