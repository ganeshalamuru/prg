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
	string s,t;
    cin >> s>> t;
    bool ans = true;
    for(int i=1;i<s.size();i++) {
        if (isupper(s[i])) {
            if (find(t.begin(), t.end(), s[i-1])==t.end()) {
                ans = false;
                break;
            }
        }
    }
    if (ans) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
