#include <stdio.h>
#include <string>
#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int x, y;
	int ans = 0;
	x = s[0]-96;
	y = s[1]-48;

	int step[8][2] = { {1,-2},{-1,-2}, {1,2},{-1,2},{2,1},{2,-1},{-2,1},{-2,-1} };
	
	for (int i = 0; i < 8; i++) {
		int tmpA = step[i][0];
		int tmpB = step[i][1];
		if (x + tmpA > 8 || x + tmpA < 1 || y + tmpB>8 || y + tmpB < 1) continue;
		ans++;
	}
	cout << ans;
	return 0;

}