#include<bits/stdc++.h>
using namespace std;

int parent[100000];
int rank[100000];

void makeSet(){
    for(int i = 0; i<100000; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPar(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findPar(parent[node]);   /////////Always remember to use this parent[node] = findPar(.....);
}

void union(int u, int v){
    u = findPar(u);
    v = findPar(v);
    if(rank[u]>rank[v]){
        parent[v] = u;
    }
    else if(rank[v] > rank[u]){
        parent[u] = v;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

void main(){
    makeSet();
    int m;
    cin>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        union(u, v);
    }

    // check if 2 and 3 belong to the same component or not
    if(findPar[2] == findPar[3]) cout<<"YES"<<endl;
    else  cout<<"NO"<<endl;
}
