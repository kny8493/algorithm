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
#define MAX 10001
#define INF 1e9 


using namespace std;

int N, cnt, start;
vector<pair<int, int>> v[MAX];
bool visit[MAX];
int ans[MAX];
int findSmallN() {
    int tmpN = INF; // 가장 작은 수
    int index; // 가장 작은 수 index
    for (int i = 1; i <= N; i++) {
        if (ans[i] < tmpN && !visit[i]) {
            tmpN = ans[i];
            index = i;
        }
    }
    return index;
}
void func(int n) {
    visit[n] = true;
    // 배열 초기화
    for (int i = 0; i < v[n].size(); i++) {
        ans[v[n][i].first] = v[n][i].second;
    }
    // 노드들 중에서 가장 작은수 선택
    int smallN = findSmallN();

    for (int i = 0; i < N - 1; i++) {
        visit[smallN] = true;
        for (int j = 0; j < v[smallN].size(); j++) {
            ans[v[smallN][j].first] = min(ans[v[smallN][j].first], ans[smallN] + v[smallN][j].second);
        }
        smallN = findSmallN();
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // 배열 가장 큰수로 초기화
    fill_n(ans, MAX, INF);
    
    cin >> N >> cnt >> start;
    ans[start] = 0;

    for (int i = 0; i < cnt; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }

    func(start);
    for (int i = 1; i <= N; i++) {
        cout << ans[i]<<"\n;
    }

}