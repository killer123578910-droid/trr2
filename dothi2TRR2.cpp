#include <iostream>

using namespace std;

int t, n, m;
int bac[105];
int maTran[105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);

    if (!(cin >> t >> n >> m)) return 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                maTran[i][j] = 0;
            } else {
                maTran[i][j] = 10000;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        bac[u]++;
        bac[v]++;
        maTran[u][v] = w;
        maTran[v][u] = w;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            cout << bac[i];
            if (i < n) cout << " ";
        }
        cout << "\n";
    } else if (t == 2) {
        cout << n << "\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << maTran[i][j];
                if (j < n) cout << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}