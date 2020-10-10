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

int num[6];

int fibo(int x) {
    if (x == 1 || x == 0) {
        return 1;
    }
    // 이미 계산이 된거면
    if (num[x] != 0) {
        return num[x];
    }
    num[x] = fibo(x - 1) + fibo(x - 2);
    return num[x];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cout<<fibo(5);

}