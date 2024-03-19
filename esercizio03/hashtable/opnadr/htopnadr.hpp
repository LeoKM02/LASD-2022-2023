
#ifndef HTOPNADR_HPP
#define HTOPNADR_HPP

#define EMPTY 0
#define FULL 1
#define REMOVED 2

#include "../hashtable.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {


template <typename Data>
class HashTableOpnAdr: public virtual HashTable<Data>{

protected:

  static const unsigned long MIN_TABLESIZE = 64;
  static const unsigned long MAX_TABLESIZE = 65536;

  using HashTable<Data>::size;
  using HashTable<Data>::hash;
  using HashTable<Data>::a;
  using HashTable<Data>::b;
  using HashTable<Data>::dista;
  using HashTable<Data>::distb;
  using HashTable<Data>::gen;
  using HashTable<Data>::tablesize;
  using HashTable<Data>::Insert;
  using HashTable<Data>::InsertAll;

  double capacity = 0.0;
  Vector<Data> table;
  Vector<int> statvec;

public:

  // Default constructor
  HashTableOpnAdr();

  /* ************************************************************************ */

  // Specific constructors
  HashTableOpnAdr(unsigned long); // A hash table of a given size
  HashTableOpnAdr(const MappableContainer<Data>&); // A hash table obtained from a MappableContainer
  HashTableOpnAdr(unsigned long, const MappableContainer<Data>&); // A hash table of a given size obtained from a MappableContainer
  HashTableOpnAdr(MutableMappableContainer<Data>&&); // A hash table obtained from a MutableMappableContainer
  HashTableOpnAdr(unsigned long, MutableMappableContainer<Data>&&); // A hash table of a given size obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  HashTableOpnAdr(const HashTableOpnAdr<Data>&);

  // Move constructor
  HashTableOpnAdr(HashTableOpnAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~HashTableOpnAdr() = default;

  /* ************************************************************************ */

  // Copy assignment
  HashTableOpnAdr& operator=(const HashTableOpnAdr<Data>&);

  // Move assignment
  HashTableOpnAdr& operator=(HashTableOpnAdr<Data>&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const HashTableOpnAdr<Data>&) const noexcept;
  bool operator!=(const HashTableOpnAdr<Data>&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  bool Insert(const Data&) override; // Override DictionaryContainer member (Copy of the value)
  bool Insert(Data&&) noexcept override; // Override DictionaryContainer member (Move of the value)
  bool Remove(const Data&) override; // Override DictionaryContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from TestableContainer)

  bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from ResizableContainer)

  void Resize(unsigned long) override; // Resize the hashtable to a given size

  /* ************************************************************************ */

  // Specific member functions (inherited from ClearableContainer)

  void Clear() override; // Override Container member

protected:

  // Auxiliary member functions

  virtual unsigned long HashKey(const Data&, unsigned long) const noexcept;
  virtual unsigned long Find(const Data&, unsigned long) const noexcept;
  virtual unsigned long FindEmpty(const Data&, unsigned long) const noexcept;
  virtual bool Remove(const Data&, unsigned long);

  unsigned long NextPowerOf2To(unsigned long) const noexcept;
  bool IsResizable(unsigned long) const noexcept;

};

/* ************************************************************************** */

}

#include "htopnadr.cpp"

#endif
