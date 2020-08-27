#include <string>
#include <vector>

using namespace std;

int solution(vector<int> p, int l) {
    int answer = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < p.size(); i++) {
        v.push_back({ p[i], i });
    }
    while (!v.empty()) {
        int idx = v.front().second;
        int num = v.front().first;
        bool hasBig = false;
        for (int i = 1; i < v.size(); i++) {
            if (v[i].first > num) {
                hasBig = true;
            }
        }
        if (hasBig) {
            v.push_back(v.front());
            v.erase(v.begin());
        }
        else {
            answer++;
            if (l == idx)  break;
            v.erase(v.begin());
        }
    }

    return answer;
}