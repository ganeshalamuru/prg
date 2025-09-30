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
	ll a,b,c;
    cin >> a >> b >> c;
    if ((a+b+c)%3!=0) {
        cout << "No\n";
        return;
    }
    int mid = (a+b+c)/3;
    if (mid>=a && mid>=b && mid<=c) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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
