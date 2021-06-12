#ifndef PAIR_H_
#define PAIR_H_

namespace sdds
{
    template <typename V, typename K>
    class Pair
    {
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
            os << keyType << " : " << valType << std::endl;
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