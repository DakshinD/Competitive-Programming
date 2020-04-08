struct BIT{
    int bit[ARRAY];
    void c(){
        for(int i=0;i<=n;i++){
            bit[i]=0;
        }
    }
    void update(int x, int y){
        for(;x<=n;x+=x&-x)
            bit[x]+=y;
    }
    int query(int x){
        int sum=0;
        for(;x>0;x-=x&-x){
            sum+=bit[x];
        }
        return sum;
    }
};
