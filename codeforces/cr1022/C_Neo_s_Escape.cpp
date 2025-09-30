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
	int n;
    cin >> n;
    vector<int> arr(n,0);
    map<int,set<int>,greater<int>> mp;
    for(int i=0;i<n;i++)
        cin >> arr[i],mp[arr[i]].insert(i);
    set<pii,greater<pii>>ss;
    vector<int> vis(n,0);
    int ans = 0;
    for(auto itr=mp.begin();itr!=mp.end();itr++) {
        while (itr->second.size()>0) {
            if (ss.empty() || ss.begin()->first!=itr->first) {
                ans++;
                auto itr2 = itr->second.begin();
                ss.insert({itr->first,*itr2});
                vis[*itr2]=1;
                itr->second.erase(itr2);
            } else {
                itr->second.erase(ss.begin()->second);
            }
            auto pp = *ss.begin();
            ss.erase(*ss.begin());
            if (pp.second+1<n && vis[pp.second+1]==0) {
                vis[pp.second+1]=1;
                ss.insert({arr[pp.second+1],pp.second+1});
            }
            if (pp.second-1>=0 && vis[pp.second-1]==0) {
                vis[pp.second-1]=1;
                ss.insert({arr[pp.second-1],pp.second-1});
            }
        }
            
    }
    cout << ans << "\n";

}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
