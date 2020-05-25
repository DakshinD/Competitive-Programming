//use Topological Sort to sort a DAG in linear time, represent a DAG in linear representation
//where the nodes with the least number of incoming edges are on the "left" and ones
//with the most incoming edges on the "right"

vector<bool> visited;
vector<int> topoSorted;

void dfs(int curr){
    visited[curr] = true;
    for(int u : adjList[curr]){
        if(!visited[u]){
            dfs(u);
        }
    }
    topoSorted.pb(curr);
}
void topoSort(){
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}

int main(){
  //make adjList
  topoSort();
  reverse(all(topoSorted));
}
