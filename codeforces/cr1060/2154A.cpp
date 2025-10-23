#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i=0;
    while(i<n && s[i]=='0') i++;
    if (i==n) {
        cout << 0 << "\n";
        return;
    }
    int safeupto=i+k-1, numprotect = 1;
    while(i<n) {
        if (s[i]=='0') {
            i++;
            continue;
        }
        if (i>safeupto)
            numprotect++;
        safeupto=i+k-1;
        i++;
    }
    cout << numprotect << "\n";

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
