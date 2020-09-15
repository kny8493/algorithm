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
		// 빼기 연산
		ans += (N - tmp);
		N = tmp;
		// 더이상 나눌수 없는경우
		if (N < K)  break;
		// 나누기 연산
		ans++;
		N /= K;
	}
	ans = ans + (N - 1);
	cout << ans;
	return 0;
}