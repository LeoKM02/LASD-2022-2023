
namespace lasd {

/* ************************************************************************** */

template <typename Data>
QueueVec<Data>::QueueVec() {
    Vector<Data>(10);
    sentinel = size-1;
}

template <typename Data>
QueueVec<Data>::QueueVec(const MappableContainer<Data>& con) {
    size = con.Size()*2;
    elements = new Data[size]{};
    sentinel = size-1;

    con.Map([this](const Data& dat) {
        Enqueue(dat);
    });
}

template <typename Data>
QueueVec<Data>::QueueVec(MutableMappableContainer<Data>&& con) noexcept {
    size = con.Size()*2;
    elements = new Data[size]{};
    sentinel = size-1;

    con.Map([this](Data& dat) {
        Enqueue(std::move(dat));
    });
}

template <typename Data>
QueueVec<Data>::QueueVec(const QueueVec& con){
    Vector<Data>::Vector(con);
    head = con.head;
    tail = con.tail;
    sentinel = con.sentinel;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& con) noexcept {
    Vector<Data>::Vector(con);
    std::swap(head, con.head);
    std::swap(tail, con.tail);
    std::swap(sentinel, con.sentinel);
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(const QueueVec& con) {
    Vector<Data>::operator=(con);
    head = con.head;
    tail = con.tail;
    sentinel = con.sentinel;
    return *this;
}

template <typename Data>
QueueVec<Data>& QueueVec<Data>::operator=(QueueVec&& con) noexcept {
    Vector<Data>::operator=(con);
    std::swap(head, con.head);
    std::swap(tail, con.tail);
    std::swap(sentinel, con.sentinel);
    return *this;
}

template <typename Data>
inline bool QueueVec<Data>::operator==(const QueueVec& con) const noexcept {
    bool ret;
    
    if(Size()==con.Size()){
        ret = true;
        if(!Empty()){
            QueueVec* temp1 = new QueueVec(*this);
            QueueVec* temp2 = new QueueVec(con);
            for(ulong i=0; i<Size(); ++i){
                if(temp1->HeadNDequeue() != temp2->HeadNDequeue()){
                    ret = false;
                    break;
                }
            }
            delete[] temp1;
            delete[] temp2;
        }
    }
    else{
        ret = false;
    }

    return ret;
}

template <typename Data>
inline bool QueueVec<Data>::operator!=(const QueueVec& con) const noexcept {
    return (! operator==(con));
}

template <typename Data>
inline const Data& QueueVec<Data>::Head() const {
    if(Size()==0){
        throw std::length_error();
    }
    return elements[head];
}

template <typename Data>
inline Data& QueueVec<Data>::Head() {
    if(Size()==0){
        throw std::length_error();
    }
    return elements[head];
}

template <typename Data>
inline void QueueVec<Data>::Dequeue() {
    if(Size()==0){
        throw std::length_error();
    }

    Reduce();
    sentinel = head;
    head = (head+1)%size;
}

template <typename Data>
inline Data QueueVec<Data>::HeadNDequeue() {
    if(Size()==0){
        throw std::length_error();
    }

    Data temp = Head();
    Dequeue();
    return temp;
}

template <typename Data>
inline void QueueVec<Data>::Enqueue(const Data& dat) {
    if(sentinel == )
}

template <typename Data>
inline void QueueVec<Data>::Enqueue(Data&& dat) noexcept {
    
}

template <typename Data>
inline bool QueueVec<Data>::Empty() const noexcept {
    return (head == tail);
}

template <typename Data>
inline ulong QueueVec<Data>::Size() const noexcept {
    if(head <= tail){
        return (tail-head); 
    }
    else{
        return (size-head)+tail;
    }
}

template <typename Data>
inline void QueueVec<Data>::Clear() {
    //
}

template <typename Data>
inline void QueueVec<Data>::Expand() {
    //
}

template <typename Data>
inline void QueueVec<Data>::Reduce() {
    //
}    

/* ************************************************************************** */

}
