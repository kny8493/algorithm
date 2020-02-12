#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;
int N,M;
int ans=-1;
bool visit[MAX];
vector<int> v[MAX];
void dfs(int idx){
	visit[idx]=true;
	ans++;
	for(int i=0;i<v[idx].size();i++){
		if(!visit[v[idx][i]]){
			dfs(v[idx][i]);
		}
	}
	
}
int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	printf("%d",ans);
}
