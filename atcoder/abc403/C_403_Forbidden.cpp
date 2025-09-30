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
	int n,m,q;
    cin >> n >> m >> q;
    vector<set<int>>pageusers(m+1);
    set<int> allpageusers;
    while(q--) {
        int t;
        cin >> t;
        int x,y;
        if (t==1) {
            cin >> x >> y;
            pageusers[y].insert(x);
        } else if (t==2) {
            cin >> x;
            allpageusers.insert(x);
        } else {
            cin >> x >> y;
            if (allpageusers.find(x)!=allpageusers.end()) {
                cout << "Yes\n";
            } else if (pageusers[y].find(x)!=pageusers[y].end()) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }


}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
