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




int max_destroyed(vector<pair<int,int>> &arr, int k) {
    int sz = arr.size();
    int maxdestroyed = arr[k].second;
    int i=k-1,j=k+1;
    while(i>=0 && j<sz) {
        if (arr[i].F==arr[j].F && arr[i].S+arr[j].S>=3) {
            maxdestroyed+=arr[i].S+arr[j].S;
            i--,j++;
        } else {
            break;
        }
    }
    return maxdestroyed;
}

void solve(){
	int n,k,x;
    cin >> n >> k >> x;
    vector<int>a(n);
    for(int &i:a)
        cin >> i;
    vector<pair<int,int>> cntcolor;
    int i=0;
    while(i<n) {
        int cur = a[i],cnt=0;
        while(i<n && cur==a[i]) cnt++,i++;
        cntcolor.push_back({cur,cnt});
    }
    int maxd=0;
    for(int i=0;i<cntcolor.size();i++) {
        if (cntcolor[i].F!=x || cntcolor[i].S<2)
            continue;
        cntcolor[i].S++;
        maxd = max(maxd, max_destroyed(cntcolor,i)-1);
        cntcolor[i].S--;
    }
    cout << maxd << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
