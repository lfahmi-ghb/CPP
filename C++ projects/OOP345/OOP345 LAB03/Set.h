#pragma once
//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <vector>
using namespace std;
namespace sdds{
    template <typename T, std::size_t N>
    class Set {
    private:
        T num[N];
        std::size_t elmSize = 0; 
        std::vector<T> s;
    public:

       std::size_t size() const { 
           return elmSize;
       }
       const T& operator[](size_t const idx) const { 
         return num[idx];
        //   return s.at(idx);
        }

       void operator+=(const T& item);
    };
}


template<typename T, std::size_t N>
inline void sdds::Set<T, N>::operator+=(const T& item)
{
    if (elmSize < N)
      //  s.push_back(item);
        num[elmSize++] = item;
}

#endif
