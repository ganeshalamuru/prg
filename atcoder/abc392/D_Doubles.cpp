#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 1e5+1, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>>arr(n);
    for(int i=0,k;i<n;i++) {
        cin >> k;
        for(int j=0,x;j<k;j++)
            cin >> x,arr[i].push_back(x);
    }
    for(int i=0;i<n;i++)
        sort(arr[i].begin(), arr[i].end());
    pair<ll,ll> ans = {0,1};    
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            int a=0,b=0;
            ll tans = 0;
            while(a<arr[i].size() && b<arr[j].size()) {
                int num = arr[i][a],freq1=0,freq2=0;
                while(a<arr[i].size() && num==arr[i][a])
                    a++,freq1++;
                while(b<arr[j].size() && arr[j][b]<num)
                    b++;
                while(b<arr[j].size() && num==arr[j][b])
                    b++,freq2++;
                tans += 1ll*freq1*freq2;
            }
            if (tans*ans.S > 1ll*arr[i].size()*arr[j].size()*ans.F)
                ans = {tans, 1ll*arr[i].size()*arr[j].size()};
        }
    }
    cout << fixed << setprecision(12)<< (1.0l*ans.F)/(1.0l*ans.S) << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
