#include <bits/stdc++.h>
using namespace std;


// Problem for reference: https://www.spoj.com/problems/RMQSQ/


class Solution {
    struct Node {
        int idx;  // idx => The index of the minim value
        int val;  // val => stores the minimum value of the range that node is responsible for
    };
    // NOTE: This implementation of RMQ (Range Minimum Query) uses 1-Based indexing, do not confuse this 0-Based indexing
    int n;           // n => the length of the input array
    vector<int> a;   // a => input array
    vector<Node> t;  // t => The segment tree

    Node combine(Node a, Node b) {
        Node res;
        if (a.val < b.val) {
            res = a;
        } else {
            res = b;
        }
        return res;
    }
    void build(int tl, int tr, int v) {
        if (tl == tr) {
            t[v].val = a[tl];
            t[v].idx = tl;
        } else {
            int tm = (tl + tr) / 2;
            build(tl, tm, 2 * v);
            build(tm + 1, tr, 2 * v + 1);
            t[v] = combine(t[2 * v + 1], t[2 * v]);
        }
    }

    Node get(int l, int r, int tl, int tr, int v) {
        if (l > r) {
            Node res;
            res.val = INT_MAX;
            return res;
        }
        if (tl == l && tr == r) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return combine(get(l, min(tm, r), tl, tm, 2 * v), get(max(l, tm + 1), r, tm + 1, tr, 2 * v + 1));
    }
    // Implement RANGE_UPDATE if required using lazy propagation method
    void pointUpdate(int pos, int tl, int tr, int v) {
        if (tl == tr) {
            t[v].val = a[pos];
            t[v].idx = a[pos];
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                pointUpdate(pos, tl, tm, 2 * v);
            } else {
                pointUpdate(pos, tm + 1, tr, 2 * v + 1);
            }
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

   public:
    void solve() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cin >> n;
        a = vector<int>(n + 1);
        t = vector<Node>(4 * (n + 1));
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        build(1, n, 1);
        int q;  // number of queries
        cin >> q;
        while (q--) {
            // Task is the to print the Minimum value in the range [l, r]
            int l, r;
            cin >> l >> r;
            l++;
            r++;
            cout << get(l, r, 1, n, 1).val << endl;
        }
    }
};

int32_t main() {
    Solution solver;
    solver.solve();
}
