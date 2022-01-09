#include <vector>
#include <map>
#include <iostream>
#include <utility>


template<typename T, typename F>
std::pair<T, F> operator*(const std::pair<T, F>& lhs,  const std::pair<T, F>& rhs);

template <typename T>
std::vector<T> Sqr(const std::vector<T>& vec);

template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value>& m);

template <typename First, typename Second>
std::pair<First, Second> Sqr(const std::pair<First, Second>& m);

template <typename T> T Sqr(T t);

template<typename T, typename F>
std::pair<T, F> operator*(const std::pair<T, F>& lhs,  const std::pair<T, F>& rhs)
{
    return std::make_pair(lhs.first*rhs.first, lhs.second*rhs.second);
}

template <typename T>
std::vector<T> Sqr(const std::vector<T>& vec)
{
    std::vector<T> result(vec.size());
    for(size_t i = 0; i < vec.size(); ++i)
    {
        result[i] = Sqr(vec[i]);
    }
    return result;
}

template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value>& m)
{
    std::map<Key, Value> result;
    for(const auto& item : m)
    {
        result[item.first] = Sqr(item.second);
    }
    return result;
}

template <typename First, typename Second>
std::pair<First, Second> Sqr(const std::pair<First, Second>& m)
{
    return m * m;
}

template <typename T>
T Sqr(T t)
{
    return t * t;
}