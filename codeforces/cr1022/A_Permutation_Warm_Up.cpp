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
    if (n==1 || n==2) {
        cout << n << "\n";
        return;
    }
    if (n%2==0) {
        cout << (n/2)*(n/2) + 1 << "\n";
    } else {
        cout << (((n-1)/2)*((n-1)/2 + 1)) +1 << "\n";
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
