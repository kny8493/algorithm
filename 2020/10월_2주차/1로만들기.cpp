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
// 0부터 시작해서 6 번째 숫자 구하기
int num[MAX];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    num[1] = 1;
    int N;
    cin >> N;
    num[0] = MAX;
    for (int i = 2; i <= N; i++) {
        int a= 0, b= 0, c= 0;

        if (i % 5 == 0) {
            a = i / 5;
        }
        if (i % 3 == 0) {
            b = i / 3;
        }
        if (i % 2 == 0) {
            c = i / 2;
        }
        int tmpA = min(num[i - 1], num[a]);
        int tmpB = min(num[b], num[c]);
        num[i] = i==2 || i==3 || i==5?min(tmpA, tmpB):min(tmpA, tmpB) + 1;
    }
    cout << num[N];

}