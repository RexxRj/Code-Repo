class LRUCache {
private:

    struct node{
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    int size;
    unordered_map<int,node*> m;

    node* head;
    node* tail;

    void addNode(node* newnode)
    {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void delNode(node* Node)
    {
        Node->prev->next = Node->next;
        Node->next->prev = Node->prev;
    }

public:
    LRUCache(int capacity) {
        size = capacity;
        head = new node(-1,-1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {

        if(m.find(key) == m.end()) return -1;

        node* temp = m[key];
        int res = temp->val;

        delNode(temp);
        addNode(temp);
        return res;
    }
    
    void put(int key, int value) {

        if(m.find(key) != m.end())
        {
            node* temp = m[key];
            delNode(temp);
            m.erase(key);
            delete temp;
        }

        if(m.size() == size)
        {
            node* del = tail->prev;
            delNode(del);
            m.erase(del->key);
            delete del;
        }

        node* newnode = new node(key,value);
        addNode(newnode);
        m[key] = newnode;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */