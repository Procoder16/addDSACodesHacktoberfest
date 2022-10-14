#include<bits/stdc++.h>
using namespace std;

void primsAlgo(vector<pair<int, int>> adj[], int n){
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);

    key[0] = 0;

    for(int i = 0; i < n-1; i++){  // because we will be having n-1 edges
        int mini = INT_MAX, u;
        for(int v = 0; v < n; v++){
            if(mst[v] == false && key[v] < mini){
                u = v;
                mini = key[v];
            }
        }

        mst[u] = true;

        for(auto it : adj[u]){
            int n = it.first;
            int w = it.second;

            if(mst[n] == false){
                if(w < key[n]){
                    key[n] = w;
                    parent[n] = u;
                }
            }
        }
    }

    cout<<"THE MINIMUM SPANNING TREE IS OF THE FORM:"<<endl;
    for(int i = 1; i < n; i++){
        cout<<parent[i]<<" - "<<i<<endl;
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

    primsAlgo(adj, n);

    return 0;
}