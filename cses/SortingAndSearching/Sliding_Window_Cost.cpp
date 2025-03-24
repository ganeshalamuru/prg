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
	ll n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    multiset<int,greater<int>> sm;
    multiset<int> gr;
    ll smsum = 0, grsum = 0;
    for(int i=0;i<k;i++)
        gr.insert(arr[i]),grsum+=arr[i];
    ll smsz = k/2;
    while(sm.size() < smsz) {
        auto itr = gr.begin();
        smsum+=(*itr), grsum-=(*itr);
        sm.insert(*itr),gr.erase(itr);
    }
    cout << 1ll*(*gr.begin())*smsz-smsum + grsum-1ll*(*gr.begin())*(k-smsz) << " ";
    for(int i=k;i<n;i++) {
        if (arr[i-k]>=(*gr.begin())) {
            grsum-=arr[i-k];
            gr.erase(gr.find(arr[i-k]));
        } else {
            smsum-=arr[i-k];
            sm.erase(sm.find(arr[i-k]));
        }
        if (k==1 || sm.empty() || arr[i] > (*sm.begin())) {
            gr.insert(arr[i]);
            grsum+=arr[i];
        } else {
            sm.insert(arr[i]);
            smsum+=arr[i];
        }
        if (gr.size()>k-smsz) {
            auto itr = gr.begin();
            smsum+=(*itr), grsum-=(*itr);
            sm.insert(*itr),gr.erase(itr);
        } else if (gr.size()<k-smsz) {
            auto itr = sm.begin();
            grsum+=(*itr),smsum-=(*itr);
            gr.insert(*itr),sm.erase(itr);
        }

        cout << 1ll*(*gr.begin())*smsz-smsum + 1ll*grsum-(*gr.begin())*(k-smsz) << " ";
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
