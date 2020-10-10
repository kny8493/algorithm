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

vector<int> solution(vector<vector<int> > v) {
	vector<int> ans;
	int x, y;

	if (v[0][0] == v[1][0]) {
		y = v[0][1] + v[1][1] - v[2][1];
		x = v[2][0];
	}
	else if (v[0][1] == v[1][1]) {
		x = v[0][0] + v[1][0] - v[2][0];
		y = v[2][1];
	}
	else {
		x = v[0][0] + v[1][0] - v[2][0];
		y = v[0][1] + v[1][1] - v[2][1];
	}
	ans.push_back(x);
	ans.push_back(y);

	return ans;
}
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int> > v={ {1,4}, {3,4},{3,10} };
	solution(v);

}