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
    vector<int>freq(101,0);
    for(int i=0,x;i<n;i++) {
        cin >> x;
        freq[x]++;
    }
    for(int i=0;i<101;i++) {
        if (freq[i]>1) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";


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
