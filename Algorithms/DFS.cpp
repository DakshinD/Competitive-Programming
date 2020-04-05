void dfs(int currentNode){
  if(visited[currentNode]){
    return;
  }
  visited[currentNode] = true;
  for(int j : adjList[currentNode]){
    if(!visited[j]){
      dfs(j);
    }
  }
  return;
}
