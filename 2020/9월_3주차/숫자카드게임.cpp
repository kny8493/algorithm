#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	int N, M, ans = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp = 1000;
		for (int j = 0; j < M; j++) {
			int card;
			cin >> card;
			if (tmp > card) {
				tmp = card;
			}
		}
		if (tmp > ans) {
			ans = tmp;
		}
	}
	cout << ans;
	return 0;
}