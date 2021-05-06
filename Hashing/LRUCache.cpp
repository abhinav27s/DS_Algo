/*
Problem: LRU Cache
Link: https://leetcode.com/problems/lru-cache/
*/
class CacheList {
public:
    int key;
    CacheList* next;
}*head, * tail;

int cacheSize, maxSize;
map<int, int> hashMap;

class LRUCache {
    void updateCacheList(int key) {
        if (head->key == key)
            return;

        CacheList* ptr = head, * back = NULL;
        while (ptr) {
            if (ptr->key == key && back) {
                back->next = ptr->next;
                if (ptr == tail)
                    tail = back;
                ptr->next = head;
                head = ptr;
                return;
            }
            back = ptr;
            ptr = ptr->next;
        }
    }
    void addNewKey(int key, int value) {
        if (cacheSize < maxSize) {
            CacheList* node = new CacheList;
            node->key = key;
            node->next = head;
            head = node;
            if (!tail)
                tail = node;
            cacheSize++;
        }
        else {
            int oldKey = tail->key;
            hashMap.erase(oldKey);
            tail->key = key;
        }
        hashMap[key] = value;
    }
public:
    LRUCache(int capacity) {
        cacheSize = 0;
        maxSize = capacity;
        CacheList* p = head, * tmp;
        while (p) {
            tmp = p->next;
            delete(p);
            p = tmp;
        }
        head = tail = NULL;
        hashMap.clear();
    }

    int get(int key) {
        if (hashMap.find(key) == hashMap.end())
            return -1;
        updateCacheList(key);
        return hashMap[key];
    }

    void put(int key, int value) {

        if (hashMap.find(key) == hashMap.end())
            addNewKey(key, value);
        else
            hashMap[key] = value;

        updateCacheList(key);
    }
};

/*
Approach - 2 data structures used - hashmap to store key,value pairs. (simple array or stl map, any can be used)
and a linked list for LRU algorithm. If list capacity is full, then delete the last node and push new node while inserting new keys.
Also, update head pointers on get and put requests. */