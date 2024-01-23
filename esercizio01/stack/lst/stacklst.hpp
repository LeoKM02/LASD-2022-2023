
#ifndef STACKLST_HPP
#define STACKLST_HPP

/* ************************************************************************** */

#include "../stack.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class StackLst: virtual public Stack<Data>,
                virtual protected List<Data>{
                  // Must extend Stack<Data>,
                  //             List<Data>
protected:

  using Container::size;
  using List<Data>::head;
  using List<Data>::tail;

public:

  // Default constructor
  StackLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  StackLst(const MappableContainer<Data>& con) : List<Data>::List(con) {} // A stack obtained from a MappableContainer
  StackLst(MutableMappableContainer<Data>&& con) noexcept : List<Data>::List(std::move(con)) {} // A stack obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  StackLst(const StackLst& con) : List<Data>::List(con) {}

  // Move constructor
  StackLst(StackLst&& con) noexcept : List<Data>::List(std::move(con)) {}

  /* ************************************************************************ */

  // Destructor
  virtual ~StackLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  StackLst& operator=(const StackLst&);

  // Move assignment
  StackLst& operator=(StackLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const StackLst&) const noexcept;
  inline bool operator!=(const StackLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Stack)

  inline const Data& Top() const override; // (non-mutable version; concrete function must throw std::length_error when empty)
  inline Data& Top() override; // (mutable version; concrete function must throw std::length_error when empty)
  inline void Pop() override; // (concrete function must throw std::length_error when empty)
  inline Data TopNPop() override; // (concrete function must throw std::length_error when empty)
  inline void Push(const Data&) override; // Copy of the value
  inline void Push(Data&&) noexcept override; // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "stacklst.cpp"

#endif
