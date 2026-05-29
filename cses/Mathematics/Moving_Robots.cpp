#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;



void solve() {
	int k;
    cin >> k;
    // dp[i][k][j] -- probabilty for ith robot on kth move
    // to be on jth cell
    // array<array<array<long double,64>,101>,64>dp{};
    vector<vector<vector<long double>>> dp(64,vector<vector<long double>>(k+1,vector<long double>(64)));
    for(int i=0;i<64;i++) {
        dp[i][0][i]=1.0l;
    }
    array<array<int,8>,8> validcnt{};
    for(int x=0;x<8;x++) {
        for(int y=0;y<8;y++) {
            for(auto &[dx, dy]:{pii{-1,0},{0,1},{1,0},{0,-1}}) {
                int nx = x+dx,ny = y+dy;
                if (nx>=0 && ny>=0 && nx<8 && ny<8)
                    validcnt[x][y]++;
            }
        }
    }
    for(int i=0;i<64;i++) {
        for(int m=1;m<=k;m++) {
            for(int x=0;x<8;x++) {
                for(int y=0;y<8;y++) {
                    for(auto [dx, dy]:{pii{-1,0},{0,1},{1,0},{0,-1}}) {
                        int nx = x+dx,ny = y+dy;
                        if (nx>=0 && ny>=0 && nx<8 && ny<8) {
                            dp[i][m][x*8+y]+=(1.0l/validcnt[nx][ny])*dp[i][m-1][nx*8+ny];
                        }
                    }

                }
            }
        }
    }
    long double expectation = 0.0l;
    for(int c=0;c<64;c++) {
        long double prob_cell_c_empty = 1.0l; 
        for(int i=0;i<64;i++) {
            prob_cell_c_empty*=(1.0l-dp[i][k][c]);
        }
        expectation+=prob_cell_c_empty;
    }
    cout.precision(6);
    cout << fixed << expectation << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
