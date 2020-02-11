#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
using namespace std;
vector<int> a[1001];
queue<int> q;
int ans=0;
bool visit[1001];
int N,M;
void dfs(int idx){
	visit[idx]=true;
	for(int i=0;i<a[idx].size();i++){
		if(!visit[a[idx][i]]) {
			dfs(a[idx][i]);
		}
	}
	
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<M;i++){
		int tmpA,tmpB;
		scanf("%d %d",&tmpA,&tmpB);
		a[tmpA].push_back(tmpB);
		a[tmpB].push_back(tmpA);	
	}
	int i=1;
	for(int i=1;i<=N;i++){
		if(!visit[i]){
			ans++;
			dfs(i);
		}
	}
	printf("%d",ans);
}
