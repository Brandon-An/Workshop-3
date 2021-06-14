//Name: Brandon An Email: ban4@myseneca.ca Student Number: 152900197 Date: June 13, 2021
#ifndef PAIR_H_
#define PAIR_H_
#include <iomanip>

namespace sdds
{
    
    template <typename V, typename K>
    class Pair
    {
    protected:
        V valType;
        K keyType;

    public:
        Pair(){};
        Pair(const K &key, const V &value)
        {
            valType = value;
            keyType = key;
        };
        const V &value() const {return valType;};
        const K &key() const {return keyType;};
        virtual void display(std::ostream &os) const 
        {
            os << std::setw(mw) << keyType << " : " << valType << std::endl;
        };
    };

    template <typename V, typename K>
    std::ostream &operator<<(std::ostream &os, const Pair<V, K> &pair)
    {
        pair.display(os);
        return os;
    };

}

#endif