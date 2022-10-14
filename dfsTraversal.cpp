//DFS Traversal In a GRAPH
#include<iostream>
#include<queue>
using namespace std;

void dfs(int i, vector<int> &vis, vector<int> adj[], vector<int> &storedfs){
    vis[i] = 1;
    storedfs.push_back(i);

    for(auto it : adj[i]){
        if(!vis[it]){
            dfs(it, vis, adj, storedfs);
        }
    }
}

void calldfs(int n, vector<int> adj[]){
    vector<int> storedfs;
    vector<int> vis(n+1, 0);

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            dfs(i, vis, adj, storedfs);
        }
    }

    for(int i = 0; i < storedfs.size(); i++){
        cout<<storedfs[i]<<" ";
    }
}

int main(){

    int n, m;
    cout<<"ENTER THE NUMBER OF NODES:";
    cin>>n;
    cout<<"ENTER THE NUMBER OF EDGES:";
    cin>>m;

    //ADJACENCY LIST
    
    vector<int> adj[n+1]; // this creates a static array of n+1 vectors
    cout<<"ENTER THE PAIRS OF NODES:"<<endl;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<"THE DFS TRAVERSAL OF THE GRAPH IS AS FOLLOWS:"<<endl;
    calldfs(n, adj);

    return 0;
}