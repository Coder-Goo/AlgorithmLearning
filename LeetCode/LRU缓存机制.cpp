//哈希加双向链表
//哈希表用来存储key对应的结点
//unordered_map<int, ListNode*> cache;    //插入元素： cache.insert(key, node); 或 cache[key] = node;
//用哈希表取出链表中的元素并改变值：node = cache[key];   node -> value = value;
//双向链表的定义和初始化：！！！！

struct ListNode {
        int key , value;
        ListNode *pre , *next;
        ListNode(): key(0), value(0), pre(nullptr), next(nullptr){}
        ListNode(int _key, int _value):key(_key), value(_value),pre(nullptr), next(nullptr){}
};

class LRUCache {
public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        //使用虚拟头节点和尾结点
        head = new ListNode();
        tail = new ListNode();
        head -> next = tail;
        tail -> pre = head;
    }
    
    int get(int key) {
        if(!cache.count(key)) {
            return -1;
        }
        //如果在缓存中，那么取出对应的值，并移动到队列头部，表示最近用过，不会先被删除
        ListNode* node = cache[key];
        MoveToHead(node);
        return node -> value;
    }
    
    void put(int key, int value) {
        //如果缓存里有键值,更新value
        if(cache.find(key) != cache.end()) {
            ListNode * node = cache[key];
            node ->value = value;
            MoveToHead(node);
        }else {
            ListNode * node = new ListNode(key, value);
            cache[key] = node; //cache.insert({key,node});
            AddToHead(node);
            size ++;
            if(size > capacity) {
                ListNode *delete_node = tail -> pre;
                RemoveNode(delete_node);
                cache.erase(delete_node -> key);
                size--;
            }
        }
    }
private:
    unordered_map<int, ListNode*> cache;
    ListNode* head, *tail;
    int size, capacity;

    void MoveToHead(ListNode* node) {
        RemoveNode(node);
        AddToHead(node);
    }

    void AddToHead(ListNode * node) {
        node -> next = head -> next;
        node -> pre = head;
        head -> next -> pre = node;
        head -> next = node;
    }
    void RemoveNode(ListNode*node) {
        node-> pre -> next = node -> next;
        node -> next -> pre = node -> pre;
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */