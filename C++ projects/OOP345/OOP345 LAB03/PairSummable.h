#pragma once
//Name: Lara Fahmi
//Student Number: 109742197
#ifndef SDDS_PAIR_SUMMABLE_H
#define SDDS_PAIR_SUMMABLE_H

#include "Pair.h"
#include <string>
#include <iomanip>

using namespace std;
namespace sdds{
    template <typename K, typename V>
    class PairSummable : public Pair<K, V>
    {
    private:
    
        static V initial;
        static std::size_t width;

        using Base = Pair<K, V>;

    public:
        using Base::display;
        using Base::key;
        using Base::value;

        PairSummable()
            : PairSummable{ K{}, V{} }
        {}

        PairSummable(const K& key, const V& value = initial) : Pair<K, V>(key, value) {
            if (width < key.size()) {
                width = key.size();
            }
        }

        PairSummable& operator+=(PairSummable const& p) {
            if (this != &p) {
                if (key() ==p.key()) {
                    Pair<K, V>::value() += p.Pair<K, V>::value();
                }
            }
            return *this;
        }


        void display(std::ostream& os) const {

            os.setf(std::ios::left);
            os.width(width);
            Base::display(os);
            os.unsetf(std::ios::left);

        }



    };



    ///**********SPECIALIZATION***********///

    template <typename K, typename V>
    size_t PairSummable<K, V>::width = 0;

    template<>
    std::string PairSummable<std::string, std::string>::initial = std::string("");

    template<>
    int PairSummable<std::string, int>::initial = 0;


    template <>
   auto PairSummable<std::string, std::string>::operator+=(PairSummable<std::string, std::string> const& other) -> PairSummable& {
       if (this != &other )
           if (Pair<std::string, std::string>::key() == other.Pair<std::string, std::string>::key()) {
               {
                   *this = PairSummable(Pair<std::string, std::string>::key(), Pair<std::string, std::string>::value() == "" ? other.value() : Pair<std::string, std::string>::value() + ", " + other.value());

               }
           }
        return *this;       

    }

  

}



#endif 

