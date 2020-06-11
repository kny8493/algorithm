#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
#include<algorithm>
#include<unordered_set>
#define MAX 8
using namespace std;
int solution(int N,int number){
	int answer=EOF;
	int tmp=0;
	unordered_set<int> num[MAX];
	for(int i=0;i<MAX;i++){
		tmp=10*tmp+1;
		num[i].insert(tmp*N);
	
	}
	for(int i=1;i<MAX;i++){
		for(int j=0;j<i;j++){
			for(auto a:num[j]){
				for(auto b:num[i-j-1]){
					num[i].insert(a+b);
					num[i].insert(a-b);
					num[i].insert(a*b);
					if(b!=0) {
						num[i].insert(a/b);
					}
				}
			}
		}	
		if(num[i].count(number)>0){
			answer=i+1;
			break;
		}
	}
	return answer;
}
int main(){
	int N=2;
	int number=11;
	int answer=solution(N,number);
	cout<<answer<<"\n";
	
}
