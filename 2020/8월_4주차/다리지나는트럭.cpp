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
            // q�� ����ִ� ���
            if (q.empty()) {
                answer++;
                q.push(truck);
                tot += truck;
                break;
            }
            // ť�� ������� �ʾ�
            // ���� ť�� �����ִ� ���
            if (q.size() == b) {
                tot -= q.front();
                q.pop();
            }
            else {
                answer++;
                // �������� ������ ���� �E�ʿ䰡 ����
                // ���� ���� �� ���� 
                if (tot + truck > w) {
                    //���԰� ���ļ� ��������
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