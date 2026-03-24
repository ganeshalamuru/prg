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
	int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n));
    int cnt = n*n-1;
    arr[0][(n-1)/2]=1;
    pii prevcell = {0,(n-1)/2};
    int prevval = 1;
    while (cnt--) {
        int nr = (prevcell.F-1+n)%n, nc = (prevcell.S+1)%n;
        if (arr[nr][nc]!=0) {
            nr = (prevcell.F+1)%n,nc = prevcell.S;
        }
        arr[nr][nc] = prevval+1;
        prevval++;
        prevcell = {nr,nc};
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


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
