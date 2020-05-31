bool sum = true; //true for sum queries
int len;
vector<int> seg, arr, lz;

void setSize(int l){
  len = l;
  seg.resize(l*4);
  lz.resize(l*4);
}

void build(vector<int> a) {
    len = a.size();
    seg.resize(len * 4);
    lz.resize(len * 4);
    arr = a;
    bld(1, 0, len - 1);
}

int query(int a, int b) {
    return qry(a, b, 1, 0, len - 1);
}

void update(int a, int b, int diff) {
    upd(1, 0, len - 1, a, b, diff);
}

//now for implementation

int f(int a, int b) { //change for different problems
    return a + b;
}

void bld(int node, int l, int r) {
    if (l > r)
        return;
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    seg[node] = f(seg[node * 2], seg[node * 2 + 1]);
}

int qry(int a, int b, int node, int l, int r) {
    down(node, l, r);
    if (l > b || r < a) {
        return -1;
    }
    if (l >= a && r <= b) {
        return seg[node];
    }
    int mid = (l + r) / 2;
    int n1 = query(a, b, node * 2, l, mid);
    int n2 = query(a, b, node * 2 + 1, mid + 1, r);
    if (n1 == -1)
        return n2;
    if (n2 == -1)
        return n1;
    return f(n1, n2);
}

void down(int node, int l, int r) {
    if(!lz[node])
        return;
    if(sum)
        seg[node] += (r - l + 1) * lz[node];
    else
        seg[node] += lz[node];
    if(l != r) {
        lz[node * 2] += lz[node];
        lz[node * 2 + 1] += lz[node];
    }
    lz[node] = 0;
}

void update(int node, int l, int r, int a, int b, int diff) {
    down(node, l, r);
    if(l > b || r < a)
        return;
    if(l >= a && r <= b) {
        lz[node] += diff;
        down(node, l, r);
        return;
    }
    int mid = (l + r) / 2;
    update(node * 2, l, mid, a, b, diff);
    update(node * 2 + 1, mid + 1, r, a, b, diff);
    seg[node] = f(seg[node*2], seg[node*2+1]);
}
