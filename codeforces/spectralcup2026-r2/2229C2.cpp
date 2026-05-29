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
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    vector<array<ll,2>> dp(n+1);
    for(int i=1;i<=n;i++) {
        if (arr[i]<0) {
            dp[i][0]=arr[i]+dp[i-1][0];
            dp[i][1]=arr[i]+dp[i-1][1];
        } else {
            dp[i][0]=-arr[i]+dp[i-1][0];
            dp[i][1]=max(arr[i]+dp[i-1][1],-arr[i]-dp[i-1][0]);
        }
    }
    
    int i=n;
    while (i>0) {
        if (arr[i]<0 || dp[i][1]==arr[i]+dp[i-1][1]) {
            i--;
            continue;
        }
        break;
    }
    vector<int> ops;
    int flip=1;
    for(int j=i-1;j>=1;j--) {
        if (arr[j]*flip>0) {
            ops.push_back(j);
            flip*=-1;
        }
    }
    if (i>=1)
        ops.push_back(i);
    cout << ops.size() << "\n";
    for(int j=0;j<int(ops.size());j++) {
        cout << ops[j] << " ";
    }
    cout << "\n";
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
