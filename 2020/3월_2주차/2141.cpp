#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#define MAX 1000000001
#define ll long long
using namespace std;
int N;
int ans;
vector<pair<ll, ll>> v;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N;
	ll sum=0;
	ll manTemp=0;
	ll helf;
	for(int i=0;i<N;i++){
		ll tmpa,tmpb;
		cin>>tmpa>>tmpb;
		v.push_back({tmpa,tmpb});
		sum+=tmpb;
	}
	
	if(sum%2==1) {
		helf=sum/2+1;
	} else {
		helf=sum/2;
	}
	
	sort(v.begin(),v.end());

	for(int i=0;i<N;i++){
		manTemp+=v[i].second;
		if(manTemp>=helf){
			ans=i;
			break;
		}
	}
	cout<<v[ans].first;
}

