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
 
const int M = 64;
const int ft_sz = 3001 / M + 2;
const unsigned long long ALL_SET = -1ULL; 

void update_ft(array<int,ft_sz>&ft,array<unsigned ll,ft_sz> &delmask, int i,int val) {
    i+=M;
    delmask[i/M] |= (1ULL<<(i&(M-1)));
    i=(i/M);
    while (i < ft_sz) {
        ft[i]+=val;
        i+=(i&-i);
    }
}

int query_ft(array<int,ft_sz>&ft,array<unsigned ll,ft_sz> &delmask, int i) {
    i+=M;
    int ii = i/M;
    int ans = __builtin_popcountll((ALL_SET>>((M-1)-(i&(M-1))))&delmask[ii]);
    ii--;
    while (ii>0) {
        ans+=ft[ii];
        ii-=(ii&-ii);
    }
    return ans;
}
 
void solve(int n,int k, vector<string>&grid) {
    array<array<short,3000>,3000> left,right,up,down;
    // right
    for(int i=0;i<n;i++) {
        right[i][n-1]=1;
        for(int j=n-2;j>=0;j--) {
            if (grid[i][j]==grid[i][j+1]) {
                right[i][j]=right[i][j+1]+1;
            } else {
                right[i][j]=1;
            }
        }
    }
    // down
    for(int j=0;j<n;j++) {
        down[n-1][j]=1;
        for(int i=n-2;i>=0;i--) {
            if (grid[i][j]==grid[i+1][j]) {
                down[i][j]=down[i+1][j]+1;
            } else {
                down[i][j]=1;
            }
        }
    }
    // left
    for(int i=0;i<n;i++) {
        left[i][0]=1;
        for(int j=1;j<n;j++) {
            if (grid[i][j]==grid[i][j-1]) {
                left[i][j]=left[i][j-1]+1;
            } else {
                left[i][j]=1;
            }
        }
    } 
    // up
    for(int j=0;j<n;j++) {
        up[0][j]=1;
        for(int i=1;i<n;i++) {
            if (grid[i][j]==grid[i-1][j]) {
                up[i][j]=up[i-1][j]+1;
            } else {
                up[i][j]=1;
            }
        }
    }
    array<ll,26>ans{};
    array<int,3001> head{},val{},lnk{};
    array<int,ft_sz> ft{};
    // frist lower triangle with main diagnoanl and second upper triangle
    for(auto &[dst,xst,yst]:{array<int,3>{0,1,0},{1,0,1}}) {
        for(int d=dst;d<n;d++) {
            array<short,3000> charstyp,tmp_dr,tmp_ul;
            int dsz = 0;
            for(int x=d*xst,y=d*yst;x<n&&y<n;x++,y++) {
                short charnum= grid[x][y]-'A';
                charstyp[dsz]=charnum;
                tmp_dr[dsz]= min(down[x][y],right[x][y]);
                tmp_ul[dsz]=min(up[x][y],left[x][y]);
                dsz++;
            }
            int ctr=0;
            ft.fill(0);
            array<unsigned ll,ft_sz> delmask{};
            for(int i=0,tot_del=0;i<dsz;i++) {
                for(int ptr=head[i];ptr>0;ptr=lnk[ptr]) {
                    tot_del++;
                    update_ft(ft,delmask,val[ptr],1);
                }
                head[i]=0;
                ctr++;
                val[ctr]=i;
                lnk[ctr]=head[i+tmp_dr[i]];
                head[i+tmp_dr[i]]=ctr;
                ans[charstyp[i]]+=tmp_ul[i]-(tot_del-query_ft(ft,delmask,i-tmp_ul[i]));
            }
            head[dsz]=0;
        }
    }
 
    for(int i=0;i<k;i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t = 1;
    // cin >> t;
 
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<string> grid(n);
        for(int i=0;i<n;i++) {
            cin >> grid[i];
        }
    	solve(n,k,grid);
    }
    
    return 0;
}