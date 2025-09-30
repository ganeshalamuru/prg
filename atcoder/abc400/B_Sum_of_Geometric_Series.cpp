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
    ll n,m;
    cin >> n >>m;
    ll sum = 1;
    ll term = 1;
    for(int i=1;i<=m;i++) {
        if (term>1e9l/n) {
            cout << "inf" << "\n";
            return;
        }
        term*=n;
        if (sum+term>1e9l) {
            cout << "inf" << "\n";
            return;
        }
        sum+=term;
    }
    cout << sum << "\n";

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
