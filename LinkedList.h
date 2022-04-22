#pragma once

#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include"exception.h"

using namespace std;

template<class T>
class LinkedList{
    private:
        struct ListItem{
            T itemData;
            ListItem* next = nullptr;
        };
        ListItem* listHead = nullptr;
        ListItem* listTail = nullptr;
    public:
        LinkedList();
        LinkedList(T* items , int count);
        LinkedList(const LinkedList<T> &ObjectFromCopy);
        LinkedList(initializer_list<T> list){
            int size = list.size();
            T* items = new T[size];
            int count = 0;
            for(auto element:list){
                items[count] = element;
                ++count;
            }
            for(int i = 0; i < size; ++i){
                ListItem* curItem = new ListItem;
                curItem -> next = nullptr;
                curItem -> itemData = items[i];
                if(i == 0){
                    this -> listHead = curItem;
                    this -> listTail = curItem; 
                }
                else{
                    this -> listTail -> next = curItem;
                    this -> listTail = curItem;
                }   
            }
            delete[] items;
        };
        T GetFirst();
        T GetLast();
        T Get(int index);
        LinkedList<T>* GetSubList(int startIndex , int endIndex);
        int GetSize();
        void DeleteStart();
        void DeleteEnd();
        void Append(T item);
        void Prepend(T item);
        void InsertAt(T item , int index);
        LinkedList<T>* Concat(LinkedList<T> *list);
        void Print();
        ~LinkedList();
        T operator[](int index);
        bool operator==(const LinkedList& obj){
            int size1 = this -> GetSize();
            int size2 = this -> GetSize();
            if(size1 != size2){
                return false;
            }
            ListItem* curItem1 = this -> listHead;
            ListItem* curItem2 = obj.listHead;
            while(curItem1){
                if(curItem1 -> itemData != curItem2 -> itemData){
                    return false;
                }
                curItem1 = curItem1 -> next;
                curItem2 = curItem2 -> next;
            }
            return true;
        }
        bool operator!=(const LinkedList& obj){
            return !(*this == obj);
        }
        int rfind(T* subSeq, size_t size);
};

template<class T> LinkedList<T>::LinkedList(){
    listHead =nullptr;
    listTail = nullptr;
}
template<class T> LinkedList<T>::LinkedList(T* items , int count){
    for(int i = 0; i < count ; i++){
        ListItem* newItem = new ListItem;
        newItem -> itemData = items[i];
        if(listHead == nullptr){
            listHead = newItem;
            listTail = listHead;
        }
        else{
            listTail -> next = newItem;
            listTail = listTail -> next;
        }
    }
}
template<class T> LinkedList<T>::LinkedList(const LinkedList<T> &ObjectFromCopy){
    ListItem* curItem = ObjectFromCopy.listHead;
    while(curItem){
        ListItem* newItem = new ListItem;
        newItem -> itemData = curItem -> itemData;
        if(listHead == nullptr){
            listHead = newItem;
            listTail = newItem;
        }
        else{
            listTail -> next = newItem;
            listTail = listTail -> next;
        }
        curItem = curItem -> next;
    }
}
template<class T> T LinkedList<T>::GetFirst(){
    if(listHead == nullptr){
        throw ExceptionError(1);
    }
    return listHead -> itemData;
}
template<class T> T LinkedList<T>::GetLast(){
    if(listHead == nullptr){
        throw ExceptionError(1);
    }
    return listTail -> itemData;
}
template<class T> T LinkedList<T>::Get(int index){
    if(index < 0 || index > this -> GetSize()){
        throw ExceptionError(1);
    }
    ListItem* curItem = listHead;
    for(int i = 0; i < index ; i++){
        curItem = curItem -> next;
    }
    return curItem -> itemData;
}
template<class T> LinkedList<T>* LinkedList<T>::GetSubList(int startIndex , int endIndex){
    if(startIndex < 0 || endIndex < 0 || endIndex > this -> GetSize()){
        throw ExceptionError(1);
    }
    LinkedList<T>* resListPtr = new LinkedList<T>;
    ListItem* curItem = listHead;
    for(int i = 0; i < startIndex;++i){curItem = curItem->next;}
    for(int j = 0; j < endIndex - startIndex + 1; ++j){
        ListItem* newItem = new ListItem;
        newItem -> itemData = curItem -> itemData;
        if(resListPtr->listHead == nullptr){
            resListPtr->listHead  = newItem;
            resListPtr->listTail = newItem;
        }
        else{
            resListPtr->listTail -> next = newItem;
            resListPtr->listTail = newItem;
        }
        curItem = curItem -> next;
    }
    return resListPtr;
}
template<class T> int LinkedList<T>::GetSize(){
    if(this -> listHead == nullptr){
        return 0;
    }
    int length = 0;
    ListItem* curItem = listHead;
    while(curItem){
        length++;
        curItem = curItem -> next;
    }
    return length;
}
template<class T> void LinkedList<T>::DeleteStart(){
    if(this -> listHead == nullptr){
        throw ExceptionError(1);
    }
    ListItem* cur = this -> listHead;
    while(cur -> next != this -> listTail){
        cur = cur -> next;
    }
    delete listTail;
    this -> listTail = cur;
    this -> listTail -> next = nullptr;
}
template<class T> void LinkedList<T>::DeleteEnd(){
    if(this -> listHead == nullptr){
        throw ExceptionError(1);
    }
    ListItem* cur = this -> listHead;
    listHead = listHead -> next;
    delete cur;
}
template<class T> void LinkedList<T>::Append(T item){
    ListItem* newItem = new ListItem;
    newItem -> itemData = item;
    if(listHead == nullptr){
        listHead = newItem;
        listTail = newItem;
    }
    else{
        listTail -> next = newItem;
        listTail = newItem;
    }
}
template<class T> void LinkedList<T>::Prepend(T item){
    ListItem* newItem = new ListItem;
    newItem ->itemData = item;
    if(listHead == nullptr){
        listHead = newItem;
        listTail = newItem;
    }
    else{
        newItem -> next = listHead;
        listHead = newItem;
    }
}
template<class T> void LinkedList<T>::InsertAt(T item , int index){
    if(index < 0){
        cout << "IndexOutOfRange\n";
        exit(0);
    }
    ListItem* newItem = new ListItem;
    newItem -> itemData = item;
    ListItem* curItem = listHead;
    for(int i = 0; i < index - 1; ++i){
        curItem = curItem -> next;    
    }
    newItem -> next = curItem -> next;
    curItem-> next = newItem;
}
template<class T> LinkedList<T>* LinkedList<T>::Concat(LinkedList<T> *list){
    LinkedList<T>* newList = new LinkedList<T>(*this);
    ListItem* curItem = list -> listHead;
    while(curItem){
        ListItem* newItem = new ListItem;
        newItem -> next = nullptr;
        newItem -> itemData = curItem -> itemData;
        if(newList -> listHead == nullptr){
            newList -> listHead = newItem;
            newList -> listTail = newItem;
        }
        else{
            newList -> listTail -> next = newItem;
            newList -> listTail = newItem;
        }
        curItem = curItem -> next;
    }
    return newList;
}
template<class T> void LinkedList<T>::Print(){
    ListItem* cur = listHead;
    while(cur){
        cout << cur -> itemData;
        cur = cur -> next;
    }
}
template<class T> LinkedList<T>::~LinkedList(){
    ListItem* curItem = nullptr;
    while(listHead){
        curItem = listHead;
        listHead = listHead -> next;
        delete curItem;
    }
}
template<class T> T LinkedList<T>::operator[](int index){
    ListItem* cur = this -> listHead;
    for(int i = 0; i < index ; ++i){
        cur = cur -> next;
    }
    return cur -> itemData;
}
template<class T> int LinkedList<T>::rfind(T* subSeq, size_t size) {
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
        if ((*this)[curPos] == subSeq[size - 1]) {
            for (int i = curPos - size + 1; i < curPos; ++i) {
                if ((*this)[i] == subSeq[i - curPos + size - 1]) {
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
            auto iter = table.find((*this)[curPos]);
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