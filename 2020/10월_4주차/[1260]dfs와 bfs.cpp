#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <deque>
#include <stack>
#include <vector>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<queue>
#include<map>
#define MAX 1001
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;


bool visit[MAX];
int N, M, V;
vector<int> v[10001];
queue<int> q;

void dfs(int i) {
	visit[i] = true;
	cout << i << " ";
	for (int j = 0; j < v[i].size(); j++) {
		if (!visit[v[i][j]]) {
			dfs(v[i][j]);
		}
	}
}
void bfs(int i) {
	cout << "\n";
	visit[i] = true;
	q.push(i);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp<<" ";\
		for (int j = 0; j < v[tmp].size(); j++) {
			if (!visit[v[tmp][j]]) {
				q.push(v[tmp][j]);
				visit[v[tmp][j]] = true;
			}
		}
	}
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(V);
	memset(visit, false, sizeof(visit));
	bfs(V);

}