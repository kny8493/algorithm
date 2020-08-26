#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool gCompare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}
bool pCompare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> g, vector<int> p) {
    vector<int> answer;
    unordered_map<string, int> gLevel;
    unordered_map<string, int> ::iterator iterG;

    unordered_map<string, vector<pair<int, int>>> pLevel;
    unordered_map<string, vector<pair<int, int>>>::iterator iter;

    for (int i = 0; i < g.size(); i++) {
        gLevel[g[i]] += p[i];
        pLevel[g[i]].push_back({ p[i], i });
    }
    vector<pair<string, int>> ansFlg(gLevel.begin(), gLevel.end());
    sort(ansFlg.begin(), ansFlg.end(), gCompare);

    for (auto tmp : ansFlg) {
        sort(pLevel[tmp.first].begin(), pLevel[tmp.first].end(), pCompare);
        answer.push_back(pLevel[tmp.first][0].second);
        if (pLevel[tmp.first].size() > 1) {
            answer.push_back(pLevel[tmp.first][1].second);
        }
    }

    return answer;
}