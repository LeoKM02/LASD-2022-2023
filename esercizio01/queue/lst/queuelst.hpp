
#ifndef QUEUELST_HPP
#define QUEUELST_HPP

/* ************************************************************************** */

#include "../queue.hpp"
#include "../../list/list.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class QueueLst: virtual public Queue<Data>,
                virtual protected List<Data> {
                  // Must extend Queue<Data>,
                  //             List<Data>
protected:

  using Container::size;
  using List<Data>::head;
  using List<Data>::tail;

public:

  // Default constructor
  QueueLst() = default;

  /* ************************************************************************ */

  // Specific constructor
  QueueLst(const MappableContainer<Data>& con) : List<Data>(con) {} // A queue obtained from a MappableContainer
  QueueLst(MutableMappableContainer<Data>&& con) noexcept : List<Data>(std::move(con)) {} // A queue obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  QueueLst(const QueueLst& con) : List<Data>(con) {}

  // Move constructor
  QueueLst(QueueLst&& con) noexcept : List<Data>(std::move(con)) {}

  /* ************************************************************************ */

  // Destructor
  virtual ~QueueLst() = default;

  /* ************************************************************************ */

  // Copy assignment
  QueueLst& operator=(const QueueLst&);

  // Move assignment
  QueueLst& operator=(QueueLst&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const QueueLst&) const noexcept;
  inline bool operator!=(const QueueLst&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions (inherited from Queue)

  inline virtual const Data& Head() const override; // (non-mutable version; concrete function must throw std::length_error when empty)
  inline virtual Data& Head() override; // (mutable version; concrete function must throw std::length_error when empty)
  inline virtual void Dequeue() override; // (concrete function must throw std::length_error when empty)
  inline virtual Data HeadNDequeue() override; // (concrete function must throw std::length_error when empty)
  inline virtual void Enqueue(const Data&) override; // Copy of the value
  inline virtual void Enqueue(Data&&) noexcept override; // Move of the value

  /* ************************************************************************ */

  inline void View() const override;
  
  // Specific member function (inherited from ClearableContainer)

  using List<Data>::Clear;

};

/* ************************************************************************** */

}

#include "queuelst.cpp"

#endif
