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
using namespace std;
void quickSort(int* arr, int start, int end) {
    if (start >= end) return; // 원소가 1개인 경우 종료
    int pivot = start; // 피벗은 첫 번째 원소
    int left = start + 1;
    int right = end;
    while (left <= right) {
        // 피벗보다 큰 데이터를 찾을 때까지 반복
        while (left <= end && arr[left] <= arr[pivot]) left++;
        // 피벗보다 작은 데이터를 찾을 때까지 반복
        while (right > start && arr[right] >= arr[pivot]) right--;
        // 엇갈렸다면 작은 데이터와 피벗을 교체
        if (left > right) swap(arr[pivot], arr[right]);
        // 엇갈리지 않았다면 작은 데이터와 큰 데이터를 교체
        else swap(arr[left], arr[right]);
    }
    // 분할 이후 왼쪽 부분과 오른쪽 부분에서 각각 정렬 수행
    quickSort(arr, start, right - 1);
    quickSort(arr, right + 1, end);
}

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int num[] = { 7,5,9,0,3,1,6,2,4,8 };
	// 퀵 정렬
	// 라이브러리 이용
	// sort(num, num + 10);
	// 일반 구현
	quickSort(num, 0, 9);
	for (int i = 0; i < 10; i++) {
		cout << num[i] << " ";
	}

}