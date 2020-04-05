int bSearch(int low, int right){
    if(low == right){
        return low;
    }
    if(low + 1 == right) {
        if (check(low)) {
            return low;
        } else {
            return right;
        }
    }
    int mid = (low+right)/2;
    if(check(mid)){
        return bSearch(low, mid);
    }
    else{
        return bSearch(mid+1, right);
    }
}

