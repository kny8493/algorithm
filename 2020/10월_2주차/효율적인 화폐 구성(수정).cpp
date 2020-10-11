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

using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int num[MAX];
    int N, M;
    int ans = 0;
    vector<int> v;

    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        num[i] = 10001;
    }
    num[0] = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        for (int j = v[i]; j <= M; j++) {
            if (num[j - v[i]] != MAX) {
                num[j] = min(num[j], num[j - v[i]] + 1);
            }
        }
    }
    int answer = num[M] == MAX ? -1 : num[M];
    cout << answer;
}