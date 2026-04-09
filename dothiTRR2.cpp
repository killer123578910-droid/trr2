#include <iostream>

using namespace std;

int t, n;
int maTran[105][105];
int bac[105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    if (!(cin >> t >> n)) return 0;

    int m = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> maTran[i][j];
            if (maTran[i][j] == 1) {
                bac[i]++;
                if (i < j) {
                    m++;
                }
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            cout << bac[i];
            if (i < n) cout << " ";
        }
        cout << "\n";
    } else if (t == 2) {
        cout << n << " " << m << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (maTran[i][j] == 1) {
                    cout << i << " " << j << "\n";
                }
            }
        }
    }

    return 0;
}