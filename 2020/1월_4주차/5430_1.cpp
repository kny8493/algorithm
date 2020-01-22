#include<cstdio>
#include<iostream>
#include<deque>
#include<string>

using namespace std;

void func(){
	string ans;
	bool check=false;
	string ac;
	cin>>ac;
	int len;
	cin>>len;
	string str;
	cin>>str;
	deque<int> dq;
	string tmp;
	for(int i=0;i<str.length();i++){
		if(str[i]=='[') {
			continue;
		}
		else if(str[i]==','||str[i]==']'&&tmp!=""){
			dq.push_back(stoi(tmp));
			tmp="";
		}else {
			tmp+=str[i];
		}
	}
	int i;
	for(i=0;i<ac.length();i++){
		if(ac[i]=='D'){
			if(dq.empty()){
				ans="error";
				break;
			}
			if(check==false){			
				dq.pop_front();
			}else {
				dq.pop_back();
			}
		}
		else if(i<ac.length()-1){
			string tmpAC="";
			tmpAC+=ac[i];
			tmpAC+=ac[i+1];
			if(tmpAC=="RR") {
				i++;
				continue;
			}
		}
		if(ac[i]=='R'){
			check=!check;
		}
	}
	if(i<ac.length()){
		cout<<ans<<endl;
	}
	else{
		ans+="[";
		if(check==true){
			for(int i=dq.size()-1;i>=0;i--){
				ans+=to_string(dq[i]);
				if(i!=0){
					ans+=",";
				}
			}
		}
		else{
			for(int i=0;i<dq.size();i++){
				ans+=to_string(dq[i]);
				if(i!=dq.size()-1){
					ans+=",";
				}
			}
		}
		ans+="]";
		cout<<ans<<endl;
	}

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int cnt;
	cin>>cnt;
	for(int i=0;i<cnt;i++){
		func();
	}
}
