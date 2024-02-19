
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
    if(root == nullptr)
        throw std::length_error("Tree is empty!");
    
    return FindPointerToMin(root)->elem;
}

template <typename Data>
Data BST<Data>::MinNRemove(){
    if(root == nullptr)
        throw std::length_error("Tree is empty!");
    
    return DataNDelete(DetachMin(root));
}

template <typename Data>
void BST<Data>::RemoveMin(){
    if(root == nullptr)
        throw std::length_error("Tree is empty!");
    
    delete DetachMin(root);
}

template <typename Data>
const Data& BST<Data>::Max() const{
    if(root == nullptr)
        throw std::length_error("Tree is empty!");
    
    return FindPointerToMax(root)->elem;
}

template <typename Data>
Data BST<Data>::MaxNRemove(){
    if(root == nullptr)
        throw std::length_error("Tree is empty!");
    
    return DataNDelete(DetachMax(root));
}

template <typename Data>
void BST<Data>::RemoveMax(){
    if(root == nullptr)
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
            NodeLnk* tmp = DetachMax(nod->lc);
            std::swap(nod->elem, tmp->elem);
            return tmp;
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
    NodeLnk* tmp = nullptr;
    if(nod != nullptr) {
        std::swap(tmp, nod->lc);
        std::swap(tmp, nod);
        size--;
    }
    return tmp;
}

template <typename Data>
typename BST<Data>::NodeLnk* BST<Data>::Skip2Right(NodeLnk*& nod) noexcept {
    NodeLnk* tmp = nullptr;
    if(nod != nullptr) {
        std::swap(tmp, nod->rc);
        std::swap(tmp, nod);
        size--;
    }
    return tmp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMin(NodeLnk*& nod) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMin(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMin(NodeLnk* const & nod) const noexcept {
    NodeLnk* const * tmp = &nod;
    NodeLnk* cur = nod;
    if(cur != nullptr) {
        while(cur->lc != nullptr) {
            tmp = &cur->lc;
            cur = cur->lc;
        }
    }
    return *tmp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerToMax(NodeLnk*& nod) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerToMax(nod));
}

template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerToMax(NodeLnk* const & nod) const noexcept {
    NodeLnk* const * tmp = &nod;
    NodeLnk* cur = nod;
    if(cur != nullptr) {
        while(cur->rc != nullptr) {
            tmp = &cur->rc;
            cur = cur->rc;
        }
    }
    return *tmp;
}

template <typename Data>
typename BST<Data>::NodeLnk*& BST<Data>::FindPointerTo(NodeLnk*& nod, const Data& dat) noexcept {
    return const_cast<NodeLnk* &>(static_cast<const BST<Data> *>(this)->FindPointerTo(nod, dat));
}

template <typename Data>
typename BST<Data>::NodeLnk* const & BST<Data>::FindPointerTo(NodeLnk* const & nod, const Data& dat) const noexcept {
    NodeLnk* const * tmp = &nod;
    if(*tmp != nullptr) {
        if(nod->elem == dat) {
            return *tmp;
        }
        else if(nod->elem < dat) {
            tmp = &(FindPointerTo(nod->rc, dat));
        }
        else {
            tmp = &(FindPointerTo(nod->lc, dat));
        }
    }
    return *tmp;
}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToPredecessor(NodeLnk*& nod, const Data& dat) noexcept {
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToPredecessor(nod, dat));
}

template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToPredecessor(NodeLnk* const & nod, const Data& dat) const noexcept {
    NodeLnk* const * cur = &nod;
    NodeLnk* const * tmp = nullptr;
    while(*cur != nullptr && (*cur)->elem != dat) {
        if((*cur)->elem < dat) {
            tmp = cur;
            cur = &((*cur)->rc);
        }
        else if((*cur)->elem > dat) {
            cur = &((*cur)->lc);
        }
    }
    if(*cur != nullptr && (*cur)->HasLeftChild()) {
        return &FindPointerToMax((*cur)->lc);
    }
    return tmp;
}

template <typename Data>
typename BST<Data>::NodeLnk** BST<Data>::FindPointerToSuccessor(NodeLnk*& nod, const Data& dat) noexcept {
    return const_cast<NodeLnk* *>(static_cast<const BST<Data> *>(this)->FindPointerToSuccessor(nod, dat));
}

template <typename Data>
typename BST<Data>::NodeLnk* const * BST<Data>::FindPointerToSuccessor(NodeLnk* const & nod, const Data& dat) const noexcept {
    NodeLnk* const * cur = &nod;
    NodeLnk* const * tmp = nullptr;
    while(*cur != nullptr && (*cur)->elem != dat) {
        if((*cur)->elem > dat) {
            tmp = cur;
            cur = &((*cur)->lc);
        }
        else if((*cur)->elem < dat) {
            cur = &((*cur)->rc);
        }
    }
    if(*cur != nullptr && (*cur)->HasRightChild()) {
        return &FindPointerToMin((*cur)->rc);
    }
    return tmp;
}


/* ************************************************************************** */

}
