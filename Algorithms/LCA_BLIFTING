struct LCA {
    int n, l;
    vector<int> dep, par;
    vector<vector<int>> adj, anc;
    LCA(vector<vector<int>> &adjList, int mxn){
        n = mxn;
        adj.reserve(n);
        adj = adjList;
        l = ceil(log(n)/log(2));
        dep.resize(n);
        par.resize(n);
        dep.resize(n);
        anc.resize(n, vector<int>(l));
        preprocess();
    }

    int getlca(int a, int b){
        if(dep[a] < dep[b]) 
            swap(a, b);
        int dist = dep[a]-dep[b];
        while(dist > 0){
            FOR(i, l){
                if(dist & (1 << i)){
                    a = anc[a][i];
                    dist -= 1 << i;
                }
            }
        }
        if(a == b) return a;
        ROF(j, l){
            if(anc[a][j] != -1 && anc[a][j] != anc[b][j]){
                a = anc[a][j]; b = anc[b][j];
            }
        }
        return par[a];
    }

    void dfs(int u, int p, int d){
        par[u] = p; dep[u] = d;
        for(auto v : adj[u]){
            if(v != p){
                dfs(v, u, d+1);
            }
        }
        return;
    }
    
    void preprocess(){
        dfs(0, -1, 0);
        FOR(i, n) FOR(j, l) anc[i][j] = -1;
        FOR(i, n) anc[i][0] = par[i];
        for(int j = 1; j < l; j++){
            FOR(i, n){
                if(anc[i][j-1] != -1){
                    anc[i][j] = anc[anc[i][j-1]][j-1];
                }
            }
        }
        return;
    }
};
