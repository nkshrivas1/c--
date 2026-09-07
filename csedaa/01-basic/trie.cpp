#include<iostream>
using namespace std;
class TrieNode{
    public:
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isEnd=false;
        }
};

class Trie{
    private: TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }
        void insert(string word){
            TrieNode* curr = root;
            for(char ch: word){
                int index = ch-'a';
                if(curr->children[index] == NULL){
                    curr->children[index] = new TrieNode();
                }
                curr = curr->children[index];
            }
            curr->isEnd = true;
        }
        bool search(string word){
            TrieNode* curr = root;
            for( char ch: word){
                int index = ch-'a';
                if(curr->children[index] == NULL ) return false;
                curr = curr->children[index];
            }
            return curr->isEnd;
        }
        bool startsWith(string prefix){
            TrieNode* curr=root;
            for( char ch: prefix){
                int index = ch-'a';
                if(curr->children[index] == NULL ) return false;
                curr = curr->children[index];
            }
            return true;
        }
};


int main(){
    Trie t;
    t.insert("apple");
    t.insert("apps");
    t.insert("apt");
    t.insert("bat");
    t.insert("bag");

    cout << t.search("app")<<endl;
    cout<<t.startsWith("app")<<endl;
    return 0;
}