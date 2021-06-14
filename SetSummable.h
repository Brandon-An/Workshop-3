//Name: Brandon An Email: ban4@myseneca.ca Student Number: 152900197 Date: June 13, 2021
#ifndef SETSUMMABLE_H_
#define SETSUMMABLE_H_

#include "Set.h"

namespace sdds
{
    template <unsigned N, class T>
    class SetSummable : public Set<N, T>
    {
    public:
        SetSummable()
        {
            mw = 0;
        }
        T accumulate(const std::string &filter) const
        { 
            T localPairSum(filter);
            for (unsigned i = 0; i < N; i++)
            {
                if (this->get(i).isCompatibleWith(localPairSum))
                {
                    localPairSum += Set<N, T>::arr[i];
                }
            }
            return localPairSum;
        };
    };
}

#endif