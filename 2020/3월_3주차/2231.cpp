#include<cstdio>
#include<algorithm>
#include<iostream>
#include<vector>
#define MAX 1000000
using namespace std;

int N;
int answer=0;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	
	for(int i=1;i<=MAX;i++){
		int tmp = i;
		int cnt = i;
		while(tmp!=0) {
			int funT=tmp%10;
			cnt+=funT;
			tmp/=10;
		}
		if(cnt== N) {
			answer = i;
			break;
		} 
	}
	cout<<answer<<endl;
}
