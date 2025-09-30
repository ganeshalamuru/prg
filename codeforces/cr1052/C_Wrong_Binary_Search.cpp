#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    string s;
    cin >> s;
    s='0'+s;
    vector<int>arr(n+1);
    for(int i=0;i<n+1;i++)
        arr[i]=i;
    int i=1;
    while(i<n+1) {
        if (s[i]=='1') {
            i++;
            continue;
        } else {
            int j=i;
            while(j<n+1 && s[j]=='0')
                j++;
            if (j-i==1) {
                cout << "NO\n";
                return;
            }
            for(int z=j-1,y=i;z>=i;z--,y++) {
                arr[z]=y;
            }
            i=j;
        }
    }
    cout << "YES\n";
    for(int i=1;i<=n;i++) {
        cout << arr[i] << " ";
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
