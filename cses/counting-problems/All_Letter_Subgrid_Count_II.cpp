#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second
 
template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int,int>;
 
 
 
void solve() {
	int n,k;
    cin >> n >> k;
    vector<string> grid(n);
    for(int i=0;i<n;i++) {
        cin >> grid[i];
    }

    ll ans = 0;
    for(int i=0;i<n;i++) {
        array<int,500> colmask{};
        for(int j=i;j<n;j++) {
            for(int z=0;z<n;z++) {
                colmask[z]|=(1<<(grid[j][z]-'A'));
            }
            array<int,501> lstk,lorstk,rstk,rorstk;
            int lstkind=0,rstkind=0;
            lstk[0]=lorstk[0]=rstk[0]=rorstk[0]=0;
            int r=0;
            while (r<n) {
                rstk[rstkind+1]=colmask[r];
                rorstk[rstkind+1]=rorstk[rstkind]|rstk[rstkind+1];
                rstkind++;
                while ((rorstk[rstkind] | lorstk[lstkind]) == (1<<k)-1) {
                    ans+=n-r;
                    if (lstkind <= 0) {
                        while(rstkind > 0) {
                            lstk[lstkind+1]=rstk[rstkind];
                            lorstk[lstkind+1]=lorstk[lstkind]|lstk[lstkind+1];
                            lstkind++;
                            rstkind--;
                        }
                    }
                    lstkind--;  
                }
                r++;
            }
        }
    }
    cout << ans << "\n";
 
 
}
 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
 
    while(t--) {
    	solve();
    }
    
    return 0;
}