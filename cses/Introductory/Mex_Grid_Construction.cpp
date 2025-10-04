#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n;
    cin >> n;
    vector<vector<int>> grid(n+1,vector<int>(n+1));
    grid[1][1]=0;
    vector<set<int>> row(n+1),col(n+1);  
    row[1].insert(0),col[1].insert(0);
    for(int j=2,z=0;j<=n;j++) {

        for(int i=1;i<j;i++) {
            z=0;
            while(col[j].find(z)!=col[j].end() || row[i].find(z)!=row[i].end()) {
                z++;
            }
            grid[i][j]=z;
            col[j].insert(z),row[i].insert(z);
        }

        for(int k=1;k<j;k++) {
            z=0;
            while(col[k].find(z)!=col[k].end() || row[j].find(z)!=row[j].end()) {
                z++;
            }
            grid[j][k]=z;
            col[k].insert(z),row[j].insert(z);
        }
        z=0;
        while(col[j].find(z)!=col[j].end() || row[j].find(z)!=row[j].end()) {
            z++;
        }
        grid[j][j]=z;
        col[j].insert(z),row[j].insert(z);

    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout << grid[i][j] << " ";
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
