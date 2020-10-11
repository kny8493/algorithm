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

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	vector<string> str;
	string target;
	int ans;
	cin >> num >> target;

	for (int i = 0; i < num; i++) {
		string strTmp;
		cin >> strTmp;
		str.push_back(strTmp);
	}
	for (ans = 0; ans < num; ans++) {
		if (str[ans] == target) {
			break;
		}
	}
	cout << ans+1;
}