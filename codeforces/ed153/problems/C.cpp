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




void solve(){
	int n;
    cin >> n;
    vector<int>arr(n);
    for (int &i:arr)
        cin >> i;
    vector<int>dp(n+1, 0);
    set<int> ss;
    ss.insert(arr[0]), dp[arr[0]] = 1;
    for (int i = 1; i < n;i++) {
        auto itr = ss.lower_bound(arr[i]);
        if (itr == ss.end()) {
            auto itr1 = ss.rbegin();
            dp[arr[i]] = dp[*itr1] + 1;
        } else {
            if (itr == ss.begin()) {
                dp[arr[i]] = 1;
            } else {
                itr--;
                dp[arr[i]] = dp[*itr] + 1;
                itr++;
                vector<set<int>::iterator> vsitrs;
                while(itr != ss.end() && dp[*itr] <= dp[arr[i]])
                    vsitrs.push_back(itr), itr++;
                for(auto it : vsitrs)
                    ss.erase(it);
            }
        }
        ss.insert(arr[i]);
    }
    int wins = 0;
    for (int i = 0; i <n;i++)
        if (dp[arr[i]] == 2)
            wins++;
    cout << wins << "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
