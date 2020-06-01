//algo to find shortest path for all pairs of nodes in cubic/O(n^3) time. Uses adjacency matrix
for(int k = 0; k < n; j++){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }
}
