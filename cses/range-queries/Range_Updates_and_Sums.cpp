#include <bits/stdc++.h>

using namespace std;

#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define F first
#define S second

template <typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
using ll = long long;
using pii = pair<int, int>;

vector<array<ll, 3>> sgtree;
int sgtreebasesz = 1;

void propagate(int l, int r, int tind) {
    if (l == r) {
        if (sgtree[tind][2] != 0) {
            sgtree[tind][0] = sgtree[tind][2];
            sgtree[tind][2] = 0;
        }
        if (sgtree[tind][1] != 0) {
            sgtree[tind][0] += sgtree[tind][1];
            sgtree[tind][1] = 0;
        }
        return;
    }
    if (sgtree[tind][2] != 0) {
        sgtree[tind][0] = sgtree[tind][2] * (r - l + 1);
        sgtree[2 * tind][2] = sgtree[tind][2];
        sgtree[2 * tind + 1][2] = sgtree[tind][2];
        sgtree[2 * tind][1] = 0;
        sgtree[2 * tind + 1][1] = 0;
        sgtree[tind][2] = 0;
    }
    if (sgtree[tind][1] != 0) {
        sgtree[tind][0] += sgtree[tind][1] * (r - l + 1);
        sgtree[2 * tind][1] += sgtree[tind][1];
        sgtree[2 * tind + 1][1] += sgtree[tind][1];
        sgtree[tind][1] = 0;
    }
}

ll getsumofnode(int tind, int l, int r) {
    ll sum = 0;
    if (sgtree[tind][2]!=0) {
        sum = sgtree[tind][2]*(r-l+1);
    } else {
        sum+=sgtree[tind][0];
    }

    if (sgtree[tind][1]!=0) {
        sum+=sgtree[tind][1]*(r-l+1);
    }
    return sum;
}

void updateval(int a, int b, int val, int tind, int l, int r) {
    propagate(l, r, tind);
    if (b < l || a > r) return;
    if (a <= l && r <= b) {
        sgtree[tind][1] += val;
        return;
    }
    int mid = l + (r - l) / 2;
    updateval(a, b, val, 2 * tind, l, mid);
    updateval(a, b, val, 2 * tind + 1, mid + 1, r);
    sgtree[tind][0] =
        getsumofnode(2 * tind, l, mid) + getsumofnode(2 * tind + 1, mid + 1, r);
}

void setval(int a, int b, int val, int tind, int l, int r) {
    propagate(l, r, tind);
    if (b < l || a > r) return;
    if (a <= l && r <= b) {
        sgtree[tind][2] = val;
        return;
    }
    int mid = l + (r - l) / 2;
    setval(a, b, val, 2 * tind, l, mid);
    setval(a, b, val, 2 * tind + 1, mid + 1, r);
    sgtree[tind][0] =
        getsumofnode(2 * tind, l, mid) + getsumofnode(2 * tind + 1, mid + 1, r);
}

ll query(int a, int b, int tind, int l, int r) {
    propagate(l, r, tind);
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return sgtree[tind][0];
    int mid = l + (r - l) / 2;
    return query(a, b, 2 * tind, l, mid) +
           query(a, b, 2 * tind + 1, mid + 1, r);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    while (sgtreebasesz < n) sgtreebasesz <<= 1;
    sgtree.resize(sgtreebasesz << 1);
    for (int i = 0; i < n; i++) {
        updateval(i, i, arr[i], 1, 0, sgtreebasesz - 1);
    }
    while (q--) {
        int typ, a, b, x;
        cin >> typ;
        if (typ == 1) {
            cin >> a >> b >> x;
            a--, b--;
            updateval(a, b, x, 1, 0, sgtreebasesz - 1);
        } else if (typ == 2) {
            cin >> a >> b >> x;
            a--, b--;
            setval(a, b, x, 1, 0, sgtreebasesz - 1);
        } else {
            cin >> a >> b;
            a--, b--;
            cout << query(a, b, 1, 0, sgtreebasesz - 1) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
