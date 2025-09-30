#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	ll n,k,x;
    cin >> n >> k >> x;
    vector<ll>arr(n);
    ll totsum = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        totsum+=arr[i];
    }
    ll fullsumm = totsum*k;
    if (fullsumm<x) {
        cout << 0 << "\n";
        return;
    }
    ll l=1,r=1ll*n*k;
    while(l<r) {
        ll mid = l+(r-l+1)/2;
        ll psum = totsum*((mid-1)/n);
        int rem = (mid-1)%n;
        if (rem>0) {
            for(int j=0;j<rem;j++)
                psum+=arr[j];
        }
        ll reqsum = fullsumm-psum;
        if (reqsum<x)
            r=mid-1;
        else
            l=mid;
    }
    cout << l << "\n";


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
