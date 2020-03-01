#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
#include<iostream>
#define long long ll
#define MAX 500001
using namespace std;
int N,M; //N 상근이의 숫자 갯수, M 입력받을 숫자 갯 수 
int input[MAX];
int num[MAX];
int ans[MAX];
int check(int idx,int target, int left, int right){
	
	if (left>right) return -1;

	int p = (left+right)/2;
	if(num[p] == target){
		ans[idx]=1;
		return 0;
	} else if( num[p] > target) {
		return check(idx,target, left, p-1);

	} else {
		return check(idx,target, p+1, right);

	}
}

void put(){
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>num[i];
	}
	
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>input[i];
	}
	sort(num, num+N);
		
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	put();
	int tmp;
	for(int i=0;i<M;i++){
		tmp=check(i,input[i],0,N-1);
	}
	
	for(int i=0;i<M;i++){
		cout<<ans[i]<<" ";
	}
	
}

