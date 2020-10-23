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
#include <sstream>

#define MAX 10

using namespace std;

bool visit[MAX];
int N, M, V;
vector<int> v[MAX];
void bfs(int i) {
	cout << "\n";
	visit[i] = true;
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << " ";
		for (int k = 0; k < v[tmp].size(); k++) {
			if (!visit[v[tmp][k]]) {
				q.push(v[tmp][k]);
				visit[v[tmp][k]] = true;
			}
		}
	}
}
void dfs(int i) {
	visit[i] = true;
	cout << i << " ";
	for (int k = 0; k < v[i].size(); k++) {
		if (!visit[v[i][k]]) {
			dfs(v[i][k]);
		}
	}
}
int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(V);

	memset(visit, false, sizeof(visit));
	bfs(V);
}