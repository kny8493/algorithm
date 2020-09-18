#include <stdio.h>
#include <string>
#include <iostream>
#include<stdlib.h>
using namespace std;

int main() {
	int n;
	string str;
	int x = 1, y = 1;
	// L R U D 에 따른 이동 방향
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { -1,1,0,0 };
	char type[4] = { 'L','R','U','D' };

	// 입력 받기
	cin >> n;
	cin.ignore();
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		char tmp = str[i]; 
		// 이동 후 좌표 (공백일 경우도 있기 때문에)
		int nx = 0, ny = 0;
		
		for (int j = 0; j < 4; j++) {
			// 공백이 아닐 경우에
			if (tmp == type[j]) {
				nx = x + dx[j];
				ny = y + dy[j];
			}
		}
		// 공간을 벗어나는 경우 무시 + 공백인 경우 무시
		if (nx<1 || ny<1 || nx>n || ny>n) continue;
		// 이동
		x = nx;
		y = ny;
	}
	cout << x << " " << y << "\n";

	return 0;
}