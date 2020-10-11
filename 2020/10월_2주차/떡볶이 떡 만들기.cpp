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
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt;
	int etc;
	vector<int> rice;
	cin >> cnt >> etc;
	for (int i = 0; i < cnt; i++) {
		int tmp;
		cin >> tmp;
		rice.push_back(tmp);
	}
	int left, right;
	sort(rice.begin(), rice.end());
	left = 0;
	right = rice.back();
	int ans, mid;

	while (left < right) {
		ans = 0;
		mid = (left + right) / 2;
		for (int i = 0; i < cnt; i++) {
			int tmp = rice[i] - mid < 0 ? 0 : rice[i] - mid;
			ans += tmp;
		}
		if (ans == etc)  break;
		else if (ans < etc) {
			right = mid - 1;
		}
		else {
			// 적어도 M만큼의 떡을 얻기 위해
			result = mid;
			left = mid + 1;
		}
	}
	cout << result;

}