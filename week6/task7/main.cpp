#include <map>
#include <stdexcept>

template<typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& m,Key key)
{
    if(m.count(key)) {
        Value& res = m[key];
        return res;
    }
    throw std::runtime_error("not found");
}