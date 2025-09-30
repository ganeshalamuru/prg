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
	string t,u;
    cin >> t >> u;
    for(int i=0;i<t.size();i++) {
        int x=i,y=0;
        while (x<t.size() && y<u.size()) {
            if (t[x]=='?'|| t[x]==u[y]) {
                x++,y++;
            } else {
                break;
            }
        }
        if (y==u.size()) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";

}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
