/*
Problem: LRU Cache
Link: https://leetcode.com/problems/lru-cache/
*/
class CacheList{
    public:
    int key;
    CacheList *next, *prev;
}*head, *tail;

class LRUCache {
    
    unordered_map<int, pair<int, CacheList*> > hashMap;
    int maxCapacity, curCapacity;
    void updateCacheList(CacheList *p){
        if(p==head || p==NULL)
            return;
        p->prev->next = p->next;
        
        if(p->next)
            p->next->prev = p->prev;
        
        if(p==tail)
            tail = p->prev;
        
        p->next = head;
        p->prev = NULL;
        head->prev = p;
        head = p;
    }
    void addCacheList(int key,int value){
        CacheList *node = new CacheList();
        node->key = key;
        node->next = node->prev = NULL;
        if(head==NULL)
            head = tail = node;
        else{
            head->prev = node;
            node->next = head;
            head = node;
        }
        hashMap[key].first = value;
        hashMap[key].second = node;
        if(curCapacity < maxCapacity)
            curCapacity++;
        else{
            hashMap.erase(tail->key);
            CacheList *tmp = tail->prev;
            tmp->next = NULL;
            delete(tail);
            tail = tmp;
        }
    }
public:
    LRUCache(int capacity) {
        curCapacity = 0;
        maxCapacity = capacity;
        hashMap.clear();
        CacheList *ptr = head;
        while(ptr){
            CacheList *tmp = ptr->next;
            delete(ptr);
            ptr = tmp;
        }
        head = tail = NULL;
    }
    
    int get(int key) {
        if(hashMap.find(key)==hashMap.end())
            return -1;
        updateCacheList(hashMap[key].second);
        return hashMap[key].first;
    }
    
    void put(int key, int value) {
        if(hashMap.find(key)==hashMap.end())
            addCacheList(key,value);
        else
            hashMap[key].first = value;
        updateCacheList(hashMap[key].second);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
/*
Approach - 2 data structures used - hashmap to store key,value pairs. (simple array or stl map, any can be used)
and a linked list for LRU algorithm. If list capacity is full, then delete the last node and push new node while inserting new keys.
Also, update head pointers on get and put requests. */