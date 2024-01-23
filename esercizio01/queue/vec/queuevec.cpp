
namespace lasd {

/* ************************************************************************** */

template <typename Data>
QueueVec<Data>::QueueVec() {
    Vector<Data>(DEFAULT_CAPACITY);
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
QueueVec<Data>::QueueVec(const QueueVec& con) : Vector<Data>::Vector(con) {
    head = con.head;
    tail = con.tail;
    sentinel = con.sentinel;
}

template <typename Data>
QueueVec<Data>::QueueVec(QueueVec&& con) noexcept : Vector<Data>::Vector(con) {
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
    if(Empty()){
        throw std::length_error("Empty container!");
    }
    return elements[head];
}

template <typename Data>
inline Data& QueueVec<Data>::Head() {
    if(Empty()){
        throw std::length_error("Empty container!");
    }
    return elements[head];
}

template <typename Data>
inline void QueueVec<Data>::Dequeue() {
    if(Empty()){
        throw std::length_error("Empty container!");
    }

    Reduce();
    sentinel = head;
    head = (head+1)%size;
}

template <typename Data>
inline Data QueueVec<Data>::HeadNDequeue() {
    if(Empty()){
        throw std::length_error("Empty container!");
    }

    Data temp = Head();
    Dequeue();
    return temp;
}

template <typename Data>
inline void QueueVec<Data>::Enqueue(const Data& dat) {
    Expand();
    elements[tail] = dat;
    tail = (tail+1)%size;

}

template <typename Data>
inline void QueueVec<Data>::Enqueue(Data&& dat) noexcept {
    Expand();
    elements[tail]= std::move(dat);
    tail = (tail+1)%size;

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
    Vector<Data>::Clear();
    size = DEFAULT_CAPACITY;
    elements = new Data[size]{};
    head = 0;
    tail = 0;
    sentinel = size - 1;
}

template <typename Data>
inline void QueueVec<Data>::Expand() {
    if(sentinel == tail){
        if(head <= tail){
            Vector<Data>::Resize(size*2);
            sentinel = (head-1)%size;
        }
        else{
            ulong newsize = size*2;

            Data* temp = new Data[newsize] {};
            ulong i, j;
            for(i=head, j=0; i!=tail; i=(i+1)%size, ++j){
                std::swap(elements[i], temp[j]);
            }
            std::swap(elements, temp);
            delete[] temp;

            size = newsize;
            head = 0;
            tail = j;
            sentinel = size-1;
            
        }
    }
}

template <typename Data>
inline void QueueVec<Data>::Reduce() {
    if(Size() <= size/4){
        ulong newsize = size/2;

        Data* temp = new Data[newsize] {};
        ulong i, j;
        for(i=head, j=0; i!=tail; i=(i+1)%size, ++j){
            std::swap(elements[i], temp[j]);
        }
        std::swap(elements, temp);
        delete[] temp;

        size = newsize;
        head = 0;
        tail = j;
        sentinel = size-1;
    }
}    

/* ************************************************************************** */

}
