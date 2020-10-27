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
using namespace std;
int N, M;
vector<pair<int, pair<int, int>>> v;
int sum;
int parent[MAX];
int findParent(int x) {
    if (x == parent[x]) return x;
    return parent[x] = findParent(parent[x]);
}
void unionFunc(int a, int b) {
     a = findParent(a);
    b = findParent(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({ c, {a,b} });
    }
    sort(v.begin(), v.end());
    int tmp;
    for (int i = 0; i < v.size(); i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        int c = v[i].first;
        // 사이클이 아닌 경우
        if (findParent(a) != findParent(b)) {
            unionFunc(a, b);
            sum += c;
            tmp = c;
        }
    }
    cout << sum - tmp;
}