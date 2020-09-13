#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(int b, int w, vector<int> t) {
    int answer = 0;
    queue<int> q;
    int tot = 0;
    for (int i = 0; i < t.size(); i++) {
        int truck = t[i];
        while (1) {
            // q가 비어있는 경우
            if (q.empty()) {
                answer++;
                q.push(truck);
                tot += truck;
                break;
            }
            // 큐는 비어있지 않아
            // 만약 큐가 꽉차있는 경우
            if (q.size() == b) {
                tot -= q.front();
                q.pop();
            }
            else {
                answer++;
                // 꽉차있지 않으니 굳이 뺼필요가 없음
                // 값을 넣을 수 있음 
                if (tot + truck > w) {
                    //무게가 넘쳐서 넣지못함
                    q.push(0);
                }
                else {
                    tot += truck;
                    q.push(truck);
                    break;

                }
            }

        }
    }
    return answer + b;
}