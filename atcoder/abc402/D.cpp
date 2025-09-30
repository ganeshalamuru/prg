#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
    ll n,m;
    cin >> n >> m;
    vector<ll> arr(m);
    map<ll,int> freq;
    for(ll i=0,a,b;i<m;i++) {
        cin >> a >> b;
        arr[i]=a+b;
        freq[arr[i]]++;
    }
    ll ans = (m*(m-1))/2;
    for(int i=0;i<m;i++) {
        ans+=m-1 - (freq[arr[i]]-1);
    }
    cout << ans/2 << "\n";

}
int main() {
    fast;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}