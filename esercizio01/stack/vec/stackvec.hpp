
#ifndef STACKVEC_HPP
#define STACKVEC_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackVec: virtual public Stack<Data>, virtual public Vector<Data> {
                  // Must extend Stack<Data>,
                  //             Vector<Data>
protected:

  using Container::size;
  using Vector<Data>::elements;

public:

  // Default constructor
  StackVec() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackVec(const MappableContainer&); // A stack obtained from a MappableContainer
  StackVec(MutableMappableContainer&&) noexcept; // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackVec(const StackVec&);

  // Move constructor
  StackVec(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~StackVec() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackVec& operator=(const StackVec&);

  // Move assignment
  StackVec& operator=(StackVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const StackVec&) const noexcept;
  inline bool operator!=(const StackVec&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  inline virtual const Data& Top() const override; // (non-mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data& Top() override; // (mutable version; concrete function must throw std::length_error when empty)
  inline virtual void Pop() override; // (concrete function must throw std::length_error when empty)
  inline virtual Data TopNPop() override; // (concrete function must throw std::length_error when empty)
  inline virtual void Push(const Data&) override; // Copy of the value
  inline virtual void Push(Data&&) noexcept override; // Move of the value

  /* ************************************************************************ */

  // Specific member functions (inherited from Container)

  inline virtual bool Empty() const noexcept override; // Override Container member

  inline virtual ulong Size() const noexcept override; // Override Container member

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline virtual void Clear() override; // Override ClearableContainer member

protected:

  // Auxiliary member functions

  type Expand();
  type Reduce();

};

/* ************************************************************************** */

}

#include "stackvec.cpp"

#endif
