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
	int n,m;
    cin >> n >> m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<m;i++)
        cin >> b[i];
    vector<int>p(m,INT_MAX),s(m,INT_MIN);
    int i=0,j=0;
    while(i<n && j<m) {
        if (a[i]>=b[j]) {
            p[j]=i;
            j++;
        }
        i++;
    }
    i=n-1,j=m-1;
    while(i>=0 && j>=0) {
        if (a[i]>=b[j]) {
            s[j]=i;
            j--;
        }
        i--;
    }
    if (p[m-1]!=INT_MAX) {
        cout << 0 << "\n";
        return;
    }
    if (m==1) {
        cout << b[0] << "\n";
        return;
    }
    int mink = INT_MAX;
    for(int z=0;z<m;z++) {
        if (z==0) {
            if (s[z+1]!=INT_MIN) {
                mink = min(mink,b[z]);
            }
        } else if (z==m-1) {
            if (p[z-1]!=INT_MAX) {
                mink=min(mink,b[z]);
            }
        } else {
            if (p[z-1]<s[z+1]) {
                mink=min(mink,b[z]);
            }
        }
    }

    if (mink==INT_MAX)
        cout << -1 << "\n";
    else
        cout << mink << "\n";
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
