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
// 0부터 시작해서 6 번째 숫자 구하기
int num[6];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    num[0] = 1;
    num[1] = 1;

    for (int i = 2; i <= 6; i++) {
        num[i] = num[i - 1] + num[i - 2];
    }
    cout << num[5];
}