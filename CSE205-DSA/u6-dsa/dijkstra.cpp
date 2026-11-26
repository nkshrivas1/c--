#include<iostream>
using namespace std;

/*



*/
vector<int> dijkstra(int start, int V, vector<vector<pair<int,int>>>& adj){
    vector<int> dist(V,INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        int curr = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();
        if(currDist > dist[curr]) continue;
        for(auto& edge : adj[curr]){
            int next = edge.first;
            int weight = edge.second;
            if(dist[curr] + weight < dist[next]){
                dist[next] = dist[curr] + weight;
                pq.push({dist[next],next});
            }
        }
    }
    return dist;
}
