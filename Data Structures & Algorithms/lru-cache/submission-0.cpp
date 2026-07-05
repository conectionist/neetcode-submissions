class LRUCache {
public:
    LRUCache(int capacity) : m_capacity(capacity){
        
    }
    
    int get(int key) {
        if(!m_map.contains(key))
            return -1;

        auto it = m_map[key];
        m_cache.splice(m_cache.begin(), m_cache, it);

        return it->second;
    }
    
    void put(int key, int value) {
        if(!m_map.contains(key))
        {
            if(m_cache.size() == m_capacity)
            {
                m_map.erase(m_cache.back().first);
                m_cache.pop_back();
            }
            
            m_cache.insert(m_cache.begin(), {key, value});
            m_map[key] = m_cache.begin();
        }
        else
        {
            auto it = m_map[key];
            it->second = value;
            m_cache.splice(m_cache.begin(), m_cache, it);
        }
    }

private:
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
    list<pair<int, int>> m_cache;
    int m_capacity;
};
