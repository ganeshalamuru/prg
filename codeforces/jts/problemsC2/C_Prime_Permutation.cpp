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


void sieve(vector<int>& prime) {
    for(auto &num:prime)
        num=1;
    prime[0] = prime[1] = 0;
    for(int i=2;i<prime.size();i++) {
        if (prime[i] != 1)
            continue;
        for(int j=i*i;j<prime.size();j+=i)
            prime[j]=0;
    }
}


void solve() {
    string str;
    cin >> str;
	vector<int> prime(str.size()+1);
    sieve(prime);
    vector<pair<int,int>> freq(26,{0,0});
    for(auto& ch:str)
        freq[ch-'a'].first++,freq[ch-'a'].second=ch-'a';
    sort(freq.rbegin(), freq.rend());
    string ans(str.size(),'#');
    int z=0;
    for(int i=2;i<prime.size();i++) {
        if (prime[i] != 1)
            continue;
        auto& freqp = freq[z];
        for(int j=i;j<prime.size();j+=i) {
            if (ans[j-1] == '#' && freqp.first > 0) {
                ans[j-1]=(char)(freqp.second+'a');
                freqp.first--;
            } else if (ans[j-1]=='#' || ans[j-1] != (char)(freqp.second + 'a')) {
                cout << "NO\n";
                return;
            }
        }
        if (freqp.first <= 0)
            z++;
            
    }
    int i=0;
    while(z<26) {
        auto& freqp = freq[z];
        while(freqp.first > 0) {
            while(i<ans.size() && ans[i]!='#')
                i++;
            ans[i] = (char)(freqp.second+'a');
            freqp.first--;
        }
        z++;
    }
    cout << "YES\n";
    cout << ans << "\n";

}




signed main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
