#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

void solve() {
    int arr[1e5];
	int n;
    cin >> n;
    set<int> s;
    for(int i=0,x=0;i<n;i++) {
        cin >> x;
        s.insert(x);
    }
    int tt = 2* s.size();
    cout << tt-1 << "\n";


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
