
#ifndef BINARYTREEVEC_HPP
#define BINARYTREEVEC_HPP

/* ************************************************************************** */

#include "../binarytree.hpp"
#include "../../vector/vector.hpp"

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template <typename Data>
class BinaryTreeVec: public virtual MutableBinaryTree<Data> {

protected:

  using Container::size;
  using typename BinaryTree<Data>::Node;
  using typename MutableBinaryTree<Data>::MutableNode;

  struct NodeVec: public virtual MutableNode {
  public:

    unsigned long curr = 0;
    Data elem;
    Vector<NodeVec*> *vecptr = nullptr;

    NodeVec() = default;
    NodeVec(const Data&, unsigned long, Vector<NodeVec*>*);

    virtual ~NodeVec() = default;

    NodeVec& operator=(const NodeVec&);
    NodeVec& operator=(NodeVec&&) noexcept;

    bool operator==(const NodeVec& nod) const noexcept {
      return BinaryTree<Data>::Node::operator==(nod);
    };
    bool operator!=(const NodeVec& nod) const noexcept {
      return BinaryTree<Data>::Node::operator!=(nod);
    };

    const Data& Element() const noexcept override;
    Data& Element() noexcept override;
    bool IsLeaf() const noexcept override;
    bool HasRightChild() const noexcept override;
    bool HasLeftChild() const noexcept override;
    virtual const Node& RightChild() const override;
    virtual const Node& LeftChild() const override;
    virtual MutableNode& RightChild() override;
    virtual MutableNode& LeftChild() override;

  };

  Vector<NodeVec*> *vec = nullptr;

public:

  // Default constructor
  BinaryTreeVec() = default;

  /* ************************************************************************ */

  // Specific constructors
  BinaryTreeVec(const MappableContainer<Data>&); // A binary vecptr obtained from a MappableContainer
  BinaryTreeVec(MutableMappableContainer<Data>&&) noexcept; // A binary vecptr obtained from a MutableMappableContainer

  /* ************************************************************************ */

  // Copy constructor
  BinaryTreeVec(const BinaryTreeVec&);

  // Move constructor
  BinaryTreeVec(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Destructor
  virtual ~BinaryTreeVec();

  /* ************************************************************************ */

  // Copy assignment
  BinaryTreeVec& operator=(const BinaryTreeVec&);

  // Move assignment
  BinaryTreeVec& operator=(BinaryTreeVec&&) noexcept;

  /* ************************************************************************ */

  // Comparison operators
  bool operator==(const BinaryTreeVec<Data>& btv) const noexcept {
    return MutableBinaryTree<Data>::operator==(btv);
  };
  bool operator!=(const BinaryTreeVec<Data>& btv) const noexcept {
    return !(*this == btv);
  };

  /* ************************************************************************ */

  // Specific member functions (inherited from BinaryTree)

  const Node& Root() const override; // Override BinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from MutableBinaryTree)

  MutableNode& Root() override; // Override MutableBinaryTree member (throw std::length_error when empty)

  /* ************************************************************************ */

  // Specific member function (inherited from ClearableContainer)

  void Clear() override; // Override ClearableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthFoldableContainer)

  using typename BreadthFoldableContainer<Data>::FoldFunctor;

  void BreadthFold(FoldFunctor, void*) const override; // Override BreadthFoldableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from BreadthMappableContainer)

  using typename BreadthMappableContainer<Data>::MapFunctor;

  void BreadthMap(MapFunctor) const override; // Override BreadthMappableContainer member

  /* ************************************************************************ */

  // Specific member functions (inherited from MutableBreadthMappableContainer)

  using typename MutableBreadthMappableContainer<Data>::MutableMapFunctor;

  void BreadthMap(MutableMapFunctor) override; // Override MutableBreadthMappableContainer member

};

/* ************************************************************************** */

}

#include "binarytreevec.cpp"

#endif
