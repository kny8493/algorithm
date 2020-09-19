#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#define MAX 53
using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int N, M;
int x, y, d;
int ans = 1;
int map[MAX][MAX];
void input() {
	for (int i = 0; i <= N+1; i++) {
		for (int j = 0; j <= M+1; j++) {
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1) {
				map[i][j] = 1;
				continue;
			}
			int tmp;
			cin >> map[i][j];
		}
	}

}
bool stop() {
	int i = 0;
	for (i = 0; i < 4; i++) {
		if (map[y + dy[i]][x + dx[i]] == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> y >> x >> d;
	x++;
	y++;

	input();

	while (1) {
		// 더이상 이동 못할때 멈춤
		if (stop()) break;
		d = d - 1 < 0 ? 3 : d - 1;

		// 갈 수 있는 경우 
		if (map[y + dy[d]][x + dx[d]] == 0) {
			x = x + dx[d];
			y = y + dy[d];
			map[y][x] = 1;
			ans++;
		}
	}
	cout << ans;
	return 0;
}