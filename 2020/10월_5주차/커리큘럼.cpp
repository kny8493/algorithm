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
#define MAX 501
using namespace std;
int N;
int cls[MAX];
vector<int> v[MAX];
int num[MAX];
queue<int> q;
int result[MAX];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        num[i] = tmp;
        while (1) {
            cin >> tmp;
            if (tmp == -1) break;
            v[tmp].push_back(i);
            cls[i]++;
        }
    }
    int i;
    for (i = 1; i <= N; i++) {
        if (cls[i] == 0) {
            q.push(i);
            break;
        }
    }
    result[i] = num[i];

    while (!q.empty()) {
        int n = q.front();
        q.pop();
        for (int i = 0; i <v[n].size(); i++) {
            result[v[n][i]] = max(result[n] + num[v[n][i]], result[v[n][i]]);
            cls[v[n][i]]--;
            if (cls[v[n][i]] == 0) {
                q.push(v[n][i]);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << result[i] << "\n";
    }
    
}