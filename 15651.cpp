#include<cstdio>
#include<deque>
using namespace std;

int N,M;
deque<int> dq;
void fun(int idx){
	if(dq.size()==M){
		for(int i=0;i<dq.size();i++){
			printf("%d ",dq[i]);
		}
		printf("\n");
		return;
	}
	for(int i=1;i<=N;i++){
		dq.push_back(i);
		fun(i);
		dq.pop_back();
	}
}
int main(){
	scanf("%d %d",&N,&M);
	fun(0);
}
