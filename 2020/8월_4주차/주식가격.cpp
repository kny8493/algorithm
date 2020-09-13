#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> p) {
    vector<int> answer;
    for (int i = 0; i < p.size(); i++) {
        int tmp = 0;
        for (int j = i + 1; j < p.size(); j++) {
            tmp++;
            if (p[i] > p[j]) break;
        }
        answer.push_back(tmp);
    }
    return answer;
}