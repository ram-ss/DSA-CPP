#include <iostream>
using namespace std;
class LinkList{
  public:
    int data;
    LinkList *next;
  LinkList(int data){
    this->data=data;
    this->next=nullptr;
  }
};
// function signature
void print(LinkList *head);
LinkList *RevKGroup(LinkList *head,int k);
int Middle(LinkList *head);
int CountNode(LinkList *head);
LinkList *Reverse(LinkList *head);
LinkList *RecReverse(LinkList *head);
bool DetectLoop(LinkList *head);
LinkList *RemoveDuplicateInSortedLL(LinkList *head);
bool PalindromeCheck(LinkList *head);


// palindrome check
bool PalindromeCheck(LinkList *head){
  int n=CountNode(head);
  LinkList *pre=nullptr;
  LinkList *cur=head;
  LinkList *next=cur->next;
  LinkList *fast=head;
  while(fast!=nullptr && fast->next!=nullptr){
    fast=fast->next->next;
    next=cur->next;
    cur->next=pre;
    pre=cur;
    cur=next;
  }
  if(n%2==1){
    cur=cur->next;
  }
  while(pre!=nullptr && cur!=nullptr){
    if(pre->data!=cur->data){
      return false;
    }
    pre=pre->next;
    cur=cur->next;
  }
  return true;
}
// remove duplicate in sorted ll
LinkList *RemoveDuplicateInSortedLL(LinkList *head){
  LinkList *temp=head;
  while(temp->next!=nullptr){
    if(temp->data==temp->next->data){
      temp->next=temp->next->next;
    }
    else{
      temp=temp->next;
    }
  }
  return head;
}
// detect loop
bool DetectLoop(LinkList *head){
  LinkList *slow=head;
  LinkList *fast=head;
  while(fast!=nullptr){
    if(slow==fast){
      return false;
    }
    slow=slow->next;
    fast=slow->next;
  }
  return true;
}
// print nodes
void print(LinkList *head){
  LinkList *temp=head;
  while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
}
// reverse in k groups
LinkList *RevKGroup(LinkList *head,int k){
  if(CountNode(head)<k){
    return head;
  }
  LinkList *pre=nullptr;
  LinkList *cur=head;
  LinkList *next=cur->next;
  int count=0;
  while(count<k){
    next=cur->next;
    cur->next=pre;
    pre=cur;
    cur=next;
    count++;
  }
  LinkList *result=RevKGroup(cur,k);
  head->next=result;
  return pre;
}
// middle in link list
int Middle(LinkList *head){
  LinkList *slow=head;
  LinkList *fast=head->next;
  while(fast!=nullptr && fast->next!=nullptr){
    slow=slow->next;
    fast=fast->next->next;
  }
  return slow->data;
}
// count number of nodes in linkList
int CountNode(LinkList *head){
  LinkList *temp=head;
  int count=0;
  while(temp!=nullptr){
    count++;
    temp=temp->next;
  }
  return count;
}
// iterative reverse
LinkList *Reverse(LinkList *head){
  LinkList *pre=nullptr;
  LinkList *cur=head;
  LinkList *next=cur->next;
  while(cur!=nullptr){
    next=cur->next;
    cur->next=pre;
    pre=cur;
    cur=next;
  }
  return pre;
}
// recursive reverse
LinkList *RecReverse(LinkList *head){
  if(head->next==nullptr){
    return head;
  }
  LinkList* rev=RecReverse(head->next);
  head->next->next=head;
  head->next=nullptr;
  return rev;
}
int main() {
  cout << "Link List Revesion" << endl;
  LinkList *head=new LinkList(11);
  LinkList *head2=new LinkList(22);
  LinkList *head3=new LinkList(33);
  LinkList *head4=new LinkList(44);
  LinkList *head5=new LinkList(33);
  LinkList *head6=new LinkList(22);
  LinkList *head7=new LinkList(11);
  head->next=head2;
  head2->next=head3;
  head3->next=head4;
  head4->next=head5;
  head5->next=head6;
  head6->next=head7;
  // print
  cout<<"Original List"<<endl;
  print(head);
  
  // iterative
  head=Reverse(head);
  print(head);

  // recursive
  // head=RecReverse(head);
  // print(head);

  cout<<"No of nodes "<<CountNode(head)<<endl;

  cout<<"Middle "<<(Middle(head))<<endl;

  // cout<<"Reverse in k group"<<endl;
  // head=RevKGroup(head,3);
  // print(head);

  // cout<<"Remove duplicate"<<endl;
  // head=RemoveDuplicateInSortedLL(head);
  // print(head);
  
  // 1--true. 0--false
  // cout<<"Is Palindrome "<<PalindromeCheck(head)<<endl;

  return 0;
}
