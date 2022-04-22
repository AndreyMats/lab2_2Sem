#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include"DynamicArray.h"
#include"LinkedList.h"
#include"Sequence.h"
#include"MapReduce.h"
#include"Stack.h"

using namespace std;

template<typename T>
void MoveDisk(Stack<T>* outSt, Stack<T>* inSt){
    T item = outSt->Top();
    outSt->Delete();
    inSt -> Add(item);
}

template <typename T>
void hanoiTower(size_t count , Stack<T>* outSt, Stack<T>* inSt, Stack<T>* tempSt){
    if(count == 0){
        return;
    }
    hanoiTower(count - 1, outSt , tempSt , inSt);
    MoveDisk(outSt , inSt);
    hanoiTower(count - 1, tempSt , inSt , outSt);
}