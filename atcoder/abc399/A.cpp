#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;
void solve() {
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    int ans = 0;
    for(int i=0;i<n;i++) {
        ans+=s[i]!=t[i];
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