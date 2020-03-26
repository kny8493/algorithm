#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll num[100001];
ll N,M;
int main(){
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	ll max=0;
	for(ll i=0;i<N;i++){
		cin>>num[i];
		if(max<num[i]){
			max=num[i];
		}
	}
	
	ll left=0;
	ll right=max*M;
	ll result=max*M;
	while(left<=right){
		ll mid=(left+right)/2;
		ll tmp=0;
		for(ll i=0;i<N;i++){
			tmp+=(mid/num[i]);
		}
		if(tmp<M){
			left=mid+1;
		} else {
			right = mid-1;
			if(result>mid){
				result=mid;
			}
		}
		
	}
	cout<<result;
}

