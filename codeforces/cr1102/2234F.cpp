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


void build_nge_table(int n,vector<int>&arr, vector<int>&nge, vector<vector<int>>&dp, vector<vector<ll>>&dpsum) {
    nge[2*n+1]=2*n+1;
    stack<int> stk;
    for(int i=2*n;i>=1;i--) {
        while (!stk.empty() && arr[i]>arr[stk.top()]) {
            stk.pop();
        }
        if (!stk.empty()) {
            nge[i]=stk.top();
        } else {
            nge[i]=2*n+1;
        }
        stk.push(i);
    }
    for(int i=1;i<=2*n+1;i++) {
        dp[i][0]=nge[i];
        dpsum[i][0]=1ll*arr[i]*(nge[i]-i);
    }
    for(int j=1;j<18;j++) {
        for(int i=1;i<=2*n+1;i++) {
            dp[i][j]=dp[dp[i][j-1]][j-1];
            dpsum[i][j]=dpsum[i][j-1]+dpsum[dp[i][j-1]][j-1];
        }
    }
}


void build_npe_table(int n,vector<int>&arr,vector<int>&npe, vector<vector<int>>&dp, vector<vector<ll>> dpsum) {
    npe[0]=0;
    stack<int>stk;
    for(int i=1;i<=2*n;i++) {
        while (!stk.empty() && arr[i]>arr[stk.top()]) {
            stk.pop();
        }
        if (!stk.empty()) {
            npe[i]=stk.top();
        } else {
            npe[i]=0;
        }
        stk.push(i);
    }
    for(int i=0;i<=2*n;i++) {
        dp[i][0]=npe[i];
        dpsum[i][0]=1ll*arr[i]*(i-npe[i]);
    }
    for(int j=1;j<18;j++) {
        for(int i=0;i<=2*n;i++) {
            dp[i][j]=dp[dp[i][j-1]][j-1];
            dpsum[i][j]=dpsum[i][j-1]+dpsum[dp[i][j-1]][j-1];
        }
    }
}


void solve() {
	int n;
    cin >> n;
    vector<int> arr(2*n+2);
    int maxele = INT_MIN;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
        maxele=max(maxele,arr[i]);
    }
    arr[0]=arr[2*n+1]=INT_MAX;
    for(int i=n+1;i<=2*n;i++)
        arr[i]=arr[i-n];
    vector<vector<int>> dp(2*n+2,vector<int>(18));
    vector<vector<ll>> dpsum(2*n+2,vector<ll>(18));
    vector<int> nge(2*n+2);
    build_nge_table(n,arr,nge,dp,dpsum);

    vector<vector<int>> dp2(2*n+2,vector<int>(18));
    vector<vector<ll>> dpsum2(2*n+2,vector<ll>(18));
    vector<int> npe(2*n+2);
    build_npe_table(n,arr,npe,dp2,dpsum2);

    for(int i=1;i<=n;i++) {
        ll maxwater = 0;
        if (arr[i]==maxele) {
            int l=1,r=n;
            while (l<r) {
                int mid = l+(r-l)/2;
                int ind = i + n-1,tmp=mid;
                for(int j=17;j>=0;j--) {
                    if ((1<<j)<=tmp) {
                        ind = dp2[ind][j];
                        tmp-=(1<<j);
                    }
                }
                if (arr[ind]>maxele) {
                    r=mid-1;
                } else if (arr[ind]==maxele) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            }
            ll tmpsum = 0,ind=i+n-1;
            for(int j=17;j>=0;j--) {
                if ((1<<j)<=l) {
                    tmpsum+=dpsum2[ind][j];
                    ind = dp2[ind][j];
                    l-=(1<<j);
                }
            }
            maxwater+=tmpsum+1ll*maxele*(ind-i);
        } else if (arr[i+n-1]==maxele) {
            int l=1,r=n;
            while (l<r) {
                int mid = l+(r-l)/2;
                int ind = i,tmp=mid;
                for(int j=17;j>=0;j--) {
                    if ((1<<j)<=tmp) {
                        ind = dp[ind][j];
                        tmp-=(1<<j);
                    }
                }
                if (arr[ind]>maxele) {
                    r=mid-1;
                } else if (arr[ind]==maxele) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            }
            ll tmpsum = 0,ind=i;
            for(int j=17;j>=0;j--) {
                if ((1<<j)<=l) {
                    tmpsum+=dpsum[ind][j];
                    ind = dp[ind][j];
                    l-=(1<<j);
                }
            }
            maxwater+=tmpsum+1ll*maxele*(i+n-1 - ind);
        } else {
            int l=1,r=n;
            while (l<r) {
                int mid = l+(r-l)/2;
                int ind = i,tmp=mid;
                for(int j=17;j>=0;j--) {
                    if ((1<<j)<=tmp) {
                        ind = dp[ind][j];
                        tmp-=(1<<j);
                    }
                }
                if (arr[ind]>maxele) {
                    r=mid-1;
                } else if (arr[ind]==maxele) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            }
            ll tmpsum = 0,ind1=i;
            for(int j=17;j>=0;j--) {
                if ((1<<j)<=l) {
                    tmpsum+=dpsum[ind1][j];
                    ind1 = dp[ind1][j];
                    l-=(1<<j);
                }
            }
            l=1,r=n;
            while (l<r) {
                int mid = l+(r-l)/2;
                int ind = i + n-1,tmp=mid;
                for(int j=17;j>=0;j--) {
                    if ((1<<j)<=tmp) {
                        ind = dp2[ind][j];
                        tmp-=(1<<j);
                    }
                }
                if (arr[ind]>maxele) {
                    r=mid-1;
                } else if (arr[ind]==maxele) {
                    r=mid;
                } else {
                    l=mid+1;
                }
            }
            ll tmpsum2 = 0,ind2=i+n-1;
            for(int j=17;j>=0;j--) {
                if ((1<<j)<=l) {
                    tmpsum2+=dpsum2[ind2][j];
                    ind2 = dp2[ind2][j];
                    l-=(1<<j);
                }
            }
            maxwater+=tmpsum+tmpsum2+1ll*maxele*(ind2-ind1);
        }
        cout << maxwater << " ";
    }
    cout << "\n";

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
