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


struct Node {
    int l;
    int r;
    int maxval;
    Node* left;
    Node* right;
};

Node* init_sgtree(int l, int r, vector<int>&val) {
    if (l==r)
        return new Node{l,r,val[l],nullptr,nullptr};
    int mid = l + (r-l)/2;
    Node* left = init_sgtree(l,mid,val);
    Node* right = init_sgtree(mid+1,r,val);
    return new Node{l,r,max(left->maxval,right->maxval),left,right};
}

void update_sgtree(int i,int newval,Node* sgtree) {
    if (sgtree->l == sgtree->r && sgtree->l == i) {
        sgtree->maxval=newval;
        return;
    }
    int mid = sgtree->l+(sgtree->r - sgtree->l)/2;
    if (i<=mid) {
        update_sgtree(i,newval,sgtree->left);
    } else {
        update_sgtree(i,newval,sgtree->right);
    }
    sgtree->maxval=max(sgtree->right->maxval, sgtree->left->maxval);
}

// unsolved
void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> val(n+1);
    for(int i=1;i<=n;i++) {
        cin >> val[i];
    }
    vector<vector<int>> adj(n+1);
    for(int i=1,a,b;i<n;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<pii> dfstimes(n+1);
    int dfstimer=0;
    function<void(int,int)> dfs = [&](int u, int p) {
        dfstimes[u].F = ++dfstimer;
        for(int v:adj[u]) {
            if (v==p) continue;
            dfs(v,u);
        }
        dfstimes[u].S = dfstimer;
    };
    dfs(1,0);
    Node* sgtree = init_sgtree(1,n,val);
    while (q--) {
        int t,s,x;
        cin >> t >> s;
        if (t==1) {
            cin >> x;
            update_sgtree(dfstimes[s].F,x,sgtree);
        } else {
            
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
