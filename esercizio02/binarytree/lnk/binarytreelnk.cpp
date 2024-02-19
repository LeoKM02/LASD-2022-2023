
namespace lasd {

/* ************************************************************************** */

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const Data& dat) {
    elem = dat;
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(Data&& dat) noexcept {
    std::swap(elem, dat);
}

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(const NodeLnk& nod) {
    elem = nod.elem;
    if(nod.lc != nullptr) {
        lc = new NodeLnk(*nod.lc);
    }
    if(nod.rc != nullptr) {
        rc = new NodeLnk(*nod.rc);
    }
};

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::NodeLnk(NodeLnk&& nod) noexcept {
    std::swap(elem, nod.elem);
    std::swap(lc, nod.lc);
    std::swap(rc, nod.rc);
};

template <typename Data>
BinaryTreeLnk<Data>::NodeLnk::~NodeLnk() {
    delete lc;
    delete rc;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(const NodeLnk& nod) {
    elem = nod.elem;
    if(nod.HasLeftChild()) {
        lc = nod.lc;
    }
    if(nod.HasRightChild()) {
        rc = nod.rc;
    }

    return *this;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk& BinaryTreeLnk<Data>::NodeLnk::operator=(NodeLnk&& nod) noexcept {
    std::swap(elem, nod.elem);
    std::swap(lc, nod.lc);
    std::swap(rc, nod.rc);

    return *this;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator==(const NodeLnk& nod) const noexcept{
    return BinaryTree<Data>::Node::operator==(nod);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::operator!=(const NodeLnk& nod) const noexcept {
    return !(*this == nod);
}

template <typename Data>
const Data& BinaryTreeLnk<Data>::NodeLnk::Element() const noexcept {
    return elem;
}

template <typename Data>
Data& BinaryTreeLnk<Data>::NodeLnk::Element() noexcept {
    return elem;
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::IsLeaf() const noexcept {
    return !(this->HasLeftChild() || this->HasRightChild());
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasRightChild() const noexcept {
    return (rc != nullptr);
}

template <typename Data>
bool BinaryTreeLnk<Data>::NodeLnk::HasLeftChild() const noexcept {
    return (lc != nullptr);
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::RightChild() const{
    if(!this->HasRightChild()){
        throw std::out_of_range("Right child not found!");
    }
    else{
        return *rc;
    }
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::NodeLnk::LeftChild() const{
    if(!this->HasLeftChild()){
        throw std::out_of_range("Left child not found!");    
    }
    else{
        return *lc;
    }
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::RightChild() {
    if(!this->HasRightChild()){
        throw std::out_of_range("Right child not found!");
    }
    else{
        return *rc;
    }
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::NodeLnk::LeftChild() {
    if(!this->HasLeftChild()){
        throw std::out_of_range("Left child not found!"); 
    }
    else{
        return *lc;
    }
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const MappableContainer<Data>& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;

    que.Enqueue(&root);
    con.Map([&que](const Data& dat) {
        NodeLnk*& temp = *que.HeadNDequeue();
        temp = new NodeLnk(dat);

        que.Enqueue(&temp->lc);
        que.Enqueue(&temp->rc);
    });
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(MutableMappableContainer<Data>&& con) {
    size = con.Size();
    QueueVec<NodeLnk**> que;

    que.Enqueue(&root);
    con.Map([&que](const Data& dat) {
        NodeLnk*& temp = *que.HeadNDequeue();
        temp = new NodeLnk(std::move(dat));

        que.Enqueue(&temp->lc);
        que.Enqueue(&temp->rc);
    });
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(const BinaryTreeLnk& btl){
    size = btl.Size();
    root = Copy(btl.root);
}

template <typename Data>
BinaryTreeLnk<Data>::BinaryTreeLnk(BinaryTreeLnk&& btl) noexcept{
    std::swap(size, btl.size);
    std::swap(root, btl.root);
}

template <typename Data>
BinaryTreeLnk<Data>::~BinaryTreeLnk() {
    Clear();
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(const BinaryTreeLnk& btl) {
    BinaryTreeLnk<Data>* temp = new BinaryTreeLnk<Data>(btl);
    std::swap(*temp, *this);
    delete temp;

    return *this;
}

template <typename Data>
BinaryTreeLnk<Data>& BinaryTreeLnk<Data>::operator=(BinaryTreeLnk&& btl) noexcept {
    std::swap(root, btl.root);
    std::swap(size, btl.size);

    return *this;
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator==(const BinaryTreeLnk& btl) const noexcept {
    return BinaryTree<Data>::operator==(btl);
}

template <typename Data>
bool BinaryTreeLnk<Data>::operator!=(const BinaryTreeLnk& btl) const noexcept {
    return !(*this == btl);
}

template <typename Data>
const BinaryTree<Data>::Node& BinaryTreeLnk<Data>::Root() const {
    if(this->Empty()) {
        throw std::length_error("Tree is empty!");
    }
    return *root;
}

template <typename Data>
MutableBinaryTree<Data>::MutableNode& BinaryTreeLnk<Data>::Root() {
    if(this->Empty()) {
        throw std::length_error("Tree is empty!");
    }
    return *root;
}

template <typename Data>
void BinaryTreeLnk<Data>::Clear() {
    size = 0;
    delete root;
    root = nullptr;
}

template <typename Data>
typename BinaryTreeLnk<Data>::NodeLnk* BinaryTreeLnk<Data>::Copy(NodeLnk* nod) {
    NodeLnk* temp = nullptr;

    if(nod != nullptr){
        temp = new NodeLnk(nod->elem);

        if(nod->HasLeftChild())
            temp->lc = Copy(nod->lc);
        if(nod->HasRightChild())
            temp->rc = Copy(nod->rc);
    }
    
    return temp;
}

/* ************************************************************************** */

}
