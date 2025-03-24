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
    vector<int> arr(n);
    map<int, vector<int>> mp;
    for(int i=0;i<n;i++)
        cin >> arr[i],mp[arr[i]].push_back(i+1);
    int combs = 1;
    for(auto& pp:mp) {
        combs*=pp.second.size();
        if (combs>=3)
            break;
    }
    if (combs < 3) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto &pp:mp) {
        for(auto &ind:pp.second)
            cout << ind << " ";
    }
    cout << "\n";
    for(auto &pp:mp) {
        for(auto itr = pp.second.rbegin(); itr!=pp.second.rend(); itr++)
            cout << (*itr) << " ";
    }
    cout << "\n";
    int flip = 0;
    for(auto &pp:mp) {
        int szzz = pp.second.size();
        int i=0,j=szzz-1;
        while(i<j) {
            if (flip)
                cout << pp.second[i] << " " << pp.second[j] << " ";
            else
                cout << pp.second[j] << " " << pp.second[i] << " ";
            i++,j--;
        }
        if(i==j)
            cout << pp.second[i] << " ";
        if (szzz > 1)
            flip^=1;
    }
    cout << "\n";
    
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
