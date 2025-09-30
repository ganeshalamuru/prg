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
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    int cnt = 0;
    for(int i=0;i<n;i++) {
        cin >> b[i];
        if (b[i]==-1)
            cnt++;
    }
    if (cnt == n) {
        int minn=INT_MIN,maxx=INT_MAX;
        for(int i=0;i<n;i++) {
            minn=max(a[i],minn);
            maxx=min(maxx,a[i]+k);
        }
        cout << maxx-minn+1 << "\n";
        return;
    }
    set<int>summ;
    for(int i=0;i<n;i++) {
        if (b[i]!=-1) {
            summ.insert(a[i]+b[i]);
        }
    }
    if (summ.size()>1) {
        cout << 0 << "\n";
    } else {
        for(int i=0;i<n;i++) {
            if (b[i]!=-1)
                continue;
            int req = *summ.begin() - a[i];
            if (req<0 || req>k) {
                cout << 0 << "\n";
                return;
            } 
        }
        cout << 1 << "\n";
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
