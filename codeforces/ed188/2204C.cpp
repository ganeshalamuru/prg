#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;



void solve() {
	ll a,b,c,m;
    cin >> a >> b >> c >> m;
    vector<ll> ans(3,0);
    ans[0]=6ll*(m/a);
    ans[1]=6ll*(m/b);
    ans[2]=6ll*(m/c);

    ll lcm01 = a*b/__gcd(a,b),lcm12=b*c/__gcd(b,c),lcm20=c*a/__gcd(c,a);
    ll lcm012 = c*lcm01/__gcd(c,lcm01);
    ans[0]-=( 3*(m/lcm01 + m/lcm20) - 2*(m/lcm012) );
    ans[1]-=( 3*(m/lcm01 + m/lcm12) - 2*(m/lcm012) );
    ans[2]-=( 3*(m/lcm12 + m/lcm20) - 2*(m/lcm012) );
    
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
