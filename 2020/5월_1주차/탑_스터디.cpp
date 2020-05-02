#include <string>
#include <vector>
#include<stack>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {
	vector<int> heights {7,5,3,5,3,5,3};
    int len = heights.size();
    vector<int> answer;
    deque <int> dq;
    for(int i=0;i<len;i++){
    	dq.push_front(heights[i]);
    }
    while(!dq.empty()) {
    	len--;
    	int ans=0;
        int tmp = dq.front();
        dq.pop_front();
       for(int i=len-1;i>=0;i--){
           if(heights[i]>tmp) {
			ans=i+1;
			break;
           }
       }
       answer.push_back(ans);
    }
    reverse(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++){
    	cout<<answer.at(i)<<endl;
	}
}
