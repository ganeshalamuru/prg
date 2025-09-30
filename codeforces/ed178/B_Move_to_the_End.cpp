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
	int n;
    cin >> n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> pmax(n,INT_MIN);
    pmax[0]=arr[0];
    for(int i=1;i<n;i++) {
        pmax[i]=max(pmax[i-1],arr[i]);
    }
    vector<ll> ssum(n,0);
    ssum[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--) {
        ssum[i]=ssum[i+1]+arr[i];
    }
    vector<ll>ans(n+1);
    for(int k=1;k<n;k++) {
        if (pmax[n-k-1]>arr[n-k]) {
            ans[k]=ssum[n-k]-arr[n-k]+pmax[n-k-1];
        } else {
            ans[k]=ssum[n-k];
        }
    }
    ans[n]=ssum[0];
    for(int k=1;k<=n;k++) {
        cout << ans[k] << " ";
    }
    cout << "\n";

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
