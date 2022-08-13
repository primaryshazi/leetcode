#include <iostream>
#include <unordered_map>

struct LinkNode
{
    int key, value;
    LinkNode *prev;
    LinkNode *next;
    LinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    LinkNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
public:
    LRUCache() : LRUCache(10) {}

    LRUCache(int capacity) : capacity_(capacity)
    {
        head_ = new LinkNode();
        tail_ = new LinkNode();
        head_->next = tail_;
        tail_->prev = head_;
    }

    ~LRUCache()
    {
        for (auto &c : cache_)
        {
            delete c.second;
            c.second = nullptr;
        }
    }

    int get(int key)
    {
        if (cache_.count(key) == 0)
        {
            return -1;
        }

        // 将访问的节点移动到头部
        LinkNode *node = cache_[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (cache_.count(key) == 0)
        {
            // 新建节点将节点并添加到头部
            LinkNode *node = new LinkNode(key, value);
            cache_[key] = node;
            addToHead(node);

            // 若超过容量最删除尾部节点
            if (cache_.size() > capacity_)
            {
                LinkNode *last = removeTail();
                cache_.erase(last->key);
                delete last;
            }
        }
        else
        {
            // 修改节点值并将节点移动至头部
            LinkNode *node = cache_[key];
            node->value = value;
            moveToHead(node);
        }
    }

private:
    void addToHead(LinkNode *node)
    {
        node->prev = head_;
        head_->next->prev = node;
        node->next = head_->next;
        head_->next = node;
    }

    void removeNode(LinkNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(LinkNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    LinkNode *removeTail()
    {
        LinkNode *tmp = tail_->prev;
        removeNode(tmp);
        return tmp;
    }

private:
    std::unordered_map<int, LinkNode *> cache_; // 缓存key -> node
    LinkNode *head_;                            // 记录node访问时间顺序之头
    LinkNode *tail_;                            // 记录node访问时间顺序之尾
    size_t capacity_;                           // 最大容量
};

int main()
{
    LRUCache cache(5);
    for (int i = 0; i < 10; i++)
    {
        cache.put(i, i * i);
    }

    /**
     * => 0  -1
     * => 2  -1
     * => 4  -1
     * => 6  36
     * => 8  64
     */
    for (int i = 0; i < 10; i += 2)
    {
        std::cout << i << "  " << cache.get(i) << std::endl;
    }

    return 0;
}
