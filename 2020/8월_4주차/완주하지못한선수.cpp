#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> p, vector<string> c) {
    string answer = "";
    unordered_map<string, int> m;
    vector<string>::iterator iter;
    for (iter = c.begin(); iter != c.end(); iter++) {
        m.insert({ *iter,0 });
        m.find(*iter)->second++;
    }
    for (iter = p.begin(); iter != p.end(); iter++) {
        if (m.count(*iter) == 0) {
            answer = *iter;
            break;
        }
        if (m.find(*iter)->second == 0) {
            answer = *iter;
            break;
        }
        else {
            m.find(*iter)->second--;
        }
    }
    return answer;
}