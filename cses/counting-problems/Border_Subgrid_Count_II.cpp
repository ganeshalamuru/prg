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
    array<ll,26> ans{};
    for(int i=0;i<n;i++) {
        array<int,500> vconsec{};
        vconsec.fill(1);
        int j = i;
        while (j<n) {
            if (j>i) {
                for(int z=0;z<n;z++) {
                    if (grid[j][z]==grid[j-1][z])
                        vconsec[z]++;
                    else
                        vconsec[z]=0;
                }
            }
            int x = 0;
            while (x<n) {
                char ch = grid[j][x];
                int cnt = 0;
                while (x<n && grid[j][x]==ch && grid[i][x]==ch) {
                    if (vconsec[x]>=j-i+1)
                        cnt++;
                    x++;
                }
                
                int tmp = (cnt*(cnt+1))/2;
                ans[ch-'A']+= tmp;
                // cout << "i j " << i << " " << j << " ch : " << ch << " tmp: " << tmp << "\n"; 
                if (x<n && grid[j][x]==ch)
                    x++;
            }
            j++;
        }
    }
    for(int i=0;i<k;i++) {
        cout << ans[i] << "\n";
    }

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
