// O(log^2(n)) for query and O(log(n)) for update

const int MXN = 1e5;
const int MXL = 17;

int arr[MXN];
vector<int> adj[MXN];

int seg[4*MXN];

void segupdate(int node, int l, int r, int i, int v){
    if(l == r) seg[node] = v;
    else{
        int mid = (l+r)/2;
        if(i <= mid) segupdate(2*node, l, mid, i, v);
        else segupdate(2*node+1, mid+1, r, i, v);
        seg[node] = seg[2*node]^seg[2*node+1];
    }
}
void segupdate(int i, int v){
    segupdate(1, 0, MXN-1, i, v);
}

int segquery(int node, int l, int r, int a, int b){
    if(l >= a && r <= b)return seg[node];
    int ans = 0;
    int mid = (l+r)/2;
    if(mid >= a) ans ^= segquery(2*node, l, mid, a, b);
    if(mid+1 <= b) ans ^= segquery(2*node+1, mid+1, r, a, b);
    return ans;
}
int segquery(int a, int b){
    return segquery(1, 0, MXN-1, a, b);
}

int lca[MXN][MXL];
int dep[MXN];

int getLCA(int a, int b){
    if(dep[a] < dep[b]) swap(a, b);
    for(int l = MXL-1; l >= 0; l--){
        if(dep[a] - (1<<l) >= dep[b]){
            a = lca[a][l];
        }
    }
    for(int l = MXL-1; l >= 0; l--){
        if(lca[a][l] != lca[b][l]){
            a = lca[a][l];
            b = lca[b][l];
        }
    }
    if(a != b){
        a = lca[a][0];
        b = lca[b][0];
    }
    return a;
}
void makeLCA(){
    for(int l = 1; l < MXL; l++){
        for(int i = 0; i < MXN; i++){
            lca[i][l] = lca[lca[i][l-1]][l-1];
        }
    }
}

int st_size[MXN];
int position[MXN];
int chain_head[MXN];

void dfsHLD(int curr, int topofchain, int par, int &internalidx){
    position[curr] = internalidx++;
    segupdate(position[curr], arr[curr]);
    chain_head[curr] = topofchain;
    int largestchild = -1, largestsz = -1;
    for(auto v : adj[curr]){
        if(v == par) continue;
        if(st_size[v] > largestsz){
            largestsz = st_size[v];
            largestchild = v;
        }
    }
    if(largestchild < 0) return;
    dfsHLD(largestchild, topofchain, curr, internalidx);
    for(auto v : adj[curr]){
        if(v == par || v == largestchild) continue;
        dfsHLD(v, v, curr, internalidx);
    }
}

void dfs(int u, int par){
    st_size[u]++;
    for(auto v : adj[u]){
        if(v == par) continue;
        dep[v] = dep[u]+1;
        lca[v][0] = u;
        dfs(v, u);
        st_size[u] += st_size[v];
    }
}

void makeHLD(){
    dfs(0, -1);
    makeLCA();
    int internalidx = 0;
    dfsHLD(0, 0, -1, internalidx);
}

int pathQuery(int c, int p){
    int ans = 0;
    while(c != p){
        if(chain_head[c] == c){
            //light edge
            ans ^= arr[c];
            c = lca[c][0];
        }
        else if(dep[chain_head[c]] > dep[p]){
            ans ^= segquery(position[chain_head[c]], position[c]);
            c = lca[chain_head[c]][0];
        }
        else{
            ans ^= segquery(position[p]+1, position[c]);
            break;
        }
    }
    return ans;
}

int hldQry(int a, int b){
    int r = getLCA(a, b);
    return pathQuery(a, r) ^ pathQuery(b, r) ^ arr[r];
}
