#include<vector>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<string>
#define MAX 1001
#include<iostream>
#include<cstdlib>
#include<memory.h>
using namespace std;
vector<int> v[MAX];
queue<int> q;
int N,M,start;
bool visit[MAX];
void dfs(int s){
	visit[s]=true;
	printf("%d ",s);
	for(int i=0;i<v[s].size();i++){
		if(!visit[v[s][i]]){
			dfs(v[s][i]);
		}
	}
}
void bfs(int s){
	q.push(s);
	visit[s]=true;
	while(!q.empty()){
		int tmp=q.front();
		printf("%d ",tmp);
		q.pop();
		for(int i=0;i<v[tmp].size();i++){
			if(!visit[v[tmp][i]]){			
				q.push(v[tmp][i]);
				visit[v[tmp][i]]=true;
			}
		}
	}
}
int main(){
	scanf("%d %d %d",&N,&M,&start);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=N;i++){
		sort(v[i].begin(),v[i].end());
	}
	dfs(start);
	printf("\n");
	memset(visit,0,sizeof(visit));
	bfs(start);
}
