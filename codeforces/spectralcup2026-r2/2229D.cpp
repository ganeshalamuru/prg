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


bool possible(int target,vector<int>&a, vector<int>&b, vector<int>&c) {
    array<int,3> cnt{};
    int n = int(a.size());
    for(int i=0;i<n;i++) {
        int typ = -1;
        if (max(a[i],b[i])<target) {
            typ = 0;
        } else if (min(a[i],b[i])>=target) {
            typ = 2;
        } else {
            typ = 1;
        }
        c[i]=typ;
        cnt[typ]++;
    }
    if (cnt[2]<1) 
        return false;
    int z1=0,z2=n-1;
    while (z1<n && c[z1]==1)
        z1++;
    while (z2>=0 && c[z2]==1)
        z2--;
    if (z1<=z2 && c[z1]==2 && c[z2]==2)
        return true;
    int consectwocnt = 1,minprev = INT_MAX;
    if (c[z1]==2 || c[z2]==2) {
        while (z1<n && c[z1]!=2)
            z1++;
        z1++;
        while (z1<n && consectwocnt<2) {
            if (c[z1]==2) {
                if (minprev>0)
                    consectwocnt++,minprev=INT_MAX;
                else
                    minprev=1;
            } else {
                minprev=min(c[z1],minprev);
            }
            z1++;
        }
        if (consectwocnt==2)
            return true;
    } else {
        while (z1<n && c[z1]!=2)
            z1++;
        z1++;
        while (z1<n && consectwocnt<3) {
            if (c[z1]==2) {
                if (minprev>0)
                    consectwocnt++,minprev=INT_MAX;
                else
                    minprev=1;
            } else {
                minprev=min(c[z1],minprev);
            }
            z1++;
        }
        if (consectwocnt==3)
            return true;
    }

    return false;

}


void solve() {
	int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++) {
        cin >> b[i];
    }
    if (n==1) {
        cout << min(a[0],b[0]) << "\n";
        return;
    }
    int l=1,r=2*n;
    while (l<r) {
        int mid = l + (r-l+1)/2;
        if (possible(mid,a,b,c)) {
            l=mid;
        } else {
            r=mid-1;
        }
    }
    cout << l << "\n";

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
