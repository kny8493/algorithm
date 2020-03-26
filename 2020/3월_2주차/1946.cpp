#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100001
using namespace std;
int N;
void func(){
	int M;
	int cnt=0;
	pair<int, int> num[MAX];
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>num[i].first>>num[i].second;
	}
	sort(num,num+M);
	cnt++;
	int second=num[0].second;
	for(int i=1;i<M;i++){
		if(num[i].second<second){
			second=num[i].second;
			cnt++;
		}
	} 
	cout<<cnt<<endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		func();
	}
}
