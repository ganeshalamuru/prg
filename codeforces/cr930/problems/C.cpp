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


string buildquery(vector<int> indices) {
    string query = "? ";
    for(int ind:indices) {
        query += to_string(ind) + " ";
    }
    query.pop_back();
    return query;
}


void solve(){
	int n;
    cin >> n;
    string res;
    int maxvalind = 0;
    int i=1;
    while(i<n) {
        cout << buildquery({i, i, maxvalind, maxvalind}) << "\n";
        cout.flush();
        cin >> res;
        if (res[0]=='>')
            maxvalind = i;
        i++;
    }
    vector<int> maxorvalinds{0};
    int j=1;
    while(j<n) {
        cout << buildquery({j, maxvalind, maxvalind, maxorvalinds[0]}) << "\n";
        cout.flush();
        cin >> res;
        if (res[0]=='>') {
            maxorvalinds = vector<int>();
            maxorvalinds.push_back(j);
        }
        else if (res[0]=='=') {
            maxorvalinds.push_back(j);
        }
        j++;
    }
    int minvalormaxvalind = maxorvalinds[0];
    int z = 1;
    while (z < maxorvalinds.size()) {
        cout << buildquery({maxorvalinds[z], maxorvalinds[z], minvalormaxvalind, minvalormaxvalind}) << "\n";
        cout.flush();
        cin >> res;
        if (res[0]=='<')
            minvalormaxvalind = maxorvalinds[z];
        z++;
    }
    cout << "! " << to_string(maxvalind) << " " << to_string(minvalormaxvalind) << "\n";
    cout.flush();
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
