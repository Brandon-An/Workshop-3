//Name: Brandon An Email: ban4@myseneca.ca Student Number: 152900197 Date: June 13, 2021
#ifndef SET_H_
#define SET_H_
#include <cstring>
namespace sdds
{
    unsigned mw = 11;
    template <unsigned N, typename T>
    class Set
    {
    protected:
        T arr[N];

        size_t unfilled = 0;
        
    public:

        size_t size() const{return unfilled;};

        const T &get(size_t idx) const{return arr[idx];};

        void operator+=(const T &item)
        {
            if (unfilled < N)
            {
                mw = mw > item.key().length()? mw : item.key().length();
                arr[unfilled] = item;
                unfilled++;
            }

        };

        void print()
        {
            for (size_t i = 0; i < N; ++i)
			arr[i].print();
        };

    };

}

#endif