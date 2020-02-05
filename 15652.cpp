#include<cstdio>
#include<deque>
using namespace std;
int N,M;
deque<int> dq;
void func(int idx){
	if(dq.size()==M){
		for(int i=0;i<dq.size();i++){
			printf("%d ",dq[i]);
		}
		printf("\n");
		return;
	}
	for(int i=idx;i<=N;i++){
		dq.push_back(i);
		func(i);
		dq.pop_back();
	}
}
int main(){
	scanf("%d %d",&N,&M);
	func(1);
}
