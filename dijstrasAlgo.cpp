//DIJKSTRA's ALGORITHM
#include<iostream>
#include<vector>
#include<utility>
#include<queue>
using namespace std;

void dijkstra(vector<pair<int, int>> adj[], int n){
    vector<int> shortDist(n+1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    shortDist[1] = 0;
    pq.push(make_pair(0, 1));

    while(!pq.empty()){
        int node = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();
        for(auto it : adj[node]){
            int dist = it.second;
            int n = it.first;
            if(shortDist[node] + dist < shortDist[n]){
                shortDist[n] = currDist + dist;
                pq.push(make_pair(shortDist[n], n));
            }
        }
    }

    cout<<"FINAL SHORTEST DISTANCE ARRAY IS:";
    for(int i = 1; i <= n; i++){
        cout<<shortDist[i]<<" ";
    }
}

int main(){

    int n, m;
    cout<<"ENTER THE NUMBER OF NODES:";
    cin>>n;
    cout<<"ENTER THE NUMBER OF EDGES:";
    cin>>m;

    vector<pair<int, int>> adj[n+1];

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin>>u>>v>>w;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    dijkstra(adj, n);

    return 0;
}