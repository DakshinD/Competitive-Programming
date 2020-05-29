//if going into infinite loops, try (l+r+1)/2
//find smallest value for which P(x) holds true
while (l < r) {
  int mid = (l + r) / 2;
  if (P(mid)) r = mid;
  else l = mid + 1;
} // after the loop, l = r = x
//might not work if P(r) = 0, so extend to r+1 or pre check

//find largest value for which P(x) holds true - we could just set Q(x) != P(x) and use above to find x+1
//or use below implementation
while (l < r) {
  int mid = (l + r + 1) / 2;
  if (P(mid)) l = mid;
  else r = mid - 1;
} // after the loop, l = r = x

//if you need to find occurrence of k in sorted array, modified 1st version
bool search(int x[], int n, int k) {
  int l = 0, r = n - 1;
  while (l < r) {
    int mid = (l + r) / 2;
    if (x[mid] >= k) r = mid; 
    else l = mid + 1;
  }
  return x[l] == k;
}
