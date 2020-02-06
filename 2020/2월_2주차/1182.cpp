#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int N,S;
vector<int> v;
int ans=0;

void func(int idx,int sum){
	if(idx==N){
		if(sum==S){
			ans++;
		}
		return;
	}
	func(idx+1,sum+v[idx]);
	func(idx+1,sum);
	
}
int main(){
	scanf("%d %d",&N,&S);
	for(int i=0;i<N;i++){
		int tmp;
		int c;
		scanf("%d",&tmp);
		scanf("%c",&c);
		v.push_back(tmp);
	}
	func(0,0);
	if(S==0){
		ans--;
	}
	printf("%d",ans);
}
