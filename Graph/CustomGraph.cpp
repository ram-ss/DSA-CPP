#include <iostream>
#include <list>
#include <unordered_map>
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
};

int main() {
  cout << "Genric Graph" << endl;
  Graph<int> g;
  g.addEdge(1,2,0);
  g.addEdge(2,3,0);
  g.addEdge(1,3,0);
  g.printGraph();
  return 0;
}