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
int num[MAX];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 2; i <= N; i++) {
        num[i] = num[i - 1] + 1;

        if (i % 5 == 0) {
            num[i] = min(num[i], num[i / 5] + 1);
        }
        if (i % 3 == 0) {
            num[i] = min(num[i], num[i / 3] + 1);
        }
        if (i % 2 == 0) {
            num[i] = min(num[i], num[i / 2] + 1);
        }
    }
    cout << num[N];

}