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
    ll value;
    int l,r;
    Node *left=nullptr;
    Node *right=nullptr;
    Node(ll v, int lind, int rind):value(v),l(lind),r(rind){}; 
};

Node* buildSgtree(int l, int r, vector<int> &arr) {
    if (l==r)
        return new Node(arr[l],l,r);
    int mid = l + (r-l)/2;
    Node* left = buildSgtree(l,mid,arr);
    Node* right = buildSgtree(mid+1,r,arr);
    Node* node = new Node(left->value+right->value,l,r);
    node->left = left;
    node->right = right;
    return node;
}

Node* update(Node* node,int i, int val) {
    if (i<node->l || node->r<i)
        return node;
    if (node->l == i && node->r == i)
        return new Node(val,i,i);
    Node* left =  update(node->left,i,val);
    Node* right = update(node->right,i,val);
    Node* nnode = new Node(left->value + right->value,node->l, node->r);
    nnode->left = left;
    nnode->right = right;
    return nnode;
}

ll querysum(Node* node, int a, int b) {
    if (b<node->l || node->r<a)
        return 0;
    if (a<=node->l && node->r<=b)
        return node->value;
    return querysum(node->left,a,b) + querysum(node->right,a,b);
}


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    vector<ll>psum(n+1);
    for(int i=1;i<=n;i++)
        psum[i]=psum[i-1]+arr[i];    
    Node *head = buildSgtree(1,n,arr);
    int maxcopies = 0;
    map<int, Node*> arrcopies;
    arrcopies[++maxcopies] = head;
    while (q--) {
        int typ,k,a,b;
        cin >> typ;
        if (typ == 1) {
            cin >> k >> a >> b;
            arrcopies[k]=update(arrcopies[k],a,b);
        } else if (typ == 2) {
            cin >> k >> a >> b;
            cout << querysum(arrcopies[k],a,b) << "\n";
        } else {
            cin >> k;
            arrcopies[++maxcopies]=arrcopies[k];
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
