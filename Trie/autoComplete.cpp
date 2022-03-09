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
    trie(){
        root = new trieNode('\0');
    }

    void insertWord(trieNode* root,string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        trieNode* childNode;

        if(root->children[index] != NULL){
            childNode = root->children[index];
        }
        else{
            childNode = new trieNode(word[0]);
            root->children[index] = childNode;
        }

        insertWord(childNode,word.substr(1));
    }

    void insertWord(string word){
        insertWord(root,word);
    }

    trieNode* search(trieNode* root,string word){
        if(word.size() == 0){
            return root;
        }

        int index = word[0] -'a';
        if(root->children[index] != NULL)
            return search(root->children[index],word.substr(1));
    }

    trieNode* search(string word){
        return search(root,word);
    }

    void searchAutoWords(trieNode* root,string word){
        if(root==NULL){
            return;
        }

        if(root->isTerminal){
            cout<<word<<" ";
        }

        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                searchAutoWords(root->children[i],word+root->children[i]->data);
            }
        }
    }

    void autoComplete(vector<string> input,string pattern){
        for(int i=0;i<input.size();i++){
            insertWord(input[i]);
        }

        trieNode* temp = search(pattern);
        searchAutoWords(temp,pattern);
    }

};

int main() {
    trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}