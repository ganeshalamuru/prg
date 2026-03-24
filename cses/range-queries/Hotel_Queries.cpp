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
int N=0;


void update(int i, int val) {
    i += N;
    sgtree[i]=val;
    int k = i/2;
    while (k>0) {
        sgtree[k]= max(sgtree[2*k],sgtree[2*k+1]);
        k/=2;
    }
}
int querymax(int l, int r) {
    l+=N, r+=N;
    int maxx = 0;
    while (l<=r) {
        if (l%2 == 1) maxx = max(maxx,sgtree[l++]);
        if (r%2 == 0) maxx = max(maxx,sgtree[r--]);
        l/=2,r/=2;
    }
    return maxx;
}



void solve() {
	int n,m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int &num:arr)
        cin >> num;
    int pow2=0;
    while((1<<pow2)<n)
        pow2++;
    N = (1<<pow2);
    sgtree.resize(2*N);
    for(int i=0;i<n;i++) {
        update(i,arr[i]);
    }
    vector<int> queryans(m,-1);
    for(int i=0,query;i<m;i++) {
        cin >> query;
        int l=0,r=n-1;
        while(l<r) {
            int mid = l + (r-l)/2;
            if (querymax(0,mid)>=query) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        if (querymax(0,l)>=query) {
            queryans[i]=l;
            arr[l]-=query;
            update(l,arr[l]);
        }
    }
    for(int i=0;i<m;i++) {
        cout << queryans[i]+1 << " ";
    }
    cout << "\n";

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
