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
#define MAX 300001
using namespace std;
int N, M;
vector<int> v[MAX];
int num[MAX];
queue<int> q;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin>>a >> b;
        v[a].push_back(b);
        num[b]++;
    }
    int i = 1;
    for (i = 1; i <= N; i++) {
        if (num[i] == 0) break;
    }
    q.push(i);
    while (!q.empty()) {
        int idx = q.front();
        q.pop();
        cout << idx << " ";
        for (int j = 0; j < v[idx].size(); j++) {
            num[v[idx][j]]--;
            if (!num[v[idx][j]]) {
                q.push(v[idx][j]);
            }
        }
    }


}