// finds lowest common ancestor with euler tour + segment tree RMQ
// Answers querys in O(log n) with preprocssing of O(n)

struct LCA {
    int n;
    vector<int> seg, height, euler, first;
    vector<bool> visited;

    LCA(vector<vector<int>> &adj, int root = 0){
        n = adj.size();
        height.resize(n);
        euler.reserve(2*n);
        first.resize(n);
        visited.assign(n, false);
        dfs(adj, root);
        int m = sz(euler);
        seg.resize(4*m);
        build(1, 0, m-1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0){
        visited[node] = 1;
        height[node] = h;
        first[node] = euler.size();
        euler.pb(node);
        for(auto v : adj[node]){
            if(!visited[v]){
                dfs(adj, v, h+1);
                euler.pb(node);
            }
        }
        return;
    }

    void build(int node, int l, int r){
        if(l > r){
            return;
        }
        if(l == r){
            seg[node] = euler[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        int a = seg[2*node], b = seg[2*node+1];
        seg[node] = (a < b) ? a : b;
        return;
    }

    int query(int node, int l, int r, int a, int b){
        if(l > b || r < a){
            return ninf;
        }
        if(l >= a && r <= b){
            return seg[node];
        }
        int mid = (l+r)/2;
        int n1 = query(2*node, l, mid, a, b);
        int n2 = query(2*node+1, mid+1, r, a, b);
        if(n1==ninf) return n2;
        if(n2==ninf) return n1;
        return (height[n1] < height[n2]) ? n1 : n2;
    }

    int getlca(int u, int v){
        int a = first[u], b = first[v];
        if(a > b) swap(a, b);
        return query(1, 0, sz(euler)-1, a, b);
    }
};
