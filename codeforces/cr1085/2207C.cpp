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

const int INF = 1e9+1;

vector<ll> sgtree;
int sgtreebasesz = 1;

void updatesgtree(int i, ll val) {
    i+=sgtreebasesz;
    sgtree[i]=val;
    i/=2;
    while (i>0) {
        sgtree[i]=max(sgtree[2*i],sgtree[2*i+1]);
        i/=2;
    }
    
}

ll querymax(int l, int r) {
    l+=sgtreebasesz;
    r+=sgtreebasesz;
    ll maxval = LLONG_MIN;
    while (l<=r) {
        if (l%2 == 1) maxval = max(maxval,sgtree[l++]);
        if (r%2 == 0) maxval = max(maxval,sgtree[r--]);
        l/=2,r/=2;
    }
    return maxval;
}


void solve() {
    int n,h;
    cin >> n >> h;
    vector<int> arr(n+2);
    arr[0]=arr[n+1]=h;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }
    vector<int> nge(n+2);
    vector<ll> wtrdrainright(n+2);
    stack<int> stk;
    stk.push(n+1);
    // cout << "before nge\n" << flush;
    for(int i=n;i>=1;i--) {
        while (arr[stk.top()]<arr[i]) {
            stk.pop();
        }
        nge[i]=stk.top();
        // cout << "i " << i << " " << nge[i] << "\n" << flush;
        wtrdrainright[i]=1ll*(nge[i]-i)*(h-arr[i])+wtrdrainright[nge[i]];
        stk.push(i);
    }
    // cout << "nge done\n" << flush;
    // return;
    stk = stack<int>();
    vector<int> npe(n+2);
    vector<ll> wtrdrainleft(n+2);
    stk.push(0);
    for(int i=1;i<=n;i++) {
        while (arr[stk.top()]<arr[i]) {
            stk.pop();
        }
        npe[i]=stk.top();
        wtrdrainleft[i]=1ll*(i-npe[i])*(h-arr[i])+wtrdrainleft[npe[i]];
        stk.push(i);
    }
    vector<ll> wtrdrain(n+2);
    for(int i=1;i<=n;i++) {
        wtrdrain[i]=wtrdrainleft[i]+wtrdrainright[i]-(h-arr[i]);
    }
    while (sgtreebasesz<n) {
        sgtreebasesz<<=1;
    }
    sgtree.resize(sgtreebasesz<<1);
    for(int i=1;i<=n;i++) {
        updatesgtree(i-1,wtrdrain[i]);
    }
    vector<ll> wtrdrainmaxrone(n+2);
    for(int i=n;i>=1;i--) {
        ll maxwtdrainbtw = querymax(i-1,nge[i]-2);
        wtrdrainmaxrone[i]=max(maxwtdrainbtw-wtrdrain[i],wtrdrainmaxrone[nge[i]]);
    }
    ll maxtwodrains = LLONG_MIN;
    for(int i=1;i<=n;i++) {
        maxtwodrains = max(maxtwodrains,wtrdrain[i]+wtrdrainmaxrone[i]);
    }
    cout << maxtwodrains << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while(t--) {
    	solve();
    }
    
    return 0;
}
