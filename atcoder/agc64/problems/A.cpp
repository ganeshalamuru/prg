#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


bool fillArrAtIndex(vector<int> &arr, int index, int prevNum, map<int, int> &freq) {
    vector<int> availableNumsToFill = {prevNum + 2, prevNum + 1, prevNum - 1 ,prevNum - 2};
    for (int i = 0; i < availableNumsToFill.size(); i++) {
        int num = availableNumsToFill[i];
        if (num < 0)
            continue;
        if (freq[num] > 0) {
            arr[index] = num;
            freq[num]--;
            return true;
        }
    }
    return false;
}


void solve(){
	int n;
    cin >> n;
    vector<int> arr(n*(n+1)/2);
    map<int, int> freq;
    for (int i = 1; i <=n ; i++)
        freq[i] = i;
    int i = 0, j = arr.size() - 1;
    arr[i] = n, arr[j] = n - 1;
    freq[n]--, freq[n-1]--;
    i++, j--;
    while (i < j)
    {
        fillArrAtIndex(arr, i, arr[i-1], freq), i++;
        fillArrAtIndex(arr, j, arr[j+1], freq), j--;
    }
    if (i == j) {
        fillArrAtIndex(arr, i, arr[i-1], freq);
    }
    for (int num : arr)
        cout << num << " ";
    cout << "\n";
}


signed main(){
    fast;
    int t = 1;
    while(t--){
    	solve();
    }
    return 0;
}
