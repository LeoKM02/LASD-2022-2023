
namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline List<Data>::Node::Node(const Data& dat){
    elem = dat;
}

template<typename Data>
inline List<Data>::Node::Node(Data&& dat) noexcept {
    elem = std::move(dat);
}

template<typename Data>
inline List<Data>::Node::Node(const Node& nod) {
    elem = nod.elem;
}

template<typename Data>
inline List<Data>::Node::Node(Node&& nod) noexcept {
    std::swap(elem, node.elem);
    std::swap(next, node.next);
}

template<typename Data>
inline bool List<Data>::Node::operator==(const Node& nod) const noexcept{
    return (elem == nod.elem);
}

template<typename Data>
inline bool List<Data>::Node::operator!=(const Node& nod) const noexcept{
    return (elem != nod.elem);
}

template<typename Data>
List<Data>::List(const MappableContainer<Data>& con){
    con.Map([this, temp](const Data& dat){
        InsertAtBack(dat);
    });
}

template<typename Data>
List<Data>::List(MutableMappableContainer<Data>&& con) noexcept {
    con.Map([this, temp](Data& dat){
        InsertAtBack(std::move(dat));
    });
}

template<typename Data>
List<Data>::List(const List& con) {
    Node * temp = con.head;
    while(temp != nullptr){
        InsertAtBack(temp->elem);
        temp = temp->next;
    }
}

template<typename Data>
List<Data>::List(List&& con) {
    std::swap(head, con.head);
    std::swap(tail, con.tail);
    std::swap(size, con.size);
}

template<typename Data>
List<Data>::~List() {
    Clear();
}

template<typename Data>
inline List<Data>& List<Data>::operator=(const List& con){
    List* temp = new List(con);
    std::swap(*temp, *this);
    delete temp;
    return *this;
}

template<typename Data>
inline List<Data>& List<Data>::operator=(List&& con) noexcept {
    std::swap(head, con.head);
    std::swap(tail, con.tail);
    std::swap(size, con.size);
    return *this;
}

template<typename Data>
inline bool List<Data>::operator==(const List& con) const noexcept {
    if(size == con.size){
        Node* temp = head;
        Node* tempcmp = con.head;
        while(temp != nullptr){
            if(temp->elem != tempcmp->elem){
                return false;
            }
            temp = temp->next;
            tempcmp = tempcmp->next;
        }
        return true;
    }
    return false;
}

template<typename Data>
inline bool List<Data>::operator!=(const List& con) const noexcept {
    if(size == con.size){
        Node* temp = head;
        Node* tempcmp = con.head;
        while(temp != nullptr){
            if(temp->elem != tempcmp->elem){
                return true;
            }
            temp = temp->next;
            tempcmp = tempcmp->next;
        }
        return false;
    }
    return true;
}

template<typename Data>
inline void List<Data>::InsertAtFront(const Data& dat) {
    Node* temp = new Node(dat);
    if(head != nullptr){
        temp->next = head->next;
    }
    else{
        tail = temp;
    }
    head = temp;
    ++size;
}

template<typename Data>
inline void List<Data>::InsertAtFront(Data&& dat) noexcept {
    Node* temp = new Node(std::move(dat));
    if(head != nullptr){
        temp->next = head;
    }
    else{
        tail = temp;
    }
    head = temp;
    ++size;
}

template<typename Data>
inline void List<Data>::RemoveFromFront() {
    if(size == 0){
        throw std::length_error();
    }
    Node * temp = head->next;
    delete head;
    head = temp;
    if(head == nullptr){
        tail = nullptr;
    }
    --size;
}

template<typename Data>
inline Data List<Data>::FrontNRemove() {
    if(size == 0){
        throw std::length_error();
    }

    Data ret = head->elem;

    Node * temp = head->next;
    delete head;
    head = temp;
    if(head == nullptr){
        tail = nullptr;
    }
    --size;

    return ret;
}

template<typename Data>
inline void List<Data>::InsertAtBack(const Data& dat) {
    Node* temp = new Node(dat);
    if(tail != nullptr){
        tail->next = temp;
    }
    else{
        head = temp;
    }
    tail = temp;
    ++size;
}

template<typename Data>
inline void List<Data>::InsertAtBack(Data&& dat) noexcept {
    Node* temp = new Node(std::move(dat));
    if(tail != nullptr){
        tail->next = temp;
    }
    else{
        head = temp;
    }
    tail = temp;
    ++size;
}

template<typename Data>
inline void List<Data>::Clear() {
    if(head != nullptr){
        Node * temp;
        while(head != nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }
}

template<typename Data>
inline bool List<Data>::Exists(const Data& dat) const noexcept {
    Node * temp = head;
    while(temp != nullptr){
        if(temp->elem == dat){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

template<typename Data>
inline bool List<Data>::Insert(const Data& dat) {
    if(Exists(dat)){
        return false;
    }
    else{
        InsertAtBack(dat);
        return true;
    }
}

template<typename Data>
inline bool List<Data>::Insert(Data&& dat) {
    if(Exists(dat)){
        return false;
    }
    else{
        InsertAtBack(std::move(dat));
        return true;
    }
}

template<typename Data>
inline bool List<Data>::Remove(const Data& dat) {
    if(head != nullptr){
        if(head->elem == dat){
            RemoveFromFront(dat);
            return true;
        }

        Node* curr = head->next;
        Node* prev = head;
        while(curr != nullptr){
            if(curr->elem == dat){
                prev->next = curr->next;
                if(curr->next == nullptr){
                    tail = prev;
                }
                delete curr;
                --size;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return false;
}

template<typename Data>
inline const Data& List<Data>::operator[](const ulong index) const {
    if(index >= size){
        throw std::out_of_range();
    }

    if(index == size - 1){
        return tail->elem;
    }

    Node* temp = head;
    ulong i = 0;
    while(i != index){
        temp = temp->next;
        ++i;
    }
    return temp->elem;
}

template<typename Data>
inline Data& List<Data>::operator[](const ulong i) {
    if(index >= size){
        throw std::out_of_range();
    }

    if(index == size - 1){
        return tail->elem;
    }

    Node* temp = head;
    ulong i = 0;
    while(i != index){
        temp = temp->next;
        ++i;
    }
    return temp->elem;
}

template<typename Data>
inline const Data& List<Data>::Front() const {
    if(size == 0){
        throw std::length_error();
    }
    return head->elem;
}

template<typename Data>
inline Data& List<Data>::Front() {
    if(size == 0){
        throw std::length_error();
    }
    return head->elem;
}

template<typename Data>
inline const Data& List<Data>::Back() const {
    if(size == 0){
        throw std::length_error();
    }
    return tail->elem;
}

template<typename Data>
inline Data& List<Data>::Back() {
    if(size == 0){
        throw std::length_error();
    }
    return tail->elem;
}

// Inherited member functions
template<typename Data>
inline void List<Data>::PreOrderFold(FoldFunctor fun, void * ret) const {
    Node * temp = head;
    while(temp != nullptr){
        fun(temp->elem, ret);
        temp = temp->next;
    }
}

template<typename Data>
inline void List<Data>::PostOrderFold(FoldFunctor fun, void * ret) const {
    PostOrderFold(fun, ret, head);
}

template<typename Data>
inline void List<Data>::PreOrderMap(MapFunctor fun) const {
    Node * temp = head;
    while(temp != nullptr){
        fun(temp->elem);
        temp = temp->next;
    }
}

template<typename Data>
inline void List<Data>::PostOrderMap(MapFunctor fun) const {
    PostOrderMap(fun, head);
}

template<typename Data>
inline void List<Data>::PreOrderMap(MutableMapFunctor fun) {
    Node * temp = head;
    while(temp != nullptr){
        fun(temp->elem);
        temp = temp->next;
    }
}

template<typename Data>
inline void List<Data>::PostOrderMap(MutableMapFunctor fun) {
    PostOrderMap(fun, head);
}

// Auxiliary member functions
template<typename Data>
inline void List<Data>::PostOrderFold(FoldFunctor fun, void * ret, Node * nod) const {
    if(nod != nullptr){
        PostOrderFold(fun, ret, nod->next);
        fun(nod->elem, ret);
    }
}

template<typename Data>
inline void List<Data>::PostOrderMap(MapFunctor fun, Node * nod) const {
    if(nod != nullptr){
        PostOrderMap(fun, nod->next);
        fun(nod->elem);
    }
}

template<typename Data>
inline void List<Data>::PostOrderMap(MutableMapFunctor fun, Node * nod) {
    if(nod != nullptr){
        PostOrderMap(fun, nod->next);
        fun(nod->elem);
    }
}

/* ************************************************************************** */

}
