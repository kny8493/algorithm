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
using namespace std;

vector<int> v[1001];
bool visit[1001];

void dfs(int num) {
	// 탐색 노드 스택에 삽입 후 방문처리
	visit[num] = true;
	cout << num << " ";
	for (int i = 0; i < v[num].size(); i++) {
		int tmp = v[num][i];
		// 방문하지 않은 인접 노드가 있는 경우 -> 노드를 스택에 넣고 반문처리
		//									-> 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드 꺼냄
		if (!visit[tmp]) {
			dfs(tmp);
		}
	}
}

void bfs(int num) {

	deque<int> dq;
	// 시작 노드를 큐에 삽입 후 방문 처리
	dq.push_back(num);
	visit[num] = true;
	// 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입후 방문 처리
	while (!dq.empty()) {
		int tmp = dq.front();
		dq.pop_front();
		cout << tmp << " ";
		for (int i = 0; i < v[tmp].size(); i++) {
			if (!visit[v[tmp][i]]) {
				dq.push_back(v[tmp][i]);
				visit[v[tmp][i]] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= cnt; i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(1);
	memset(visit, false, sizeof(visit));
	cout << \n;
	bfs(1);
}