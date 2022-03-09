#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
   int count;
    Trie() { 
        root = new TrieNode('\0'); 
        count = 0;
    }

    // bool insertWord(TrieNode *root, string word) {
    //     // Base case
    //     if (word.size() == 0) {
    //         if (!root->isTerminal) {
    //             root->isTerminal = true;
    //             return true;
    //         } else {
    //             return false;
    //         }
    //     }

    //     // Small calculation
    //     int index = word[0] - 'a';
    //     TrieNode *child;
    //     if (root->children[index] != NULL) {
    //         child = root->children[index];
    //     } else {
    //         child = new TrieNode(word[0]);
    //         root->children[index] = child;
    //     }

    //     // Recursive call
    //     return insertWord(child, word.substr(1));
    // }

    // void insertWord(string word) {
    //     if (insertWord(root, word)) {
    //         this->count++;
    //     }
    // }

    void insertWord(TrieNode* root,string word){
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* childNode;

        if(root->children[index] != NULL){
            childNode = root->children[index];
        }
        else{
            childNode = new TrieNode(word[0]);
            root->children[index] = childNode;
        }

        insertWord(childNode,word.substr(1));
    }

    void insertWord(string word){
        insertWord(root,word);
    }

    bool search(TrieNode* root,string word){
        if(word.size()==0)
            return true;
      
        int index=word[0]-'a';
        
        if(root->children[index]!=NULL)
            return search(root->children[index],word.substr(1));
        else
            return false;
    }

    bool search(string word) {
        // Write your code here
        return search(root,word);
    }

    string strReverse(string word){
        int left=0;
        int right = word.size()-1;
        
        while(left < right){
            char temp = word[left];
            word[left] = word[right];
            word[right] = temp;

            left++;
            right--;
        }
        return word;
    }

    bool pallindromePair(vector<string> arr){
        for(int i=0;i<arr.size();i++){
                insertWord(arr[i]);
        }

        for(int i=0;i<arr.size();i++){
            string word = strReverse(arr[i]);

            if(search(word)){
                return true;
            }
            else if(search(word.substr(1))){
                return true;
            }
        }
        return false;
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.pallindromePair(words) ? "true" : "false");
}

