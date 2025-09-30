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
	ll n,k;
    cin >> n >> k;
    vector<pii> gloves(n); 
    for(int i=0;i<n;i++)
        cin >> gloves[i].F;
    for(int i=0;i<n;i++)
        cin >> gloves[i].S;
    vector<int> remm;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        ans+=max(gloves[i].F,gloves[i].S);
        remm.push_back(min(gloves[i].F,gloves[i].S));
    }
    sort(rall(remm));
    for(int i=0;i<k-1;i++)
        ans+=remm[i];
    cout << ans +1<< "\n";
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
