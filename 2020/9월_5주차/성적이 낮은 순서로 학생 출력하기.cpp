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
using namespace std;

bool compare(pair <string,int> a, pair <string,int> b) {
	return a.second < b.second;
}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<pair<string, int>> v;
	for (int i = 0; i < N; i++) {
		string name;
		int score;
		cin >> name >> score;
		v.push_back({name, score});
	}
	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < N; i++) {
		cout << v[i].first << " ";
	}
}