#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int tdiff = 0;
    for (int i = 0; i < n; i++) {
        tdiff += ((s[i] == 'a') ? 1 : -1);
    }
    if (tdiff == 0) {
        cout << 0 << "\n";
        return;
    }
    map<int, int> diffind{{0, -1}};
    int minconsec = n;
    int cdiff = 0;
    for (int i = 0; i < n; i++) {
        cdiff += ((s[i] == 'a') ? 1 : -1);
        if (diffind.find(cdiff-tdiff)!=diffind.end()) {
            minconsec=min(minconsec,i-diffind[cdiff-tdiff]);
        }
        diffind[cdiff]=i;        
    }
    if (minconsec==n) {
        cout << -1 << "\n";
    } else {
        cout << minconsec << "\n";
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
