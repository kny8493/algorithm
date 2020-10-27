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
int team[MAX];
int findParent(int x) {
    if (team[x] == x) return x;
    return team[x] = findParent(team[x]);
}
void unionFunc(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (team[a] > team[b]) team[a]=b;
    else team[b] = a;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        team[i] = i;
    }
    for (int i = 0; i < M; i++) {
        int flag, a, b;
        cin >> flag >> a >> b;
        
        // union 연산
        if (flag==0) {
            unionFunc(a, b);
        }
        // find 연산
        else {
            if (findParent(b) == findParent(a)) { cout << "YES\n"; }
            else { cout << "NO\n"; }
        }
    }
}