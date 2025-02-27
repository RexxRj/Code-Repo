class LFUCache {
    private:

    struct node{
        int key;
        int val;
        int cnt;
        node* next;
        node* prev;
        node(int _key, int _val, int _cnt = 1){
            key = _key;
            val = _val;
            cnt = _cnt;
        }
    };

    int size;
    unordered_map<int,node*> m;

    node* head;
    node* tail;

    void addNode(node* newnode)
    {
        node* temp = head->next;
        while(temp->cnt>newnode->cnt)
        temp = temp->next;
        newnode->prev = temp->prev;
        newnode->next = temp;
        temp->prev->next = newnode;
        temp->prev = newnode;

    }

    void delNode(node* Node)
    {
        Node->prev->next = Node->next;
        Node->next->prev = Node->prev;
    }
public:
    LFUCache(int capacity) {
        size = capacity;
        head = new node(-1,-1,0);
        tail = new node(-1,-1,0);
        head->next = tail;
        tail->prev = head;
        
    }
    
    int get(int key) {
          if(m.find(key) == m.end()) return -1;

        node* temp = m[key];
        int res = temp->val;
        temp->cnt++;

        delNode(temp);
        addNode(temp);
        return res;
    }
    
    void put(int key, int value) {
        int cnt = 0;
        
        if(m.find(key) != m.end())
        {
            node* temp = m[key];
            cnt = temp->cnt;
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

        node* newnode = new node(key,value,++cnt);
        addNode(newnode);
        m[key] = newnode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */