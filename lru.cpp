#include <map>
#include <iostream>

using namespace std;


#define null 0
class LRUCache {
public:
    int capacity;
    int size;
    struct Node{
        Node *prev;
        Node *next;   
        int val;
        int key;
        Node(int k, int v){
            prev = null;
            next = null;
            key = k;
            val = v;
        }
    };
    class List{
        public:
        Node *head;
        Node *tail;
        List(){head = null;tail=null;}
        Node *add(int k, int v){
            if (!head){
                head = new Node(k ,v);
                tail = head;
                return head;
            }else{
                Node *otail = tail;
                tail = new Node(k, v);
                tail->prev = otail;
                otail->next = tail;
                return tail;
            }
        }
        void erase(Node *p){
            if(p != head){
                p->prev->next = p->next;
            }else{
                head = p->next;
            }
            if(p != tail){
                p->next->prev = p->prev;
            }else{
                tail = p->prev;
            }
            delete p;
        }
    };
    map<int, Node*> kvs;
    List *l;
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        l = new List();
    }
    
    int get(int key) {
        if(kvs.find(key) != kvs.end()){
            Node *now =  kvs[key];
            int ans = now->val;
            l->erase(now);
            Node * news = l->add(key, ans);
            kvs[key] = news;
            return ans;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(kvs.find(key) != kvs.end()){
            l->erase(kvs[key]);
            kvs.erase(key);
        }else if(kvs.size() >= capacity ){
            kvs.erase(l->head->key);
            l->erase(l->head);
        }
        Node * news = l->add(key, value);
        kvs[key] = news;
    }
};

int main(){
    LRUCache cache = LRUCache( 1 /* capacity */ );

cache.put(2, 1);
cout << cache.get(2) << endl;       // returns 1
cache.put(3, 2);    // evicts key 2
cout << cache.get(2)<< endl;       // returns -1 (not found)
cout << cache.get(3)<< endl;       // returns 3
}