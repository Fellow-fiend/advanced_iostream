/*  © Fellow-fiend
 *  Advanced input/output library can input or output from(to) standart stream 
 *  std::vector<T>, std::array<T>, std::list<T>, std::forward_list<T>, std::deque<T>,
 *  std::map<Key, Value>, std::multimap<Key, Value>, std::unordered_map<Key, Value>, std::unordered_multimap<Key, Value>
 *  std::set<T>, std::multiset<T>, std::unordered_set<T>, std::unordered_multiset<T>.
 *
 *  You can switch off input/output for all kinds of std::map by simply adding a line 
 *  #define WITHOUT_MAP 
 *  at the beginning of your program.
 *
 * */

/*           TODO 
 *  add move semantics
 *  add support C++11
 *  make git repository and push to github 
 *
 * */

#pragma once

#include <iostream>


template <typename T>
using predicat = std::enable_if_t<(sizeof(typename T::value_type) != sizeof(T)) 
                                && !std::is_convertible_v<T, std::string>,
                                std::ostream&>;

/* Output */
template <typename T, typename = predicat<T> >
std::ostream& operator<< (std::ostream& out, const T& coll)
{
    for (const auto& item : coll)
        out << item << " ";

    return out << std::endl;
}

#ifndef WITHOUT_MAP
#include <map>
#include <unordered_map>
template <typename T, typename V>
std::ostream& operator<< (std::ostream& out, const std::map<T, V>& coll)
{
    for (const auto& item : coll)
        out << item.first << ": " << item.second << "\n";

    return out;
}

template <typename T, typename V>
std::ostream& operator<< (std::ostream& out, const std::multimap<T, V>& coll)
{
    for (const auto& item : coll)
        out << item.first << ": " << item.second << "\n";

    return out;
}

template <typename T, typename V>
std::ostream& operator<< (std::ostream& out, const std::unordered_map<T, V>& coll)
{
    for (const auto& item : coll)
        out << item.first << ": " << item.second << "\n";

    return out;
}

template <typename T, typename V>
std::ostream& operator<< (std::ostream& out, const std::unordered_multimap<T, V>& coll)
{
    for (const auto& item : coll)
        out << item.first << ": " << item.second << "\n";

    return out;
}

#endif

/* Input */
template <typename T, typename = predicat<T> >
std::istream& operator>> (std::istream& input, T& coll)
{
    for (auto& item : coll)
    {
        input >> item;
    }
    return input;
}

#ifndef WITHOUT_MAP
template <typename T, typename V>
std::istream& operator>> (std::istream& input, std::map<T, V>& coll)
{
    T key {};
    V value {};
    while (input >> key >> value)
        coll[key] = value;

    return input;
}

template <typename T, typename V>
std::istream& operator>> (std::istream& input, std::multimap<T, V>& coll)
{
    T key {};
    V value {};
    while (input >> key >> value)
        coll.insert(std::pair<T, V>(key, value));

    return input;
}

template <typename T, typename V>
std::istream& operator>> (std::istream& input, std::unordered_map<T, V>& coll)
{
    T key {};
    V value {};
    while (input >> key >> value)
        coll[key] = value;

    return input;
}

template <typename T, typename V>
std::istream& operator>> (std::istream& input, std::unordered_multimap<T, V>& coll)
{
    T key {};
    V value {};
    while (input >> key >> value)
        coll.insert(std::pair<T, V>(key, value));

    return input;
}
#endif
