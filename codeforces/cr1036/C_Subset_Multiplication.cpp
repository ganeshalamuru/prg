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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> mm;
    for(int i=0;i<n-1;i++) {
        if (arr[i+1]%arr[i]!=0) {
            mm.push_back(i);
        }
    }
    if (mm.empty()) {
        cout << 1 << "\n";
        return;
    }
    vector<ll> aa;
    for(int i=0;i<mm.size();i++) {
        aa.push_back(arr[mm[i]]/__gcd(arr[mm[i]],arr[mm[i]+1]));
    }
    ll lcm = aa[0];
    for(int i=1;i<aa.size();i++) {
        lcm = (lcm*aa[i]) / __gcd(lcm,aa[i]);
    }
    cout << lcm << "\n";

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
