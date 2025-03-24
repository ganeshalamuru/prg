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



bool pos(string &s, int k, vector<int>&penality, int optcost) {
    int j=0,i=0,n=s.size();
    while (i<n&&j<k) {
        if (s[i]=='R' || penality[i]<=optcost) {
            i++;
            continue;
        }
        while(i<n && (s[i]=='B'|| penality[i]<=optcost))
            i++;
        j++;
    }
    while (i<n && (s[i]=='R'|| penality[i]<=optcost))
        i++;
    return i==n;
}

void solve() {
	int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> penalty(n);
    int maxcost = INT_MIN;
    for(int i=0;i<n;i++)
        cin >> penalty[i],maxcost=max(maxcost, penalty[i]);
    int l = 0,r=maxcost;
    while(l<r) {
        int mid = l+(r-l)/2;
        if (!pos(s,k,penalty,mid)) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    cout << l << "\n";
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
