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


vector<ll> pxor(vector<int> &partition, vector<ll> &psums) {
    vector<ll> ppxor(partition.size());
    ll prefxor = 0;
    for(int i=0;i<partition.size();i++) {
        prefxor^=psums[partition[i]];
        ppxor[i]=prefxor;
    }
    return ppxor;
} 


void solve() {
    vector<vector<vector<int>>> parts(2,vector<vector<int>>(680000));
	int n;
    cin >> n;
    vector<ll>a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    vector<ll> psums(1<<n,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<psums.size();j++) {
            if ((j>>i)&1)
                psums[j]+=a[i];
        }
    }
    if (n==1) {
        cout << 1 << "\n";
        return;
    }
    vector<int> sz(2,0);
    int flip=0;
    parts[flip][sz[flip]]={1};
    sz[flip]++;
    flip^=1;
    for(int i=1;i<n-1;i++) {
        sz[flip]=0;
        int x=0;
        for(int j=0;j<sz[flip^1];j++) {
            auto &partition = parts[flip^1][j];
            partition.push_back(1<<i);
            parts[flip][x++]=partition;
            partition.pop_back();
            for(int z=0;z<partition.size();z++) {
                partition[z]^=(1<<i);
                parts[flip][x++]=partition;
                partition[z]^=(1<<i);
            }
        }
        sz[flip]=x;
        flip^=1;
    }
    unordered_set<ll> ans;
    for(int j=0;j<sz[flip^1];j++) {
        auto &partition = parts[flip^1][j];
        vector<ll>prefxor = pxor(partition, psums);
        ans.insert(prefxor.back()^a[n-1]);
        for(int z=0;z<partition.size();z++) {
            ll leftx = 0,rightx=0;
            if (z-1>=0)
                leftx=prefxor[z-1];
            rightx=prefxor.back()^prefxor[z];
            ll cursum = leftx^prefxor[z]; 
            ans.insert(leftx^(cursum+a[n-1])^rightx);
        }
    }
    cout << ans.size() << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
