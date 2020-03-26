#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 500001

using namespace std;
int N,M;
int A[MAX];
int B[MAX];
int ans[MAX];
int func(int idx,int left, int right){
	if(left>right) return -1;
	int mid = (left+right)/2;
	if(B[idx]==A[mid]){
		ans[idx]=1;
		return 0;
	} else if(A[mid]>B[idx]) {
		return func(idx,left, mid-1);;
	} else {
		return func(idx, mid+1, right);
	}
	
}
int main(){
	ios_base::sync_with_stdio();
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>B[i];
	}
	sort(A,A+N);
	
	for(int i=0;i<M;i++){
		int tmp = func(i,0,N-1);
	}
	for(int i=0;i<M;i++){
		cout<<ans[i]<<" ";
	}
}
