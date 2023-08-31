#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

template<typename T>
class Graph{
  public:
    unordered_map<T,list<T>> adjList;
    void addEdge(T u,T v,bool direction){
      adjList[u].push_back(v);
      // 0---> denotes undirected graph
      if(direction==0){
        adjList[v].push_back(u);
      }
    }
    void printGraph(){
      for(auto node:adjList){
        cout<<node.first<<"--> ";
        for(auto neighbour:node.second){
          cout<<neighbour<<", ";
        }
        cout<<endl;
      }
    }
    bool checkCycleDFS(int src,unordered_map<int,bool>& visited,int parent){
      // checking dfs way
      visited[src]=true;
      for(auto neigbour:adjList[src]){
        if(!visited[neigbour]){
          return checkCycleDFS(neigbour,visited,src);
        }
        else{
          if(neigbour!=parent){
            // cycle found
            return true;
          }
        }
      }
      return false;
    }
    bool checkCycleBFS(int src,unordered_map<int,bool>& visited){
      // checking cycle bfs way
      queue<int> q;
      unordered_map<int,int> parent;
      q.push(src);
      visited[src]=true;
      parent[src]=-1;
      while(!q.empty()){
        int front=q.front();
        q.pop();
        for(auto neigbour:adjList[front]){
          if(!visited[neigbour]){
            q.push(neigbour);
            visited[neigbour]=true;
            parent[neigbour]=front;
          }
          else{
            if(parent[front]!=neigbour){
              // cycle detected
              return true;
            }
          }
        }
      }
      return false;
    }
};

int main() {
  cout << "Genric Graph" << endl;
  Graph<int>g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);
    g.addEdge(4,0,0);
    int n = 5;
    bool ans = false;
    unordered_map<int,bool>visited;
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            ans = g.checkCycleDFS(i,visited,-1);
            // ans = g.checkCycleBFS(i,visited);
            if(ans == true)
                break;
        }
    }
    if(ans == true)
        cout<<"Cycle is present";
    else    
        cout<<"Cycle not present";
    return 0;

  return 0;
}