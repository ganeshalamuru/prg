#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n,k;
    cin >> n >> k;
    vector<pair<ll,ll>>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i].F;
    }
    for(int i=0;i<n;i++) {
        cin >> arr[i].S;
    }
    ll coins = 0;
    for(int i=0;i<n;i++) {
        if (arr[i].F>arr[i].S)
            swap(arr[i].F, arr[i].S);
        coins+=arr[i].S-arr[i].F;
    }
    sort(all(arr),[&](const auto &a, const auto &b) {
        if (a.S==b.S) {
            return a.F < b.F;
        }
        return a.S < b.S;
    });
    ll mincoinsdiff = LLONG_MAX;
    for(int i=1;i<n;i++) {
        if (arr[i-1].S<arr[i].F) {
            mincoinsdiff = min(mincoinsdiff, 2*(arr[i].F-arr[i-1].S));
        } else {
            mincoinsdiff = min(mincoinsdiff,0ll);
        }

    }
    cout << coins + mincoinsdiff << "\n";

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
