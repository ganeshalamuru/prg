#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll INF=1e17; 
 
void solve() {
	int n,m;
    cin >> n >> m;
    vector<array<int,3>> edges;
    for(int i=0,a,b,c;i<m;i++) {
        cin >> a >> b >> c;
        edges.push_back({a,b,c});
    }
    vector<int> pa(n+1,0);
    // intilize all dis to 0
    // dis[u] after i iterations --> shortest walk to u using
    // atmost i edges from any source node
    vector<ll> dis(n+1,0);
    for(int i=0;i<n-1;i++) {
        for(auto [u,v,c]:edges) {
            if (dis[v]>dis[u]+c) {
                dis[v]=dis[u]+c;
                pa[v]=u;
            }
        }
    }
    bool chng = false;
    int cyclepathnode=0;
    for(auto [u,v,c]:edges) {
        if (dis[v]>dis[u]+c) {
            chng = true;
            dis[v]=dis[u]+c;
            pa[v]=u;
            cyclepathnode=v;
        }
    }
    if (!chng) {
        cout << "NO\n";
        return;
    }
    vector<int> negcyc;
    set<int> pnode;
    while(pnode.find(cyclepathnode)==pnode.end()) {
        negcyc.push_back(cyclepathnode);
        pnode.insert(cyclepathnode);
        cyclepathnode=pa[cyclepathnode];
    }
    negcyc.push_back(cyclepathnode);
    reverse(all(negcyc));
    while(negcyc.back()!=cyclepathnode) {
        negcyc.pop_back();
    }
    cout << "YES\n";
    for(int &v:negcyc) {
        cout << v << " ";
    }
    cout << "\n";
}
 
 
int main() {
    fast;
    int t = 1;
    // cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}