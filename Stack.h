#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include"DynamicArray.h"
#include"LinkedList.h"
#include"Sequence.h"
#include"MapReduce.h"
#include<initializer_list>

using namespace std;

int getVariant(){
    int x;
    cout << "Организация данных в памяти\n";
    cout << "1.DynamicArray.\n";
    cout << "2.LinkedList.\n";
    cin >> x;
    return x;
}

template<typename T>
class Stack{
private:
      Sequence<T>* ptrSequence = nullptr; 
public:
    Stack(){
        int var = getVariant();
        switch(var){
            case 1:
                ptrSequence = new ArraySequence<T>;
                break;
            case 2:
                ptrSequence = new ListSequence<T>;
                break;
        }
    }
    Stack(initializer_list<T> list ,int var){
        //int var = getVariant();
        switch(var){
            case 1:
                ptrSequence = new ArraySequence<T>(list);
                break;
            case 2:
                ptrSequence = new ListSequence<T>(list);
                break;
        }
    }
    ~Stack(){
        delete ptrSequence;
    }
    bool Full(){
        int x = this -> ptrSequence -> GetLength();
        if(x != 0){
            return true;
        }
        else{
            return true;
        }
    }
    void Add(T item){
        this -> ptrSequence -> Append(item);
    }
    void Delete(){
        this -> ptrSequence -> DeleteStart();
    }
    T Top(){
        return this -> ptrSequence -> GetLast();
    }
    int Size(){
        return this -> ptrSequence -> GetLength();
    }
    Stack<T>* Concat(Stack<T>* st){
        Stack<T>* resStack = new Stack<T>;
        resStack -> ptrSequence = this -> ptrSequence -> Concat(st -> ptrSequence);
        return resStack;
    }
    Stack<T>* GetSubSequnce(int startIndex , int endIndex){
        Stack<T>* resStack = new Stack<T>;
        resStack -> ptrSequence = this -> ptrSequence -> GetSubSequence(startIndex , endIndex);
        return resStack;
    }
    int rfind(T* items , size_t sizeSubs){
        return ptrSequence -> rfind(items, sizeSubs);
    } 
    void Print(){
        this -> ptrSequence-> Print();
    }
    friend T* map(T (*func)(T) , T* items , size_t size){};
    friend T reduce(T (*func)(T , T) , T* items , T constItem , size_t size){};
    friend T* where(bool (*func)(T) , T* items , size_t size){};
};