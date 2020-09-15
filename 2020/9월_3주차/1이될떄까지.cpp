
#include <iostream>
using namespace std;
int main()
{
    int N, K, ans = 0, tmp=0;
    cin >> N >> K;
    while (N) {
        tmp = N;

        while (1) {
            if (tmp % K != 0) break;
            tmp = tmp / K;
            ans++;
            if (tmp == 1) {
                cout << ans;
                return 0;
            }
        }
        N--;
        ans++;

    }
    cout << ans;
    return 0;

}
