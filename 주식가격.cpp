#include <string>
#include <vector>
#include<iostream>
#include<stdio.h>
using namespace std;
//입력 : [ 1, 2, 3, 2, 3, 1 ]
//출력 : [ 5, 4, 1, 2, 1, 0 ]
int main() {
	vector<int> prices{1,2,3,2,3,1};
    vector<int> answer;
    for(int i=0;i<prices.size();i++){
    	int chk = 0;
    	for(int j=i+1;j<prices.size();j++){
    		 if(prices[j]<prices[i]) {
    		 	chk++;
    		 	break;
			 }
		}
		if(chk == 0) answer.push_back(prices.size()-i-1);
        else answer.push_back(chk);
	} 
    for(int i=0;i<answer.size();i++){
    	cout<<answer[i]<<" ";
	}
}