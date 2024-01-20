
#ifndef QUEUEVEC_HPP
#define QUEUEVEC_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueVec: virtual public Queue<Data>,
                virtual protected Vector<Data>{
                  // Must extend Queue<Data>,
                  //             Vector<Data>
protected:

  const ulong DEFAULT_CAPACITY = 10;

  using Container::size;
  using Vector<Data>::elements;
  ulong head = 0;
  ulong tail = 0;
  ulong sentinel = 0;

public:

  // Default constructor
  QueueVec();

  /* ************************************************************************ */

  // Specific constructor
  QueueVec(const MappableContainer<Data>&); // A queue obtained from a MappableContainer
  QueueVec(MutableMappableContainer<Data>&&) noexcept; // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueVec(const QueueVec&);

  // Move constructor
  QueueVec(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueVec& operator=(const QueueVec&);

  // Move assignment
  QueueVec& operator=(QueueVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const QueueVec&) const noexcept;
  inline bool operator!=(const QueueVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  inline const Data& Head() const override; // Override Queue member (non-mutable version; must throw std::length_error when empty)
  inline Data& Head() override; // Override Queue member (mutable version; must throw std::length_error when empty)
  inline void Dequeue() override; // Override Queue member (must throw std::length_error when empty)
  inline Data HeadNDequeue() override; // Override Queue member (must throw std::length_error when empty)
  inline void Enqueue(const Data&) override; // Override Queue member (copy of the value)
  inline void Enqueue(Data&&) noexcept override; // Override Queue member (move of the value)

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline bool Empty() const noexcept override; // Override Container member

  inline ulong Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  inline void Expand();
  inline void Reduce();
  // inline void SwapVectors(arguments);

};

/* ************************************************************************** */

}

#include "queuevec.cpp"

#endif
