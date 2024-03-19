
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeVec<Data>::NodeVec::NodeVec(const Data& dat, unsigned long index, Vector<NodeVec*> *vec){
    elem = dat;
    curr = index;
    vecptr = vec;
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(const NodeVec& nod){
    elem = nod.elem;
    curr = nod.curr;
    vecptr = nod.vecptr;

    return *this;
}

template <typename Data>
typename BinaryTreeVec<Data>::NodeVec& BinaryTreeVec<Data>::NodeVec::operator=(NodeVec&& nod) noexcept{
    std::swap(elem, nod.elem);
    std::swap(curr, nod.curr);
    std::swap(vecptr, nod.vecptr);

    return *this;
}

template <typename Data>
const Data& BinaryTreeVec<Data>::NodeVec::Element() const noexcept{
    return elem;
}

template <typename Data>
Data& BinaryTreeVec<Data>::NodeVec::Element() noexcept{
    return elem;
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::IsLeaf() const noexcept{
    return ((2*curr)+1) > vecptr->Size();
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasRightChild() const noexcept{
    return ((2*curr)+2) < vecptr->Size();
}

template <typename Data>
bool BinaryTreeVec<Data>::NodeVec::HasLeftChild() const noexcept{
    return ((2*curr)+1) < vecptr->Size();
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::RightChild() const{
    if(!HasRightChild())
        throw std::out_of_range("Right child not found!");
    
    return *(vecptr->operator[](2*curr+2));
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::NodeVec::LeftChild() const{
    if(!HasLeftChild())
        throw std::out_of_range("Left child not found!");
    
    return *(vecptr->operator[](2*curr+1));
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::RightChild(){
    if(!HasRightChild())
        throw std::out_of_range("Right child not found!");
    
    return *(vecptr->operator[](2*curr+2));
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::NodeVec::LeftChild(){
    if(!HasLeftChild())
        throw std::out_of_range("Left child not found!");
    
    return *(vecptr->operator[](2*curr+1)); 
}






template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const MappableContainer<Data>& con){
    size = con.Size();

    if(this->Size() > 0){
        treevec = new Vector<NodeVec*>(this->Size());
        
        unsigned long i = 0;
        con.Map([this, &i](const Data& dat){
            NodeVec* nod = new NodeVec(dat, i, treevec);
            treevec->operator[](i++) = nod;
        });
    }
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(MutableMappableContainer<Data>&& con) noexcept{
    size = con.Size();

    if(this->Size() > 0){
        treevec = new Vector<NodeVec*>(this->Size());
        
        unsigned long i = 0;
        con.Map([this, &i](Data& dat){
            NodeVec* nod = new NodeVec(dat, i, treevec);
            treevec->operator[](i++) = nod;
        });
    } 
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(const BinaryTreeVec<Data>& btvec){
    size = btvec.Size();

    if(this->Size() > 0){
        treevec =  new Vector<NodeVec*>(this->Size());

        for(unsigned long i=0; i < this->Size(); ++i){
            NodeVec* temp = new NodeVec(btvec.treevec->operator[](i)->Element(), i, treevec);
            treevec->operator[](i) = temp;
        }
    }
    
}

template <typename Data>
BinaryTreeVec<Data>::BinaryTreeVec(BinaryTreeVec<Data>&& btvec) noexcept{
    std::swap(size, btvec.size);
    std::swap(treevec, btvec.treevec);
}

template <typename Data>
BinaryTreeVec<Data>::~BinaryTreeVec(){
    Clear();

    delete treevec;
    treevec = nullptr;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(const BinaryTreeVec<Data>& btvec){
    BinaryTreeVec<Data>* temp = new BinaryTreeVec<Data>(btvec);
    std::swap(*this, *temp);
    delete temp;

    return *this;
}

template <typename Data>
BinaryTreeVec<Data>& BinaryTreeVec<Data>::operator=(BinaryTreeVec<Data>&& btvec) noexcept{
    std::swap(size, btvec.size);
    std::swap(treevec, btvec.treevec);

    return *this;
}

template <typename Data>
bool BinaryTreeVec<Data>::operator==(const BinaryTreeVec<Data>& btvec) const noexcept{
    return MutableBinaryTree<Data>::operator==(btvec);
}

template <typename Data>
bool BinaryTreeVec<Data>::operator!=(const BinaryTreeVec<Data>& btvec) const noexcept{
    return !(*this == btvec);
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeVec<Data>::Root() const{
    if(this->Empty())
        throw std::length_error("Tree is empty!");
    
    return *(treevec->operator[](0));
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeVec<Data>::Root(){
    if(this->Empty())
        throw std::length_error("Tree is empty!");
    
    return *(treevec->operator[](0));
}

template <typename Data>
void BinaryTreeVec<Data>::Clear(){
    if(!this->Empty()){
        for(unsigned long i=0; i < this->Size(); ++i){
            if(treevec->operator[](i) != nullptr){
                delete (*treevec)[i];
            }
        }

        treevec->Clear();
        size = 0;
    }

}

template <typename Data>
void BinaryTreeVec<Data>::BreadthFold(FoldFunctor fun, void* res) const{
    for(unsigned long i=0; i < this->Size(); ++i) {
        if(treevec->operator[](i) != nullptr)
            fun(treevec->operator[](i)->Element(), res);
        
    }
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MapFunctor fun) const {
    for(unsigned long i=0; i < this->Size(); ++i) {
        if(treevec->operator[](i) != nullptr)
            fun(treevec->operator[](i)->Element());

    }
}

template <typename Data>
void BinaryTreeVec<Data>::BreadthMap(MutableMapFunctor fun){
    for(unsigned long i=0; i < this->Size(); ++i){
        if(treevec->operator[](i) != nullptr)
            fun(treevec->operator[](i)->Element());

    }    
}

/* ************************************************************************** */

}
