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
    void bfs(int src,unordered_map<int,bool>& visited){
      queue<int> q;
      q.push(src);
      visited[src]=true;
      while(!q.empty()){
        // take out the first node
        int front=q.front();
        q.pop();
        cout<<front<<" ";
        for(auto neigbour:adjList[front]){
          // extract all unvisited nodes
          if(!visited[neigbour]){
            q.push(neigbour);
            visited[neigbour]=true;
          }
        }
      }
    }
    void dfs(int src,unordered_map<int,bool>& visited){
      cout<<src<<" ";
      visited[src]=true;
      for(auto neigbour:adjList[src]){
        if(!visited[neigbour]){
          dfs(neigbour,visited);
        }
      }
    }
};

int main() {
  cout << "Genric Graph" << endl;
  Graph<int> g;
  g.addEdge(0,1,0);
  g.addEdge(1,2,0);
  g.addEdge(1,3,0);
  g.addEdge(3,5,0);
  g.addEdge(3,7,0);
  g.addEdge(7,6,0);
  g.addEdge(7,4,0);
  g.printGraph();
  // bfs of graph (traversal)
  cout<<"BFS Traversal"<<endl;
  unordered_map<int,bool> visited;
  for(int i=0;i<=7;i++){
    if(!visited[i]){
      g.bfs(i,visited);
    }
  }
  // dfs of graph (traversal)
  cout<<"BFS Traversal"<<endl;
  for(int i=0;i<=7;i++){
    if(!visited[i]){
      g.dfs(i,visited);
    }
  }

  return 0;
}