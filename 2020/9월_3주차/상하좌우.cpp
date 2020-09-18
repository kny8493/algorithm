#include<iostream>
#include<cstdio>  
#include<string>
using namespace std;
// 공간 벗어나면 무시
// L -> left
// R
// U
// D


int N;
string str;
int main() {
	cin >> N;
	cin.ignore();
	getline(cin, str);
	int row = 1, col = 1;
	
	for (int i = 0; i < str.size(); i ++) {
		char tmp = str[i];
		switch (tmp){
		case 'L':
			if (col - 1 < 1)  break;
			col --;
			break;
		case 'R' :
			if (col + 1 > N) break;
			col++;
			break;
		case 'U':
			if (row - 1 < 1) break;
			row--;
			break;
		case 'D':
			if (row + 1 > N) break;
			row++;
			break;
		}
	}
	cout << row << " "<<col;
	return 0;

}