#include<iostream>
using namespace std;
class TrieNode{
    public:
        TrieNode* children[26];
        int prefixCount;
        int endCount;
        TrieNode(){
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            prefixCount=0;
            endCount=0;
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
                curr->prefixCount++;
            }
            curr->endCount++;
        }
        int search(string word){
            TrieNode* curr = root;
            for( char ch: word){
                int index = ch-'a';
                if(curr->children[index] == NULL ) return 0;
                curr = curr->children[index];
            }
            return curr->endCount;
        }
        int startsWith(string prefix){
            TrieNode* curr=root;
            for( char ch: prefix){
                int index = ch-'a';
                if(curr->children[index] == NULL ) return 0;
                curr = curr->children[index];
            }
            return curr->prefixCount;
        }
        void erase(string word){
            TrieNode* curr = root;
            for(char ch : word){
                int index = ch-'a';
                if(curr->children[index]==nullptr) return;
                curr = curr->children[index];
            }
            if( curr->endCount == 0) return;
            curr = root;
            for(char ch: word){
                int index = ch-'a';
                curr = curr->children[index];
                curr->prefixCount--;
            }
            curr->endCount--;
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