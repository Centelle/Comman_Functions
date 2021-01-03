
#include <bits/stdc++.h>
using namespace std;

class disjoint_set {
    // NOTE: This implementation of disjoint_set uses 1-based indexing 
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
    
    int union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            if(size[a] < size[b]){
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            return 1;
        }
        return 0;
    }
}; 
int32_t main(){
    int n = 10; // maximum number of vertices in the graph
    disjoint_set DSU(n);
    
    for(int i = 1; i <= n; ++i){
        DSU.make_set(i);   
    }
    
    DSU.union_set(1, 3);
    DSU.union_set(3, 5);
    DSU.union_set(4, 6);
    
    for(int i = 1; i <= n; ++i){
        printf("parent[%d] = %d\n", i, DSU.parent[i]);
    }
}
