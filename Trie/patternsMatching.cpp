#include<bits/stdc++.h>
using namespace std;

class trieNode{
    public:
    char data;
    trieNode** children;
    bool isTerminal;

    trieNode(char data){
        this->data = data;
        children = new trieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class trie{
    trieNode* root;

    public:
    int count;
    trie() { 
        root = new trieNode('\0'); 
        count = 0;
    }

    bool insertWord(trieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        trieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }


    bool search(trieNode* root,string word){
        if(word.size() == 0){
            return true;
        }

        int index = word[0] -'a';

        if(root->children[index] != NULL){
            return search(root->children[index],word.substr(1));
        }
        else{
            return false;
        }
    }

    bool search(string word){
        return search(root,word);
    }

    bool patternMatching(vector<string> v,string pattern){
        for(int i=0;i<v.size();i++){
            while(v[i].size()!=0){
                insertWord(v[i]);
                v[i] = v[i].substr(1);
            }

            if(search(pattern)){
                return true;
            }
        }
        return false;
    }
};

int main(){
    trie t;
    int n;
    string pattern;
    vector<string> s(n);
    cin>>n;

    for(int i=0;i<n;i++){
        string word;
        cin>>s[i];
        s.push_back(word);
    }

    cin>>pattern;

    t.patternMatching(s,pattern) ? cout<<"True" : cout<<"False";

}
