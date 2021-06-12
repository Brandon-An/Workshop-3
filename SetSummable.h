#ifndef SETSUMMABLE_H_
#define SETSUMMABLE_H_

#include "Set.h"

namespace sdds
{
    template <unsigned N, class T>
    class SetSummable : public Set<N, T>
    {
        T arr[N];

    public:
        T accumulate(const std::string &filter) const
        { 
            T local(filter);
            elem
        };
    };
}

#endif