
namespace lasd {

/* ************************************************************************** */

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(){
    tablesize = MIN_TABLESIZE;
    
    a = 2*(dista(gen))+1;
    b = 2*(distb(gen));

    table.Resize(tablesize);
    statvec.Resize(tablesize);

    for(unsigned long i=0; i<tablesize; ++i) {
        statvec[i] = EMPTY;
    }

    capacity = (size/tablesize) * 100;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long s){
    tablesize = NextPowerOf2To(s);

    a = 2*(dista(gen))+1;
    b = 2*(distb(gen));
    
    table.Resize(tablesize);
    statvec.Resize(tablesize);

    for(unsigned long i=0; i<tablesize; ++i) {
        statvec[i] = EMPTY;
    }

    capacity = (size/tablesize)*100;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const MappableContainer<Data>& con) : HashTableOpnAdr() {
    InsertAll(con);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long s, const MappableContainer<Data>& con) : HashTableOpnAdr(s) {
    InsertAll(con);
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(MutableMappableContainer<Data>&& con) : HashTableOpnAdr() {
    InsertAll(std::move(con));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(unsigned long s, MutableMappableContainer<Data>&& con) : HashTableOpnAdr(s) {
    InsertAll(std::move(con));
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(const HashTableOpnAdr<Data>& ht) {
    size = ht.size;
    tablesize = ht.tablesize;
    a = ht.a;
    b = ht.b;
    table = ht.table;
    statvec = ht.statvec;
    capacity = ht.capacity;
}

template <typename Data>
HashTableOpnAdr<Data>::HashTableOpnAdr(HashTableOpnAdr<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(table, ht.table);
    std::swap(statvec, ht.statvec);
    std::swap(capacity, ht.capacity);
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(const HashTableOpnAdr<Data>& ht) {
    HashTableOpnAdr<Data>* temp = new HashTableOpnAdr(ht);
    std::swap(*this, *temp);
    delete temp;
    return *this;
}

template <typename Data>
HashTableOpnAdr<Data>& HashTableOpnAdr<Data>::operator=(HashTableOpnAdr<Data>&& ht) noexcept {
    std::swap(size, ht.size);
    std::swap(tablesize, ht.tablesize);
    std::swap(a, ht.a);
    std::swap(b, ht.b);
    std::swap(table, ht.table);
    std::swap(statvec, ht.statvec);
    std::swap(capacity, ht.capacity);
    return *this;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator==(const HashTableOpnAdr<Data>& ht) const noexcept {
    if(size == ht.size) {
        for(unsigned long i = 0; i<tablesize; ++i){
            if(statvec[i] == FULL){
                if(!(ht.Exists(table[i]))){
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::operator!=(const HashTableOpnAdr<Data>& ht) const noexcept {
    return !(*this == ht);
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(const Data& dat) {
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
    if((capacity) > 75) {
        Resize(2*tablesize+1);
    }
    if(!Exists(dat)) {
        unsigned long index = FindEmpty(dat, 0);
        if(index < tablesize) {
            unsigned long pos = HashKey(dat, index);
            if(statvec[pos] == EMPTY || statvec[pos] == REMOVED) {
                table[pos] = dat;
                statvec[pos] = FULL;
                
                ++size;
                return true;
            }
        }
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Insert(Data&& dat) noexcept {
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
    if(capacity > 75){
        Resize(2*tablesize+1);
    }
    if(!Exists(dat)){
        unsigned long index = FindEmpty(dat, 0);
        if(index < tablesize) {
            unsigned long pos = HashKey(dat, index);
            if(statvec[pos] == EMPTY || statvec[pos] == REMOVED) {
                table[pos] = std::move(dat);
                statvec[pos] = FULL;
                
                ++size;
                return true;
            }
        }
    }
    return false;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& dat) {
    capacity = (static_cast<double>(size)/static_cast<double>(tablesize))*100;
    bool res = Remove(dat, 0);
    if(capacity < 10) {
        Resize((tablesize/2)-1);
    }
    return res;
}

template <typename Data>
bool HashTableOpnAdr<Data>::Exists(const Data& dat) const noexcept {
    if(size != 0) {
        unsigned long index = Find(dat, 0);   
        if(index < tablesize) {
            unsigned long pos = HashKey(dat, index);
            if(statvec[pos] == FULL && table[pos] == dat) {
                return true;
            }
        }
    }
    return false;
}

template <typename Data>
void HashTableOpnAdr<Data>::Resize(unsigned long siz) {
    unsigned long newsize;
    if(!IsResizable(siz)) {
        return;
    }
    newsize = NextPowerOf2To(siz);
    if(newsize == tablesize) {
        return;
    }
    HashTableOpnAdr<Data>* temp = new HashTableOpnAdr<Data>(newsize);
    for(unsigned long i=0; i<tablesize; i++) {
        if(statvec[i] == FULL) {
            temp->Insert(table[i]);
        }
    }
    std::swap(*this, *temp);
    delete temp;
}

template <typename Data>
void HashTableOpnAdr<Data>::Clear() {
    tablesize = MIN_TABLESIZE;
    size = 0;
    table.Clear();
    table.Resize(tablesize);
    statvec.Resize(tablesize);
    for(unsigned long i = 0; i<tablesize; i++) {
        statvec[i] = EMPTY;
    }
    
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::HashKey(const Data& dat, unsigned long index) const noexcept {
    unsigned long key = hash(dat);
    return ((HashTable<Data>::HashKey(key)+index)%tablesize);
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::Find(const Data& dat, unsigned long index) const noexcept {
    unsigned long start = HashKey(dat, index);
    ulong collision = 0;
    while(index < tablesize) {
        if(table[start] == dat) {
            return index;
        }
        if(statvec[start] ==EMPTY) {
            return tablesize;
        }

        ++collision;
        ++index;

        start = HashKey(dat, index);
    }
    return index;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::FindEmpty(const Data& dat, unsigned long index) const noexcept {
    unsigned long start = HashKey(dat, index);
    ulong collision = 0;
    while(index < tablesize) {
        if(statvec[start] == EMPTY || statvec[start] == REMOVED) {
            return index;
        }

        ++collision;
        ++index;

        start = HashKey(dat, index);
    }
    return index;
}    

template <typename Data>
bool HashTableOpnAdr<Data>::Remove(const Data& dat, unsigned long index) {
    if(size > 0) {
        unsigned long idx = Find(dat, index);
        if(idx < tablesize) {
            unsigned long pos = HashKey(dat, idx);  
                if(statvec[pos] == FULL && table[pos] == dat) {
                statvec[pos] = REMOVED;
                size--;
                return true;
            }
        }
    }
    return false;
}

template <typename Data>
unsigned long HashTableOpnAdr<Data>::NextPowerOf2To(unsigned long s) const noexcept {
    unsigned long newsize = MIN_TABLESIZE;
    while(newsize < s) {
        if(newsize >= MAX_TABLESIZE) {
            break;   
        }
        newsize = newsize << 1;
    } 
    return newsize;
}

template <typename Data>
bool HashTableOpnAdr<Data>::IsResizable(unsigned long siz) const noexcept {
    if(siz > tablesize) {
        return true;
    } else {
        if(siz == tablesize) {
            return false;
        }
        ulong cap = (static_cast<double>(size)/static_cast<double>(siz))*100;
        if(cap < 75) {
            return true;
        }
        return false;
    } 

}

/* ************************************************************************** */

}
