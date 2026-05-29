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
	int n,k;
    cin >> n >> k;
    vector<int> moves(n+1);
    vector<int> arr(k);
    for(int i=0;i<k;i++) {
        cin >> arr[i], moves[arr[i]]++;
    }
    sort(all(arr));
    vector<int>dp(n+1);
    for(int i=1;i<=n;i++) {
        if (moves[i]>0) {
            dp[i]=1;
            continue;
        }
        for(int j=0;j<k && arr[j]<i;j++) {
            if (dp[i-arr[j]]^1) {
                dp[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if (dp[i]==1) {
            cout << "W";
        } else {
            cout << "L";
        }
    }
    cout << "\n";


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
