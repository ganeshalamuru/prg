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



void solve(vector<int>&g) {
    int n;
    cin >> n;
    if (n>1300 || g[n]>0) {
        cout << "first\n";
    } else {
        cout << "second\n";
    }


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;
    vector<int> g(1301);
    g[1]=g[2]=0;
    for(int i=3;i<int(g.size());i++) {
        set<int> vals;
        for(int j=1;j<i;j++) {
            int rem = i-j;
            if (j!=rem)
                vals.insert(g[j]^g[rem]);
        }
        int mex = 0;
        for(int j=0;auto val:vals) {
            if (j==val)
                mex++,j++;
            else
                break;
        }
        g[i]=mex;
    }
    while(t--) {
        solve(g);
    }
    
    return 0;
}
