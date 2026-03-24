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


vector<int> sgtree;
int sgtreebasesz = 1;

void update(int i, int val) {
    i+=sgtreebasesz;
    sgtree[i]=val;
    i/=2;
    while (i>0) {
        sgtree[i]=sgtree[2*i] + sgtree[2*i+1];
        i/=2;
    }
}

int query(int a, int b) {
    a+=sgtreebasesz;
    b+=sgtreebasesz;
    int ans = 0;
    while (a<=b) {
        if (sgtree[a%2 == 1]) ans+=sgtree[a++];
        if (sgtree[b%2 == 0]) ans+=sgtree[b--];
        a/=2,b/=2;
    }
    return ans;
}

void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    vector<array<int,3>> queries(q);
    for(int i=0,a,b;i<q;i++) {
        cin >> a >> b;
        a--,b--;
        queries[i]={a,b,i};
    }
    sort(all(queries),[](const auto &a, const auto &b){return a[1]<b[1];});
    while (sgtreebasesz<n) {
        sgtreebasesz<<=1;
    }
    sgtree.resize(sgtreebasesz<<1);
    map<int,int> pind;
    vector<int> ans(q);
    for(int i=0,j=0;i<n;i++) {
        if (pind.find(arr[i]) != pind.end())
            update(pind[arr[i]],0);
        update(i,1);
        pind[arr[i]]=i;
        while (j<q && queries[j][1]<=i) {
            ans[queries[j][2]]=query(queries[j][0], queries[j][1]);
            j++;
        }
    }
    for(int i=0;i<q;i++) {
        cout << ans[i] << "\n";
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
