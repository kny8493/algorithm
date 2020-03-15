#include<cstdio>
#include<iostream>
#include<string.h>
#define MAX 21
using namespace std;
int num[MAX][MAX];
bool ans[MAX][MAX];
int n;
int result=0;
void func(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j||i==k||j==k) {
					continue;
				}
				if(num[i][k]+num[k][j]<num[i][j]){
					result = -1;
					return;
				} else if(num[i][k]+num[k][j]==num[i][j]){
					ans[i][j]=true;
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(num, 0, sizeof(num));
	memset(ans, false, sizeof(ans));
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>num[i][j];
		}
	}
	func();
	if(result!=-1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!ans[i][j]){
					result+=num[i][j];
				}
			}
		}
	}
	if(result!=-1) result/=2;
	cout<<result;
}
