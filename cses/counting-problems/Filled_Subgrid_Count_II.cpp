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
    vector<vector<int>> vh(n,vector<int>(n));
    vh[0][0]=1;
    for(int j=1;j<n;j++)
        vh[0][j]=1;
    
    for(int i=1;i<n;i++) {
        for(int j=0;j<n;j++) {
            if (grid[i-1][j]==grid[i][j])
                vh[i][j]=1+vh[i-1][j];
            else
                vh[i][j]=1;
        }
    }
    
    vector<vector<ll>> numrec(n,vector<ll>(n));
    numrec[0][0]=1;
    for(int i=0;i<n;i++) {
        vector<int>prevsmall(n);
        stack<pair<ll,ll>> stk;
        stk.push({INT_MIN,-1});
        numrec[i][0]=vh[i][0];
        stk.push({vh[i][0],0});
        for(int j=1;j<n;j++) {
            if (grid[i][j]==grid[i][j-1]) {
                while (stk.top().F>vh[i][j])
                    stk.pop();
            } else {
                stk.push({INT_MIN,j-1});
            }
            numrec[i][j]=vh[i][j]*(j-stk.top().S);
            if (stk.top().S>=0 && grid[i][j]==grid[i][stk.top().S])
                numrec[i][j]+=numrec[i][stk.top().S];
            stk.push({vh[i][j],j});
        }
    }
    vector<ll>ans(k,0);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            ans[grid[i][j]-'A']+=numrec[i][j];
        }
    }
    for(auto x:ans)
        cout << x << "\n";


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
