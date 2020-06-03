
#include <bits/stdc++.h>

using namespace std;

class Directed_Graph{
    int vertices;
    vector<vector<int>> adj;
    bool has_cycle_dfs(int node, vector<bool>& visited, vector<bool> rec_stack){
        if(rec_stack[node])
            return true;
        if(visited[node])
            return true;
        visited[node] = true;
        rec_stack[node] = true;
        for(int t : adj[node]){
            if(has_cycle_dfs(t, visited, rec_stack)){
                return true;
            }
        }
        rec_stack[node] = false;
        return false;
    }
    public:
    Directed_Graph(int v){
        this->vertices = v;
        adj.resize(vertices);
    }
    void add_edge(int u, int v){
        adj[u].push_back(v);
    }
    bool has_cycle(){
        vector<bool> visited(vertices, 0);
        vector<bool> rec_stack(vertices, 0);
        for(int node = 0; node < vertices; ++node){
            if(has_cycle_dfs(node, visited, rec_stack)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Directed_Graph* g = new Directed_Graph(4);
    g->add_edge(0, 1);
    g->add_edge(0, 2);
    g->add_edge(1, 2);
    g->add_edge(2, 0);
    g->add_edge(2, 3);
    g->add_edge(3, 3);
    if(g->has_cycle()){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
