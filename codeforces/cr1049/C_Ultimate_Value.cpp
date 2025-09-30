#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v);
#define rall(v) rbegin(v),rend(v);
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<ll> arr(n+1);
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        if (i%2==1)
            ans+=arr[i];
        else
            ans-=arr[i];
    }
    if (n==1) {
        cout << ans << "\n";
        return;
    }
    ll maxdiff = LLONG_MIN;
    maxdiff=max(maxdiff,n-2ll+(n%2));
    set<ll,greater<ll>> ss;
    for(int i=2;i<=n;i++) {
        if (i%2==0) {
            ss.insert(2*arr[i]-i);
            continue;
        }
        maxdiff = max(maxdiff,(*(ss.begin())) - (2*arr[i]-i));
    }
    set<ll,greater<ll>>ss2;
    for(int i=n-(n%2);i>=1;i--) {
        if (i%2==0) {
            ss2.insert(2*arr[i]+i);
            continue;
        }
        maxdiff = max(maxdiff,(*(ss2.begin())) - (2*arr[i]+i));
    }
    if (maxdiff<=0) {
        cout << ans << "\n";
    } else {
        cout << ans+maxdiff << "\n";
    }


}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
