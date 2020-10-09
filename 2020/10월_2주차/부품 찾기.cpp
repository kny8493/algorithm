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
int tot, cnt;
vector<int> num;
vector<int> findNum;

int search(int left, int right, int target) {
	if (left > right) return -1;
	int mid = (left + right) / 2;
	if (target == num[mid]) return mid;
	else if (target > num[mid]) return search(mid + 1, right, target);
	else return search(left, mid - 1, target);
}
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> tot;
	for (int i = 0; i < tot; i++) {
		int tmp;
		cin >> tmp;
		num.push_back(tmp);
	}
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		int tmp;
		cin >> tmp;
		findNum.push_back(tmp);
	}

	sort(num.begin(), num.end());
	for (int i = 0; i < cnt; i++) {
		int tmp = search(0, tot - 1, findNum[i]);
		if (tmp == -1) {
			cout << "no ";
		}
		else {
			cout << "yes ";
		}
	}

}