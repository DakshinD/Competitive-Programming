int low = 0; int right = n;
int val = 0; //make this value looking for
while(low <= right){
  int mid = (low + (right - low))/2;
  if(arr[mid] == mid){
    return mid;
  }
  if(array[mid] > val){
    right = mid - 1;
  }
  else{
    low = mid + 1;
  }
}
