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
	int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    multiset<int,greater<int>> sm;
    multiset<int>gr;
    int smsz = k/2 + k%2;
    for(int i=0;i<k;i++)
        gr.insert(arr[i]);
    while(sm.size()<smsz) {
        sm.insert(*gr.begin());
        gr.erase(gr.begin());
    }
    cout << *sm.begin() << " ";
    for(int i=k;i<n;i++) {
        if (arr[i-k] <= *sm.begin())
            sm.erase(sm.find(arr[i-k]));
        else
            gr.erase(gr.find(arr[i-k]));
        if (k==1 || gr.empty() || arr[i] < *gr.begin()) {
            sm.insert(arr[i]);
        } else {
            gr.insert(arr[i]);
        }
        if (sm.size()<smsz) {
            sm.insert(*gr.begin());
            gr.erase(gr.begin());
        } else if (sm.size()>smsz) {
            gr.insert(*sm.begin());
            sm.erase(sm.begin());
        }
        cout << *sm.begin() << " ";
    }
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
