#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define F first
#define S second
const ll mod = 1e9+7;


void solve() {
	int n;
    cin >> n;
    vector<ll> arr(n);
    ll totsum = 0;
    for(int i=0;i<n;i++) {
        cin >> arr[i];
        totsum+=arr[i];
    }
    if (totsum%2==1) {
        cout << -1 << "\n";
        return;
    }
    vector<ll>psum(n);
    psum[0]=arr[0];
    for(int i=1;i<n;i++) {
        psum[i] = psum[i-1] + arr[i];
    }
    for(int i=0;i<n-1;i++) {
        if (psum[i]==totsum-psum[i]) {
            cout << 1 << "\n";
            for(int j=0;j<n;j++) 
                cout << arr[j] << " ";
            cout << "\n";
            return;
        }
    }
    ll cursum = 0;
    for(int i=0;i<n-1;i++) {
        cursum=psum[i];
        ll req=0;
        if (cursum<totsum-cursum) {
            req = (totsum-cursum-cursum)/2;
            auto itr = lower_bound(psum.begin()+i+1,psum.end(),req,[&](const auto &a,const auto &b){return a-cursum<b;});
            ll remsum = psum[n-1]-(*itr);
            int ind = distance(psum.begin(), itr);
            if (remsum>=req && n-i-1>1) {
                vector<ll> fin(n,0);
                ll temp = 0;
                for(int j=i+1;j<ind;j++) {
                    fin[j]=arr[j];
                    temp+=arr[j];
                }
                fin[ind]=req-temp;
                temp=0;
                for(int j=ind+1;j<n;j++) {
                    if (temp==req) {
                        fin[j]=0;
                    } else if (temp+arr[j]<=req) {
                        fin[j]= arr[j];
                        temp+=arr[j];
                    } else {
                        fin[j]= req-temp;
                        temp+=req-temp;
                    }
                }
                cout << 2 << "\n";
                for(int j=0;j<n;j++) {
                    cout << fin[j] << " ";
                }
                cout << "\n";
                for(int j=0;j<n;j++) {
                    cout << arr[j]-fin[j] << " ";
                }
                cout << "\n";
                return;
            }
        } else {
            req = (cursum-(totsum-cursum))/2;
            auto itr = lower_bound(psum.begin(),psum.begin()+i+1,req);
            ll remsum = psum[i]-(*itr);
            int ind = distance(psum.begin(), itr);
            if (remsum>=req && i>0 && ind<i) {
                vector<ll>fin(n,0);
                ll temp =0;
                for(int j=0;j<ind;j++) {
                    fin[j]=arr[j];
                    temp+=arr[j];
                }
                fin[ind]=req-temp;
                temp = 0;
                for(int j=ind+1;j<=i;j++) {
                    if (temp==req) {
                        fin[j]=0;
                    } else if (temp+arr[j]<=req) {
                        fin[j] = arr[j];
                        temp+=arr[j];
                    } else {
                        fin[j]= req-temp;
                        temp+=req-temp;
                    }
                }
                cout << 2 << "\n";
                for(int j=0;j<n;j++) {
                    cout << fin[j] << " ";
                }
                cout << "\n";
                for(int j=0;j<n;j++) {
                    cout << arr[j]-fin[j] << " ";
                }
                cout << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
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
