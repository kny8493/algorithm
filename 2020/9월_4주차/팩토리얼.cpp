#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
int answer = 0;
int factorial(int n) {
	// n = 1 인경우 재귀함수 멈춤
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	cin >> num;
	
	cout<<factorial(num);
	
}