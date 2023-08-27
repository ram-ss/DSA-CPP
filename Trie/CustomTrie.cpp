#include <iostream>
using namespace std;

class TrieNode{
        public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char d) {
                this->data = d;
                for(int i=0; i<26 ; i++) {
                        this->children[i] = NULL;
                }
                this->isTerminal = false;
        }
};

void insertWord(TrieNode* root, string word) {
        //cout << "Inserting " << word << endl;
   //base case
        if(word.length() == 0) {
                root->isTerminal = true;
                return;
        }
        
        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;
        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else {
                //not present
                child = new TrieNode(ch);
                root->children[index] = child;
        }

        //recursion
        insertWord(child, word.substr(1));
}

bool searchWord(TrieNode* root, string word) {
        //base case
        if(word.length() == 0) {
                return root->isTerminal;
        }

        char ch = word[0];
        int index = ch - 'a';
        TrieNode* child;

        //present
        if(root->children[index] != NULL) {
                child = root->children[index];
        }
        else{
                return false;
        }
        //rec call
        return searchWord(child, word.substr(1));

}

void deleteWord(TrieNode *root, string word)
{
        // base case
        if (word.length() == 0 && root->isTerminal == true)
        {
                cout << "Match Found and deleted" << endl;
                root->isTerminal = false;
                return;
        }
        char ch = word[0];
        int index = ch - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
                child = root->children[index];
                // recursion
                return deleteWord(child, word.substr(1));
        }
        else
        {
                cout << "Match Not Found" << endl;
        }
}

int main() {
  cout<<"Trie Implementation"<<endl;
  TrieNode* root = new TrieNode('-');

  //root->insertWord("coding");
  insertWord(root, "coding");
  insertWord(root, "code");
  insertWord(root, "coder");
  insertWord(root, "hello");
  deleteWord(root, "hello");
  cout << "Searching " << endl;
  if(searchWord(root,"cod")) {
          cout << "present" << endl;
  }
  else {
          cout << "absent" << endl;
  }

  return 0;
}
