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

vector<int> sgtreeplus,sgtreminus;
int sgtreebasesz=1;

void updatesgtree(vector<int>&sgtree, int i, int val) {
    i+=sgtreebasesz;
    sgtree[i]=val;
    i/=2;
    while (i>0) {
        sgtree[i]=min(sgtree[2*i],sgtree[2*i + 1]);
        i/=2;
    }
}

int querymin(vector<int>&sgtree,int a,int b) {
    a+=sgtreebasesz;
    b+=sgtreebasesz;
    int minp = INT_MAX;
    while (a<=b) {
        if (a%2 == 1) minp=min(minp,sgtree[a++]);
        if (b%2 == 0) minp=min(minp,sgtree[b--]);
        a/=2,b/=2;
    }
    return minp;
    
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
    sgtreeplus.resize(sgtreebasesz<<1);
    sgtreminus.resize(sgtreebasesz<<1);
    for(int i=0;i<n;i++) {
        updatesgtree(sgtreeplus,i,arr[i]+i);
        updatesgtree(sgtreminus,i,arr[i]-i);
    }
    for(int i=0,typ,k,x;i<q;i++) {
        cin >> typ;
        if (typ==1) {
            cin >> k >> x;
            k--;
            updatesgtree(sgtreeplus,k,x+k);
            updatesgtree(sgtreminus,k,x-k);
        } else {
            cin >> k;
            k--;
            cout << min(querymin(sgtreeplus,k,n-1)-k,querymin(sgtreminus,0,k)+k) << "\n";
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
