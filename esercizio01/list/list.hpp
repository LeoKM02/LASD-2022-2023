
#ifndef LIST_HPP
#define LIST_HPP

/* ************************************************************************** */

#include "../container/container.hpp"
#include "../container/dictionary.hpp"
#include "../container/linear.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class List: virtual public ClearableContainer, virtual public DictionaryContainer<Data>, virtual public LinearContainer<Data> {
              // Must extend ClearableContainer,
              //             DictionaryContainer<Data>,
              //             LinearContainer<Data>
protected:

  using Container::size;

  struct Node {

    // Data
    // ...
    Data elem;
    Node * next = nullptr;

    /* ********************************************************************** */

    // Specific constructors
    // ...
    inline Node(const Data& dat);
    inline Node(Data&&) noexcept;

    /* ********************************************************************** */

    // Copy constructor
    // ...
    inline Node(const Node& node);

    // Move constructor
    // ...
    inline Node(Node&&) noexcept;

    /* ********************************************************************** */

    // Destructor
    // ...
    virtual ~Node() = default;

    /* ********************************************************************** */

    // Comparison operators
    // ...
    inline bool operator==(const Node&) const noexcept;
    inline bool operator!=(const Node&) const noexcept;

    /* ********************************************************************** */

    // Specific member functions

    // ...

  };

  // ...
  Node * head = nullptr;
  Node * tail = nullptr;

public:

  // Default constructor
  List() = default;

  /* ************************************************************************ */

  // Specific constructor
  List(const MappableContainer<Data>&); // A list obtained from a MappableContainer
  List(MutableMappableContainer<Data>&&) noexcept; // A list obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  List(const List&);

  // Move constructor
  List(List&&);

  /* ************************************************************************ */

  // Destructor
  virtual ~List();

  /* ************************************************************************ */

  // Copy assignment
  inline List& operator=(const List&);

  // Move assignment
  inline List& operator=(List&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  inline bool operator==(const List&) const noexcept;
  inline bool operator!=(const List&) const noexcept;

  /* ************************************************************************ */

  // Specific member functions

  inline virtual void InsertAtFront(const Data&); // Copy of the value
  inline virtual void InsertAtFront(Data&&) noexcept; // Move of the value

  inline virtual void RemoveFromFront(); // (must throw std::length_error when empty)

  inline virtual Data FrontNRemove(); // (must throw std::length_error when empty)

  inline virtual void InsertAtBack(const Data&); // Copy of the value
  inline virtual void InsertAtBack(Data&&) noexcept; // Move of the value

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  inline virtual void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from TestableContainer)

  inline virtual bool Exists(const Data&) const noexcept override; // Override TestableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from DictionaryContainer)

  inline virtual bool Insert(const Data&) override; // Copy of the value
  inline virtual bool Insert(Data&&) override; // Move of the value
  inline virtual bool Remove(const Data&) override;

  /* ************************************************************************ */

  // Specific member functions (inherited from LinearContainer)

  inline virtual const Data& operator[](const ulong) const override; // Override (NonMutable) LinearContainer member (must throw std::out_of_range when out of range)
  inline virtual Data& operator[](const ulong) override; // Override (Mutable) LinearContainer member (must throw std::out_of_range when out of range)

  inline virtual const Data& Front() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline virtual Data& Front() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  inline virtual const Data& Back() const override; // Override (NonMutable) LinearContainer member (must throw std::length_error when empty)
  inline virtual Data& Back() override; // Override (Mutable) LinearContainer member (must throw std::length_error when empty)

  /* ************************************************************************ */

  using typename FoldableContainer<Data>::FoldFunctor;

  // Specific member function (inherited from PreOrderFoldableContainer)

  inline virtual void PreOrderFold(FoldFunctor, void *) const override; // Override PreOrderFoldableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderFoldableContainer)

  inline virtual void PostOrderFold(FoldFunctor, void *) const override; // Override PostOrderFoldableContainer member

  /* ************************************************************************ */

  using typename MappableContainer<Data>::MapFunctor;

  /* ************************************************************************ */

  // Specific member function (inherited from PreOrderMappableContainer)

  inline virtual void PreOrderMap(MapFunctor) const override; // Override PreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from PostOrderMappableContainer)

  inline virtual void PostOrderMap(MapFunctor) const override; // Override PostOrderMappableContainer member

  /* ************************************************************************ */

  using typename MutableMappableContainer<Data>::MutableMapFunctor;

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePreOrderMappableContainer)

  inline virtual void PreOrderMap(MutableMapFunctor) override; // Override MutablePreOrderMappableContainer member

  /* ************************************************************************ */

  // Specific member function (inherited from MutablePostOrderMappableContainer)

  inline virtual void PostOrderMap(MutableMapFunctor) override; // Override MutablePostOrderMappableContainer member

protected:

  // Auxiliary member functions (for PreOrderFoldableContainer & PostOrderFoldableContainer)

  inline virtual void PostOrderFold(FoldFunctor, void *, Node*) const; // Accessory function executing from one point of the list onwards

  /* ************************************************************************ */

  // Auxiliary member functions (for PreOrderMappableContainer & PostOrderMappableContainer)

  inline virtual void PostOrderMap(MapFunctor, Node*) const; // Accessory function executing from one point of the list onward

  /* ************************************************************************ */

  // Auxiliary member functions (for MutablePreOrderMappableContainer & MutablePostOrderMappableContainer)

  inline virtual void PostOrderMap(MutableMapFunctor, Node*); // Accessory function executing from one point of the list onward

  /* ************************************************************************ */

};

/* ************************************************************************** */

}

#include "list.cpp"

#endif
