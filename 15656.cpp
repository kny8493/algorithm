#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int N,M;
vector<int> v;
vector<int> newv;
void fun(int idx){
	if(newv.size()==M){
		for(int i=0;i<newv.size();i++){
			printf("%d ",newv[i]);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<N;i++){
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
