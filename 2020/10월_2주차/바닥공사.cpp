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

#define MOX 796796
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int num[MAX];
    cin >> N;
    num[1] = 1;
    num[2] = 3;
    for(int i = 3; i <= N; i++) {
        num[i] = num[i - 1] + (num[i - 2] * 2);
    }
    cout << num[N];
}