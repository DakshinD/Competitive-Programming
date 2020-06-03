//single source shortest path algo in O(NM), uses an edge list instead 
//but can be used on graphs with negative edge weights unlike dijkstra. 
//can identify positive/negative cycles
void bellmanFord(){
    distances[0] = 0;
    for(int i = 0; i < n; i++){
        bool relax = false;
        for(auto e : edgeList){
            ll a, b, w;
            tie(a, b, w) = e;
            if(disstances[a] + w < distances[b]){
                distances[b] = distances[a] + w;
                relax = true;
            }
        }
        if(!relax) break;
    }
    return;
}

//to find a negative cycle
for(auto e : edgeList){
     ll a, b, w;
     tie(a, b, w) = e;
     if(distances[a] + w < distances[b]){
         hasCycle = true;
         break;
     }
 }

//if you need to find if a cycle contains source and end node, you can do
for(int i = 0; i < n-1; i++){
        for(auto e : edgeList){
            ll a,b,w; tie(a,b,w) = e;
            if(distances[a] + w < distances[b] && distances[a] != INF){
                distances[b] = -INF; //then check if your target nodes have value of -INF
            }
        }
    }
