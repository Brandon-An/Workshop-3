#ifndef PAIRSUMMABLE_H_
#define PAIRSUMMABLE_H_
#include <iomanip>
#include "Pair.h"

namespace sdds
{
    template <typename V, typename K>
    class PairSummable : public Pair<V, K>
    {
        static V initial;
        static size_t width;

    public:
        PairSummable(){};
        PairSummable(const K &key, const V &value = initial) : Pair<V, K>(key, value)
        {
            // PairSummable<V, K>width = key.size();
        };
        
        bool isCompatibleWith(const PairSummable<V, K> &b) const
        {
            if (b.key() == this.key())
            {
                return true;
            }
            else
            {
                return false;
            }
        };

        PairSummable &operator+=(const PairSummable &item)
        {

        };
        
        void display(std::ostream &os) const
        {
            os << std::left << std::setw(PairSummable<V, K>::width);
            Pair<V, K>::display(os);
            os << std::right;
        };

    };

    template <typename V, typename K>
    size_t PairSummable<V, K>::width = 0;

}

#endif