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
    int minval;
    Node* left;
    Node* right;
};

Node* init_sgtree(int l,int r, vector<int>&arr) {
    if (l==r) {
        return new Node(l,r,arr[l],nullptr,nullptr);
    }
    int mid = l + (r-l)/2;
    Node* left = init_sgtree(l,mid,arr);
    Node* right = init_sgtree(mid+1,r,arr);
    int minval = min(left->minval, right->minval);
    return new Node(l,r,minval,left,right);
}
int find_minval(int l, int r, Node* node) {
    if (node->l==l && node->r==r)
        return node->minval;
    int mid = node->l + (node->r-node->l)/2;
    if (r<=mid) {
        return find_minval(l,r, node->left);
    } else if (l<=mid) {
        return min(find_minval(l,mid,node->left),find_minval(mid+1,r,node->right));
    } else {
        return find_minval(l,r,node->right);
    }
}


void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    Node* sgtree = init_sgtree(1,n,arr);
    while (q--) {
        int l,r;
        cin >> l >> r;
        cout << find_minval(l,r,sgtree) << "\n";
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
