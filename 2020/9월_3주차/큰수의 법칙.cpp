#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;
	int answer;
	int max1=0, max2=0;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		if (max1 < tmp || max2<tmp) {
			if (max1 < tmp) {
				max2 = max1;
				max1 = tmp;

			}
			else {
				max2 = tmp;
			}
		}
	}
	int tmp =max1* K + max2;
	int ans = M % (K + 1);
	answer = tmp * M / (K + 1) + ans * max1;
	cout << answer;

	return 0;
}