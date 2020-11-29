#include <bits/stdc++.h>

using namespace std;

class fenwick_tree {
    // NOTE THAT THIS IMPLEMENTATION FOLLOWS 1 BASED INDEXING 
    public:
    int n;
    vector<int> BIT;

    fenwick_tree(int length){
        // The constructor only initializes the BIT vector
        // You are required to call the update method as and when required
        n = length;
        BIT = vector<int> (n + 1);
    }

    int sum(int r) {
        int s = 0;
        while (r > 0) {
            s += BIT[r];
            r -= r & -r;
        }
        return s;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void update(int i, int delta) {
        while (i <= n) {
            BIT[i] += delta;
            i += i & -i;
        }
    }

};

int32_t main() {
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    fenwick_tree t(n);
    for(const int& val : a){
        cout << val << ' ' ;
    }
    cout << endl;
    for(int i = 1; i <= n; ++i){
        t.update(i, a[i]);
    }
    for(int i = 2; i <= n; ++i){
        cout << t.sum(i) << endl;
    }
}
