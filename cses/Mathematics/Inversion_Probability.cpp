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
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    long double expectation = 0.0l;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            long long sum1=0,sum2=0;
            for(int z=1;z<=arr[i];z++) {
                if (z>=arr[j]+1)
                    sum2++;
                else
                    sum1+=z-1;
            }
            expectation+=((long double)sum1)/(arr[i]*arr[j]);
            expectation+=((long double)sum2)/arr[i];
        }
    }
    cout << fixed << setprecision(6) << expectation << '\n';
 
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