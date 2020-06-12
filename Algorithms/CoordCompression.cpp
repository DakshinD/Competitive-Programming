// O(n logn), but bad constant factor. Try finding solution with set + lower_bound
void coordCompress(){
    int temp[n];
    memcpy(temp, arr, n*sizeof(int));
    sort(temp, temp+n);
    unordered_map<int, int> map;
    int val = 0;
    FOR(i, n){
        map[temp[i]] = val++;
    }
    FOR(i, n){
        arr[i] = map[arr[i]];
    }
    return;
}
