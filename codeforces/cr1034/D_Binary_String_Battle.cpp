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
	int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int onecnt = 0;
    for(char &ch:s) {
        if (ch=='1')
            onecnt++;
    }
    int tmp = (n+1)/2 + ((n+1)%2);
    if (onecnt<=k) {
        cout << "Alice\n";
    } else if (k>=tmp) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
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
