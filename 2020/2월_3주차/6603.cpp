#include<vector>
#include<queue>
#include<deque>
#include<cstdio>
#define MAX 50
using namespace std;
deque<int> dq;
bool visit[MAX];
deque<int> q;
int num;
void func(int idx){
	if(q.size()==6){
		for(int i=0;i<q.size();i++){
			printf("%d ",q[i]);
		}
		printf("\n");
		return;
	}
	for(int i=idx;i<num;i++){
		q.push_back(dq[i]);
		func(i+1);
		q.pop_back();
	}

}
int main(){
	char c;
	scanf("%d",&num);
	scanf("%c",&c);
	while(num!=0){
		for(int i=0;i<num;i++){
			int tmp;
			scanf("%d",&tmp);
			scanf("%c",&c);
			dq.push_back(tmp);
		}
		func(0);
		printf("\n");
		dq.clear();
		q.clear();
		scanf("%d",&num);
	}
}
