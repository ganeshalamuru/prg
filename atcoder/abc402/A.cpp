#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;
void solve() {
    string s;
    cin >> s;
    string ans = "";
    for(int i=0;i<s.size();i++) {
        if (isupper(s[i]) > 0) {
            ans.push_back(s[i]);
        }
    }
    cout << ans << "\n";
}
int main() {
    fast;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}