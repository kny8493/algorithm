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
vector<pair< int, pair<int, int>>> v;
int num[MAX];
int N, M;
int findParent(int a) {
    if (num[a] == a) return a;
    num[a] = findParent(num[a]);
}
void unionFInd(int a, int b) {
    a = findParent( a);
    b = findParent(b);
    if (a > b) {
        num[a] = b;
    }
    else {
        num[b] = a;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
       
        v.push_back({ c, {a,b} });
    }
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        num[i] = i;
    }


    for (int i = 0; i < M; i++) {
        int a = v[i].second.first;
        int b = v[i].second.second;
        int c = v[i].first;

        if (findParent(a)!=findParent(b)) {
            unionFInd(a, b);
            sum += c;
        }
    }
    cout << sum << endl;
}