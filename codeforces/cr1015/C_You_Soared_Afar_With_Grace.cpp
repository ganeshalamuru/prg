#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<int>a(n+1),b(n+1),aind(n+1);
    for(int i=1;i<=n;i++)
        cin >> a[i],aind[a[i]]=i;
    for(int i=1;i<=n;i++)
        cin >> b[i];
    vector<int> eq;
    for(int i=1;i<=n;i++) {
        if (a[i]==b[i]) {
            eq.push_back(i);
            continue;
        }
        if (b[aind[b[i]]]!=a[i]) {
            cout << -1 << "\n";
            return;
        }
    }
    if (n%2==1 && (eq.size()==0 || eq.size()>1)) {
        cout << -1 << "\n";
        return;
    }
    if (n%2==0 && eq.size()>0) {
        cout << -1 << "\n";
        return;
    }
    int i=n/2,j=n/2+1;
    vector<pii> ops;
    if (n%2==1) {
        if (eq[0] != j) {
            ops.push_back({j,eq[0]});
            swap(a[j],a[eq[0]]),swap(b[j],b[eq[0]]);
            aind[a[j]]=j;
            aind[a[eq[0]]]=eq[0];
        }
        j++;
    }
    while (i>0 && j<=n) {
        if (aind[b[i]]!=j) {
            int ind = aind[b[i]];
            ops.push_back({j,ind});
            swap(a[j],a[ind]),swap(b[j],b[ind]);
            aind[a[j]]=j;
            aind[a[ind]]=ind;
        }
        i--,j++;
    }
    cout << ops.size() << "\n";
    for(int z=0;z<ops.size();z++) {
        cout << ops[z].F << " " << ops[z].S << "\n";
    }


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
