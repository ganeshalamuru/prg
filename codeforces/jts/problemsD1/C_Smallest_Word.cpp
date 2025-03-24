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




void solve() {
	string s;
    cin >> s;
    int n = s.size();
    string smallest="", largest ="";
    vector<vector<int>> seq(2,vector<int>(n));
    for(int i=0;i<n;i++) {
        char ch = s[i];
        string s1 = smallest+ch;
        reverse(largest.begin(), largest.end());
        string s2 = ch+largest;
        vector<int>smalseq,largeseq;
        if (s1 < s2)
            smallest=s1,smalseq=seq[0],smalseq[i]=0;
        else
            smallest=s2,smalseq=seq[1],smalseq[i]=1;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        if (s1 < s2)
            largest=s2,largeseq=seq[1],largeseq[i]=0;
        else
            largest=s1,largeseq=seq[0],largeseq[i]=1;
        seq[0]=smalseq,seq[1] = largeseq;
    }
    for(int i=0;i<n;i++)
        cout << seq[0][i] << " ";
}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
