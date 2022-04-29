

###### Copyright &#169; 2022 Fellow-fiend

---

## Description
Library for simplefy input & output STL containers.
Support all one-dimensional containers:
- std::vector
- std::deque
- std::list
- std::forward_list
- std::array
- std::map
- std::unordered_map
- std::multimap
- std::unordered_multimap
 - std::set
 - std::unordered_set
 - std::multiset
 - std::unordered_multiset


You can switch off input/output for all kinds of std::map by simply adding a line `#define WITHOUT_MAP` at the beginning of your program.

**Input doesn't resize containters! So empty containers won't fill by std::cin**

## Examples
#### Simple input & output for list

    #include <advanced_iostream>
    #include <list>
    
    int main(int argc, char** argv)
    {
        std::list<int> coll1 {1, -2, 3, -4, 5};
        std::list<double> coll2(5);
        
        std::cin >> coll2;
        coll1.sort(), coll2.sort();
        
        std::cout << coll1 << coll2;
        
        return 0;
    }

Input:
    
    -3.1
    -6.8
    0.3
    4.2
    9.9
    
Output:
    
    -4 -2 1 3 5
    -6.8 -3.1 0.3 4.2 9.9
    
#### Simple input & output for map

    #include <advanced_iostream>
    #include <unordered_map>
    
    int main(int argc, char** argv)
    {
        std::unordered_map<std::string, int> coll {
                {"a", 2},
                {"b", 3},
                {"ab", 6},
                {"ba", 6}
            };
    
        std::cout << coll << "\n";
        std::cin >> coll;
        std::cout << coll;
        
        return 0;
    }
    
Input:
    
    Hello 0
    My 100
    Map 200
    
Output:
    
    ab: 6
    b: 3
    ba: 6
    a: 2
    
    My: 100
    Hello: 0
    ab: 6
    Map: 200
    b: 3
    ba: 6
    a: 2

#### Disable extra code for all kinds of std::map
    
    #define WITHOUT_MAP 
    #include <advanced_iostream>
    #include <vector>
    
    int main()
    {
        std::vector<char> coll(10);
        
        std::cin >> coll;
        
        for (auto& i : coll)
            i -= 1;
        
        std::cout << "\n" << coll;
    
        return 0;
    }

Input:

    b c d e f g h z x y
    
Output:
    
    a b c d e f g y w x 

    
    
## Requirements
Compiler with support C++17 and above.

## Installation
    
    git clone 
    
For include to your app:
    
    #include "{path}/advanced_iostream/advanced_iostream.hpp"

or add the compiler option `g++ your_app.cpp -I{path}/advanced_iostream/` and then:
    
    #include <advanced_iostream.hpp>




