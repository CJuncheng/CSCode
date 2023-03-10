
#include "hash_table.hpp"

// 基于哈希表的无序集合
template <class Object, class HashFunc = std::hash<Object>>
class HashSet
{
public:
    using MHashTable = HashTable<Object, HashFunc>;
    using Iterator = typename MHashTable::Iterator;
    using ConstIterator = typename MHashTable::ConstIterator;
    using KeyType = typename MHashTable::KeyType;

    HashSet(int n = 32): table_(n) {}

    // 插入
    std::pair<Iterator, bool> insert(const Object& obj)
    { return table_.insert(obj); }

    std::pair<Iterator, bool> insert(Object&& obj)
    { return table_.insert(std::move(obj)); }

    // 查找
    Iterator find(const KeyType& key) {return table_.find(key);}
    ConstIterator find(const KeyType& key) const {return table_.find(key);}

    // 删除
    bool remove(const KeyType& key) { return table_.remove(key); }

    void clear() { table_.clear(); }

    int size() const { return table_.size(); }

    ConstIterator begin() const { return table_.begin(); }
    Iterator begin() { return table_.begin(); }

    ConstIterator end() const { return table_.end(); }
    Iterator end() { return table_.end(); }

private:
    MHashTable table_; // 底层容器：哈希表
};


// 测试
#include <iostream>

int main()
{
    using namespace std;
    HashSet<int> set(4);
    set.insert(298);
    set.insert(190);
    set.insert(892);
    set.insert(92);
    set.insert(122);

    cout << set.size() << endl;

    cout << (set.find(298) != set.end()) << endl;
    cout << (set.find(10) != set.end()) << endl;

    for (const auto& x : set) cout << x << " ";
    cout << endl;

    set.remove(92);

    for (const auto& x : set) cout << x << " ";
    cout << endl;

    return 0;
}

