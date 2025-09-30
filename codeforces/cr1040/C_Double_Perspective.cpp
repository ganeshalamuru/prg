#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;

vector<int> pa,ds_rank;

void init_ds(int n) {
    pa.resize(2*n);
    ds_rank.resize(2*n);
    for(int i=0;i<2*n;i++) {
        pa[i]=i;
        ds_rank[i]=1;
    }
}
int find_rep(int a) {
    if (pa[a]==a) {
        return a;
    } else {
        return pa[a]=find_rep(pa[a]);
    }
}

void dsu_union(int a, int b) {
    int arep = find_rep(a), brep=find_rep(b);
    if (arep==brep)
        return;
    int arep_rank = ds_rank[arep], brep_rank = ds_rank[brep];
    if (arep_rank < brep_rank) {
        pa[arep]=brep;
        ds_rank[brep]+=ds_rank[arep];
    } else {
        pa[brep]=arep;
        ds_rank[arep]+=ds_rank[brep];
    }
}


void solve() {
	int n;
    cin >> n;
    init_ds(n);
    vector<pii>edges(n);
    for(int i=0;i<n;i++) {
        cin >> edges[i].F >> edges[i].S;
        edges[i].F--,edges[i].S--;
    }
    vector<int> ans;
    for(int i=0;i<n;i++) {
        if (find_rep(edges[i].F)==find_rep(edges[i].S))
            continue;
        ans.push_back(i+1);
        dsu_union(edges[i].F,edges[i].S);
    }
    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

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
