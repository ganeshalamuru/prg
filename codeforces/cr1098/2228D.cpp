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



void solve() {
	int n;
    cin >> n;
    vector<pii> arr(n+1);
    vector<int> xcord(n+1,0);
    for(int i=1;i<=n;i++) {
        cin >> arr[i].F >> arr[i].S;
        xcord[arr[i].F]=1;
    }
    vector<int>pxcord(n+1,0);
    for(int i=1;i<=n;i++) {
        pxcord[i]=pxcord[i-1]+xcord[i];
    }
    ll ans = 0;
    sort(all(arr),[](const auto& a, const auto& b){return a.S<b.S;});
    int btmmaxx=0,btmminx=n+1;
    vector<pii>bottommm(n+1);
    for(int i=0,j=1;i<=n;i++) {
        while (j<=n && arr[j].S<=i) {
            btmmaxx=max(btmmaxx,arr[j].F);
            btmminx=min(btmminx,arr[j].F);
            j++;
        }
        bottommm[i]={btmminx,btmmaxx};
    }
    int topmaxx = 0, topminx=n+1;
    for(int i=n,j=n;i>=0;i--) {
        bool partitionchanged = false;
        while (j>=1 && arr[j].S>i) {
            topmaxx=max(topmaxx,arr[j].F);
            topminx=min(topminx,arr[j].F);
            j--;
            partitionchanged = true;
        }
        if (partitionchanged && topminx<topmaxx && bottommm[i].F<bottommm[i].S) {
            int leftmaxmin = max(topminx,bottommm[i].F);
            int rightminmax = min(topmaxx,bottommm[i].S);
            if (leftmaxmin<rightminmax) {
                ans+=pxcord[rightminmax-1]-pxcord[leftmaxmin-1];
            }
        }
    }
    cout << ans << "\n";

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
