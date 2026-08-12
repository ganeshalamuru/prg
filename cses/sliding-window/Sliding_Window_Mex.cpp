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

const int M = 2e5+2;


vector<int> bit;

void update(int i, int inc) {
    while (i<int(bit.size())) {
        bit[i]+=inc;
        i+=(i&-i);
    }
    
}

int sum(int i) {
    int ans = 0;
    while (i>0) {
        ans+=bit[i];
        i-=(i&-i);
    }
    return ans;
}

int calculatemex() {
    int l=1,r=M;
    while (l<r) {
        int mid = l+(r-l)/2;
        int summ = sum(mid);
        if (summ>=mid) {
            l=mid+1;
        } else {
            r=mid;
        }
    }
    return l;
}

void solve() {
    int n,k;
    cin >> n >> k;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        arr[i]++;
        if (arr[i]>M)
            arr[i]=M;
    }
    bit.resize(M+1);
    vector<int> freq(M+1,0);
    for(int i=1;i<k;i++) {
        freq[arr[i]]++;
        if (freq[arr[i]]==1)
            update(arr[i],1);
    }
    for(int i=k;i<=n;i++) {
        freq[arr[i]]++;
        if (freq[arr[i]]==1)
            update(arr[i],1);
        cout << calculatemex()-1 << " ";
        int removeval = arr[i-k+1];
        freq[removeval]--;
        if (freq[removeval]==0)
            update(removeval,-1);
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
