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
	int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    vector<vector<string>>b(m,vector<string>(n));
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++)
            cin >> b[i][j];
    }
    for(int i=0;i<n;i++) {
        bool exists = false;
        for(int j=0;j<m;j++) {
            if (b[j][i]==a[i]) {
                exists=true;
                break;
            }
        }
        if (!exists) {
            cout << -1 << "\n";
            return;
        }
    }
    int longest = 0;
    for(int i=0;i<m;i++) {
        int cnt = 0;
        for(int j=0;j<n;j++) {
            if (a[j]==b[i][j])
                cnt++;
        }
        longest = max(longest, cnt);
    }
    cout << 3*n - 2*longest << "\n";

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
