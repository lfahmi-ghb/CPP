#pragma once
//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_SET_SUMMABLE_H
#define SDDS_SET_SUMMABLE_H

#include "Set.h"
#include <string>
using namespace std;
namespace sdds{
    template <typename T, std::size_t N>
    class SetSummable : public Set<T, N> {
    private:
     //   constructor that accepts the address of an unmodifiable C - style string, which specifies the filter.
        using SetClass = Set<T, N>;

    public:

        //aknowledge these elements
        using SetClass::size;
        using SetClass::operator[];
        using SetClass::operator+=;

        T accumulate(const string& filter) const {

           // initialize the accumulator by calling the one - argument constructor
            T temp( filter);

            //iterate over the collection
            for (std::size_t i = 0; i < size(); ++i){

            //add each item's contribution to the accumulator.
                temp += (*this)[i];
            }

            //return the accumulator to the client.
            return temp;
        }
    };
}

#endif