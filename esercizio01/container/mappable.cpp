
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline void MappableContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    Map([fun, ret](const Data& dat){
        fun(dat, ret);
    });
} // Override FoldableContainer member

template<typename Data>
inline void PreOrderMappableContainer<Data>::Map(MapFunctor fun) const {
    PreOrderMap(fun);
}

template<typename Data>
inline void PreOrderMappableContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    PreOrderFold(fun, ret);
}

template<typename Data>
inline void PreOrderMappableContainer<Data>::PreOrderFold(FoldFunctor fun, void * ret) const {
    PreOrderMap([fun, ret](const Data& dat){
        fun(dat, ret);
    });
}

template<typename Data>
inline void PostOrderMappableContainer<Data>::Map(MapFunctor fun) const {
    PostOrderMap(fun);
}

template<typename Data>
inline void PostOrderMappableContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    PostOrderFold(fun, ret);
}

template<typename Data>
inline void PostOrderMappableContainer<Data>::PostOrderFold(FoldFunctor fun, void * ret) const {
    PostOrderMap([fun, ret](const Data& dat){
        fun(dat, ret);
    });
}

template<typename Data>
inline void InOrderMappableContainer<Data>::Map(MapFunctor fun) const {
    InOrderMap(fun);
}

template<typename Data>
inline void InOrderMappableContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    InOrderFold(fun, ret);
}

template<typename Data>
inline void InOrderMappableContainer<Data>::InOrderFold(FoldFunctor fun, void * ret) const {
    InOrderMap([fun, ret](const Data& dat){
        fun(dat, ret);
    });
}

template<typename Data>
inline void BreadthMappableContainer<Data>::Map(MapFunctor fun) const {
    BreadthMap(fun);
}

template<typename Data>
inline void BreadthMappableContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    BreadthFold(fun, ret);
}

template<typename Data>
inline void BreadthMappableContainer<Data>::BreadthFold(FoldFunctor fun, void * ret) const {
    BreadthMap([fun, ret](const Data& dat){
        fun(dat, ret);
    });
}

template<typename Data>
inline void MutablePreOrderMappableContainer<Data>::Map(MutableMapFunctor fun) {
    PreOrderMap(fun);
}

template<typename Data>
inline void MutablePostOrderMappableContainer<Data>::Map(MutableMapFunctor fun) {
    PostOrderMap(fun);
}

template<typename Data>
inline void MutableInOrderMappableContainer<Data>::Map(MutableMapFunctor fun) {
    InOrderMap(fun);
}

template<typename Data>
inline void MutableBreadthMappableContainer<Data>::Map(MutableMapFunctor fun) {
    BreadthMap(fun);
}

/* ************************************************************************** */

}
