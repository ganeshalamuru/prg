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
	int n,q;
    cin >> n >> q;
    vector<vector<int>> grid(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) {
        string str;
        cin >> str;
        for(int j=1;char ch:str) {
            if (ch=='*')
                grid[i][j]=1;
            j++;
        }
    }
    vector<vector<int>> psum(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            psum[i][j]= grid[i][j]+psum[i][j-1]+psum[i-1][j]-psum[i-1][j-1];
        }
    }
    while (q--) {
        int y1,x1,y2,x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int maxy = max(y1,y2),miny = min(y1,y2);
        int maxx = max(x1,x2),minx=min(x1,x2);
        cout << psum[maxy][maxx]-psum[maxy][minx-1]-psum[miny-1][maxx]+psum[miny-1][minx-1] << "\n";
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
