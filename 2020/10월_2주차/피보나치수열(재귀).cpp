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

int fibo(int x) {
    if (x == 0 || x == 1) {
        return 1;
    }
    return fibo(x - 1) + fibo(x - 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int num[6];
    memset(num,sizeof(num), 0);
    
    cout<<fibo(5);
}