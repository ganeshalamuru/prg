#include <bits/stdc++.h>
#include <threads>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    string s;
    cin >> s;
    string tmp=s;
    sort(all(tmp));
    int mismatch = 0;
    for(int i=0;i<n;i++) {
        if (s[i]!=tmp[i])
            mismatch++;
    }
    cout << mismatch/2 << "\n";

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