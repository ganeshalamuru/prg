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


// -1 if no perfect sq
ll findSqrt(long long n) {
       
    if (n == 0)
        return 0;
    ll l = 1, r = 2e9l ;
    while (l < r)
    {
        ll mid = (l + (r-l) / 2);
        ll midsq = mid*mid;
        if (midsq == n)
            return mid;
        else if (midsq > n) 
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (l*l == n) {
        return l;
    }
    return -1;
}



void solve(){
    ll n, arrval;
    cin >> n;
    map<ll,ll>mp;
    for(int i=0;i<n;i++)
        cin >> arrval,mp[arrval]++;
    int q;
    cin >> q;
    while(q--) {
        ll x,y;
        cin >> x >> y;
        ll spval = (x*x - 4*y);
        if (spval < 0) {
            cout << 0 << " ";
            continue;
        }
        ll sqrtspval = findSqrt(spval);
        if (sqrtspval == - 1 || (x+sqrtspval)%2 != 0 || (x-sqrtspval)%2 != 0) {
            cout << 0 << " ";
            continue;
        }
        ll solai = (x+sqrtspval) / 2, solaj = (x-sqrtspval) / 2;
        if (solai == solaj) {
            ll freq = mp[solai];
            cout << (freq*(freq - 1)) / 2 << " ";
            continue;
        } else {
            ll aiFreq = mp[solai], ajFreq = mp[solaj];
            cout << aiFreq * ajFreq << " ";
        }
    }
    cout << "\n";
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
