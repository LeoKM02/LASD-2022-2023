#include <string>

namespace lasd
{

    /* ************************************************************************** */

    template <>
    class Hashable<int>
    {
    public:
        unsigned long operator()(const int &dat) const noexcept
        {
            return (dat * dat);
        }
    };

    template <>
    class Hashable<double>
    {
    public:
        unsigned long operator()(const float &dat) const noexcept
        {
            long integer = floor(dat);
            long decimal = (dat - integer) * pow(2, 24);

            return (integer * decimal);
        }
    };

    template <>
    class Hashable<std::string>
    {
    public:
        unsigned long operator()(const std::string &dat) const noexcept
        {
            unsigned long hsh = 5381;

            for (char ch : dat)
                hsh = (hsh << 5) + hsh + ch;

            return hsh;
        }
    };

    template <typename Data>
    HashTable<Data>::HashTable()
    {
        a = dista(gen);
        b = distb(gen);
    }

    template <typename Data>
    HashTable<Data>::HashTable(const HashTable &ht)
    {
        size = ht.size;
        tablesize = ht.tablesize;
        a = ht.a;
        b = ht.b;
    }

    template <typename Data>
    HashTable<Data>::HashTable(HashTable &&ht) noexcept
    {
        std::swap(size, ht.size);
        std::swap(tablesize, ht.tablesize);
        std::swap(a, ht.a);
        std::swap(b, ht.b);
    }

    template <typename Data>
    unsigned long HashTable<Data>::HashKey(unsigned long k) const noexcept
    {
        return (((a * k + b) % PRIME_NUM) % tablesize);
    }

    /* ************************************************************************** */

}
