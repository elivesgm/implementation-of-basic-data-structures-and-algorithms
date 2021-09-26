#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> & v);

int get_max_value(int N, int M, vector<int> &w, vector<int> &v) {
    vector<vector<int> > dp(N + 1, vector<int> (M + 1, 0));

    for (int j = 1; j <= N; ++j)
        dp[0][j] = 0;

    for (int i = 1; i <= N; ++i) {
        for (int j = M; j > 0; j--) {
            if (w[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }

    cout << "DEBUG: " << endl;
    for (int i = 0; i < dp.size(); ++i) print_vector(dp[i]);

    return dp[N][M];
}

void print_vector(vector<int> & v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(void)
{
    int N, M, a, b;
    vector<int> w(1, 0);
    vector<int> v(1, 0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> a;
        w.push_back(a);
    }
    for (int i = 1; i <= N; ++i) {
        cin >> b;
        v.push_back(b);
    }

    cout << "INPUT: " << endl;
    cout << " N=" << N << endl;
    cout << " M=" << M << endl;
    cout << " w=";
    print_vector(w);
    cout << " v=";
    print_vector(v);

    cout << "OUTPUT: " << endl;
    cout << " Result = " << get_max_value(N, M, w, v) << endl;

    return 0;
}
