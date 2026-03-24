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
 
 
vector<vector<int>> dpnge;
vector<vector<ll>>dpngesum;
void solve() {
	int n,q;
    cin >> n >> q;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin >> arr[i];
    vector<ll>psum(n);
    psum[0]=arr[0];
    for(int i=1;i<n;i++)
        psum[i]=psum[i-1]+arr[i];
    
    vector<int> nge(n,n);
    stack<int> stk;
    for(int i=n-1;i>=0;i--) {
        while (!stk.empty() && arr[stk.top()]<=arr[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            nge[i]=stk.top();
        }
        stk.push(i);
    }
    dpnge.resize(n+1,vector<int>(18));
    dpngesum.resize(n+1,vector<ll>(18));
    for(int i=0;i<n;i++) {
        dpnge[i][0]=nge[i];
        dpngesum[i][0]=1ll*(nge[i]-i)*arr[i];
    }
    for(int i=0;i<18;i++)
        dpnge[n][i]=n;
    for(int i=1;i<18;i++) {
        for(int j=0;j<n;j++) {
            dpngesum[j][i]=dpngesum[j][i-1]+dpngesum[dpnge[j][i-1]][i-1];
            dpnge[j][i]=dpnge[dpnge[j][i-1]][i-1];
        }
    }
    while (q--) {
        int a,b;
        cin >> a >> b;
        a--,b--;
        ll pmaxsum = 0,psumm=0;
        psumm=psum[b];
        if (a-1>=0) psumm-=psum[a-1];
        int curpos=a;
        for(int i=17;i>=0;i--) {
            if (dpnge[curpos][i]<=b) {
                pmaxsum+=dpngesum[curpos][i];
                curpos=dpnge[curpos][i];
            }
        }
        pmaxsum+=1ll*(b-curpos+1)*arr[curpos];
        cout << pmaxsum-psumm << "\n";
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