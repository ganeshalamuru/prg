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


int solvee(string str) {
    int n = str.size();
    int s=0,e=n-1;
    while(s<e && str[s]==str[e])
        s++,e--;
    vector<int>palindrome(n,0);
    int i=(n-1)/2,j=n/2;
    while(i>=s && j<=e && str[i]==str[j])
        palindrome[i]=palindrome[j]=1,i--,j++;
    vector<int> freq1(26,0),freq2(26,0);
    int ans = INT_MAX;
    i=s,j=e;
    while(i<j) {
        freq1[str[i]-'a']++,freq2[str[j]-'a']++;
        if ((i+1>=j || palindrome[i+1]==1) && freq1==freq2) {
            ans = min(ans, i-s+1);
        }
        i++,j--;
    }
    while(i<=e) {
        freq1[str[i]-'a']++,freq2[str[i]-'a']--;
        bool subset=true;
        for(int z=0;z<26;z++) {
            if (freq2[z]>freq1[z]) {
                subset=false;
                break;
            }
        }
        if (subset)
            ans=min(ans,i-s+1);
        i++;
    }
    return ans;
}


void solve() {
	string str;
    cin >> str;
    int ans = solvee(str);
    reverse(str.begin(), str.end());
    ans = min(ans, solvee(str));
    if (ans == INT_MAX)
        cout << 0 << "\n";
    else
        cout << ans << "\n";
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
