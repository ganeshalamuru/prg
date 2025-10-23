#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int x,y,z;
    cin >> x>> y >> z;
    set<int> ss;
    ss.insert(x&y);
    ss.insert(y&z);
    ss.insert(z&x);
    ss.insert((x&y)&z);
    if (ss.size() == 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


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
