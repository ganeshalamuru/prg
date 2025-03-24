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


string xorstr(string a, string b) {
    string xxor = "";
    int n = a.size(), m = b.size();
    int i=n-1, j=m-1;
    while(i >=0 && j>= 0) {
        int fbit = (a[i]-'0')^(b[j]-'0');
        xxor.push_back(fbit+'0');
        i--,j--;
    }
    while(i>=0) {
        xxor.push_back(a[i]);
        i--;
    }
    while (j>=0) {
        xxor.push_back(b[j]);
        j--;
    }
    reverse(xxor.begin(), xxor.end());
    return xxor;
}

void solve() {
	string str;
    cin >> str;
    int n = str.size();
    int zind = -1;
    for(int i=0;i<n;i++) {
        if (str[i]=='0') {
            zind = i;
            break;
        }
    }
    if (zind == -1) {
        cout << 1 << " " << n << " "<< 1 << " "<< 1 << "\n";
        return;
    }
    int len = n-zind;
    deque<char> dq;
    for(int i=0;i<len-1;i++) {
        dq.push_back(str[i]);
    }
    string maxstr = str;
    int a=0,b=len-1;
    for(int i=len-1;i<n;i++) {
        dq.push_back(str[i]);
        string temp = "";
        for(auto &ch:dq)
            temp.push_back(ch);
        string xxor = xorstr(str, temp);
        if (xxor > maxstr) {
            b = i, a = i-len+1;
            maxstr = xxor;
        }
        dq.pop_front();
    }
    cout << 1 << " " << n << " " << a+1 << " " << b+1 << "\n";
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
