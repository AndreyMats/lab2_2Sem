#include <cassert>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include"lab2/DynamicArray.h"
#include"lab2/LinkedList.h"
#include"lab2/Sequence.h"
#include"lab2/MapReduce.h"
#include"lab2/Stack.h"
#include"lab2/hanoiTower.h"
#include"lab2/complex.h"
#include"lab2/Person.h"

// testing DynamicArray

void test_getter_array() {
    int* a = new int[10];
    for(int i = 0; i < 10 ; ++i){
        a[i] = i;
    }
    DynamicArray<int> q(a, 10);
    int f = q.GetFirst();
    int l = q.GetLast();
    int m = q.Get(5);
    int size = q.GetSize();
    assert(size == 10);
    assert(f == 0);
    assert(l == 9);
    assert(m == 5);
    delete[] a;
    DynamicArray<int> z;
    //z.GetFirst();
}

void test_oper_array() {
    int* a = new int[10];
    for(int i = 0; i < 10; ++i){
        a[i] = i;
    }
    DynamicArray<int> arr(a , 10);
    int item = a[3];
    assert(item == 3);
    DynamicArray<int> arr2 = arr;
    assert(arr2 == arr);
    arr2.DeleteStart();
    arr2.DeleteEnd();
    assert(arr2 != arr);
    delete[] a;
}

void test_concat_subarr_arr(){
    // testing GetSubList
    int* a = new int[10];
    for(int i = 0; i < 10; ++i){
        a[i] = i;
    }
    int* ptr_2 = new int[4];
    for(int i = 0; i < 4; ++i){
        ptr_2[i] = i + 1;
    }
    DynamicArray<int> arr1(a , 10);
    DynamicArray<int>arr2(ptr_2, 4);
    DynamicArray<int>*arr3 = arr1.GetSubList(1,4);
    assert(arr2 == *arr3);
    delete arr3;
    //testing Concat
    DynamicArray<int> arr4{0, 1 , 2 , 3, 4 ,5};
    DynamicArray<int> arr5{6, 7, 8, 9};
    DynamicArray<int>* ptr = arr4.Concat(&arr5);
    assert(arr1 == *ptr);
    delete ptr;
    delete[] a;
    delete[] ptr_2;
}

void test_insert(){
    //testing Set 
    DynamicArray<int> arr1{1 , 2 , 3, 4, 5};
    DynamicArray<int> arr2{1, 2 , 5, 4, 5};
    arr1.Set(2, 5);
    assert(arr1 == arr2);
    //testing append
    arr2.Append(6);
    DynamicArray<int>arr3{1, 2, 5, 4, 5, 6};
    assert(arr2 == arr3);
    //testing prepend
    arr3.Prepend(7);
    DynamicArray<int>arr4{7, 1, 2 , 5, 4, 5, 6};
    assert(arr3 == arr4);
}

void rfind(){
    DynamicArray<int> arr1{2,5,4,7,6,8,6};
    int* subArr = new int[3];
    subArr[0] = 5;
    subArr[1] = 4;
    subArr[2] = 7;
    int start = arr1.rfind(subArr , 3);
    assert(start == 2);
    int* subArr2 = new int[3];
    subArr2[0] = 5;
    subArr2[1] = 4;
    subArr2[2] = 3;
    int start2 = arr1.rfind(subArr2 , 3);
    assert(start2 == 0);
    delete[] subArr2;
    delete[] subArr;
}

//testing Linkedlist

void test_getter_list(){
    LinkedList<int> list1{1, 2, 3, 4, 5, 6};
    // testing GetFirst
    int f = list1.GetFirst();
    assert(f == 1);
    // testing GetLast
    int l = list1.GetLast();
    assert(l == 6);
    // testing Get
    int m = list1.Get(3);
    assert(m == 4);

}

void test_subList_concat(){
    // testing GetSubList
    LinkedList<int> list1 {2, 4, 1 , 6, 7 , 8 ,9};
    LinkedList<int>* ptr = list1.GetSubList(2 , 4);
    LinkedList<int> list2{1 , 6, 7};
    assert(*ptr == list2);
    delete ptr;
    // Concat
    LinkedList<int> list5 {4 , 5, 7};
    LinkedList<int> list6 {6 , 6 , 8};
    LinkedList<int>* res = list5.Concat(&list6);
    LinkedList<int> list3 {4 , 5, 7 , 6, 6, 8};
    assert(*res == list3);
    delete res;
}

void test_del_impl_list(){
    // testing DeleteStart
    LinkedList<int> list1{2 , 3, 4, 5, 6, 7 ,8};
    LinkedList<int> res1 {2, 3, 4, 5, 6, 7};
    list1.DeleteStart();
    assert(list1 == res1);
    // testing DeleteEnd
    LinkedList<int> res2{3 ,4 ,5 , 6 ,7};
    list1.DeleteEnd();
    assert(list1 == res2);
    //testing Append
    LinkedList<int> list2;
    LinkedList<int> res3{1};
    list2.Append(1);
    assert(list2 == res3);
    // tesing Prepend
    list2.Prepend(2);
    LinkedList<int> res4{2 , 1};
    assert(res4 == list2);
    //testing InsertAt
    LinkedList<int> res5{2 , 3 ,1};
    list2.InsertAt(3, 1);
    assert(res5 == list2);
}

void test_rfind_list(){
    // testing rfind 
    LinkedList<int> list1{1 , 4 , 7 , 2, 8, 4};
    int* ptr = new int[3];
    ptr[0] = 4; 
    ptr[1] = 7;
    ptr[2] =2;
    bool answer = list1.rfind(ptr , 3);
    assert(answer == true);
    delete[] ptr;
    int* ptr1 = new int[4];
    ptr1[0] = 7; 
    ptr1[1] = 2;
    ptr1[2] = 8;
    ptr1[3] = 4;
    bool ans1 = list1.rfind(ptr1 , 4);
    assert(ans1 == true);
    delete[] ptr1;
}

// testing ArraySequence

void test_geters_ArrSeq(){
    // testing Geters
    ArraySequence<int> arr1{1 ,2, 3, 4, 5, 6, 7};
    int f = arr1.GetFirst();
    assert(1 == f);
    int l = arr1.GetLast();
    assert(l == 7);
    int m = arr1.Get(3);
    assert(m == 4);
    int size = arr1.GetLength();
    assert(size == 7);
}

void test_del_implace_ArrSeq(){
    // testing DeleteStart
    ArraySequence<int> arr1{1 , 4 , 5, 7, 3};
    ArraySequence<int> res1{1 , 4, 5 , 7};
    arr1.DeleteStart();
    assert(arr1 == res1);
    // testing DeleteEnd
    ArraySequence<int> res2{4 , 5, 7};
    arr1.DeleteEnd();
    assert(arr1 == res2);
    // testing Append
    ArraySequence<int> res3{4 , 5, 7, 8};
    arr1.Append(8);
    assert(arr1 == res3);
    //testing Prepend
    ArraySequence<int> res4{1 , 4, 5, 7 ,8};
    arr1.Prepend(1);
    assert(res4 == arr1);
    // testing InsertAt
    ArraySequence<int> res5{1 ,2 , 4 , 5 , 7, 8};
    arr1.InsertAt(2 , 1);
    assert(arr1 == res5);
}

void test_rfind_ArrSeq(){
       // testing rfind 
    ArraySequence<int> list1{1 , 4 , 7 , 2, 8, 4};
    int* ptr = new int[3];
    ptr[0] = 4; 
    ptr[1] = 7;
    ptr[2] =2;
    bool answer = list1.rfind(ptr , 3);
    assert(answer == true);
    delete[] ptr;
    int* ptr1 = new int[4];
    ptr1[0] = 7; 
    ptr1[1] = 2;
    ptr1[2] = 8;
    ptr1[3] = 4;
    bool ans1 = list1.rfind(ptr1 , 4);
    assert(ans1 == true);
    delete[] ptr1; 
}

// testing ListSequence

void test_geters_ListSeq(){
    //testing GetFirst
    ListSequence<int> list1{1 , 3, 4, 5, 2, 8, 6, 4};
    int f = list1.GetFirst();
    assert(f == 1);
    //testing GetLast
    int l = list1.GetLast();
    assert(l == 4);
    //testing Get
    int m = list1.Get(3);
    assert(m == 5);
    //testing GetSize
    int size = list1.GetLength();
    assert(size == 8);
}

void test_del_implace_ListSeq(){
    ListSequence<int> list1{5 , 3, 7, 8, 1 ,2 ,4 ,5 ,6};
    //testing DeleteStart
    ListSequence<int> res1{5 , 3, 7 , 8, 1, 2 , 4 , 5};
    list1.DeleteStart();
    assert(list1 == res1);
    //testing DeleteEnd
    ListSequence<int> res2 {3 , 7, 8 , 1, 2 ,4 ,5};
    list1.DeleteEnd();
    assert(res2 == list1);
    //testing Append
    ListSequence<int> list2{1 , 2, 3};
    ListSequence<int> res3{1, 2,3 , 1};
    list2.Append(1);
    assert(list2 == res3);
    //testing Prepend
    ListSequence<int> res4{5 , 1 ,2 ,3 ,1};
    list2.Prepend(5);
    assert(list2 == res4);
}

void test_concat_subList_listSeq(){
    //testing Concat
    ListSequence<int> list1{1 , 2 ,3};
    ListSequence<int> list2{6 , 4, 5};
    ListSequence<int> res1{1 ,2 ,3 , 6 ,4 ,5};
    ListSequence<int>* ptr1 = list1.Concat(&list2);
    assert(*ptr1 == res1);
    delete ptr1;
    //testing GetSubList
    ListSequence<int> list3{1 ,2 ,3 ,4 ,5 , 6 , 7 ,8};
    ListSequence<int>* ptr2 = list3.GetSubSequence(2, 5);
    ListSequence<int> res2{3 ,4, 5,6};
    assert(res2 == *ptr2);
    delete ptr2;
}

void test_rfind_listSeq(){
    //testing rfind
    ListSequence<int> list1{2 ,3 ,4 , 5, 6, 9, 8,1};
    int* ptr1 = new int[4];
    ptr1[0] =4;
    ptr1[1] = 5;
    ptr1[2] = 6;
    ptr1[3] = 9;
    bool ans = list1.rfind(ptr1 , 4);
    assert(ans == true);
    delete[] ptr1;

    int* ptr2 = new int[3];
    ptr2[0] = 2;
    ptr2[1] = 3;
    ptr2[2] = 4;
    bool ans2 = list1.rfind(ptr2 , 3);
    assert(ans2 == true);
    delete[] ptr2;
}

//testing class Stack

void test_geters(){
    Stack<int> st1({1, 4, 3, 2,7,6,2,1}, 1);
    // testing method's Full 
    bool ans1 = st1.Full();
    assert(ans1 == true);
    // testing geters
    Stack<int> st2({1,2}, 1);
    st2.Add(3);
    Stack<int> res1({1,2,3}, 1);
}