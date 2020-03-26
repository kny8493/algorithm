#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<deque>
using namespace std;
bool visit[9];
int N,M;
deque<int> dq;
int cnt=0;
void sol(int idx){
	if(dq.size()==M){
		for(int i=0;i<dq.size();i++){
			printf("%d ",dq[i]);
		}
		printf("\n");
		return;
	}
	for(int i=idx+1;i<=N;i++){
		dq.push_back(i);
		sol(i);
		dq.pop_back();
	}
}

int main(){
	scanf("%d %d",&N,&M);

	sol(0);
}
