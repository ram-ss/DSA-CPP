#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class MaxHeap{
  private:
    vector<int> vec={-1};
    int it;
  public:
    MaxHeap(){
      this->it=0;
    }

    MaxHeap(int val){
      this->vec.push_back(val);
      this->it=1;
    }

    void push(int val){
      this->vec.push_back(val);
      this->it+=1;
      // positioning of inserted element
      int i=it;
      while(i>1){
        int parent=i/2;
        if(this->vec[i]>this->vec[parent]){
          swap(this->vec[i],this->vec[parent]);
        }
        i=parent;
      }
    }

    int top(){
      return this->vec[1];
    }

    void pop(){
      this->vec[1]=this->vec[this->it];
      this->vec.pop_back();
      this->it-=1;
      // positioning after poping
      int i=1;
      int largest=1;
      while(i<=this->it){
        int left=2*i;
        int right=2*i+1;
        if(left<=this->it && this->vec[largest]<this->vec[left]){
          largest=left;
        }
        if(right<=this->it && this->vec[largest]<this->vec[right]){
          largest=right;
        }
        if(i==largest){
          break;
        }
        swap(this->vec[i],this->vec[largest]);
        i=largest;
      }
    }
    
    int size(){
      return this->it;
    }

    void print(){
      for(int i=1;i<this->vec.size();i++){
        cout<<this->vec[i]<<" ";
      }
      cout<<endl;
    }
};

int main() {
  cout<<"Max Heap Custom "<<endl;
  MaxHeap h;
  h.push(1);
  h.push(2);
  h.push(3);
  h.pop();
  h.push(200);
  cout<<h.top()<<endl;
  h.print();
  return 0;
}