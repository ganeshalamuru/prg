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
    string str="@#";
    for(int i=0;i<s.size();i++)
        str.push_back(s[i]),str.push_back('#');
    str.push_back('$');
    vector<int> len(str.size(),0);
    int l=1,r=1;
    for(int i=1;i+1<str.size();i++) {
        len[i]=min(r-i,len[l+r-i]);
        while(str[i-len[i]]==str[i+len[i]])
            len[i]++;
        if (i+len[i]>r) {
            l = i - len[i];
            r = i + len[i];
        }
    }
    str.pop_back();
    int chtoadd = str.size();
    for(int j=1;j+1<str.size();j++) {
        if (j+len[j]== str.size()) {
            chtoadd=j-len[j];
            break;
        }
    }
    
    for(int j=chtoadd;j>=1;j--) {
        str.push_back(str[j]);
    }
    for(int j=1;j+1<str.size();j++) {
        if (str[j]!='#')
            cout << str[j];
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
