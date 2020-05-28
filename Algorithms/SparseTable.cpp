//constructs in O(N LogN), answers sum in O(log MAXN) and min in O(1), however, original array is static, can't update
//range sum implementation
long long st[MAXN][K]; //where K is the max power of 2, 25 for <= 1e7, 32 for 1e9, etc.

for (int i = 0; i < N; i++)
    st[i][0] = array[i];

for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1];

int query(int l, int r){       
    long long sum = 0; //sum of (l, r) in O(log MAXN)
    for (int j = K; j >= 0; j--) {
        if ((1 << j) <= R - L + 1) {
            sum += st[L][j];
            L += 1 << j;
        }
    }      
    return sum;
}

//range min implementation
//precomputaton of logs

int log[MAXN+1];
int st[MAXN][K];

//precompute logs
log[1] = 0;
for (int i = 2; i <= MAXN; i++)
    log[i] = log[i/2] + 1;
//construction
for (int i = 0; i < N; i++)
    st[i][0] = array[i];
for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= N; i++)
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);   
//query in O(1)
int query(int l, int r){
    int j = logs[r - l +1];
    int minimum = min(sparse[l][j], sparse[r-(1<<j)+1][j]);
    return minimum;
}
