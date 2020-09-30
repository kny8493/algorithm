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

int numA[MAX];
int numB[MAX];
int N, K;
int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> numA[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> numB[i];
	}

	sort(numA, numA + N);
	sort(numB, numB + N, greater<int>());
	int sum = 0;
	for (int i = 0;i< N; i++) {
		i < K ? sum += numB[i] : sum += numA[i];
	}
	cout << sum;
}