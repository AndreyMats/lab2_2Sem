#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<initializer_list>
#include"DynamicArray.h"
#include"LinkedList.h"

using namespace std;

template<typename T>
class Sequence{
private:
public:
    virtual ~Sequence() = 0;
    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;
    virtual int GetLength() = 0;
    virtual void DeleteStart() = 0;
    virtual void DeleteEnd() = 0;
    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item , int index) = 0;
    virtual int rfind(T* items , size_t size) = 0;
    virtual Sequence<T>* GetSubSequence(int startIndex , int endIndex) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;
    virtual void Print() = 0;
};

template<typename T>
Sequence<T>::~Sequence(){}

template<class T>
class ArraySequence:public Sequence<T>{
protected:
    DynamicArray<T>* ArrayItems = nullptr;
public:
    ~ArraySequence(){
        delete ArrayItems;
    }
    ArraySequence(){
        ArrayItems = new DynamicArray<T>;
    }
    ArraySequence(T* items , int count){
        this -> ArrayItems = new DynamicArray<T>(items , count);
    }
    ArraySequence(const ArraySequence<T>& ArrSeq){
        this -> ArrayItems = new DynamicArray<T>;
        *ArrayItems = *ArrSeq.ArrayItems;
    }
    ArraySequence(initializer_list<T> list){
        this -> ArrayItems = new DynamicArray<T>(list);
    }
    T GetFirst() override{
        return this -> ArrayItems -> GetFirst();
    }
    T GetLast() override{
        return this -> ArrayItems -> GetLast();
    }
    T Get(int index) override{
        return this -> ArrayItems -> Get(index);
    }
    int GetLength() override{
        return this -> ArrayItems -> GetSize();
    }
    void DeleteStart() override{
        this -> ArrayItems -> DeleteStart();
    }
    void DeleteEnd() override{
        this -> ArrayItems -> DeleteEnd();
    }
    void Append(T item) override{
        this -> ArrayItems -> Append(item);
    }
    void Prepend(T item) override{
        this -> ArrayItems -> Prepend(item);
    }
    void InsertAt(T item , int index) override{
        this -> ArrayItems -> InsertAt(item , index);
    }
    int rfind(T* items , size_t size) override{
        return this -> ArrayItems -> rfind(items , size);
    }
    T operator[](int index){
        return this -> Get(index);
    }
    bool operator==(const ArraySequence<T> &obj){
        return *(this -> ArrayItems) == *obj.ArrayItems;
    }
    bool operator!=(const ArraySequence<T> &obj){
        return *(this -> ArrayItems) != *obj.ArrayItems;
    }
    ArraySequence<T>* GetSubSequence(int startIndex , int endIndex) override{
        ArraySequence<T>* resSeq = new ArraySequence<T>;
        delete resSeq -> ArrayItems;
        resSeq -> ArrayItems = this -> ArrayItems -> GetSubList(startIndex , endIndex);
        return resSeq;
    }
    ArraySequence<T>* Concat(Sequence<T>* ListS) override{
        ArraySequence<T>* list = static_cast<ArraySequence<T>*>(ListS);
        ArraySequence<T>* resSeq = new ArraySequence<T>;
        delete resSeq -> ArrayItems;
        resSeq -> ArrayItems = this -> ArrayItems -> Concat(list -> ArrayItems);
        return resSeq;
    }
    void Print() override{
        this -> ArrayItems -> Print();
    }
};

// Constructors are overloaded auto in runtime!
template<class T>
class ListSequence:public Sequence<T>
{
protected:
    LinkedList<T>* listItems = nullptr;
public:
    ~ListSequence(){
        delete listItems;
    }
    ListSequence(){
        listItems = new LinkedList<T>;
    }
    ListSequence(T* items , int count){
        this -> listItems = new LinkedList<T>(items , count);
    }
    ListSequence(const ListSequence<T>& listSeq){
        this -> listItems = new LinkedList<T>;
        *(this -> listItems) = *listSeq.listItems;
    }
    ListSequence(initializer_list<T> list){
        this -> listItems = new LinkedList<T>(list);
    }
    T GetFirst() override{
        return this -> listItems -> GetFirst();
    }
    T GetLast() override{
        return this -> listItems -> GetLast();
    }
    T Get(int index) override{
        return this -> listItems -> Get(index);
    } 
    int GetLength() override{
        return this -> listItems -> GetSize();
    }
    void DeleteStart() override{
        this -> listItems -> DeleteStart();
    }
    void DeleteEnd() override{
        this -> listItems -> DeleteEnd();
    }
    void Append(T item) override{
        this -> listItems -> Append(item);
    }
    void Prepend(T item) override{
        this -> listItems -> Prepend(item);
    }
    void InsertAt(T item , int index) override{
        this -> listItems -> InsertAt(item , index);
    }
    int rfind(T* items , size_t size) override{
        return this -> listItems -> rfind(items , size);
    }
    T operator[](int index){
        return this -> listItems -> Get(index);
    }
    bool operator==(const ListSequence<T> &obj){
        return *(this -> listItems) == *obj.listItems; 
    }
    bool operator!=(const ListSequence<T> &obj){
        return !(*(this -> listItems) == *obj.listItems);
    }
    ListSequence<T>* GetSubSequence(int startIndex , int endIndex) override{
        ListSequence<T>* resSeq = new ListSequence<T>;
        delete resSeq -> listItems;
        resSeq -> listItems = this -> listItems -> GetSubList(startIndex , endIndex);
        return resSeq;
    }
    ListSequence<T>* Concat(Sequence<T>* ListS) override{
        ListSequence<T>* list = static_cast<ListSequence<T>*>(ListS);
        ListSequence<T>* resSeq = new ListSequence<T>;
        delete resSeq -> listItems;
        resSeq -> listItems = this -> listItems -> Concat(list -> listItems);
        return resSeq;
    }
    void Print() override{
        this -> listItems -> Print();
    }
};
