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


vector<int> bit;
void initbit(int sz) {
    bit.clear();
    bit.resize(sz+1,0);
} 

void update(int i) {
    while(i<bit.size()) {
        bit[i]++;
        i+=i-(i&(i-1));
    }
}

int sum(int i) {
    int sum = 0;
    while(i>0) {
        sum+=bit[i];
        i=i&(i-1);
    }
    return sum;
}


void solve() {
	int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> arr(m);
    for(int i=0;i<n;i++) {
        cin >> a[i];
        arr[a[i]].push_back(i);
    }
    initbit(m);
    ll inv = 0;
    for(int i=n-1;i>=0;i--)
        inv+=sum(a[i]),update(a[i]+1);
    cout << inv << "\n";
    for(int i=1;i<m;i++) {
        int numsz = arr[m-i].size();
        for(int j=0;j<numsz;j++) {
            int ind = arr[m-i][j];
            inv+=(ind-j)-(n-1-ind-(numsz-(j+1)));
        }
        cout << inv << "\n";
    }

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
