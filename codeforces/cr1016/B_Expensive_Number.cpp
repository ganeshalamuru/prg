#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	string s;
    cin >> s;
    if (s.size()==1) {
        cout << 0 << "\n";
        return;
    }
    int n = s.size();
    int nonzerocnt = 0;
    int ans = n-1;
    for(int i=0;i<n;i++) {
        if (s[i]=='0')
            continue;
        ans = min(ans,nonzerocnt+n-(i+1));
        nonzerocnt++;
    }
    cout << ans << "\n";
    


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
