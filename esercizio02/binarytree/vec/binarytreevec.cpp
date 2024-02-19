
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data & dat, unsigned long index, Vector<NodeVec*> *vec) {
    elem = dat;
    curr = index;
    vecptr = vec;
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& nod) {
    elem = nod.elem;
    curr = nod.curr;
    vecptr = nod.vecptr;
    return *this;
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& nod) noexcept {
    std::swap(elem, nod.elem);
    std::swap(curr, nod.curr);
    std::swap(vecptr, nod.vecptr);

    return *this;
}

template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept {
    return elem;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept {
    return elem;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept {
    return ((2*curr+1) > vecptr->Size());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept {
    return ((2*curr+2) < vecptr->Size());
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept {
    return ((2*curr+1) < vecptr->Size());
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const {
    if(HasRightChild()) {
        return *(vecptr->operator[](2*curr+2));
    } else {
        throw std::out_of_range("Right child not found!");
    }
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const {
    if(HasLeftChild()) {
        return *(vecptr->operator[](2*curr+1));
    } else {
        throw std::out_of_range("Left child not found!");
    }
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild() {
    if(HasRightChild()) {
        return *(vecptr->operator[](2*curr+2));
    } else {
        throw std::out_of_range("Right child not found!");
    }
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild() {
    if(HasLeftChild()) {
        return *(vecptr->operator[](2*curr+1));
    } else {
        throw std::out_of_range("Left child not found!");
    }    
}






template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const MappableContainer<Data>& con) {
    size = con.Size();
    if(this->Size() > 0) {
        vec = new Vector<NodeVec*>(this->Size());
        unsigned long index = 0;

        con.Map([this, &index](const Data& data) {
            NodeVec* nod = new NodeVec(data, index, vec);
            vec->operator[](index++) = nod;
        });
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MutableMappableContainer<Data>&& con) noexcept {
    size = con.Size();
    if(this->Size() > 0) {
        vec = new Vector<NodeVec*>(this->Size());
        unsigned long index = 0;

        con.Map([this, &index](Data& data) {
            NodeVec* nod = new NodeVec(data, index, vec);
            vec->operator[](index++) = nod;
        });
    } 
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& btv) {
    size = btv.Size();
    if(this->Size() > 0) {
        vec =  new Vector<NodeVec*>(this->Size());
        for(unsigned long i=0; i<this->Size(); i++) {
            NodeVec* tmp = new NodeVec(btv.vec->operator[](i)->Element(), i, vec);
            vec->operator[](i) = tmp;
        }
    }
    
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& btv) noexcept {
    std::swap(size, btv.size);
    std::swap(vec, btv.vec);
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec() {
    Clear();

    delete vec;
    vec = nullptr;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& btv) {
    BinaryTreeVec<Data>* tmp = new BinaryTreeVec<Data>(btv);
    std::swap(*this, *tmp);
    delete tmp;
    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& btv) noexcept {
    std::swap(size, btv.size);
    std::swap(vec, btv.vec);
    return *this;
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::Root() const {
    if(this->Size() > 0) {
        return *(vec->operator[](0));
    } else {
        throw std::length_error("Tree is empty!");
    }
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::Root() {
    if(this->Size() > 0) {
        return *(vec->operator[](0));
    } else {
        throw std::length_error("Tree is empty!");
    }
}

template <typename Data>
void BinaryTreeVec<Data>::Clear() {
    if(this->Size()>0) {
        for(unsigned long i=0; i<this->Size(); i++) {
            if(vec->operator[](i) != nullptr) {
                delete (*vec)[i];
            }
        }
        vec->Clear();
        size = 0;
    }

}

template <typename Data>
void BinaryTreeVec<Data>::BreadthFold(FoldFunctor fun, void* acc) const {
    for(unsigned long i=0; i<this->Size(); i++) {
        if(vec->operator[](i) != nullptr) {
            fun(vec->operator[](i)->Element(), acc);
        }
        
    }
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFunctor fun) const {
    for(unsigned long i=0; i<this->Size(); i++) {
        if(vec->operator[](i) != nullptr) {
            fun(vec->operator[](i)->Element());
        }
    }
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MutableMapFunctor fun) {
    for(unsigned long i=0; i<this->Size(); i++) {
        if(vec->operator[](i) != nullptr) {
            fun(vec->operator[](i)->Element());
        }
    }    
}

/* ************************************************************************** */

}
