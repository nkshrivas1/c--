#include<iostream>
#include<vector>
using namespace std;
void bfs(int start,int V, vector<vector<int>>& adj){
    vector<bool> visited(V,false);
    queue<int> q;
    visited[start]=true;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for( int negh : adj[curr]){
            if(!visited[negh]){
                visited[negh] = true;
                q.push(negh);
            }
        }
    }
}
void dfs(int start,int V, vector<vector<int>>& adj,vector<bool>& visited){
    visited[start] = true;
    cout << start << " ";
    for( int negh : adj[start]){
        if(!visited[negh]){
            dfs(negh,V,adj,visited);
        }
    }
}
int main(){
    // adjacency matrxi
    int n,m;
    cin>> n >> m;
    vector<int> adjL[n+1];
    for(int i =0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adjL[u].push_back(v);
        adjL[v].push_back(u);
        
    }


    int adj[n+1][m+1];
    for(int i =0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] =1;
    }
}