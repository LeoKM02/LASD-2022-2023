
namespace lasd {

/* ************************************************************************** */

template<typename Data>
QueueLst<Data>::QueueLst(const MappableContainer<Data>& con){
    List<Data>::List(con);
}

template<typename Data>
QueueLst<Data>::QueueLst(MutableMappableContainer<Data>&& con) noexcept {
    List<Data>::List(std::move(con));
}

template<typename Data>
QueueLst<Data>::QueueLst(const QueueLst& con){
    List<Data>::List(con);
}

template<typename Data>
QueueLst<Data>::QueueLst(QueueLst&& con) noexcept {
    List<Data>::List(std::move(con));
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(const QueueLst& con){
    List<Data>::operator=(con);
    return *this;
}

template<typename Data>
QueueLst<Data>& QueueLst<Data>::operator=(QueueLst&& con) noexcept{
    List<Data>::operator=(std::move(con));
    return *this;
}

template<typename Data>
inline bool QueueLst<Data>::operator==(const QueueLst& con) const noexcept{
    return List<Data>::operator==(con);
}

template<typename Data>
inline bool QueueLst<Data>::operator!=(const QueueLst& con) const noexcept{
    return List<Data>::operator!=(con);
}

template<typename Data>
inline const Data& QueueLst<Data>::Head() const{
    return Front();
}

template<typename Data>
inline Data& QueueLst<Data>::Head() {
    return Front();
}

template<typename Data>
inline void QueueLst<Data>::Dequeue() {
    RemoveFromFront();
}

template<typename Data>
inline Data QueueLst<Data>::HeadNDequeue() {
    return FrontNRemove();
}

template<typename Data>
inline void QueueLst<Data>::Enqueue(const Data& dat) {
    InsertAtBack(dat);
}

template<typename Data>
inline void QueueLst<Data>::Enqueue(Data&& dat) noexcept {
    InsertAtBack(dat);
}

/* ************************************************************************** */

}
