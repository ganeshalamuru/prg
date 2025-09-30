#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;
void solve() {
    int q;
    cin >> q;
    queue<int> qq;
    while(q--) {
        int t;
        cin >> t;
        if (t==1) {
            int x;
            cin >> x;
            qq.push(x);
        } else {
            cout << qq.front() << "\n";
            qq.pop();
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