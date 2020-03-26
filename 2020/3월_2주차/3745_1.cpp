#include<algorithm>
#include<vector>
#include<cstdio>
#include<iostream>
using namespace std;
int N;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(cin>>N){
		vector<int> v;
		for(int i=0;i<N;i++){
			int tmp;
			cin>>tmp;
			int idx=lower_bound(v.begin(),v.end(),tmp)-v.begin();
			if((int)v.size()==idx)v.push_back(tmp);
			else if(v[idx]>tmp) v[idx]=tmp;
		}
		cout<<v.size()<<endl;
	}
    return 0;
}
