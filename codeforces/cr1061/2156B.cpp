#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    bool typebexits = false;
    for(int i=0;i<n;i++) {
        if (s[i]=='B') {
            typebexits = true;
            break;
        }
    }
    while (q--) {
        int num;
        cin >> num;
        if (!typebexits) {
            cout << num << "\n";
        } else {
            int j=0,ans = 0;
            while (num>0) {
                if (s[j]=='A') {
                    num--;
                } else {
                    num/=2;
                }
                j=(j+1)%n;
                ans++;
            }
            cout << ans << "\n";
        }
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
