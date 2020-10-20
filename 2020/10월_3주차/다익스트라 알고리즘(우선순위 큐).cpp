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
#define MAX 100001
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 노드의 개수(N), 간선의 개수(M), 시작 노드 번호(Start)
// 노드의 개수는 최대 100,000개라고 가정
int n, m, start;
// 각 노드에 연결되어 있는 노드에 대한 정보를 담는 배열
vector<pair<int, int> > v[100001];
// 최단 거리 테이블 만들기
int ans[100001];

void func(int n) {
	priority_queue < pair<int, int>, vector<pair<int,int>>> pq;
	pq.push({ 0,n });
	ans[n] = 0;
	while (!pq.empty()) {
		int node = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (ans[now] < node) continue; //이미 연결한 적이 있는경우
		for (int j = 0; j < v[now].size(); j++) {
			int tmp = node + v[now][j].second;
			if (tmp < ans[v[now][j].first]) {
				ans[v[now][j].first] = tmp;
				pq.push({ tmp, v[now][j].first });
			}
		}

	}
}
int main(void) {
	cin >> n >> m;
	cin >> start;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });

	}
	fill(ans, ans+ 100001, INF);

	func(start);

	for (int i = 1; i <= n; i++) {
		if (ans[i] == MAX) { cout << "INF" << "\n"; }
		else { cout << ans[i] << "\n"; }
	}
}