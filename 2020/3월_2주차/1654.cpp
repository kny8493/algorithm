#include<algorithm>
#include<cstdio>
#include<iostream>
#define ll long long
#define MAX 10001
using namespace std;
int K,N;
ll num[MAX];
int answer;

int check(ll left, ll right){
	ll mid = (left+right)/2;
	int total=0;
	for(int i=0;i<K;i++){
		total+=num[i]/mid;
	}
	if(left>=right){
		return answer;
	}
		
	if(total>=N){
		answer=mid;
	} 
	
	if(total<N){
		 return check(left, mid-1);
	} else {
		if(mid>answer){
			answer=mid;
		}
		return check(mid+1, right);
	}
}

int main(){
	ios_base::sync_with_stdio();
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>K>>N;
	ll left=1;
	ll right=0;
	for(int i=0;i<K;i++){
		cin>>num[i];
		right = max(right, num[i]);
	}
	cout<<check(left,right);
}

