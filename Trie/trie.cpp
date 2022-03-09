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

    bool search(trieNode* root,string word){
        if(word.size() == 0 && root->isTerminal == true){
            return true;
        }
        else if(word.size() == 0 && root->isTerminal != true){
            return false;
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

    void remove(trieNode* root,string word){
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        trieNode* child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return;
        }

        remove(child,word.substr(1));

        if(child->isTerminal == false){
            for(int i=0;i<26;i++){
                if(child->children[i] != NULL){
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }

}

    void remove(string word){
        remove(root,word);
    }
};

int main(){
    trie t;

    t.insertWord("omkar");
    t.insertWord("om");
    t.insertWord("rahul");
    t.insertWord("onkar");
    t.insertWord("raghav");

    cout<<"Before deletion....."<<endl;
    cout<<t.search("omkar")<<endl;
    cout<<t.search("om")<<endl;
    cout<<t.search("raghav")<<endl;
    cout<<t.search("onkar")<<endl;
    cout<<t.search("rahul")<<endl;
    cout<<t.search("ragham")<<endl;

    t.remove("rahul");
    t.remove("om");

    cout<<"After deletion....."<<endl;
    cout<<t.search("omkar")<<endl;
    cout<<t.search("om")<<endl;
    cout<<t.search("raghav")<<endl;
    cout<<t.search("onkar")<<endl;
    cout<<t.search("rahul")<<endl;
}