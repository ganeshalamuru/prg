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
    int n;
    cin >> n;
	vector<int> a,b;
    string s;
    cin >> s;
    for(int i=1;i<=n;i++) {
        if (s[i-1]=='A')
            a.push_back(i);
        else
            b.push_back(i);
    }
    if (a[0]==1 && a.back()==n) {
        cout << "Alice\n";
        return;
    } else if (b[0]==1 && b.back()==n) {
        cout << "Bob\n";
        return;
    }
    if (a[0]==1) {
        if (b.size()==1) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    } else {
        if (a.size()==1 || a[a.size()-2]<=b.back()) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
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
