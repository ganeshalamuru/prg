#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).end()
#define F first
#define S second
const ll mod = 1e9+7;


struct segt {
    int l;
    int r;
    int maxdiffval;
    segt* left;
    segt*right;
};

segt* buildsegt(int l,int r, vector<int> &b) {
    if (l>r)
        return nullptr;
    if (l==r)
        return new segt{l,r,b[l]-l,nullptr,nullptr}; 
    int mid = l+(r-l)/2;
    segt* leftnode = buildsegt(l,mid,b);
    segt* rightnode = buildsegt(mid+1,r,b);
    return new segt{l,r,max(leftnode->maxdiffval,rightnode->maxdiffval),leftnode,rightnode};
}

int querysegt(segt* head, int l,int r) {
    if (head->l==l && head->r==r)
        return head->maxdiffval;
    int mid=head->l+(head->r-head->l)/2;
    if (r<=mid) {
        return querysegt(head->left,l,r);
    } else if (l>mid) {
        return querysegt(head->right,l,r);
    } else {
        return max(querysegt(head->left,l,mid),querysegt(head->right,mid+1,r));
    }
}

void solve() {
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<int> b(n);
    for(int i=0;i<n;i++) {
        auto itr = lower_bound(arr.begin(), arr.end(), 2*arr[i]);
        b[i]=distance(arr.begin(), itr);
    }
    segt* head=buildsegt(0,n-1,b);
    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        l--,r--;
        if (b[l]>r) {
            cout << 0 << "\n";
            continue;
        }
        int ll=1,rr=(r-l+1)/2;
        while(ll<rr) {
            int mid = ll+(rr-ll+1)/2;
            int maxdiff=querysegt(head,l,l+mid-1);
            if (mid+max(maxdiff,mid)<=r-l+1) {
                ll=mid;
            } else {
                rr=mid-1;
            }
        }
        cout << ll << "\n";
    }


}


int main() {
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
