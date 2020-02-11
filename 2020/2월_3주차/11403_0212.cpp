#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
int a[101][101];
int N;
void print(){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}

}
void func(){
	for(int k=1;k<=N;k++){
		for(int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(a[i][k]==1&&a[k][j]==1){
					a[i][j]=1;
				}
			}
		}
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>N;
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin>>a[i][j];
		}
	}
	func();
	print();
	
}
