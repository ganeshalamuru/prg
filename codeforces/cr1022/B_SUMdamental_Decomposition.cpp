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
	int n,x;
    cin >> n >> x;
    if (n==1) {
        if (x==0) {
            cout << -1 << "\n";
        } else {
            cout << x << "\n";
        }
        return;
    }
    if (x==0) {
        if (n%2==0) {
            cout << n << "\n";
        } else {
            cout << n+3 << "\n";
        }
        return;
    }
    int bits=0;
    bitset<31>bs(x);
    for(int i=0;i<31;i++) {
        if (bs[i]==1) {
            bits++;
        }
    }
    if (bits>=n) {
        cout << x << "\n";
        return;
    }
    if (x==1 && n%2==0) {
        cout << x+n+2 << "\n";
        return;
    }
    int diff = n-bits;
    cout << x + diff+diff%2 << "\n";
    

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
