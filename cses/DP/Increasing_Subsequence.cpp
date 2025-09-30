#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}



// a simpler way ?
void solve() {
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    set<pii> ss;
    ss.insert({arr[0],1});
    for(int j=1;j<n;j++) {
        auto itr = ss.lower_bound({arr[j],0});
        if (itr==ss.end()) {
            ss.insert({arr[j], ss.rbegin()->second+1});
            continue;
        }
        pii pp;
        if (itr == ss.begin()) {
            pp={arr[j],1};
        } else {
            itr--;
            pp = {arr[j],itr->second+1};
            itr++;
        }
        vector<pii> todelete;
        while(itr!=ss.end() && itr->second<=pp.second) {
            todelete.push_back(*itr);
            itr++;
        }
        for(auto &pai:todelete)
            ss.erase(pai);
        ss.insert(pp);
    }
    cout << ss.rbegin()->second << "\n";
}

void solve2() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<int> dp(n+1,INT_MAX);
    dp[0]=INT_MIN;
    int ans = INT_MIN;
    for(int i=0;i<n;i++) {
        auto itr = lower_bound(dp.begin(), dp.end(), arr[i]);
        int ind = distance(dp.begin(), itr);
        dp[ind]=min(dp[ind],arr[i]);
        ans = max(ans, ind);
    }
    cout << ans << "\n";
}
 

signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve2();
    }
    return 0;
}
