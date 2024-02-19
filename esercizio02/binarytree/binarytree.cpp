
namespace lasd {

/* ************************************************************************** */

template <typename Data>
bool BinaryTree<Data>::Node::operator==(const Node& nod) const noexcept {
    if(this->Element() == nod.Element()) {
        bool thisHasRC = this->HasRightChild();
        bool thisHasLC = this->HasLeftChild();
        bool nodHasRc = nod.HasRightChild();
        bool nodHasLc = nod.HasLeftChild();

        bool bothHaveRC = (thisHasRC == nodHasRc);
        bool bothHaveLC = (thisHasLC == nodHasLc);

        if(bothHaveLC && bothHaveRC) {
            if(thisHasLC && thisHasRC) {
                return((this->LeftChild() == nod.LeftChild()) && (this->RightChild() == nod.RightChild()));
            }
            else if(thisHasLC) {
                return( this->LeftChild() == nod.LeftChild() );
            }
            else if(thisHasRC) {
                return( this->RightChild() == nod.RightChild() );
            }
            else{
                return true;
            }
        }
    }
    return false;
}

template <typename Data>
bool BinaryTree<Data>::Node::operator!=(const Node& nod) const noexcept {
    return !(*this == nod);
}





template <typename Data>
bool BinaryTree<Data>::operator==(const BinaryTree& bt) const noexcept {
    if(this->Size() == bt.Size() && !this->Empty()) {
        return (Root() == bt.Root());
    }
    return false;
}

template <typename Data>
bool BinaryTree<Data>::operator!=(const BinaryTree& bt) const noexcept {
    return !(*this == bt);
}

template <typename Data>
void BinaryTree<Data>::Fold(FoldFunctor fun, void* res) const {
    if(!this->Empty()) {
        PreOrderFold(fun, res, &this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::Map(MapFunctor fun) const {
    if(!this->Empty()) {
        PreOrderMap(fun, &this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor fun) const {
    if(!this->Empty()) {
        PreOrderMap(fun, &this->Root());
    }  
}

template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor fun) const {
    if(!this->Empty()) {
        PostOrderMap(fun, &this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor fun) const {
    if(!this->Empty()) {
        InOrderMap(fun, &this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor fun) const {
    if(!this->Empty()) {
        BreadthMap(fun, &this->Root());
    }
}

template <typename Data>
void BinaryTree<Data>::PreOrderFold(FoldFunctor fun, void* res, const Node* nod) const {
    if(nod != nullptr) {
        fun(nod->Element(), res);

        if(nod->HasLeftChild()) {
            PreOrderFold(fun, res, &nod->LeftChild());
        }
        if(nod->HasRightChild()) {
            PreOrderFold(fun, res, &nod->RightChild());
        }
    }
}

template <typename Data>
void BinaryTree<Data>::PreOrderMap(MapFunctor fun, const Node* nod) const {
    if(nod != nullptr) {
        fun(nod->Element());
        
        if(nod->HasLeftChild()) {
            PreOrderMap(fun, &nod->LeftChild());
        }
        if(nod->HasRightChild()) {
            PreOrderMap(fun, &nod->RightChild());
        }
    }
}

template <typename Data>
void BinaryTree<Data>::PostOrderMap(MapFunctor fun, const Node* nod) const {
    if(nod != nullptr) {
        if(nod->HasLeftChild()) {
            PostOrderMap(fun, &nod->LeftChild());
        }
        if(nod->HasRightChild()) {
            PostOrderMap(fun, &nod->RightChild());
        }
        fun(nod->Element());
    }
}

template <typename Data>
void BinaryTree<Data>::InOrderMap(MapFunctor fun, const Node* nod) const {
    if(nod != nullptr) {
        if(nod->HasLeftChild()) {
            InOrderMap(fun, &nod->LeftChild());
        }

        fun(nod->Element());

        if(nod->HasRightChild()) {
            InOrderMap(fun, &nod->RightChild());
        }
    }    
}

template <typename Data>
void BinaryTree<Data>::BreadthMap(MapFunctor fun, const Node* nod) const {
    QueueVec<const Node*> que;

    if(nod != nullptr) {
        que.Enqueue(nod);
    }
    while (!que.Empty()) {
        fun(que.Head()->Element());
        
        if (que.Head()->HasLeftChild()) {
            que.Enqueue(&(que.Head()->LeftChild()));
        }
        
        if (que.Head()->HasRightChild()) {
            que.Enqueue(&(que.Head()->RightChild()));
        }

        que.Dequeue();
    }
}





template <typename Data>
void MutableBinaryTree<Data>::Map(MutableMapFunctor fun) {
    if(!this->Empty()){
        PreOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor fun) {
    if(!this->Empty()){
        PreOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor fun) {
    if(!this->Empty()) {
        PostOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor fun) {
    if(!this->Empty()) {
        InOrderMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor fun) {
    if(!this->Empty()) {
        BreadthMap(fun, &Root());
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PreOrderMap(MutableMapFunctor fun, MutableNode* nod) {
    if(nod != nullptr) {
        fun(nod->Element());

        if(nod->HasLeftChild()) {
            PreOrderMap(fun, &nod->LeftChild());
        }

        if(nod->HasRightChild()) {
            PreOrderMap(fun, &nod->RightChild());
        }
    }
}

template <typename Data>
void MutableBinaryTree<Data>::PostOrderMap(MutableMapFunctor fun, MutableNode* nod) {
    if(nod != nullptr) {
        if(nod->HasLeftChild()) {
            PostOrderMap(fun, &nod->LeftChild());
        }
        if(nod->HasRightChild()) {
            PostOrderMap(fun, &nod->RightChild());
        }
        fun(nod->Element());
    }    
}

template <typename Data>
void MutableBinaryTree<Data>::InOrderMap(MutableMapFunctor fun, MutableNode* nod) {
    if(nod != nullptr) {
        if(nod->HasLeftChild()) {
            InOrderMap(fun, &nod->LeftChild());
        }

        fun(nod->Element());

        if(nod->HasRightChild()) {
            InOrderMap(fun, &nod->RightChild());
        }
    }      
}

template <typename Data>
void MutableBinaryTree<Data>::BreadthMap(MutableMapFunctor fun, MutableNode* nod) {
    lasd::QueueVec<MutableNode*> que;
    if(nod != nullptr) {
        que.Enqueue(nod);
    }
    while (!que.Empty()) {
        fun(que.Head()->Element());
        
        if (que.Head()->HasLeftChild()) {
            que.Enqueue(&(que.Head()->LeftChild()));
        }
        
        if (que.Head()->HasRightChild()) {
            que.Enqueue(&(que.Head()->RightChild()));
        }
        que.Dequeue();
    }
}





template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BinaryTree<Data>& bt) {
    if(!bt.Empty()){
        root = &bt.Root();
        curr = root;
    }
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(const BTPreOrderIterator& iter) {
    root = iter.root;
    curr = iter.root;
    stk = iter.stk;
}

template <typename Data>
BTPreOrderIterator<Data>::BTPreOrderIterator(BTPreOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(const BTPreOrderIterator& iter) {
    root = iter.root;
    curr = iter.curr;
    stk = iter.stk;

    return *this;
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator=(BTPreOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);

    return *this;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator==(const BTPreOrderIterator& iter) const noexcept {
    if(curr!=iter.curr || root!=iter.root || stk!=iter.stk)
        return false;

    return true;
}

template <typename Data>
bool BTPreOrderIterator<Data>::operator!=(const BTPreOrderIterator& iter) const noexcept {
    return !(*this == iter);
}

template <typename Data>
const Data& BTPreOrderIterator<Data>::operator*() const {
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");
        
    return curr->Element();
}

template <typename Data>
bool BTPreOrderIterator<Data>::Terminated() const noexcept {
    return (curr == nullptr);
}

template <typename Data>
BTPreOrderIterator<Data>& BTPreOrderIterator<Data>::operator++() {
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");

    if(curr->HasRightChild())
        stk.Push(&(curr->RightChild()));
    if(curr->HasLeftChild())
        stk.Push(&(curr->LeftChild()));
    
    if(stk.Empty()){
        curr = nullptr;
    }
    else{
        curr = stk.TopNPop(); 
    }

    return (*this);
}

template <typename Data>
void BTPreOrderIterator<Data>::Reset() noexcept {
    curr = root;
    stk.Clear();
}





template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(const BTPreOrderMutableIterator& iter){
    BTPreOrderIterator<Data>::operator=(iter);
}

template <typename Data>
BTPreOrderMutableIterator<Data>& BTPreOrderMutableIterator<Data>::operator=(BTPreOrderMutableIterator&& iter) noexcept{
    BTPreOrderIterator<Data>::operator=(std::move(iter));
}

template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator==(const BTPreOrderMutableIterator& iter) const noexcept{
    return BTPreOrderIterator<Data>::operator==(iter);
}

template <typename Data>
bool BTPreOrderMutableIterator<Data>::operator!=(const BTPreOrderMutableIterator& iter) const noexcept{
    return !(*this == iter);
}

template <typename Data>
Data& BTPreOrderMutableIterator<Data>::operator*(){
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");

    return const_cast<Data&>(curr->Element());
}





template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BinaryTree<Data>& bt) {
    if(!bt.Empty()){
        root = &bt.Root();
        curr = root;

        getLeftmostLeaf();
    }
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(const BTPostOrderIterator& iter) {
    root = iter.root;
    curr = iter.root;
    stk = iter.stk;
}

template <typename Data>
BTPostOrderIterator<Data>::BTPostOrderIterator(BTPostOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(const BTPostOrderIterator& iter) {
    root = iter.root;
    curr = iter.curr;
    stk = iter.stk;

    return *this;
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator=(BTPostOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);

    return *this;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator==(const BTPostOrderIterator& iter) const noexcept {
    if(curr!=iter.curr || root!=iter.root || stk!=iter.stk)
        return false;

    return true;
}

template <typename Data>
bool BTPostOrderIterator<Data>::operator!=(const BTPostOrderIterator& iter) const noexcept {
    return !(*this == iter);
}

template <typename Data>
const Data& BTPostOrderIterator<Data>::operator*() const {
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");
        
    return curr->Element();
}

template <typename Data>
bool BTPostOrderIterator<Data>::Terminated() const noexcept {
    return (curr == nullptr);
}

template <typename Data>
BTPostOrderIterator<Data>& BTPostOrderIterator<Data>::operator++() {
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");
    
    if(stk.Empty()){
        curr = nullptr;
    }
    else{
        if(stk.Top()->HasRightChild() && (&stk.Top()->RightChild() != curr)){
            curr = &stk.Top()->RightChild();
            getLeftmostLeaf();
        }
        else{
            curr = stk.TopNPop();
        }
    }

    return (*this);
}

template <typename Data>
void BTPostOrderIterator<Data>::Reset() noexcept {
    curr = root;
    stk.Clear();

    getLeftmostLeaf();
}

template <typename Data>
void BTPostOrderIterator<Data>::getLeftmostLeaf() {
    if(!this->Terminated()){
        while(curr->HasLeftChild()) {
            stk.Push(curr);
            curr = &curr->LeftChild();
        }
        if(curr->HasRightChild()) {
            stk.Push(curr);
            curr = &curr->RightChild();
            getLeftmostLeaf();
        }
    }
}





template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(const BTPostOrderMutableIterator& iter){
    BTPostOrderIterator<Data>::operator=(iter);
}

template <typename Data>
BTPostOrderMutableIterator<Data>& BTPostOrderMutableIterator<Data>::operator=(BTPostOrderMutableIterator&& iter) noexcept{
    BTPostOrderIterator<Data>::operator=(std::move(iter));
}

template <typename Data>
bool BTPostOrderMutableIterator<Data>::operator==(const BTPostOrderMutableIterator& iter) const noexcept{
    return BTPostOrderIterator<Data>::operator==(iter);
}

template <typename Data>
bool BTPostOrderMutableIterator<Data>::operator!=(const BTPostOrderMutableIterator& iter) const noexcept{
    return !(*this == iter);
}

template <typename Data>
Data& BTPostOrderMutableIterator<Data>::operator*(){
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");

    return const_cast<Data&>(curr->Element());
}





template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BinaryTree<Data>& bt) {
    if(!bt.Empty()){
        root = &bt.Root();
        curr = root;

        getLeftmostNode();
    }
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(const BTInOrderIterator& iter) {
    root = iter.root;
    curr = iter.root;
    stk = iter.stk;
}

template <typename Data>
BTInOrderIterator<Data>::BTInOrderIterator(BTInOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(const BTInOrderIterator& iter) {
    root = iter.root;
    curr = iter.curr;
    stk = iter.stk;

    return *this;
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator=(BTInOrderIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(stk, iter.stk);

    return *this;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator==(const BTInOrderIterator& iter) const noexcept {
    if(curr!=iter.curr || root!=iter.root || stk!=iter.stk)
        return false;

    return true;
}

template <typename Data>
bool BTInOrderIterator<Data>::operator!=(const BTInOrderIterator& iter) const noexcept {
    return !(*this == iter);
}

template <typename Data>
const Data& BTInOrderIterator<Data>::operator*() const {
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");
        
    return curr->Element();
}

template <typename Data>
bool BTInOrderIterator<Data>::Terminated() const noexcept {
    return (curr == nullptr);
}

template <typename Data>
BTInOrderIterator<Data>& BTInOrderIterator<Data>::operator++() {
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");

    if(curr->HasRightChild()){
        curr = &(curr->RightChild());
        getLeftmostNode();
    }
    else{
        if(stk.Empty()){
            curr = nullptr;
        }
        else{
            curr = stk.TopNPop();
        }
    }

    return (*this);
}

template <typename Data>
void BTInOrderIterator<Data>::Reset() noexcept {
    curr = root;
    stk.Clear();

    getLeftmostNode();
}

template <typename Data>
void BTInOrderIterator<Data>::getLeftmostNode() {
    if(!this->Terminated()) {
        while(curr->HasLeftChild()) {
            stk.Push(curr);
            curr = &curr->LeftChild();
        }
    }
}





template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(const BTInOrderMutableIterator& iter){
    BTInOrderIterator<Data>::operator=(iter);
}

template <typename Data>
BTInOrderMutableIterator<Data>& BTInOrderMutableIterator<Data>::operator=(BTInOrderMutableIterator&& iter) noexcept{
    BTInOrderIterator<Data>::operator=(std::move(iter));
}

template <typename Data>
bool BTInOrderMutableIterator<Data>::operator==(const BTInOrderMutableIterator& iter) const noexcept{
    return BTInOrderIterator<Data>::operator==(iter);
}

template <typename Data>
bool BTInOrderMutableIterator<Data>::operator!=(const BTInOrderMutableIterator& iter) const noexcept{
    return !(*this == iter);
}

template <typename Data>
Data& BTInOrderMutableIterator<Data>::operator*(){
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");

    return const_cast<Data&>(curr->Element());
}





template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BinaryTree<Data>& bt) {
    if(!bt.Empty()){
        root = &bt.Root();
        curr = root;
    }
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(const BTBreadthIterator& iter) {
    root = iter.root;
    curr = iter.root;
    que = iter.que;
}

template <typename Data>
BTBreadthIterator<Data>::BTBreadthIterator(BTBreadthIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(que, iter.que);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(const BTBreadthIterator& iter) {
    root = iter.root;
    curr = iter.curr;
    que = iter.que;

    return *this;
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator=(BTBreadthIterator&& iter) noexcept {
    std::swap(root, iter.root);
    std::swap(curr, iter.curr);
    std::swap(que, iter.que);

    return *this;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator==(const BTBreadthIterator& iter) const noexcept {
    if(curr!=iter.curr || root!=iter.root || que!=iter.que)
        return false;

    return true;
}

template <typename Data>
bool BTBreadthIterator<Data>::operator!=(const BTBreadthIterator& iter) const noexcept {
    return !(*this == iter);
}

template <typename Data>
const Data& BTBreadthIterator<Data>::operator*() const {
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");
        
    return curr->Element();
}

template <typename Data>
bool BTBreadthIterator<Data>::Terminated() const noexcept {
    return (curr == nullptr);
}

template <typename Data>
BTBreadthIterator<Data>& BTBreadthIterator<Data>::operator++() {
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");

    if(curr->HasLeftChild()) {
        que.Enqueue(&(curr->LeftChild()));
    }
    if(curr->HasRightChild()) {
        que.Enqueue(&(curr->RightChild()));
    }
    if(que.Empty()) {
        curr = nullptr;
    } else {
        curr = que.HeadNDequeue();
    }

    return (*this);
}

template <typename Data>
void BTBreadthIterator<Data>::Reset() noexcept {
    curr = root;
    que.Clear();
}





template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(const BTBreadthMutableIterator& iter){
    BTBreadthIterator<Data>::operator=(iter);
}

template <typename Data>
BTBreadthMutableIterator<Data>& BTBreadthMutableIterator<Data>::operator=(BTBreadthMutableIterator&& iter) noexcept{
    BTBreadthIterator<Data>::operator=(std::move(iter));
}

template <typename Data>
bool BTBreadthMutableIterator<Data>::operator==(const BTBreadthMutableIterator& iter) const noexcept{
    return BTBreadthIterator<Data>::operator==(iter);
}

template <typename Data>
bool BTBreadthMutableIterator<Data>::operator!=(const BTBreadthMutableIterator& iter) const noexcept{
    return !(*this == iter);
}

template <typename Data>
Data& BTBreadthMutableIterator<Data>::operator*(){
    if(this->Terminated())
        throw std::out_of_range("Iterator has terminated!");

    return const_cast<Data&>(curr->Element());
}

/* ************************************************************************** */

}
