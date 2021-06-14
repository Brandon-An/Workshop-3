//Name: Brandon An Email: ban4@myseneca.ca Student Number: 152900197 Date: June 13, 2021
#ifndef PAIRSUMMABLE_H_
#define PAIRSUMMABLE_H_
#include <iomanip>
#include <string>
#include "Pair.h"

namespace sdds
{
    template <typename V, typename K>
    class PairSummable : public Pair<V, K>
    {
        static V initial;
        static size_t m_width;
        static V separate;
        bool blankKey = false;

    public:
        PairSummable(){};
        PairSummable(const K &key, const V &value = initial) : Pair<V, K>(key, value)
        {
            PairSummable<V, K>::m_width = key.size();
        };

        bool isCompatibleWith(const PairSummable<V, K> &b) const
        {
            if (b.key() == this->key())
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
            V temp = item.value();
            Pair<V, K>::valType += item.value();
          
            return *this;
        }

        void display(std::ostream &os) const
        {
            os << std::left << std::setw(PairSummable<V, K>::m_width);
            Pair<V, K>::display(os);
            os << std::right;
        };
    };

    template <>
    class PairSummable<std::string, std::string> : public Pair<std::string, std::string>
    {
        static std::string initial;
        static size_t m_width;
        static std::string separate;
        bool blankKey = false;

    public:
        PairSummable(){};

        PairSummable(const std::string &key, const std::string &value = " ") : Pair<std::string, std::string>(key, value)
        {
            if (value == " ")
            {
                blankKey = true;
            }

            // b vPairSummable<std::string, std::string>::m_width = key.size();
        };

        bool isCompatibleWith(const PairSummable<std::string, std::string> &b) const
        {
            if (b.key() == this->key())
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
            if (blankKey == true)
            {
                std::string temp = item.value();
                Pair<std::string, std::string>::valType += item.value();
                blankKey = false;
            }
            else
            {
                std::string temp = item.value();
                Pair<std::string, std::string>::valType += ", " + item.value();
            }
            return *this;
        }

        void display(std::ostream &os) const
        {
            os << std::left << std::setw(PairSummable<std::string, std::string>::m_width);
            Pair<std::string, std::string>::display(os);
            os << std::right;
        };
    };

    template <typename V, typename K>
    size_t PairSummable<V, K>::m_width = 0;

    size_t PairSummable<std::string, std::string>::m_width = 0;

    template <typename V, typename K>
    V PairSummable<V, K>::initial = 0;

    template <typename V, typename K>
    V PairSummable<V, K>::separate = ", ";

}

#endif