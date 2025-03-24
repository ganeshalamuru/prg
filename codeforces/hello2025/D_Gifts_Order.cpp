#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


struct Node {
public:
    int l,r;
    // max and min of ai - i
    int max1, min1;
    // max and min of ai - n-i+1
    int max2, min2;
    int ans1, ans2;
    Node* lnode;
    Node* rnode;
    Node(Node* ln, Node* rn) {
        lnode = ln, rnode = rn;
        l = ln->l, r = rn->r;
        umm(ln, rn);
    }
    void updateMaxsAndMins() {
        umm(lnode, rnode);
    }
    Node(int i, int n, int val) {
        l=i, r=i;
        max1=val-i, min1=val-i;
        max2=val-(n-1-i), min2=val-(n-1-i);
        lnode = nullptr, rnode = nullptr;
        ans1=0,ans2=0;
    }
private:
    void umm(Node* ln, Node* rn) {
        max1 = INT_MIN, min1 = INT_MAX, max2 = INT_MIN, min2 = INT_MAX;
        if (ln != nullptr) {
            max1 = max(max1, ln->max1);
            max2 = max(max2, ln->max2);
            min1 = min(min1, ln->min1);
            min2 = min(min2, ln->min2);
        }
        if (rn != nullptr) {
            max1 = max(max1, rn->max1);
            max2 = max(max2, rn->max2);
            min1 = min(min1, rn->min1);
            min2 = min(min2, rn->min2);
        }
        ans1 = max({ln->ans1, rn->ans1, rn->max1-ln->min1});
        ans2 = max({ln->ans2, rn->ans2, ln->max2-rn->min2});
    }
};

Node* initsegtree(int l, int r, vector<int> &arr) {
    if (l==r)
        return new Node(l, arr.size(), arr[l]);
    int mid = l + (r-l)/2;
    Node* lnode = initsegtree(l, mid, arr);
    Node* rnode = initsegtree(mid+1, r, arr);
    Node* node = new Node(lnode, rnode);
    return node;
}

void update(Node* node, int p, int x, vector<int>&arr) {
    if (node==nullptr)
        return;
    int l=node->l, r = node->r;
    if (l==r && l==p) {
        int diff = -arr[p]+x;
        node->max1+=diff, node->min1+=diff;
        node->max2+=diff, node->min2+=diff;
        return;
    }
    int mid = l+(r-l)/2;
    if (p<=mid) {
        update(node->lnode, p, x, arr);
        node->updateMaxsAndMins();
    }
    else {
        update(node->rnode, p, x, arr);
        node->updateMaxsAndMins();
    }
}


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int &num:arr)
        cin >> num;
    Node* sgt = initsegtree(0, n-1, arr);
    cout << max(sgt->ans1, sgt->ans2) << "\n";
    while(q--) {
        int p,x;
        cin >> p >> x;
        p--;
        update(sgt, p, x, arr);
        arr[p]=x;
        cout << max(sgt->ans1, sgt->ans2) << "\n";
    }
}




signed main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
