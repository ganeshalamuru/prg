#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define all(v) (v).begin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;

vector<int> pa,dsurank;

void initdsu(int n) {
    pa.resize(n),dsurank.resize(n);
    for(int i=0;i<n;i++)
        pa[i]=i,dsurank[i]=1;
}

int findpa(int u) {
    if (pa[u]==u)
        return u;
    return pa[u]=findpa(pa[u]);
}

void dsuunion(int u,int v) {
    int upa = findpa(u);
    int vpa = findpa(v);
    if (upa==vpa) {
        return;
    }
    int urank = dsurank[upa],vrank = dsurank[vpa];
    if (urank<vrank) {
        pa[upa]=vpa;
        dsurank[vpa]+=dsurank[upa];
    } else {
        pa[vpa]=upa;
        dsurank[upa]+=dsurank[vpa];
    }
}



void solve() {
    int n,m;
    cin >> n >> m;
    initdsu(n);
    int ans = 0;
    for(int i=0,u,v;i<m;i++) {
        cin >> u >> v;
        u--,v--;
        if (findpa(u)==findpa(v))
            ans++;
        else
            dsuunion(u,v);
    }
    cout << ans << "\n";

}
int main() {
    fast;
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}