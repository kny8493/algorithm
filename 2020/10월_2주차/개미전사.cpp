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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<int> v;
    int ans[1001];
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        if (i < 2) {
            ans[i] = v[i];
            continue;
        }

        ans[i] = max(ans[i - 1], ans[i - 2] + v[i]);
    }

    cout << ans[N - 1];
}