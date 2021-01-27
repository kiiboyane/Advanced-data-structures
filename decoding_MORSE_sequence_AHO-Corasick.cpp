  #include <iostream>
  #include <stdio.h>
  #include <vector>
  #include <set>
  #include <queue>
  #include <map>
  #include <algorithm>
  #include <cmath>
/*

Solution for MORSE problem using Aho_Corasick algorithm
https://www.spoj.com/problems/MORSE/


*/

  using namespace std;
  #define ll long long
  string message; 
  int ID = 0;
  vector<vector<int> > indexes;
  vector<int> answer;  
  struct Node{
    Node * fail; 
    Node* next[2];
    vector<int> patternID; 
    int id;
    Node(){ 
       next[0] = NULL; 
       next[1] = NULL;
       id = ID++;  
    }
    int addWord(string s){
      Node* tmp = this; 
      int index = 0 , nxt = 0; 
      while(index < s.size()){
         if(s[index] == '.') nxt = 0; 
         else nxt = 1; 
         if(tmp->next[nxt] == NULL) tmp->next[nxt] =new Node(); 
         tmp = tmp->next[nxt]; 
         index++; 
      }
      (tmp->patternID).push_back(tmp->id); 
      return tmp->id; 
    }
  };
  template<typename Type>
  void print(vector<Type> v){
     for(auto a : v) cout << a << ' ' ; 
     cout << endl;  
  } 
  string morse(string word){
     string code[26] = {".-" ,"-...","-.-.","-..", "." ,"..-.","--.","....",".." , ".---", "-.-", ".-..","--","-.","---",".--." , "--.-", ".-.", "...", "-", "..-" , "...-", ".--", "-..-", "-.--", "--.."}; 
     string morsecode =""; 
     for(auto c : word){
        morsecode += code[c-'A']; 
     }
     return morsecode; 
  }
  Node* getfail(Node* node, Node* parentfail , int alpha){
   while(parentfail->next[alpha] == NULL) {
     parentfail = parentfail->fail; 
   }
   if(parentfail->next[alpha] != NULL){
      node->fail = parentfail->next[alpha]; 
      return parentfail->next[alpha]; 
   }
   return parentfail; 
  }
  void Aho_Corasick(Node* node, string message , map<int , string> dict){
    queue<Node* > nodes; 
    for(auto i : {0 , 1}){
      if(node->next[i]){
         node->next[i]->fail = node; 
         nodes.push(node->next[i]); 
      }else{
        node->next[i] = node;
      }
    }
    while(!nodes.empty()){
      Node * curr = nodes.front(); 
      nodes.pop();
      Node * currfail = curr->fail , childfail; 
      for(auto i : {0 , 1}){
         if(curr->next[i] == NULL) continue;
         curr->next[i]->fail = getfail(curr->next[i], currfail, i); 
         curr->next[i]->patternID.insert(curr->next[i]->patternID.end(), curr->next[i]->fail->patternID.begin(), curr->next[i]->fail->patternID.end());
         nodes.push(curr->next[i]); 
      }
    }
    Node * curr = node; 
    for(int i = 0 ; i<message.size();){
      int c = (message[i]  == '.') ? 0 : 1; 
      if(curr->next[c] != NULL){
         for(auto a : curr->next[c]->patternID){ 
           indexes[i+1-dict[a].size()].push_back(i+1); 
         } 
         curr = curr->next[c]; 
         i++;
      }else{
         if(curr != node){
          curr = curr->fail; 
         }else{
          i++;   
         }
      }
    }
  }

  void bfs(Node * node){
     queue<Node* > nodes; 
     nodes.push(node); 
     while(!nodes.empty()){
        node =  nodes.front(); 
        nodes.pop(); 
        for(auto i : {0,1}){
           if(node->next[i] != NULL){
             nodes.push(node->next[i]); 
             if(!node->patternID.empty()) cout << node->patternID[0] << endl; 
           }
        }
     }
  }
  void dfs(Node * node){
     if(node == NULL) 
       return;
     if(!node->patternID.empty()) cout << node->patternID[0] <<endl;  
     for(int i=0 ; i<2 ; i++){
       if(node->next[i] != NULL) cout<< ((i == 0)?'.':'-') << endl; 
       dfs(node->next[i]); 
     }
  }
  int decode(int index){
     if(index == message.size())
       return 1; 
     if(answer[index] != -1)
       return answer[index]; 
     int resp = 0; 
     for(auto next : indexes[index]){
       resp += decode(next); 
     }
     answer[index] = resp; 
     return resp;
  }
  int main() {
    ios::sync_with_stdio(false);    
    cin.tie(0);  
    int t, n , id;
    cin >> t;
    string word;  
    while(t--){
      map<int, string> dict; 
      Node* root = new Node();
      indexes.clear();
      answer.clear();   
      cin >> message >> n;
      indexes.resize(message.size() + 1); 
      answer.resize(message.size()+1 , -1); 
      for(int i=0; i<n ; i++){
         cin >> word; 
         id = root->addWord(morse(word)); 
         dict[id] = morse(word);
      }
      Aho_Corasick(root , message , dict);  
      cout << decode(0) << endl; 
    } 
  } 
/*



*/