#include <iostream>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, ans = 0;
	cin >> N >> K;
	while (1) {
		int tmp = (N / K) * K;
		// ���� ����
		ans += (N - tmp);
		N = tmp;
		// ���̻� ������ ���°��
		if (N < K)  break;
		// ������ ����
		ans++;
		N /= K;
	}
	ans = ans + (N - 1);
	cout << ans;
	return 0;
}