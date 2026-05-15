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

vector<array<int,31>> sgtree;
int sgtreebasesz = 1;


void buildsgtree(int t, int l, int r, vector<int>&arr) {
    if (l==r) {
        if (l<int(arr.size())) {
            for(int i=0;i<31;i++) {
                if (arr[l]>=(1<<i)) 
                    sgtree[t][i]=arr[l];
                else
                    sgtree[t][i]=INT_MAX;
            }
        } else {
            for(int i=0;i<31;i++)
                sgtree[t][i]=INT_MAX;
        }
        return;
    }
    int mid = l + (r-l)/2;
    buildsgtree(2*t,l,mid,arr);
    buildsgtree(2*t+1,mid+1,r,arr);
    for(int i=0;i<31;i++)
        sgtree[t][i]=min(sgtree[2*t][i],sgtree[2*t+1][i]);
}


ll query(int a, int b, vector<array<ll,31>> &psum) {
    int l = a, r = b;
    l += sgtreebasesz, r += sgtreebasesz;
    array<int,31> smlge2i;
    smlge2i.fill(INT_MAX);
    while (l<=r) {
        if (l%2 == 1) {
            for(int i=0;i<31;i++)
                smlge2i[i]=min(smlge2i[i],sgtree[l][i]);
            l++;
        }
        if (r%2 == 0) {
            for(int i=0;i<31;i++)
                smlge2i[i]=min(smlge2i[i],sgtree[r][i]);
            r--;
        }
        l/=2,r/=2;
    }
    ll ans = 0;
    for(int i=0;i<31;i++) {
        ll sum = psum[b][i];
        if (a-1>=0) sum-=psum[a-1][i];
        ans = sum + 1;
        if (sum>=(1ll<<(i+1))-1 || smlge2i[i]<=sum+1)
            continue;
        break;
    }
    return ans;

}


void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<array<ll,31>> psum(n);
    for(int j=1;j<31;j++) {
        if (arr[0]<(1<<j))
            psum[0][j]+=arr[0];
    }
    for(int i=1;i<n;i++) {
        for(int j=1;j<31;j++) {
            psum[i][j]+=psum[i-1][j];
            if (arr[i]<(1<<j))
                psum[i][j]+=arr[i];
        }
    }
    while (sgtreebasesz<n)
        sgtreebasesz<<=1;
    sgtree.resize(sgtreebasesz<<1);
    buildsgtree(1,0,sgtreebasesz-1,arr);
    while (q--) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        cout << query(a,b,psum) << "\n";
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
