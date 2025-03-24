#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}

string getState(deque<char>& p1, deque<char>& p2) {
    string state = "";
    for(char ch:p1)
        state.push_back(ch);
    state.push_back('#');
    for(char ch:p2)
        state.push_back(ch);
    return state;
}

void solve(){
	int n;
    cin >> n;
    deque<char> p1, p2;
    int k1,k2;
    cin >> k1;
    for(int x,i=0;i<k1;i++)
        cin >> x, x--,p1.push_back(x+'0');
    cin >> k2;
    for(int x,i=0;i<k2;i++)
        cin >> x, x--,p2.push_back(x+'0');
    set<string> state;
    int fights = 0;
    while(state.find(getState(p1,p2)) == state.end()) {
        if (p1.empty() || p2.empty()) {
            cout << fights << " " << (p1.empty() ? 2 : 1) << "\n";
            return;
        }
        state.insert(getState(p1,p2));
        int t1 = p1.front(), t2 = p2.front();
        p1.pop_front(),p2.pop_front();
        if (t1 > t2)
            p1.push_back(t2), p1.push_back(t1);
        else
            p2.push_back(t1), p2.push_back(t2);
        fights++;
    }
    cout << -1 << "\n";
}




signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
