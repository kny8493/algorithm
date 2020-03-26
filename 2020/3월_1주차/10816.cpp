#include<algorithm>
#include<stdio.h>
#include<vector>
#include<iostream>
#define MAX 500001
using namespace std;
vector<int> sangnum;
vector<int> target;
int ans[MAX];
int N,M;
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		int tmp;
		cin>>tmp;
		sangnum.push_back(tmp);
	}
	sort(sangnum.begin(), sangnum.end());
	
	cin>>M;
	for(int i=0;i<M;i++){
		int tmp;
		cin>>tmp;
		target.push_back(tmp);
		
	}
	
	for(int i=0;i<M;i++){
		int cnt=0;
		cnt=upper_bound(sangnum.begin(),sangnum.end(),target[i])-lower_bound(sangnum.begin(),sangnum.end(),target[i]);
	
		cout<<cnt<<" ";
	}
}
