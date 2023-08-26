#include <iostream>
#include<queue>
#include<stack>

using namespace std;

// function signature
void print(queue<int> &q);
void Reverse(queue<int> &q);
void ReverseKElement(queue<int> &q,int k);
vector<int> NegativeInWindow(queue<int> &q,int k);

// negative in window
vector<int> NegativeInWindow(vector<int> &vec,int k){
  queue<int> qt;
  vector<int> result;
  int n=vec.size();
  int i=0,j=0;
  while(j<n){
    if(vec[j]<0){
      qt.push(vec[j]);
    }
    if(j-i+1==k){
      result.push_back(qt.front());
      if(vec[i]==qt.front()){
        qt.pop();
      }
      i++;
      j++;
    }
    else{
      j++;
    }
  }
  return result;
}
// reverse first k
void ReverseKElement(queue<int> &q,int k){
  stack<int> s;
  int n=q.size();
  int count=0;
  while(!q.empty()){
    int top=q.front();
    q.pop();
    s.push(top);
    count++;
    if(count==k){
      break;
    }
  }
  while(!s.empty()){
    q.push(s.top());
    s.pop();
  }
  for(int i=0;i<n-k;i++){
    q.push(q.front());
    q.pop();
  }
}
// reverse
void Reverse(queue<int> &q){
  if(q.empty())
  {
    return;
  }
  int top=q.front();
  q.pop();
  Reverse(q);
  q.push(top);
}
// printing
void print(queue<int> &q){
  int n=q.size();
  for(int i=0;i<n;i++){
    int top=q.front();
    cout<<top<<" ";
    q.pop();
    q.push(top);
  }
  cout<<endl;
}
int main() {
  cout << "Queue Revesion" << endl;
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  cout<<"Original Queue"<<endl;
  print(q);

  // cout<<"reverse queue"<<endl;
  // Reverse(q);
  // print(q);

  // cout<<"Reversing k elements from start"<<endl;
  // ReverseKElement(q,4);
  // print(q);

  // first negative in k size window
  // vector<int> vec={1,-2,3,-4,1,-1,-6,9,7,-7};
  // vector<int> result=NegativeInWindow(vec,3);
  // for(auto it:result)
  //   cout<<it<<" ";
  // cout<<endl;

  

  return 0;
}
