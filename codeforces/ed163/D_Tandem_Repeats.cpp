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


bool cmpChar(char x, char y) {
    if (x == '?' || y == '?')
        return true;
    return x==y;
}

void solve() {
	string str;
    cin >> str;
    int n = str.size(), tandStrMaxLen = 0;
    for(int len=2; len<=n; len+=2) {
        int j=0, halflen = len/2;
        bool isPrevStrTand = false;
        while(j <= n-len) {
            bool isCurStrTand = false;
            int secondHalfStrt = j+halflen;
            int firstHalfInd = j;

            if (isPrevStrTand) {
                isCurStrTand = cmpChar(str[secondHalfStrt-1], str[secondHalfStrt-1+halflen]);
            } else {
                while(firstHalfInd < secondHalfStrt && cmpChar(str[firstHalfInd], str[firstHalfInd+halflen]))
                    firstHalfInd++;
                isCurStrTand = (firstHalfInd == secondHalfStrt);
                if (!isCurStrTand) j = firstHalfInd;
            }

            if (isCurStrTand && tandStrMaxLen < len)
                tandStrMaxLen = len;
            isPrevStrTand = isCurStrTand;
            j++;
        }
    }
    cout << tandStrMaxLen << "\n";
}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
