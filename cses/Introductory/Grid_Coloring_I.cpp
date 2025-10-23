#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,m;
    cin >> n >> m;
    map<int,char> revcharmap{{0b0001,'A'},{0b0010,'B'},{0b0100,'C'},{0b1000,'D'}};
    vector<vector<int>> arr(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++) {
        string s;
        cin >> s;
        for(int j=1;j<=m;j++) {
            arr[i][j] = (1<<(s[j-1]-'A'));
        }
    }
    vector<vector<int>>ans(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int usedchars = 0|arr[i][j]|ans[i-1][j]|ans[i][j-1];
            int availchars = 0b1111^usedchars;
            ans[i][j]=availchars&(-availchars); // select lowest alphabet
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cout << revcharmap[ans[i][j]];
        }
        cout << "\n";
    }

}


int main() {
    fast;
    int t = 1;
    //cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
