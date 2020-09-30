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
	int num[] = { 7,5,9,0,3,1,6,2,4,8 };
	// 삽입 정렬
	for (int i = 1; i < 10; i++) {
		for (int j = i; j>0; j--) {
			if (num[j] < num[j - 1]) {
				swap(num[j], num[j - 1]);
			}
			else {
				break;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << num[i] << " ";
	}

}