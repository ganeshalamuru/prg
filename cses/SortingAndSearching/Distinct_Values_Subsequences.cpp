#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const int mod = 1e9+7;

void solve() {
    int n;
    cin >> n;
    map<int,int> freq;
    for(int i=0,x;i<n;i++) {
        cin >> x;
        freq[x]++;
    }
    int ans = 1;
    for(auto& p:freq) {
        ans=(1ll*ans*(p.second+1))%mod;
    }
    ans = (ans-1+mod)%mod;
    cout << ans << "\n";
}


int main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
