#include <bits/stdc++.h>
using namespace std;

class Node{
    
public:
    
    int Key;
    string Dado;
    Node * Left;
    Node * Right;
    
    Node(int K = 0, string D = ""){
        
        Key = K;
        Dado = D;
        Left = nullptr;
        Right = nullptr;
        
    }
    
    ~Node(){
      
      
        
    }
    
};

class Btree{
    
private:

    Node * Root;
    int N;
    int altura;
    
    static bool insertBtree(int K, Node * D, Node ** R){
        
        if(!(*R)){
            
            *R = D;
            return true;
            
        }
        
        if((*R)->Key > K){
            
            return insertBtree(K, D, &((*R)->Left));
            
        }
        
        return insertBtree(K, D, &((*R)->Right));
        
    }
    
    static void printBTree(Node * R){
        
        if(!(R)) return;
        
        printBTree((R->Left));
        
        cout << (R->Key) << endl;
        
        printBTree((R->Right));
        return;
        
    }
    
    static bool inverte(Node ** R){
        
        if(!(*R)) return true;
        
        inverte(&((*R)->Left));
        inverte(&((*R)->Right));
        
        swap(((*R)->Left), ((*R)->Right));
        return true;
        
    }
    
    static Node * getTree(int X, Node * R){
        
        if(!R) return nullptr;
        
        if(R->Key == X) return R;
        
        if(X < R->Key) return getTree(X, R->Left);
        
        return getTree(X, R->Right);
        
    };
    
    static Node * treeMin(Node * R){
        
        if(!((*R)->Left)) return &(*R);
        
        return treeMin(&((*R)->Left));
        
    }
    
    static bool deleteElement(int X, Node ** R){
        
        if(!(*R)) return false;
        
        if((*R)->Key == X){
            
            if(!((*R)->Left)){
                
                Node * AUX = *R;
                *R = (*R)->Right;
                delete AUX;
                return true;
                
            }
            
            if(!((*R)->Right)){
                
                Node * AUX = *R;
                *R = (*R)->Left;
                delete AUX;
                return true;
                
            }
            
            Node ** T = treeMin(&((*R)->Right));
            swap((*R)->Key, (*T)->Key);
            swap((*R)->Dado, (*T)->Dado);
            return deleteElement(X, &((*R)->Right));
            
        }
        
        if((*R)->Key > X){
            
            return deleteElement(X, &(*R)->Left);
            
        }
        
        return deleteElement(X, &(*R)->Right);
        
    }
    
    static void limpaArvore(Node * R){
        
        if(!R) return;
        
        limpaArvore(R->Left);
        limpaArvore(R->Right);
        delete R;
        
    }
    
public:
    
    Btree(int n = 0){
        
        Root = nullptr;
        N = n;
        altura = n;
        
    }
    
    bool setBtree(int K, string D){
        
        Node * DD = new Node(K, D);
        
        if(insertBtree(K, DD, &Root)){
            
            N++;
            return true;
            
        }
        
        return false;
        
    }
    
    void printTree(){
        
        printBTree(Root);
        
    }
    
    bool inverter(){
        
        return inverte(&Root);
        
    }
    
    Node * find(int X){
        
        return getTree(X, Root);
        
    }
    
    bool remover(int X){
        
        if(deleteElement(X, &Root)){
            
            N--;
            return true;
            
        }
        
        return false;
        
    }
    
    ~Btree(){
        
        limpaArvore(Root);
        
    }
    
};

int main()
{
    
    int X;
    string Dado;
    Btree WHT;
    
    while(cin >> X){
        
        cin >> Dado;
        
        WHT.setBtree(X, Dado);
        
    }
    
    WHT.printTree();
    
    cout << endl << (WHT.find(50))->Dado << endl;
    
    cout << endl;
 
    WHT.remover(10);
    
    WHT.printTree();
    
    WHT.inverter();
    cout << endl;
    WHT.printTree();
    
    return 0;
}