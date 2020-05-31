int SZ;
vector<int> seg;

void setSize(int sz){
    SZ = sz;
    seg.resize(SZ*4)'
}
void build(int sz, int arr[]){
    SZ = sz;
    seg.resize(SZ*4);
    bld(1, 0, SZ-1, arr);
}
int query(int a, int b){
    return qry(a, b, 1, 0, SZ-1);
}
void update(int idx, int newVal){
    upd(1, 0, SZ-1, idx, newVal);
}
//now for the actual functions
int f(int a, int b){
    return a + b; //change this for different problems, sum query, RMQ, etc.
}
void build(int node, int l, int r, int arr[]) {
    if (l > r)
        return;
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid, arr);
    build(node * 2 + 1, mid + 1, r, arr);
    seg[node] = f(seg[node * 2], seg[node * 2 + 1]);
}
int qry(int a, int b, int node, int l, int r) {
    if (l > b || r < a) {
        return NINF;
    }
    if (l >= a && r <= b) {
        return seg[node];
    }
    int mid = (l + r) / 2;
    int n1 = query(a, b, node * 2, l, mid);
    int n2 = query(a, b, node * 2 + 1, mid + 1, r);
    if (n1 == NINF)
        return n2;
    if (n2 == NINF)
        return n1;
    return f(n1, n2);
}
void upd(int node, int l, int r, int idx, int newVal) {
    if (idx < l || idx > r)
        return;
    if(l == r) {
        seg[node] = newVal;
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, idx, newVal);
    update(node * 2 + 1, mid + 1, r, idx, newVal);
    seg[node] = f(seg[node*2], seg[node*2+1]);
}
