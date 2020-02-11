#include<cstdio>
#include<algorithm>
#define MAX 51
using namespace std;

int N,M;
int num[MAX][MAX];

int main(){
	scanf("%d %d",&N,&M);
	int ans=0;
	int k=min(N,M);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%1d",&num[i][j]);
		}
	}
	int answer=1;
	
	for(int tmp=k;tmp>=1;tmp--){
		if(tmp==1){
			answer=max(answer,tmp*tmp);
			break;
		}
		for(int i=0;i<=N-tmp;i++){
			for(int j=0;j<=M-tmp;j++){
				printf("num[i][j] %d %d|| %d\n",i,j,num[i][j]);
				printf("num[i+tmp-1][j+tmp-1] || %d \n",num[i+tmp-1][j+tmp-1]);
				if((num[i][j]==num[i+tmp-1][j+tmp-1])&&(num[i][j]==num[i][j+tmp-1])&&(num[i][j]==num[i+tmp-1][j])){
					answer=max(answer,tmp*tmp);
					break;
				}
			}
		}
	}
	printf("%d",answer);
}
