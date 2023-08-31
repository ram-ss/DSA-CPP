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
    bool checkCycle(int src,unordered_map<int,bool>&visited,unordered_map<int,bool>&dfsVisited){
            visited[src] = true;
            dfsVisited[src] = true;
            for(auto nbr : adjList[src]){
                if(!visited[nbr]){
                    bool checkAns = checkCycle(nbr,visited,dfsVisited);
                    if(checkAns == true)
                        return true;
                }
                else{
                    if(dfsVisited[nbr] == true){
                        return true;
                    }
                }
            }
            // (Backtracking)
            dfsVisited[src] = false;
            return false;
        }
};

int main() {
  cout << "Genric Graph" << endl;
  Graph<int>g;
  g.addEdge(0,1,1);
  g.addEdge(1,2,1);
  g.addEdge(2,3,1);
  g.addEdge(3,4,1);
  g.addEdge(4,2,1);
  int n = 5;
  bool ans = false;
  unordered_map<int,bool>visited;
  unordered_map<int,bool>dfsVisited;
  for(int i = 0;i<n;i++){
      if(!visited[i]){
          ans = g.checkCycle(i,visited,dfsVisited);
          if(ans == true)
              break;
      }
  }
  if(ans == true)
      cout<<"Cycle is present";
  else    
      cout<<"Cycle not present";
  return 0;
}