void bfs(int currentNode){
    //requires a queue ds
    visited[currentNode] = true;
    queue.push(currentNode);

    while (!queue.empty()) {
        int curr = queue.top();
        queue.pop();
        for (int neighbour: adjList[curr]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                queue.push(neighbour);
            }
        }
               
    }
}
