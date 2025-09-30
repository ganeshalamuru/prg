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
    vector<int> rem(4,0);
    for(int i=0;i<n;i++) {
        rem[i%4]++;
    }
    if (rem[0]!=rem[3]) {
        cout << "Alice\n";
    } else if (rem[1]!=rem[2]) {
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
