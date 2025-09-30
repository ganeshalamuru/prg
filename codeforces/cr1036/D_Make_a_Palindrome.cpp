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
	int n,k;
    cin >> n >> k;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i].F;
        arr[i].S = i;
    }
    if (k<3) {
        cout << "YES\n";
        return;
    }
    sort(arr.begin(), arr.end());
    int ele = arr[k-2].F;
    int num = k-1;
    while(num<arr.size() && ele==arr[num].F)
        num++;
    sort(arr.begin(), arr.begin()+num,[&](const auto &a,const auto &b) {return a.S<b.S;});
    vector<int> del(num,0);
    int i=0,j=num-1;
    while(i<j) {
        if (arr[i].F == arr[j].F) {
            i++,j--;
        } else if (arr[i].F!=ele && arr[j].F!=ele) {
            cout << "NO\n";
            return;
        } else if (arr[i].F==ele) {
            del[i]=1;
            i++;
        } else {
            del[j]=1;
            j--;
        }
    }
    vector<int> finarr;
    for(int z=0;z<num;z++) {
        if (del[z]==0)
            finarr.push_back(arr[z].F);
    }
    if (finarr.size()<k-1) {
        cout << "NO\n";
        return;
    }
    bool palindrome = true;
    for(int z=0;z<finarr.size();z++) {
        if (finarr[z]!=finarr[int(finarr.size())-1-z]) {
            palindrome=false;
            break;
        }
    }
    if (palindrome) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

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
