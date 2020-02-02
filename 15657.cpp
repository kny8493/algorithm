#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
vector<int> v;
vector<int> newv;
int N,M;
void fun(int idx){
	if(newv.size()==M){
		for(int i=0;i<M;i++){
			printf("%d ",newv[i]);
		}
		printf("\n");
		return;
	}
	for(int i=idx;i<N;i++){
		newv.push_back(v[i]);
		fun(i);
		newv.pop_back();
	}
}
int main(){
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		int tmp;
		char c;
		scanf("%d",&tmp);
		scanf("%c",&c);
		v.push_back(tmp);
	}
	sort(v.begin(),v.end());
	fun(0);
}
