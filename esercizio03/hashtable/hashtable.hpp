
#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <random>
#include <string>

#include "../container/dictionary.hpp"

/* ************************************************************************** */

namespace lasd
{

  template <typename Data>
  class Hashable
  {
  public:
    virtual unsigned long operator()(const Data&) const noexcept = 0; // (concrete function should not throw exceptions)
  };


  /* ************************************************************************** */

  template <typename Data>
  class HashTable : public virtual ResizableContainer,
                    public virtual DictionaryContainer<Data>
  {

  protected:
    static const unsigned long PRIME_NUM = 12582917;
    static const unsigned long DEFAULT_TABLESIZE = 97;

    static const Hashable<Data> hash;
    std::default_random_engine gen = std::default_random_engine(std::random_device{}());
    std::uniform_int_distribution<unsigned long> dista = std::uniform_int_distribution<unsigned long>(1, PRIME_NUM - 1);
    std::uniform_int_distribution<unsigned long> distb = std::uniform_int_distribution<unsigned long>(0, PRIME_NUM - 1);

    using DictionaryContainer<Data>::size;
    unsigned long tablesize = DEFAULT_TABLESIZE;
    unsigned long a;
    unsigned long b;

  public:
    // Constructor
    HashTable();

    // Copy constructor
    HashTable(const HashTable &);

    // Move constructor
    HashTable(HashTable &&) noexcept;

    // Destructor
    virtual ~HashTable() = default;

    /* ************************************************************************ */

    // Copy assignment
    HashTable &operator=(const HashTable &) = delete; // Copy assignment of abstract types should not be possible.

    // Move assignment
    HashTable &operator=(HashTable &&) noexcept = delete; // Move assignment of abstract types should not be possible.

    /* ************************************************************************ */

    // Comparison operators
    bool operator==(const HashTable &) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.
    bool operator!=(const HashTable &) const noexcept = delete; // Comparison of abstract hashtable is possible but not required.

  protected:
    // Auxiliary member functions

    virtual unsigned long HashKey(unsigned long) const noexcept;
  };

  /* ************************************************************************** */

}

#include "hashtable.cpp"

#endif
