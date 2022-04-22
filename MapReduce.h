#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include"DynamicArray.h"
#include"LinkedList.h"
#include"Sequence.h"

using namespace std;

template<typename T>
T* map(T (*func)(T) , T* items , size_t size){
    T* resItems = new T[size];
    for(int i = 0; i < size;++i){
        resItems[i] = func(items[i]);
    }
    return resItems;
}

template<typename T>
T reduce(T (*func)(T , T) , T* items , T constItem , size_t size){
    T res = func(items[0] , constItem);
    for(int i = 1; i < size ; ++i){
        res = func(items[i] , res);
    }
    return res;
}

template <typename T>
T* where(bool (*func)(T) , T* items , size_t size){
    T* resItems = nullptr;
    size_t curSize = 0;
    for(int i = 0; i < size; ++i){
        if(func(items[i])){
            T* buffer = resItems;
            curSize += 1;
            resItems = new T[curSize];
            if(buffer){
                memcpy(resItems , buffer , (curSize-1)*sizeof(T));
            }
            resItems[curSize -1] = items[i];
            if(buffer){
                delete[] items;
            }
        }
    }
    return resItems;
}
