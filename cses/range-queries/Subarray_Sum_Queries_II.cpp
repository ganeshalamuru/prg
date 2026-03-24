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

// 0-maxprefixsum, 1-maxsuffixsum, 2-sum, 3-maxsubbarrysum
vector<array<ll,4>> sgtree;
int sgtreebasesz=1;

void update(int i,int val) {
    i+=sgtreebasesz;
    sgtree[i][0]=sgtree[i][1]=sgtree[i][3]=max(0,val);
    sgtree[i][2]=val;
    i/=2;
    while (i>0) {
        sgtree[i][0]=max(sgtree[2*i][0], sgtree[2*i][2]+sgtree[2*i+1][0]);
        sgtree[i][1]=max(sgtree[2*i+1][1], sgtree[2*i+1][2]+sgtree[2*i][1]);
        sgtree[i][2]=sgtree[2*i][2]+sgtree[2*i+1][2];
        sgtree[i][3]=max(max(sgtree[2*i][3],sgtree[2*i+1][3]),sgtree[2*i][1]+sgtree[2*i+1][0]);
        i/=2;
    }
}

ll query(int a, int b) {
    a+=sgtreebasesz;
    b+=sgtreebasesz;
    vector<array<ll,4>> leftrngs,rightrngs;
    ll maxsubsum = 0;
    while (a<=b) {
        if (a%2 == 1) {
            leftrngs.push_back(sgtree[a++]);
        }
        if (b%2 == 0) {
            rightrngs.push_back(sgtree[b--]);
        }
        a/=2,b/=2;
    }
    vector<array<ll,4>> reqrngs(leftrngs);
    for(auto itr=rightrngs.rbegin();itr!=rightrngs.rend();itr++)
        reqrngs.push_back(*itr);
    for(int i=0;i<int(reqrngs.size());i++) {
        if (maxsubsum<reqrngs[i][3])
            maxsubsum=reqrngs[i][3];
        ll psum = reqrngs[i][1];
        int j=i+1;
        while (j<int(reqrngs.size())) {
            if (maxsubsum<psum+reqrngs[j][0])
                maxsubsum=psum+reqrngs[j][0];
            psum+=reqrngs[j][2];
            j++;
        }
    }
    return maxsubsum;
}



void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    while (sgtreebasesz<n) {
        sgtreebasesz<<=1;
    }
    sgtree.resize(sgtreebasesz<<1);
    for(int i=0;i<n;i++) {
        update(i,arr[i]);
    }
    while (q--) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        cout << query(a,b) << "\n";
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
