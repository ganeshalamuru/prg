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
	string s,t;
    cin >> s >> t;
    int n = int(s.size()),m = int(t.size());
    vector<vector<int>> inds(26);
    for(int i=0;i<n;i++) {
        inds[s[i]-'a'].push_back(i);
    } 
    ll ans = 0;
    for(int i=0;i<n;i++) {
        int stind = i;
        bool found = true;
        for(int j=0;j<m;j++) {
            auto &indsarr = inds[t[j]-'a'];
            auto itr = lower_bound(all(indsarr),stind);
            if (itr != indsarr.end()) {
                stind = (*itr) + 1;
            } else {
                stind = n;
                found = false;
                break;
            }
        }
        ans += (stind-i);
        if (found) ans--;
    }
    cout << ans << "\n";

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
