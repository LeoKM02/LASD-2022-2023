
#include <stdexcept>

/* ************************************************************************** */

namespace lasd {

/* ************************************************************************** */

template<typename Data>
inline bool FoldableContainer<Data>::Exists(const Data& d1) const noexcept {
    Data dcopy = d1;
    bool ret = false;
    Fold([&dcopy](const Data& d2, void * r){
        if(dcopy == d2){
            *(static_cast<bool*>(r)) = true;
        }
    }, &ret);
    return ret;
}

template<typename Data>
inline void PreOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    PreOrderFold(fun, ret);
}

template<typename Data>
inline void PostOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    PostOrderFold(fun, ret);
}

template<typename Data>
inline void InOrderFoldableContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    InOrderFold(fun, ret);
}

template<typename Data>
inline void BreadthFoldableContainer<Data>::Fold(FoldFunctor fun, void * ret) const {
    BreadthFold(fun, ret);
}

/* ************************************************************************** */

}
