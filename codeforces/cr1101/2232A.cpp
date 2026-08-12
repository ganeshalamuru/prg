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
    map<int,int> mp;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        mp[x]++;
    }
    int ans = INT_MAX, numbelow = 0;
    for(auto &[k,v]:mp) {
        int numabove = n-numbelow-v;
        ans = min(ans,max(numabove,numbelow));
        numbelow+=v;
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
