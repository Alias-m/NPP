#ifndef FACTORY_H
#define FACTORY_H
#include <iostream>
#include <map>
#include <cstring>


template<typename V> class Factory
{
    typedef typename std::map<const char*, V>::const_iterator factory_iterator;
    private:
        const int keycmp(const char* key, const char* protocol) const{
            int i = 0;
            for(; key[i] != '\0' &&  protocol[i] != '\0' && key[i] == protocol[i];i++);
            return key[i] == protocol[i];
        }
        std::map<const char*, V> items;
	public:
		void put(const char* key, V value);
		V get(const char* key) const;
		factory_iterator begin(){
            return items.begin();
        }
		factory_iterator end(){
            return items.end();
        }
};

template <typename V> V Factory<V>::get(const char* key) const{
    for(typename std::map<const char*, V>::const_iterator it = items.begin(); it != items.end(); ++it) {
        if(keycmp(it->first, key))
            return it->second;
    }
    return nullptr;
}

template <typename V> void Factory<V>::put(const char* key, const V value){
    items.insert(std::pair<const char*, V>(key, value));
}
#endif //FACTORY_H
