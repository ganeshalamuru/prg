#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;

void solve() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int>ind(k,INT_MAX);
    set<pair<int,char>,greater<pair<int,char>>> ss;
    for(int i=0;i<k;i++)
        ss.insert({ind[i],i});
    vector<int>dp(n,0);
    for(int i=n-1;i>=0;i--) {
        int ch = s[i]-'a';
        ss.erase({ind[ch],ch});
        ind[ch]=i;
        ss.insert({ind[ch],ch});
        if (ss.begin()->F==INT_MAX) {
            dp[i]=0;
        } else {
            if (ss.begin()->F+1<n) {
                dp[i] = 1+dp[ss.begin()->F+1];
            } else {
                dp[i]=1;
            }
        }
    }
    vector<vector<int>>inds(k);
    for(int i=0;i<n;i++) {
        inds[s[i]-'a'].push_back(i);
    }
    int q;
    cin >> q;
    while(q--) {
        string str;
        cin >> str;
        int j=0;
        for(int i=0;i<str.size();i++) {
            auto itr=lower_bound(all(inds[str[i]-'a']), j);
            if (itr == inds[str[i]-'a'].end()) {
                j=-1;
                break;
            }
            j=(*itr)+1;
        }
        if (j==-1) {
            cout << 0 << "\n";
        } else if (j==n) {
            cout << 1 << "\n";
        } else {
            cout << dp[j] + 1 << "\n";
        }
    }


}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
