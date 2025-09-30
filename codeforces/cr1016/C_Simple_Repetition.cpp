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
	int x,k;
    cin >> x >> k;
    if (x==1) {
        if (k==2) {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }

    if (k>1) {
        cout << "NO\n";
        return;
    }

    for(int i=2;1ll*i*i<=x;i++) {
        if (x%i==0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

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
