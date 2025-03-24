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
	int n,m,q;
    cin >> n >> m >> q;
    vector<int> a(q);
    for(int &num:a)
        cin >> num;
    int left=0,right=n+1;
    pii middle{m,m};
    if (a[0]==m) {
        left=1,right=n;
        cout << 2 << " ";
        for(int i=1;i<q;i++) {
            if (left+(n+1-right)==n) {
                cout << n << " ";
                continue;
            }
            int pos = a[i];
            if (pos<=left) {
                right=max(left+1,right-1);
            } else if (pos<right) {
                left=min(right-1,left+1);
                right=max(left+1,right-1);
            } else {
                left=min(right-1, left+1);
            }
            cout << left + (n+1-right) << " ";
        }
        cout << "\n";
        return;
    }
    for(int i=0;i<q;i++) {
        if (middle.S-middle.F+1 + left + n+1-right == n) {
            cout << n << " ";
            continue;
        }
        int pos = a[i];
        if (pos <= left) {
            if (right!=n+1)
                right = max(middle.S+1, right-1);
            middle.F = max(left+1, middle.F-1);
        } else if (pos < middle.F) {
            if (left!=0)
                left=min(middle.F-1, left+1);
            middle.F = max(left+1,middle.F-1);
            if (right!=n+1)
                right=max(middle.S+1,right-1);
        } else if (pos <= middle.S) {
            left=min(middle.F-1,left+1);
            right=max(middle.S+1,right-1);
        } else if (pos < right) {
            if (left!=0)
                left=min(middle.F-1, left+1);
            middle.S = min(middle.S+1,right-1);
            if (right!=n+1)
                right=max(middle.S+1,right-1);
        } else {
            if (left!=0)
                left=min(middle.F-1, left+1);
            middle.S = min(middle.S+1,right-1);
        }
        cout << middle.S-middle.F+1 + left + n+1-right << " ";
    }
    cout << "\n";
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
