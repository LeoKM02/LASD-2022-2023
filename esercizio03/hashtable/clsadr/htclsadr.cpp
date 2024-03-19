
namespace lasd {

/* ************************************************************************** */

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(){
    table = new BST<Data>[tablesize]{};
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long s){
    if(s <= MIN_TABLESIZE) {
        s = MIN_TABLESIZE;
    }
    else if(s >= MAX_TABLESIZE) {
        s = MAX_TABLESIZE;
    }
    else{
        s = NextPrimeTo(s);   
    }

    tablesize = s;
    table = new BST<Data>[tablesize]{};
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const MappableContainer<Data>& con): HashTableClsAdr(){
    InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long s, const MappableContainer<Data>& con): HashTableClsAdr(s){
    InsertAll(con);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(MutableMappableContainer<Data>&& con): HashTableClsAdr(){
    InsertAll(std::move(con));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(unsigned long s, MutableMappableContainer<Data>&& con): HashTableClsAdr(s){
    InsertAll(std::move(con));
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(const HashTableClsAdr<Data>& ht): HashTable<Data>(ht){
    table = new BST<Data>[tablesize]{};
    std::copy(ht.table, ht.table+tablesize, table);
}

template <typename Data>
HashTableClsAdr<Data>::HashTableClsAdr(HashTableClsAdr<Data>&& ht) noexcept: HashTable<Data>(std::move(ht)){
    std::swap(table, ht.table);
}

template <typename Data>
HashTableClsAdr<Data>::~HashTableClsAdr(){
    delete[] table;
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(const HashTableClsAdr<Data>& ht){
    HashTableClsAdr<Data>* temp = new HashTableClsAdr<Data>(ht);
    std::swap(*this, *temp);
    delete temp;
    return *this;
}

template <typename Data>
HashTableClsAdr<Data>& HashTableClsAdr<Data>::operator=(HashTableClsAdr<Data>&& ht) noexcept{
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(table, ht.table);

    return *this;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator==(const HashTableClsAdr<Data>& ht) const noexcept{
    if(size == ht.size){
        for(unsigned long i=0; i<tablesize; ++i){
            if(!(table[i].Empty())){
                BTInOrderIterator<Data> iter(table[i]);

                while(!(iter.Terminated())){
                    if(!(ht.Exists(iter.operator*()))){
                        return false;
                    }
                    iter.operator++();
                }
            }
        }
        return true;
    }
    return false;
}

template <typename Data>
bool HashTableClsAdr<Data>::operator!=(const HashTableClsAdr<Data>& ht) const noexcept{
    return !(*this == ht);
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(const Data& dat){
    unsigned long key = HashKey(hash(dat));

    if(table[key].Insert(dat)){
        ++size;
        return true;
    }

    return false;
}

template <typename Data>
bool HashTableClsAdr<Data>::Insert(Data&& dat) noexcept{
    unsigned long key = HashKey(hash(dat));

    if(table[key].Insert(std::move(dat))){
        ++size;
        return true;
    } 

    return false;
}

template <typename Data>
bool HashTableClsAdr<Data>::Remove(const Data& dat){
    unsigned long key = HashKey(hash(dat));

    if(table[key].Remove(dat)){
        --size;
        return true;
    } 

    return false;
}

template <typename Data>
bool HashTableClsAdr<Data>::Exists(const Data& dat) const noexcept{
    unsigned long key = HashKey(hash(dat));
    return table[key].Exists(dat);
}

template <typename Data>
void HashTableClsAdr<Data>::Resize(unsigned long s){

    HashTableClsAdr<Data>* temp = new HashTableClsAdr<Data>(s);
    
    for(unsigned long i = 0; i<tablesize; ++i){
        if(!(table[i].Empty())){
            BTInOrderIterator<Data> iter(table[i]);
            
            while(!(iter.Terminated())){
                Data dat = iter.operator*();
                temp->Insert(dat);
                iter.operator++();
            }

        }        
    }

    std::swap(*temp, *this);
    delete temp;
}

template <typename Data>
void HashTableClsAdr<Data>::Clear() {
    size = 0;
    delete[] table;
    table = new BST<Data>[tablesize]{};
}

template <typename Data>
unsigned long HashTableClsAdr<Data>::NextPrimeTo(unsigned long num) const noexcept{

    for(unsigned long i = 2; i <= num/2; ++i){
        if(num%i == 0){
            ++num;
            i = 2;
        }
    }

    return num;
}

/* ************************************************************************** */

}
