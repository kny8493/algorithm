#include<algorithm>
#include<cstdio>
#include<iostream>
#include<queue>
#define MAX 10001
using namespace std;
int N,L,P,result,idx;
pair<int, int> a[MAX];
priority_queue<int> pq;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>a[i].first>>a[i].second;
	}
	cin>>L>>P;
	
	sort(a, a+N);

	while(P<L) {
		while(a[idx].first<=P) {
			if(idx == N)break;
			pq.push(a[idx].second);
			idx++;
		}
		if(!pq.size())break;
		result++;
		P+=pq.top();
		pq.pop();
	}
	result = P<L?-1:result;
	cout<<result<<endl;
	return 0;
}
