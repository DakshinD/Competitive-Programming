//used to find shortest path from source to every other node in
// O(n + mlogm). CAN'T be used on graph's with negative edge weights
//utilizes negative edge weights in pq so it can sort correctly

//if not using visited array, have if(dist[a] != dist) continue; after pop to achieve linearithmic time

vector<pll> adjList[1000000];
bool visited[1000000];
ll distances[1000000];

void dijkstra(){
    priority_queue<pll> pq; // --> {-distance to node a, a)
    pq.push({0, 0});
    while(!pq.empty()){
        ll a = pq.top().s; pq.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto x : adjList[a]){
            ll b = x.f, w = x.s;
            if(distances[a]+w < distances[b]){
                distances[b] = distances[a]+w;
                pq.push({-distances[b], b});
            }
        }
    }
    return;
}
