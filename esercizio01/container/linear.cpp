
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer& con) const noexcept{
    if(size == con.Size()){
        for(ulong i=0; i<size; ++i){
            if(operator[](i) != con.operator[](i)){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
    
}

template<typename Data>
inline bool LinearContainer<Data>::operator==(const LinearContainer& con) const noexcept{
    if(size == con.Size()){
        for(ulong i=0; i<size; ++i){
            if(operator[](i) != con.operator[](i)){
                return true;
            }
        }
        return false;
    }
    else{
        return true;
    }
    
}

template<typename Data>
inline const Data& LinearContainer<Data>::Front() const {
    if(size == 0){
        throw std::length_error;
    }
    return operator[](0);
}

template<typename Data>
inline Data& LinearContainer<Data>::Front() {
    if(size == 0){
        throw std::length_error;
    }
    return operator[](0);
}

template<typename Data>
inline const Data& LinearContainer<Data>::Back() const {
    if(size == 0){
        throw std::length_error;
    }
    return operator[](0);
}

template<typename Data>
inline Data& LinearContainer<Data>::Back() {
    if(size == 0){
        throw std::length_error;
    }
    return operator[](0);
}

template<typename Data>
inline void LinearContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    PreOrderFold(fun, ret);
}

template<typename Data>
inline void LinearContainer<Data>::PreOrderFold(FoldFunctor fun, void * ret) const {
    for(int i=0; i<size; ++i){
        fun(operator[](i), ret);
    }
}

template<typename Data>
inline void LinearContainer<Data>::PostOrderFold(FoldFunctor fun, void * ret) const {
    for(int i=size-1; i>=0; --i){
        fun(operator[](i), ret);
    }
}

template<typename Data>
inline void LinearContainer<Data>::Map(MapFunctor fun) const {
    PreOrderMap(fun);
}

template<typename Data>
inline void LinearContainer<Data>::PreOrderMap(MapFunctor fun) const {
    for(int i=0; i<size; ++i){
        fun(operator[](i));
    }
}

template<typename Data>
inline void LinearContainer<Data>::PostOrderMap(MapFunctor fun) const {
    for(int i=size-1; i>=0; ++i){
        fun(operator[](i));
    }
}

template<typename Data>
inline void LinearContainer<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun);
}

template<typename Data>
inline void LinearContainer<Data>::PreOrderMap(MutableMapFunctor fun) {
    for(int i=0; i<size; ++i){
        fun(operator[](i));
    }
}

template<typename Data>
inline void LinearContainer<Data>::PostOrderMap(MutableMapFunctor fun) {
    for(int i=size-1; i>=0; ++i){
        fun(operator[](i));
    }
}

template<typename Data>
inline bool SortableLinearContainer<Data>::operator==(const SortableLinearContainer& con) const noexcept {
    if(size == con.Size()){
        for(ulong i=0; i<size; ++i){
            if(operator[](i) != con.operator[](i)){
                return false;
            }
        }
        return true;
    }
    else{
        return false;
    }
}

template<typename Data>
inline bool SortableLinearContainer<Data>::operator!=(const SortableLinearContainer& con) const noexcept {
    if(size == con.Size()){
        for(ulong i=0; i<size; ++i){
            if(operator[](i) != con.operator[](i)){
                return true;
            }
        }
        return false;
    }
    else{
        return true;
    }
}

/* ************************************************************************** */

}
