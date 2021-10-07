
#include <bits/stdc++.h> 
using namespace std; 

class TrieNode 
{ 
public:
    TrieNode *child[26]={}; 
    bool isEndOfWord=false; 
}; 

void insert(TrieNode *root, string key) 
{ 
    TrieNode *j = root; 
    for(auto i:key) 
    { 
        if (!j->child[i-'a']) j->child[i-'a'] = new TrieNode; 
        j=j->child[i-'a']; 
    } 
    j->isEndOfWord = true; 
} 


int search(TrieNode *root, string key) 
{ 
    TrieNode *j = root; 
    for(auto i:key) 
    { 
        if (!j->child[i-'a']) return false; 
        j=j->child[i-'a']; 
    } 
    return (j!=NULL)+(j->isEndOfWord); 
} 

TrieNode *trie(long long n) 
{
    TrieNode *root = new TrieNode;   string x;  
    while(n--) 
      {cin>>x;
        insert(root,x); 
      }    
    return root;
} 
