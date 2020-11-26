
#include <bits/stdc++.h>

using namespace std;

class disjoint_set {
    public:
    int n;
    vector<int> parent;
    vector<int> size;
    disjoint_set(int new_n){
        // new_n is the maximum number of vertices in the graph
        this->n = new_n;
        parent = vector<int> (n + 1);
        size = vector<int> (n + 1);
    }

    void make_set(int v){
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v){
        if(parent[v] == v){
            return v;
        }
        int topmost = find_set(parent[v]);
        parent[v] = topmost;
        return topmost;
    }
    
    void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(size[a] < size[b]){
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
}; 
int32_t main(){
    int n = 10;
    disjoint_set DSU(n);

    DSU.make_set(1);
    DSU.make_set(2);
    DSU.make_set(3);
    DSU.make_set(4);
    DSU.make_set(5);
    DSU.make_set(6);
    DSU.make_set(7);

    DSU.union_set(1, 3);
    DSU.union_set(3, 5);
    DSU.union_set(4, 6);
    for(int i = 1; i <= n; ++i){
        printf("parent[%d] = %d\n", i, DSU.parent[i]);
    }
}
