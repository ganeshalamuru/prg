#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,r1,c1,r2,c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    if (r1==r2) {
        if (c1<c2)
            cout << max(c1,c2) << "\n";
        else
            cout << max(n-c1,n-c2) << "\n";    
        return;
    } else if (c1==c2) {
        if (r1<r2)
            cout << max(r1,r2) << "\n";
        else
            cout << max(n-r1,n-r2) << "\n";    
        return;
    }
    if (r1<r2 && c1<c2) {
        cout << max(c2,r2) << "\n";
    } else if (r1<r2 && c1>c2) {
        cout << max(r2,n-c2) << "\n";
    } else if (r1>r2 && c1<c2) {
        cout << max(c2,n-r2) << "\n";
    } else {
        cout << max(n-r2,n-c2) << "\n";
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
