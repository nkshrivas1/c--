// Suppose a student has 60 minutes available and wants to complete tasks.
// Task
// Time Required
// Benefit
// A
// 10 minutes
// 20 points
// B
// 20 minutes
// 35 points
// C
// 30 minutes
// 45 points\
// Greedy  is an algorithmic technique in which a solutions
// is constructed step by step by selecting locally attractive choice at each stage.
// template://
/*
1 start with the initial state
2. consider all the options available at specific time
3. choose the option that seems best at moment
4. move to the new state based on your chosen option
5. Repeat 2-4 until reach goal or no further progress possibel

 Greedy(a,n){
    for(i=0 to n){
        x= select(a)
        if(feasible(x))then 
            solution = solution + x;
    }
 }
*/

/*
OBJECTS - 1, 2, 3, 4, 5, 6, 7
PROFITS - 10, 5, 15, 7, 6, 18, 3
WEIGHTS - 2,  3, 5,  7,  1,  4, 1
P/W -     5,  1.3,3, 1, 6, 4.5,  3

CAPACITY = 15
N = 7
// COIN CHANGE PROBLEM
*/
// Algorithm for knapsack
/*
1. Read the number of items and knapsack capacity
2. Store each item's weight and value
3.Calculate each item's value to weight ratio
4.Sort the items in decreasing ratio order
5. traverse the sorted items
6.if the complete item fits , take it
7.Otherwise,tae only the the fraction that fits
8.add the corresponding value to the total
9.stop when the capacity is exhausted or no items remain
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct item{
    double weight;
    double value;
};
double fk(vector<item>& items,double capacity){
    sort(items.begin(),items.end(),
    [](const item& a, const item& b){
        return a.value/a.weight > b.value/b.weight;
    });
    double totalValue = 0.0;
    for(const auto& item:items){
        if(capacity<=0) break;
        double wt = min(capacity,item.weight);
        double ratio = item.value/item.weight;
        totalValue += wt*ratio;
        capacity-=wt;
    }
    return totalValue;
}
/*
Minimum spanning tree
provides a minimum cost set of edges that connects every vertex of a connected ,
 weighted,undirected graph without forming cycles.

*/


int mst(int V,vector<vector<int>> adj[]){
    priority_queue<pair<int,int>,vector<pair<int,int>>
        ,greater<pair<int,int>>> pq;
    vector<int> vis(V,0);
    // {wt,node}
    pq.push({0,0});
    int sum =0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if(vis[node]==1) continue;
        vis[node] = 1;
        sum +=wt;
        for(auto it:adj[node]){
            int adjNode = it[0];
            int edw = it[1];
            if(!vis[adjNode]){
                pq.push({edw,adjNode});
            }
        }
    }
    return sum;
}



int main(){
//     PROFITS - 10, 5, 15, 7, 6, 18, 3
// WEIGHTS - 2,  3, 5,  7,  1,  4, 1
    vector<item> items={
        {2,10},
        {3,5},
        {5,15},
         {7,7},
        {1,6},
        {4,18},
        {1,3}
    };
    double capacity = 15;
    double ans = fk(items,capacity);
    cout << " Maximum Value= "<< ans << endl;
    return 0;
}
/*
Kruskal algorithm
1. sort all edges in ascending order of weight
2. initially consider every vertex to be in his own seperate component
3. select the next cheapest edge
4.if its endpoints belongs to different componet, accept the edge and merge those components
5. if its endpoint belong to te same component, reject the edge because it
would create cycle
6. stop when (V-1) edges have been accepted or when no more edhges remain

(1,2),(2,3),(4,5),(6,7),(5,6),(3,7
union(u,v)
1. find ultimate parent of u & v
2.find rank of pu , pv
3. connect smaller rank to larger rank)
5
1.
*/

class DisjointSet{
    vector<int> rank,parent;
    public:
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i =0;i<=n;i++){
                parent[i] = i;
            }
        }
        int findupar(int node){
            if(node==parent[node]) return node;
            return parent[node] = findupar(parent[node]);

        }
        void unionByRank(int u,int v){
            int ulp_u = findupar(u);
            int ulp_v = findupar(v);
            if(ulp_u==ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if( rank[ulp_v]< rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v]= ulp_u;
                rank[ulp_u]++;
            }


        }
};

/*
wt, u , v
1, 1, 4
2, 1, 2
2, 2, 3
3, 2, 4
4, 1, 5
5, 3, 4
7, 2, 6
8,3, 6
9,4, 5


*/

int kruskal(int v,vector<vector<int>> adj[]){
    vector<pair<int,pair<int,int>>> edges;
    for( int i =0;i<v;i++){
        for(auto it: adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    sort(edges.begin(),edges.end());
    DisjointSet ds(v);
    int mstwt=0;
    for(auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(ds.findupar(u) != ds.findupar(v)){
            mstwt +=wt;
            ds.unionByRank(u,v);
        }
    }
    return mstwt;
}