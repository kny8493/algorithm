#include <string>
#include <vector>
#include<unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;
    for (int i = 0; i < clothes.size(); i++) {
        m[clothes[i][1]]++;
    }

    unordered_map<string, int>::iterator iter;
    for (iter = m.begin(); iter != m.end(); iter++) {
        answer = answer * (iter->second + 1);
    }
    return answer - 1;
}