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

vector<vector<int>> bit;

void update(int y, int x, int val) {
    while (y<int(bit.size())) {
        int tmpx = x;
        while (tmpx<int(bit.size())) {
            bit[y][tmpx]+=val;
            tmpx+=(tmpx&-tmpx);
        }
        y+=(y&-y);
    }
}

int sum(int y, int x) {
    int ans = 0;
    while (y>0) {
        int tmpx=x;
        while (tmpx>0) {    
            ans+=bit[y][tmpx];
            tmpx-=(tmpx&-tmpx);
        }
        y-=(y&-y);
    }
    return ans;
    
}

int sum(int y1, int x1, int y2, int x2) {
    int ymax = max(y1,y2), ymin=min(y1,y2);
    int xmax = max(x1,x2), xmin=min(x1,x2); 
    return sum(ymax,xmax)-sum(ymax,xmin-1)-sum(ymin-1,xmax)+sum(ymin-1,xmin-1);
}

void solve() {
	int n,q;
    cin >> n >> q;
    vector<vector<int>> grid(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++) {
        string str;
        cin >> str;
        for(int j=1;char ch:str) {
            if (ch=='*')
                grid[i][j]=1;
            j++;
        }
    }
    bit.resize(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if (grid[i][j])
                update(i,j,1);
        }
    }
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int y,x;
            cin >> y >> x;
            if (grid[y][x]==0) {
                update(y,x,1);
                grid[y][x]=1;
            } else {
                update(y,x,-1);
                grid[y][x]=0;
            }
        } else {
            int y1,x1,y2,x2;
            cin >> y1 >> x1 >> y2 >> x2;
            cout << sum(y1,x1,y2,x2) << "\n";
        }
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
