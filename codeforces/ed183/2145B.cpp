#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(false);cin.tie(nullptr);
#define all(v) begin(v),end(v)
#define rall(v) rbegin(v),rend(v)
#define F first
#define S second


void solve() {
	int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int t0=0,t1=0;
    for(int i=0;i<k;i++) {
        if (s[i]=='0')
            t0++;
        else if (s[i]=='1')
            t1++;
    }
    string ans(n,'+');
    for(int i=0;i<t0;i++)
        ans[i]='-';
    for(int j=n-1;j>=n-t1;j--)
        ans[j]='-';    
    int t2 = k-t0-t1,rem=n-t0-t1;
    if (t2==rem) {
        for(int j=t0;j<n-t1;j++) {
            ans[j]='-';
        }
    } else if (t2>=(rem+1)/2) {
        for(int j=t0;j<n-t1;j++) {
            ans[j]='?';
        }
    } else {
        for(int i=t0,j=n-t1-1,cnt=0;cnt<t2;i++,j--,cnt++) {
            ans[i]='?',ans[j]='?';
        }
    }
    cout << ans << "\n";


}


int main() {
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
