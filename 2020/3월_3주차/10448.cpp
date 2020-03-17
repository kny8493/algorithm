#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int cnt, num, ans;
int math(int i){
	return i*(i+1)/2;
}
int func(){
	cin >>num;
	int tmp=num/2;
	for(int i=1;i<=tmp;i++){
		for(int j=1;j<=tmp;j++){
			for(int k=1;k<=tmp;k++){
				if(math(i)+math(j)+math(k)==num) return 1;
			}
		}
	}
	return 0;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>cnt;
	for(int i=0;i<cnt;i++){
		cout<<func()<<endl;
	}
}

