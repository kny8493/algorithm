#include <string>
#include <vector>
#include<functional>
#include<queue>

using namespace std;

int solution(vector<int> p, int l) {
    int answer = 0;
    priority_queue<int> pq;
    queue<pair<int, int>> q;

    for (int i = 0; i < p.size(); i++) {
        q.push({ p[i], i });
        pq.push(p[i]);
    }
    while (!q.empty()) {
        int idx = q.front().second;
        int num = q.front().first;
        q.pop();
        if (num == pq.top()) {
            answer++;
            pq.pop();
            if (l == idx) {
                break;
            }
        }
        else {
            q.push({ num,idx });
        }
    }

    return answer;
}