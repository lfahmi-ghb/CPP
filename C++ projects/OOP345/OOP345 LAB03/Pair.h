#pragma once
//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H

#include <iostream>
using namespace std;
namespace sdds {
    template <typename K, typename V>
    class Pair
    {
    private:
        K k;
        V v;

    protected:
        V& value() { return v; }

    public:
        Pair() : K{}, V{}
        {

        };

        Pair(const K& key, const V& value)
            : k{ key }
            ,v{ value }
        {}


        const K& key() const { return k; }
        const V& value() const { return v; }

        virtual void display(std::ostream& os) const {
            os << k << " : " << v << '\n'; 
        }

        friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair) {
            pair.display(os);
            return os;
        }

    };

}

#endif



