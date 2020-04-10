struct BIT{ //remember to stay consistent whether you one index or 2 index, never use 0 indexing
    int bit[ARRAY];
    void c(){
        for(int i = 0; i <= n; i++){
            bit[i] = 0;
        }
    }
    void update(int x, int y){
        for(;x <= MAXN; x += x & -x) //MAXN being a huge number, the restriction provided
            bit[x] += y;
    }
    int query(int x){
        int sum = 0;
        for(;x > 0; x -= x & -x){
            sum += bit[x];
        }
        return sum;
    }
};
