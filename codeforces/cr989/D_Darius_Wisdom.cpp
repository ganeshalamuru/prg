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




void solve() {
	int n;
    cin >> n;
    vector<int> arr(n),srtedarr(n);
    vector<int> cnt(3,0);
    vector<set<int>> ss(3);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
        srtedarr[i]=arr[i];
        ss[arr[i]].insert(i);
    }
    sort(srtedarr.begin(), srtedarr.end());
    vector<pair<int,int>> ans;
    while(arr != srtedarr) {
        // exchange 1s in zero camp with farthest zeros
        while((*ss[1].begin()) < cnt[0] && ss[0].size()>0 && (*ss[0].rbegin()) >= cnt[0]) {
            ans.push_back({*ss[1].begin(), *ss[0].rbegin()});
            int oneind = *ss[1].begin(),zeroind = *ss[0].rbegin();
            swap(arr[oneind],arr[zeroind]);
            ss[1].erase(oneind);
            ss[0].erase(zeroind);
            ss[1].insert(zeroind);
            ss[0].insert(oneind);
        }
        //exchange 2s in zero camp with fathest ones
        while(ss[2].size()>0 && (*ss[2].begin()) < cnt[0] && (*ss[1].rbegin()) >= cnt[0]) {
            ans.push_back({*ss[2].begin(), *ss[1].rbegin()});
            int twoind = *ss[2].begin(),oneind = *ss[1].rbegin();
            swap(arr[twoind],arr[oneind]);
            ss[2].erase(twoind);
            ss[1].erase(oneind);
            ss[2].insert(oneind);
            ss[1].insert(twoind);
        }
        // exchange 1s in two camp with farthest 2
        while((*ss[1].rbegin()) >= n-cnt[2] && ss[2].size()>0 && (*ss[2].begin()) < n - cnt[2]) {
            ans.push_back({*ss[1].rbegin(), *ss[2].begin()});
            int oneind = *ss[1].rbegin(),twoind = *ss[2].begin();
            swap(arr[oneind],arr[twoind]);
            ss[1].erase(oneind);
            ss[2].erase(twoind);
            ss[1].insert(twoind);
            ss[2].insert(oneind);
        }
        //exchange 0s in two camp with fathest ones
        while(ss[0].size() > 0 && (*ss[0].rbegin()) >= n-cnt[2] && (*ss[1].begin()) < n - cnt[2]) {
            ans.push_back({*ss[0].rbegin(), *ss[1].begin()});
            int zeroind = *ss[0].rbegin(),oneind = *ss[1].begin();
            swap(arr[zeroind],arr[oneind]);
            ss[0].erase(zeroind);
            ss[1].erase(oneind);
            ss[0].insert(oneind);
            ss[1].insert(zeroind);
        }
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++)
        cout << ans[i].F+1 << " " << ans[i].S+1 << "\n";

}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
