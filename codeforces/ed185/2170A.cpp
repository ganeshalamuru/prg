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
    vector<vector<int>> arr(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            arr[i][j]=n*(i-1)+j;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int val=arr[i][j];
            if (i-1>=1)
                val+=arr[i-1][j];
            if (j+1<=n)
                val+=arr[i][j+1];
            if (i+1<=n)
                val+=arr[i+1][j];
            if (j-1>=1)
                val+=arr[i][j-1];
            ans = max(ans, val);
        }
    }
    cout << ans << "\n";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
