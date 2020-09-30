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
using namespace std;

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int num[] = { 7,5,9,0,3,1,6,2,4,8,0,5,2};
	int ans[13] = {0,};
	// 계수 정렬
	for (int i = 0; i < 13; i++) {
		ans[num[i]]++;
	}
	for (int i = 0; i < 10; i++) {
		if (ans[i] > 0) {
			while (ans[i]--) {
				cout << i << " ";
			}
		}
	}

}