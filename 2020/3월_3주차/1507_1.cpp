#include<algorithm>
#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#define MAX 20
using namespace std;
int num[MAX][MAX];
bool check[MAX][MAX];
int n;
int result=0;
void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==k||i==j||j==k) continue;
				if(num[i][k]+num[k][j]<num[i][j]){
					result = -1;
					return;
				} 
				else if( num[i][k]+num[k][j]==num[i][j] ){
					check[i][j]=true;
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	memset(num,0,sizeof(num));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>num[i][j];
		}
	}
	floyd();
	if(result!=-1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(!check[i][j]) {
					result += num[i][j];
				}
			}
		}
		result/=2;
	}
	cout<<result<<endl;
	
}
