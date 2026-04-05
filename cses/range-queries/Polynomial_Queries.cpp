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

// 0 - sum, 1 - coefficient of x^1, 2 - coefficient of x^0
vector<array<ll, 3>> sgtree;
int sgtreebasesz = 1;



void updateval(int a, int val) {
    a+= sgtreebasesz;
    sgtree[a][0] = val;
    a/=2;
    while (a>0) {
        sgtree[a][0] = sgtree[2*a][0] + sgtree[2*a+1][0];
        a/=2;
    }
}

void applyupdate(int tind, int len, ll x1_coef, ll x0_coef) {
    sgtree[tind][0]+= x1_coef * ((1ll * (len-1) * len) / 2) + x0_coef * len;
    sgtree[tind][1]+=x1_coef;
    sgtree[tind][2]+=x0_coef;
}


void propagate(int tind, int len) {
    applyupdate(2*tind, len/2, sgtree[tind][1], sgtree[tind][2]);
    applyupdate(2*tind+1, len/2, sgtree[tind][1], sgtree[tind][1]*(len/2) + sgtree[tind][2]);
    sgtree[tind][1]=sgtree[tind][2]=0;
}

// p(x)=x+1 polynomial update
void polyrangeupdate(int a, int b, int tind, int l, int r) {
    if (b<l || r<a) return;
    int len = r-l+1;
    if (a<=l && r<=b) {
        applyupdate(tind, len, 1, 1 + l - a);
        return;
    }
    propagate(tind, len);
    int mid = l + (r-l)/2;
    polyrangeupdate(a,b,2*tind,l,mid);
    polyrangeupdate(a,b,2*tind+1,mid+1,r);
    sgtree[tind][0]=sgtree[2*tind][0] + sgtree[2*tind+1][0];
}

ll query(int a, int b, int tind, int l, int r) {
    if (b<l || r<a) return 0;
    if (a<=l && r<=b) return sgtree[tind][0];
    propagate(tind, r-l+1);
    int mid = l + (r-l)/2;
    return query(a,b,2*tind,l,mid) + query(a,b,2*tind+1,mid+1,r);
}

void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    while (sgtreebasesz<n)
        sgtreebasesz<<=1;
    sgtree.resize(sgtreebasesz<<1);
    for(int i=0;i<n;i++)
        updateval(i,arr[i]);
    while (q--) {
        int typ,a,b;
        cin >> typ >> a >> b;
        a--,b--;
        if (typ == 1) {
            polyrangeupdate(a,b,1,0,sgtreebasesz-1);
        } else {
            cout << query(a,b,1,0,sgtreebasesz-1) << "\n";
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
