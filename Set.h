#ifndef SET_H_
#define SET_H_

namespace sdds
{
    template <unsigned N, typename T>
    class Set
    {
        T arr[N];

        size_t unfilled = 0;
        
    public:

        size_t size() const{return N;};

        const T &get(size_t idx) const{return arr[idx];};

        void operator+=(const T &item)
        {
            if (unfilled < this->size())
            {
                arr[unfilled] = item;
                unfilled++;
            }

        };


    };

}

#endif