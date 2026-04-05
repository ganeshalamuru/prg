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

const int N = 1e6+1;
vector<int> spf(N);

void fillspf() {
    spf[0]=spf[1]=0;
    for(int i=2;i<N;i++)
        spf[i]=i;
    for(int i=2;i*i<N;i++) {
        if (spf[i]==i) {
            for(int j=i*i;j<N;j+=i) {
                if (spf[j]==j)
                    spf[j]=i;
            }
        }
    }
}

void solve() {
	int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    bool sorted = true;
    for(int i=1;i<n;i++) {
        if (arr[i]<arr[i-1]) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << "Bob\n";
        return;
    }
    int minpr = INT_MAX;
    for(int i=n-1;i>=0;i--) {
        if (arr[i]==1) {
            minpr = 1;
        } else {
            int tmp = arr[i];
            int firstpf = spf[tmp];
            while ((tmp%firstpf) == 0) {
                tmp/=firstpf;
            }
            if (tmp != 1 || (tmp==1 && firstpf>minpr)) {
                cout << "Alice\n";    
                return;
            }
            minpr = firstpf;
        }
    }
    cout << "Bob\n";


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t = 1;
    cin >> t;
    
    fillspf();
    while(t--) {
    	solve();
    }
    
    return 0;
}
