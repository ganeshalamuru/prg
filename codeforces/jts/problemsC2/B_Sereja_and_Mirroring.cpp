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


bool checkmirrormat(vector<bitset<100>> &smallmat, vector<bitset<100>> &bigmat) {
    // zero mirrorings
    int i=0,j=0;
    while(i<smallmat.size() && j<bigmat.size() && smallmat[i]==bigmat[j])
        i++,j++;
    if (i==smallmat.size() && j==bigmat.size())
        return true;
    // one or more mirrorings
    vector<bitset<100>> mirsmalmat = smallmat;
    for(auto itr = smallmat.rbegin();itr!= smallmat.rend();itr++) {
        mirsmalmat.push_back(*itr);
    }
    i=0,j=0;
    while(j<bigmat.size() && mirsmalmat[i] == bigmat[j]) {
        j++, i = (i+1)%(mirsmalmat.size());
    }
    int szbg = bigmat.size(), szsmalmir = mirsmalmat.size();
    int ratio = szbg / szsmalmir;
    if (j==bigmat.size() && i==0 && ((ratio-1)&ratio)==0)
        return true;
    return false;
}


void solve() {
	int n,m;
    cin >> n >> m;
    vector<bitset<100>> mat(n,bitset<100>(0));
    for(int i=0;i<n;i++) {
        int num = 0;
        for(int j=0, bit;j<m;j++)
            cin >> bit, mat[i][m-1-j] = bit;
    }
    for(int i=0;i<n-1;i++) {
        vector<bitset<100>> cutmat(i+1);
        for(int j=0;j<=i;j++)
            cutmat[j] = mat[j];
        if (checkmirrormat(cutmat, mat)) {
            cout << i+1 << "\n";
            return;
        }
    }
    cout << n << "\n";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
