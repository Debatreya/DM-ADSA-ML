#include <bits/stdc++.h>
using namespace std;

struct mnode{
    vector<int> key;
    vector<mnode*> next;

    mnode(int m,int key){
        for(int i = 0;i<m;i++){
            this->next.push_back(NULL);
        }
        this->key.push_back(key);
    }
};


class mway{
    int m,h;
    mnode* root;
public:
    mway(int m){
        root = NULL;
        this->m = m;
    }

    mnode* insertion(int item,mnode* ptr){
        if(root == NULL){
            root = new mnode(m,item);
            return root;
        }
        if(ptr == NULL){
            ptr = new mnode(m,item);
            return ptr;
        }
        mnode* newmnode = new mnode(m,item);
        if(ptr->key.size() == m-1){
            for(int i =0 ;i< m-1;i++){
                if(item < ptr->key[i]){
                    ptr->next[i] = insertion(item,ptr->next[i]);
                    break;
                }   
                else if(item > ptr->key[m-2]){
                    ptr->next[m-1] = insertion(item,ptr->next[m-1]);
                    break;
                }
            }
        }
        else{        
            ptr->key.push_back(item);
            sort(ptr->key.begin(),ptr->key.end());
        }
        return ptr;
    }

    int findsuc(mnode* ptr){
        if(ptr->next[0]==NULL){
            return ptr->key[0];
        }
        else{
            return findsuc(ptr->next[0]);
        }
    }
    mnode* deletion(int item,mnode*ptr){
        if(root == NULL){
            cout<<"\nempty tree.";
            return root;
        }
        if(ptr == NULL){
            return ptr;
        }
    
        for(int i = 0 ; i < ptr->key.size() ; i++){
            if(ptr->key[i] == item){
                if(ptr->next[i+1] != NULL){
                    int suc = findsuc(ptr->next[i+1]);
                    ptr->key[i] = suc;
                    ptr->next[i+1] = deletion(suc,ptr->next[i+1]);
                    return ptr;
                }
                else{
                    if(i < ptr->key.size()-1){
                        for(int j = i;j < ptr->key.size()-1;j++){
                            ptr->key[j] = ptr->key[j+1];
                            ptr->next[j+1] = ptr->next[j+2];
                        }
                    }
                    ptr->key.pop_back();
                    ptr->next[ptr->key.size()] = NULL;
                    return ptr;
                }
            }    
        }
        if(item < ptr->key[0]){
            ptr->next[0] = deletion(item,ptr->next[0]);
            return ptr;
        }
        for(int i =0;i<ptr->next.size();i++){
            if(i != ptr->key.size()-1){
                if(item > ptr->key[i] && item < ptr->key[i+1]){
                    ptr->next[i+1] = deletion(item,ptr->next[i+1]);
                    return ptr;
                }
            }
            else{
                if(item > ptr->key[i]){
                    ptr->next[i+1] = deletion(item,ptr->next[i+1]);
                    return ptr;
                }
            }
        }
    }

    void del(int item){
        mnode * ptr = deletion(item,root);
        if(ptr == NULL){
            cout<<"\nitem not found";
            return;
        }
        else{
            cout<<"\nitem found and deleted.";
        }
        return;
    }

    void traversal(){
        queue<mnode*> q1;
        if(root == NULL){
            cout<<"\ntree is empty.";
            return;
        }
        q1.push(root);
        q1.push(NULL);
        while(!q1.empty()){
            mnode * ptr = q1.front();
            q1.pop();
            if(ptr == NULL){
                cout<<"\n";
                continue;
            }
            for(int i =0;i<ptr->key.size();i++){
                cout<<ptr->key[i]<<"  ";
            }
            for(int i =0;i<ptr->key.size()+1;i++){
                q1.push(ptr->next[i]);
            }
        }
        return;
    }

    int height(){
        h = 0;
        queue<mnode*> q;
        mnode * ptr = root;
        q.push(ptr);
        if(root == NULL)
            return 0;
        int nodecount;
    
        while(!q.empty()){
            nodecount=q.size();
            for(int i =0;i<nodecount;i++){
                ptr = q.front();
                q.pop();
                for( int j = 0;j < ptr->next.size();j++){
                    if(ptr->next[j] != NULL)
                        q.push(ptr->next[j]);
                }
            }
            h++;
        }
        cout<<"\nheight is:"<<h;
        return h;    
    }
    
    vector<mnode*> a;
    void getlevel(mnode * ptr,int level){
        if (level == 0) {
			a.push_back(ptr);
		}
		else {
			if (ptr != NULL) {
                for(int i =0;i<m;i++){
				    getlevel(ptr->next[i], level - 1);
                }
			}
			else {
                for(int i =0;i<m;i++){
				    getlevel(NULL, level - 1);
                }
			}
		}
    }

    void ins(int item){
        insertion(item,root);
    }

    void traverse(){
        traversal();
    }
    
};

int main(){
    // Insertion
    mway t1(5);

    cout<<"Insertion\n";
    vector<int> ins = {50,60,80,30,35,58,59,63,70,73,96,52,54,61,62,57,55,56,53};
    for(auto i:ins){
        cout<<"\nInserting "<<i;
        t1.ins(i);
        // t1.traverse();
    }

    // Traversal
    cout<<"\nTraversal\n";
    t1.traverse();
    cout<<"\n";

    // Height
    t1.height();

    // Deletion
    cout<<"Deletion\n";
    vector<int> del = {63, 62, 96, 52};
    for(auto i:del){
        cout<<"\nDeleting "<<i;
        t1.del(i);
        t1.traverse();
    }
    return 0;
}