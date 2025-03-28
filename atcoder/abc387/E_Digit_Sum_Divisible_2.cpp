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
    string s;
    cin >> s;
    vector<int> arr(2e5+2,-1);
    for(int i=1;i<2e5+2;i++) {
        int sod = 0,tmp=i;
        while(tmp>0) {
            sod+=tmp%10;
            tmp/=10;
        }
        arr[i]=i%sod;
    }
    if (s.size()<=5) {
        int num = stoi(s);
        for(int i=num;i<2*num;i++) {
            if (arr[i]==0 && arr[i+1]==0) {
                cout << i << "\n";
                return;
            }
        }
        cout << -1 << "\n";
        return;
    }
    if (s[0]>'5') {
        cout << "11" << string(s.size()-1,'0') << "\n";
        return;
    }
    int num = stoi(s.substr(0,5));
    for(int i=10000;i<1e5;i++) {
        int sod = 0,tmp=i+1;
        while(tmp>0) {
            sod+=tmp%10;
            tmp/=10;
        }
        if (i>num && arr[i]==0 && arr[i+1]==0 && i%10==0 && (sod==3 || sod==9)) {
            cout << i << string(s.size()-5,'0') << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}




signed main() {
    fast;
    int t = 1;
    string s;
    while(t--){
    	solve();
    }
    return 0;
}
