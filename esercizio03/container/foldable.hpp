
#ifndef FOLDABLE_HPP
#define FOLDABLE_HPP

/* ************************************************************************** */

#include <functional>

/* ************************************************************************** */

#include "testable.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class FoldableContainer: virtual public TestableContainer<Data> {
                          // Must extend TestableContainer<Data>
protected:

  using Container::size;

public:

  // Destructor
  virtual ~FoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  FoldableContainer& operator=(const FoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  // Move assignment
  FoldableContainer& operator=(FoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const FoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using FoldFunctor = std::function<void(const Data&, void *)>;

  virtual void Fold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  inline virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PreOrderFoldableContainer: virtual public FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>
protected:

  using Container::size;

public:

  // Destructor
  virtual ~PreOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PreOrderFoldableContainer& operator=(const PreOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  // Move assignment
  PreOrderFoldableContainer& operator=(PreOrderFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PreOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PreOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PreOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  inline virtual void Fold(FoldFunctor, void *) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class PostOrderFoldableContainer: virtual public FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>
protected:

  using Container::size;

public:

  // Destructor
  virtual ~PostOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  PostOrderFoldableContainer& operator=(const PostOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  // Move assignment
  PostOrderFoldableContainer& operator=(PostOrderFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const PostOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const PostOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void PostOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  inline virtual void Fold(FoldFunctor, void *) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class InOrderFoldableContainer: virtual public FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>
protected:

  using Container::size;

public:

  // Destructor
  virtual ~InOrderFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  InOrderFoldableContainer& operator=(const InOrderFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  // Move assignment
  InOrderFoldableContainer& operator=(InOrderFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const InOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const InOrderFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void InOrderFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  inline virtual void Fold(FoldFunctor, void *) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

template <typename Data>
class BreadthFoldableContainer: virtual public FoldableContainer<Data> {
                                  // Must extend FoldableContainer<Data>
protected:

  using Container::size;

public:

  // Destructor
  virtual ~BreadthFoldableContainer() = default;

  /* ************************************************************************ */

  // Copy assignment
  BreadthFoldableContainer& operator=(const BreadthFoldableContainer&) = delete; // Copy assignment of abstract types should not be possible.
  // Move assignment
  BreadthFoldableContainer& operator=(BreadthFoldableContainer&&) noexcept = delete; // Move assignment of abstract types should not be possible.

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BreadthFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.
  bool operator!=(const BreadthFoldableContainer&) const noexcept = delete; // Comparison of abstract types might not be possible.

  /* ************************************************************************ */

  // Specific member function

  using typename FoldableContainer<Data>::FoldFunctor;

  virtual void BreadthFold(FoldFunctor, void *) const = 0;

  /* ************************************************************************ */

  // Specific member function (inherited from FoldableContainer)

  inline virtual void Fold(FoldFunctor, void *) const override; // Override FoldableContainer member

};

/* ************************************************************************** */

}

#include "foldable.cpp"

#endif
