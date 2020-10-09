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

int cnt;
vector<int> num;
int target;

int func(int left, int right) {
	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (num[mid] == target) {
		return mid;
	}
	else if (num[mid] > target) {
		return func(left, mid - 1);
	}
	else {
		return func(mid + 1, right);
	}

}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> cnt >> target;
	for (int i = 0; i < cnt; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	int ans = func(0, cnt-1);
	if (ans == -1) {
		cout << "원소가 존재하지 않습니다.";
		return 0;
	}
	cout << ans+1;

}