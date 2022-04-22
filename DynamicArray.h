#pragma once

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<initializer_list>
#include"exception.h"

using namespace std;

template<class T>
class DynamicArray{
    private:
        T* ArrayPtr = nullptr;
        int countItems = 0;
    public:
        DynamicArray();
        DynamicArray(T* items , int count);
        DynamicArray(const DynamicArray<T> &ObjectFromCopy);
        DynamicArray(initializer_list<T> list){
            int size = list.size();
            this -> ArrayPtr = new T[size];
            this -> countItems = size;
            int count = 0;
            for (auto element:list){
                this -> ArrayPtr[count] = element;
                ++count;
            }
        }
        T GetFirst();
        T GetLast();
        DynamicArray<T>* GetSubList(int startIndex , int endIndex);
        DynamicArray<T>* Concat(DynamicArray<T>* list);
        T Get(int index);
        int GetSize();
        void Set(int index , T value);
        void Resize(int newSize);
        void Append(T item);
        void Prepend(T item);
        void InsertAt(T item , int index);
        void DeleteStart();
        void DeleteEnd();
        DynamicArray<T>& operator=(const DynamicArray<T>& Arr);
        bool operator==(const DynamicArray<T> &obj1){
            if(this -> countItems != obj1.countItems){
                return false;
            }
            else{
                for(int i = 0; i < this -> countItems; ++i){
                    if(this -> ArrayPtr[i] != obj1.ArrayPtr[i]){
                        return false;
                    }
                }
                return true;
            }
        }
        bool operator!=(const DynamicArray<T>& obj){
            return !(*this == obj);
        }
        void Print();
        ~DynamicArray();
        T operator[](int index);
        int rfind(T* subSeq, size_t size);
};

template<class T> DynamicArray<T>::DynamicArray(){
    this -> ArrayPtr = nullptr;
    this -> countItems = 0;
}
template<class T> DynamicArray<T>::DynamicArray(T* items , int count){
    this -> countItems = count;
    this -> ArrayPtr = new T[count];
    memcpy(this -> ArrayPtr , items , count * sizeof(T));
}
template<class T> DynamicArray<T>::DynamicArray(const DynamicArray<T>& ObjectFromCopy){
    this -> countItems = ObjectFromCopy.countItems;
    this -> ArrayPtr = new T[countItems];
    memcpy(this -> ArrayPtr , ObjectFromCopy.ArrayPtr , (this -> countItems) * sizeof(T));
}
template<class T> T DynamicArray<T>::GetFirst(){
    if(this-> ArrayPtr == nullptr || this -> countItems == 0){
        throw ExceptionError(1);
    }
    return this -> ArrayPtr[0];
}
template<class T> T DynamicArray<T>::GetLast(){
    if(this-> ArrayPtr == nullptr || this -> countItems == 0){
        throw ExceptionError(1);
    }
    return this -> ArrayPtr[countItems - 1];
}
template<class T> DynamicArray<T>* DynamicArray<T>:: GetSubList(int startIndex , int endIndex){
    if(startIndex < 0 || endIndex < 0 || endIndex > this -> countItems){
        throw ExceptionError(1);
    }
    DynamicArray<T>* resStr = new DynamicArray<T> ;
    resStr -> countItems = endIndex - startIndex + 1;
    resStr -> ArrayPtr = new T[endIndex - startIndex + 1];
    memcpy(resStr-> ArrayPtr , &(this -> ArrayPtr[startIndex]), (endIndex -startIndex +1)*sizeof(T));
    return resStr;
}
template<class T> DynamicArray<T>* DynamicArray<T>:: Concat(DynamicArray<T>* list){
    DynamicArray<T>* resArr = new DynamicArray<T>;
    resArr -> countItems = (this -> countItems) + (list -> countItems);
    resArr -> ArrayPtr = new T[resArr-> countItems];
    for(int i = 0; i < countItems; ++i){
        resArr->ArrayPtr[i] = this -> ArrayPtr[i];
        }
    for(int i = 0; i < (list -> countItems); ++i){
        resArr->ArrayPtr[i + countItems] = list-> ArrayPtr[i];
    }
    return resArr;
}
template<class T> T DynamicArray<T>:: Get(int index){
    if(index > this -> GetSize() || index < 0){
        throw ExceptionError(1);
    }
    return this -> ArrayPtr[index];
}
template<class T> int DynamicArray<T>:: GetSize(){
    if(!ArrayPtr || countItems == 0){
        return 0;
    }
    else{
        return countItems;
    }
}
template<class T> void DynamicArray<T>::Set(int index , T value){
    if(index < 0 || index > this -> GetSize()){
        throw ExceptionError(1);
    }
    this -> ArrayPtr[index] = value;
}
template<class T> void DynamicArray<T>::Resize(int newSize){
    if(newSize < 0){
        cout << "SizeOutOfRange" << '\n';
        exit(0);
    }
    T* buffer = new T[countItems];
    memcpy(buffer ,ArrayPtr , countItems * sizeof(T));
    delete [] ArrayPtr;
    ArrayPtr = new T[newSize];
    memcpy(ArrayPtr , buffer , countItems * sizeof(T));
    delete [] buffer;
}
template<class T> void DynamicArray<T>::Append(T item){
    countItems += 1;
    T* buffer = new T[countItems];
    memcpy(buffer , ArrayPtr , (countItems-1)*sizeof(T));
    buffer[countItems - 1] = item;
    delete [] ArrayPtr;
    ArrayPtr = new T[countItems];
    memcpy(ArrayPtr , buffer , countItems*sizeof(T));
    delete [] buffer;
}
template<class T> void DynamicArray<T>::Prepend(T item){
    countItems += 1;
    T* buffer = ArrayPtr;
    ArrayPtr = new T[countItems];
    ArrayPtr[0] = item;
    memcpy(&ArrayPtr[1] , buffer , (countItems - 1)*sizeof(T));
    delete [] buffer;
}
template<class T> void DynamicArray<T>::InsertAt(T item , int index){
    countItems += 1;
    T* buffer = ArrayPtr;
    ArrayPtr = new T[countItems];
    memcpy(ArrayPtr , buffer , index * sizeof(T));
    ArrayPtr[index] = item;
    memcpy(&ArrayPtr[index+1] , &buffer[index] , (countItems-index - 1) * sizeof(T));
    delete [] buffer;
}
template<class T> void DynamicArray<T>::DeleteStart(){
    if(!ArrayPtr){
        return;
    }
    countItems -= 1;
    T* buffer = this -> ArrayPtr;
    this -> ArrayPtr = new T[countItems];
    memcpy(this -> ArrayPtr , buffer , (this -> countItems)*sizeof(T));
    delete[] buffer;
}
template<class T> void DynamicArray<T>::DeleteEnd(){
    countItems -= 1;
    T* buffer = this -> ArrayPtr;
    this -> ArrayPtr = new T[countItems];
    memcpy(this -> ArrayPtr , &buffer[1] , (this -> countItems)*sizeof(T));
    delete[] buffer;
}
template<class T> DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& Arr){
    if(ArrayPtr){
        delete [] ArrayPtr;
    }
    countItems = Arr.countItems;
    ArrayPtr = new T[countItems];
    memcpy(ArrayPtr , Arr.ArrayPtr , countItems*sizeof(T));
    return *this;
}
template<class T> void DynamicArray<T>::Print(){
    for(int i = 0 ; i < countItems; ++i){
        cout << ArrayPtr[i] << ' ';
    }
}
template<class T> DynamicArray<T>::~DynamicArray(){
    delete [] ArrayPtr;
}
template<class T> T DynamicArray<T>::operator[](int index){
    return this -> ArrayPtr[index];
}
template<class T> int DynamicArray<T>::rfind(T* subSeq, size_t size) {
    int k = 1;
    map<T, int> table;
    for (int i = size - 2; i >= 0; i--) {
        if (table.find(subSeq[i]) == table.end()) {
            table.emplace(subSeq[i], size - 2 - i + 1);
        }
    }
    if (table.find(subSeq[size - 1]) == table.end()) {
        table.emplace(subSeq[size - 1], size);
    }
    int curPos = size - 1;
    int countCoin = 0;
    int fullLength = this->GetSize();
    while (curPos < fullLength) {
        if (this->ArrayPtr[curPos] == subSeq[size - 1]) {
            for (int i = curPos - size + 1; i < curPos; ++i) {
                    if (this->ArrayPtr[i] == subSeq[i - curPos + size - 1]) {
                        countCoin++;
                    }
            }
            if (countCoin == size - 1) {
                return curPos - size + 2;
            }
            curPos++;
            countCoin = 0;
        }
        else {
            auto iter = table.find(this->ArrayPtr[curPos]);
            if (iter == table.end()) {
                curPos = curPos + size;
            }
            else {
                curPos = curPos + iter->second;
            }
        }
    }
    return 0;
}