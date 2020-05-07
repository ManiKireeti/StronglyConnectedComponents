//
//  main.cpp
//  assignment2
//
//  Created by Mani Kireeti on 06/05/20.
//  Copyright © 2020 Mani Kireeti. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


//Kosarajus's Algorithm!

void DFS(vector<int > graph[],bool visited[],int vertex,int N){
    visited[vertex]=true;
    cout << vertex << " ";
    int i=0;
    for(;i<graph[vertex].size();i++){
        if(visited[graph[vertex][i]]==false){
            DFS(graph,visited,graph[vertex][i],N);
        }
    }
}

void DFS1(vector<int > graph[],bool visited[],int vertex,int N,stack<int> &stack){
    visited[vertex]=true;
    int i=0;
    for(;i<graph[vertex].size();i++){
        if(visited[graph[vertex][i]]==false){
            DFS1(graph,visited,graph[vertex][i],N,stack);
        }
    }
    stack.push(vertex);
}


void func(vector<int> graph[],int N){
    bool visited[N];
    stack<int> stack;
    for(int i=0;i<N;i++) visited[i]=false;
    
    //finding the sequence in the order of finishing times
    for(int i=0;i<N;i++){
        if(visited[i]==false){
            DFS1(graph,visited,i,N,stack);
        }
    }
    
    //transposing the given graph
    vector<int > graph2[N];
    for(int i=0;i<N;i++){
        for(int j=0;j<graph[i].size();j++){
            graph2[graph[i][j]].push_back(i);
        }
    }
    
    
    //Doing DFS for the top elements of the stack
    //which results in the SCC
    for(int i=0;i<N;i++) visited[i]=false;
    while(stack.size()>0){
        int a= stack.top();
        stack.pop();
        if(visited[a]==false) {
            DFS(graph2,visited,a,N);
            cout<<endl;
        }
    }
    
    
}

int main() {
    //N is the number of vertices
    int N;
    cin >> N;
    vector<int> graph[N];
    //T is the number of edges
    int T;
    cin>>T;
    while(T>0){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        T--;
    }
    func(graph,N);
    
    return 0;
}
