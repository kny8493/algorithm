#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector <int> v;
int sum=0;

void printAns(int i,int j){
	for(int k=0;k<9;k++){
		if(k==i||j==k) continue;
		printf("%d\n",v[k]);
	}
}
void func(){
	for(int i=0;i<8;i++){
		for(int j=i;j<9;j++){
			if(v[i]+v[j]==sum){
				printAns(i,j);
				return;
			}
		}
	}
}

int main(){
	for(int i=0;i<9;i++){
		int tmp;
		scanf("%d",&tmp);
		v.push_back(tmp);
		sum+=tmp;
	}
	sort(v.begin(),v.end());
	sum=sum-100;
	func();
}
