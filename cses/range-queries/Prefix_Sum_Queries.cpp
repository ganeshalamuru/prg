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

vector<array<ll,2>> sgtree;
int sgtreebasesz = 1;
//   1
//  2   3
// 4 5  6 7
//8 9 10 11 12 13 14 15
void update(int i, ll val) {
    i+=sgtreebasesz;
    sgtree[i][0]=val;
    sgtree[i][1]=val;
    i/=2;
    while (i>0) {
        sgtree[i][0]=sgtree[i<<1][0]+sgtree[(i<<1)+1][0];
        sgtree[i][1]=max(sgtree[i<<1][1],sgtree[i<<1][0] + sgtree[(i<<1)+1][1]);
        i/=2;
    }
}

ll sum(int i, int j) {
    i+=sgtreebasesz;
    j+=sgtreebasesz;
    ll ans = 0;
    while (i<=j) {
        if (i%2 == 1) ans+=sgtree[i++][0];
        if (j%2 == 0) ans+=sgtree[j--][0];
        i/=2,j/=2;
    }
    return ans;
    
}


ll findmaxpsum(int i, int j) {
    ll rngsum=sum(i,j);
    i+=sgtreebasesz;
    j+=sgtreebasesz;
    ll maxpsum = LLONG_MIN,icsum = 0,jcsum = 0;
    while (i<=j) {
        if (i%2 == 1) {
            maxpsum = max(maxpsum, icsum + sgtree[i][1]);
            icsum+=sgtree[i][0];
            i++;
        }
        if (j%2 == 0) {
            maxpsum = max(maxpsum, rngsum-jcsum-sgtree[j][0] + sgtree[j][1]);
            jcsum+=sgtree[j][0];
            j--;
        }
        i/=2,j/=2;
    }
    return max(maxpsum,0ll);
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
    for(int i=0,type,x,y;i<q;i++) {
        cin >> type >> x >> y;
        if (type == 1) {
            x--;
            update(x,y);
        } else {
            x--,y--;
            cout << findmaxpsum(x,y) << "\n";
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
