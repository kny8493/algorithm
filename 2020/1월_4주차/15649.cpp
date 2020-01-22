#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int N,M;
vector<int> v;
bool visit[10];
void back(int cnt){
	if(cnt==M){
		for(int i=0;i<v.size();i++){
			printf("%d ",v[i]);
		}
        printf("\n");
		return;
	}
	for(int i=1;i<=N;i++){
		if(!visit[i]){
			visit[i]=true;
			v.push_back(i);
			back(cnt+1);
			visit[i]=false;
			v.pop_back();
		}
	}
}
int main(){
    scanf("%d %d",&N,&M);
	back(0);
}
