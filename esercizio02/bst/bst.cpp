#include <iostream>

namespace lasd {

/* ************************************************************************** */

template <typename Data>
BST<Data>::BST(const MappableContainer<Data>& con){
    con.Map([this](const Data& dat) {
        Insert(dat);
    });
}

template <typename Data>
BST<Data>::BST(MutableMappableContainer<Data>&& con) noexcept{
    con.Map([this](Data& dat) {
        Insert(std::move(dat));
    });
}

template<typename Data>
BST<Data>& BST<Data>::operator=(const BST& bst){
    BinaryTreeLnk<Data>::operator=(bst);
    return *this;
}

template<typename Data>
BST<Data>& BST<Data>::operator=(BST&& bst) noexcept{
    BinaryTreeLnk<Data>::operator=(std::move(bst));
    return *this;
}

template <typename Data>
bool BST<Data>::operator==(const BST<Data>& bst) const noexcept{
    if(size == bst.Size()){
        BTInOrderIterator<Data> iter1(*this);
        BTInOrderIterator<Data> iter2(bst);

        while(!iter1.Terminated() && !iter2.Terminated()) {
            if(*iter1 != *iter2) {
                return false;
            }

            ++iter1;
            ++iter2;
        }

        if(iter1.Terminated() && iter2.Terminated()) {
            return true;
        }
    }

    return false;
}

template <typename Data>
bool BST<Data>::operator!=(const BST<Data>& bst) const noexcept {
    return !(*this == bst);
}

template <typename Data>
const Data& BST<Data>::Min() const{
    if(this->Empty())
        throw std::length_error("Tree is empty!");
    
    return FindPointerToMin(root)->elem;
}

template <typename Data>
Data BST<Data>::MinNRemove(){
    if(this->Empty())
        throw std::length_error("Tree is empty!");
    
    return DataNDelete(DetachMin(root));
}

template <typename Data>
void BST<Data>::RemoveMin(){
    if(this->Empty())
        throw std::length_error("Tree is empty!");
    
    delete DetachMin(root);
}

template <typename Data>
const Data& BST<Data>::Max() const{
    if(this->Empty())
        throw std::length_error("Tree is empty!");
    
    return FindPointerToMax(root)->elem;
}

template <typename Data>
Data BST<Data>::MaxNRemove(){
    if(this->Empty())
        throw std::length_error("Tree is empty!");
    
    return DataNDelete(DetachMax(root));
}

template <typename Data>
void BST<Data>::RemoveMax(){
    if(this->Empty())
        throw std::length_error("Tree is empty!");
    
    delete DetachMax(root);
}

template <typename Data>
const Data& BST<Data>::Predecessor(const Data& dat) const{
    NodeLnk* const* temp = FindPointerToPredecessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Predecessor not found!");
    
    return (*temp)->elem;
}

template <typename Data>
Data BST<Data>::PredecessorNRemove(const Data& dat){
    NodeLnk** temp = FindPointerToPredecessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Predecessor not found!");
    
    return DataNDelete(Detach(*temp));
}

template <typename Data>
void BST<Data>::RemovePredecessor(const Data& dat){
    NodeLnk** temp = FindPointerToPredecessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Predecessor not found!");
    
    delete Detach(*temp);
}

template <typename Data>
const Data& BST<Data>::Successor(const Data& dat) const{
    NodeLnk* const* temp = FindPointerToSuccessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Successor not found!");
    
    return (*temp)->elem;
}

template <typename Data>
Data BST<Data>::SuccessorNRemove(const Data& dat){
    NodeLnk** temp = FindPointerToSuccessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Successor not found!");
    
    return DataNDelete(Detach(*temp));
}

template <typename Data>
void BST<Data>::RemoveSuccessor(const Data& dat){
    NodeLnk** temp = FindPointerToSuccessor(root, dat);

    if(temp == nullptr)
        throw std::length_error("Successor not found!");
    
    delete Detach(*temp);
}

template <typename Data>
bool BST<Data>::Insert(const Data& dat){
    NodeLnk*& temp = FindPointerTo(root, dat);

    if(temp == nullptr) {
        temp = new NodeLnk(dat);
        ++size;
        return true;
    }
    return false;
}

template <typename Data>
bool BST<Data>::Insert(Data&& dat) noexcept{
    NodeLnk*& temp = FindPointerTo(root, dat);

    if(temp == nullptr) {
        temp = new NodeLnk(std::move(dat));
        ++size;
        return true;
    }
    return false;
}

template <typename Data>
bool BST<Data>::Remove(const Data& dat){
    NodeLnk*& temp = FindPointerTo(root, dat);

    if(temp != nullptr) {
        delete Detach(temp);
        return true;
    }
    return false;
}

template <typename Data>
bool BST<Data>::Exists(const Data& dat) const noexcept{
    return (FindPointerTo(root, dat) != nullptr);
}

template<typename Data>
void BST<Data>::Clear(){
    BinaryTreeLnk<Data>::Clear();
}

template<typename Data>
void BST<Data>::View() const{
    if(this->Empty()){
        throw std::length_error("Empty tree!");
    }

    std::cout << "Size = " << this->Size() << "\n\n";

    std::cout << "Root: " << this->Root().Element() << "\n\n";

    std::cout << "Min: " << this->Min() << "\n";
    std::cout << "Max: " << this->Max() << "\n\n";

    BST& ref = const_cast<BST&>(*this);
    
    std::cout << "PreOrder Visit:\n";
    ref.PreOrderMap([](const Data& dat){
        std::cout << dat << " ";
    });

    std::cout << "\n\nPostOrder Visit:\n";
    ref.PostOrderMap([](const Data& dat){
        std::cout << dat << " ";
    });

    std::cout << "\n\nInOrder Visit:\n";
    ref.InOrderMap([](const Data& dat){
        std::cout << dat << " ";
    });

    std::cout << "\n\nBreadth Visit:\n";
    ref.BreadthMap([](const Data& dat){
        std::cout << dat << " ";
    });

    std::cout << "\n";
}






template <typename Data>
Data BST<Data>::DataNDelete(NodeLnk* nod) {
    Data dat{};
    std::swap(dat, nod->elem);
    delete nod;

    return dat;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Detach(NodeLnk*& nod) noexcept {
    if(nod != nullptr) {
        if(!nod->HasLeftChild()){
            return Skip2Right(nod);
        }
        else if(!nod->HasRightChild()){
            return Skip2Left(nod);
        }
        else{
            NodeLnk* temp = DetachMax(nod->lc);
            std::swap(nod->elem, temp->elem);
            return temp;
        }
    }
    return nullptr;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMin(NodeLnk*& nod) noexcept {
    return Skip2Right(FindPointerToMin(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::DetachMax(NodeLnk*& nod) noexcept {
    return Skip2Left(FindPointerToMax(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Left(NodeLnk*& nod) noexcept {
    NodeLnk* temp = nullptr;
    if(nod != nullptr) {
        std::swap(temp, nod->lc);
        std::swap(temp, nod);
        size--;
    }
    return temp;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& nod) noexcept {
    NodeLnk* temp = nullptr;
    if(nod != nullptr) {
        std::swap(temp, nod->rc);
        std::swap(temp, nod);
        size--;
    }
    return temp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& nod) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMin(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMin(NodeLnk* const & nod) const noexcept {
    NodeLnk* const * temp = &nod;
    NodeLnk* curr = nod;
    if(curr != nullptr) {
        while(curr->lc != nullptr) {
            temp = &curr->lc;
            curr = curr->lc;
        }
    }
    return *temp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& nod) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMax(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMax(NodeLnk* const & nod) const noexcept {
    NodeLnk* const * temp = &nod;
    NodeLnk* curr = nod;

    if(curr != nullptr){
        while(curr->rc != nullptr){
            temp = &curr->rc;
            curr = curr->rc;
        }
    }
    return *temp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& nod, const Data& dat) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerTo(nod, dat));
}

template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const & nod, const Data& dat) const noexcept {
    NodeLnk* const * temp = &nod;

    if(*temp != nullptr) {
        if(nod->elem == dat){
            return *temp;
        }
        else if(nod->elem < dat){
            temp = &(FindPointerTo(nod->rc, dat));
        }
        else{
            temp = &(FindPointerTo(nod->lc, dat));
        }
    }
    return *temp;
}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(NodeLnk*& nod, const Data& dat) noexcept {
    return const_cast<NodeLnk**>(static_cast<const BST<Data>*> (this)->FindPointerToPredecessor(nod, dat));
}

template <typename Data>
typename BST<Data>::NodeLnk* const* BST<Data>::FindPointerToPredecessor(NodeLnk* const& nod, const Data& dat) const noexcept {
    NodeLnk* const * curr = &nod;
    NodeLnk* const * temp = nullptr;

    while(*curr != nullptr && (*curr)->elem != dat) {
        if((*curr)->elem < dat) {
            temp = curr;
            curr = &((*curr)->rc);
        }
        else if((*curr)->elem > dat) {
            curr = &((*curr)->lc);
        }
    }
    if(*curr != nullptr && (*curr)->HasLeftChild()) {
        return &FindPointerToMax((*curr)->lc);
    }
    return temp;
}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(NodeLnk*& nod, const Data& dat) noexcept {
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(nod, dat));
}

template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToSuccessor(NodeLnk* const & nod, const Data& dat) const noexcept {
    NodeLnk* const * curr = &nod;
    NodeLnk* const * temp = nullptr;

    while(*curr != nullptr && (*curr)->elem != dat) {
        if((*curr)->elem > dat) {
            temp = curr;
            curr = &((*curr)->lc);
        }
        else if((*curr)->elem < dat) {
            curr = &((*curr)->rc);
        }
    }
    if(*curr != nullptr && (*curr)->HasRightChild()) {
        return &FindPointerToMin((*curr)->rc);
    }
    return temp;
}


/* ************************************************************************** */

}
