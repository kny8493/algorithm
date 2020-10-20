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
#define MAX 100001
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

int parent[MAX];
int V, E;
int findParent(int num) {
	if (num == parent[num]) return num;
	return parent[num] = findParent(parent[num]);
}
void func(int a, int b) {
	a = findParent(a);
	b = findParent(b);
	if (a > b) parent[a] = b;
	else parent[b] = a;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V >> E;
	bool check;
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		if (findParent(a) == findParent(b)) {
			check = false;
		}
		else {
		func(a, b);
		}
	}
	if (check) {
		cout << "사이클 없음";
	}
	else {
		cout << "사이클 있음";
	}

}