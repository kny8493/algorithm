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
#define MAX 1001
#define MAXCITY 300001
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;
int N, M,C;
vector<pair<int, int> > v[MAXCITY];
int ans[MAXCITY];
int cnt, tot;

void func(int n) {
	priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

	pq.push({ 0, n });
	ans[n] = 0;
	while (!pq.empty()) {
		int tmpValue = pq.top().first;
		int tmpNode = pq.top().second;

		pq.pop();
		if (tmpValue > ans[tmpNode]) continue;

		for (int i = 0; i < v[tmpNode].size(); i++) {
			int tmp = tmpValue + v[tmpNode][i].second;
			// 돌아가는게 더 빠른 경우
			if (tmp < ans[v[tmpNode][i].first]) {
				ans[v[tmpNode][i].first] = tmp;
				pq.push({ tmp, v[tmpNode][i].first });
			}

		}

	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> C;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b, c });
	}

	fill(ans, ans+MAXCITY, 1001);

	func(C);
	for (int i = 1; i <= N; i++) {
		if (ans[i] == 1001) continue;
		cnt++;
		tot = max(tot, ans[i]);
	}
	cout << cnt-1<<" " << tot;

}