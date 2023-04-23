
#ifndef VECTOR_HPP
#define VECTOR_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class Vector: virtual public ResizableContainer, virtual public SortableLinearContainer<Data> {
                // Must extend ResizableContainer,
                //             SortableLinearContainer<Data>
protected:

  using Container::size;

  Data* elements = nullptr;

public:

  // Default constructor
  Vector() = default;

  /* ************************************************************************ */

  // Specific constructors
  Vector(const ulong); // A vector with a given initial dimension
  Vector(const MappableContainer<Data>&); // A vector obtained from a MappableContainer
  Vector(MutableMappableContainer<Data>&&); // A vector obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  Vector(const Vector&);

  // Move constructor
  Vector(Vector&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~Vector();

  /* ************************************************************************ */

  // Copy assignment
  virtual Vector& operator=(const Vector&);

  // Move assignment
  virtual Vector& operator=(Vector&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const Vector&) const noexcept;
  inline bool operator!=(const Vector&) const noexcept;

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline virtual void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from ResizableContainer)

  inline virtual void Resize(const ulong) override; // Override ResizableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  inline virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  inline virtual const Data& operator[](const ulong) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  inline virtual Data& operator[](const ulong) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  inline virtual const Data& Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline virtual Data& Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  inline virtual const Data& Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline virtual Data& Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from SortableLinearContainer)

  inline virtual void Sort() noexcept override; // Override SortableLinearContainer member

protected:

  virtual void QuickSort(const ulong, const ulong) noexcept;
  virtual ulong Partiziona(const ulong, const ulong) noexcept;

};

/* ************************************************************************** */

}

#include "vector.cpp"

#endif
