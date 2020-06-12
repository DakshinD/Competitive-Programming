// 1 - indexed BIT
void c(){
    for(int i = 0; i <=n; i++){
        bit[i] = 0;
    }
}
void update(int x, int val){
    while(x<=n){
        bit[x]+=val;
        x+=x&(-x);
    }
}
int query(int pos){
    int sum=0;
    while(pos>0){
        sum+=bit[pos];
        pos-=pos&(-pos);
    }
    return sum;
}
