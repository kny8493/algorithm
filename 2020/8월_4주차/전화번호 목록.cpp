#include <string>
#include <vector>
#define MAX 999999
#include<iostream>
#include<cstdio>
using namespace std;

// � ��ȣ�� �ٸ� ��ȣ�� ���λ翡 ������ false������ true
bool solution(vector<string> p) {
    bool answer = true;

    for (int i = 0; i < p.size(); i++) {
        string tmpS = p[i];
        for (int j = 0; j < p.size(); j++) {
            if (i == j) continue;
            string comS = p[j].substr(0, tmpS.length());
            if (tmpS == comS) {
                return false;
            }
        }
    }
    return answer;
}