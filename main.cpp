#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include"DynamicArray.h"
#include"LinkedList.h"
#include"Sequence.h"
#include"MapReduce.h"
#include"Stack.h"
#include"hanoiTower.h"
#include"complex.h"
#include"Person.h"

using namespace std;

int menu(){
    int var;
    cout << "1.Создание стека.\n";
    cout << "2.Операции над стеком.\n";
    cout << "3.Выход.\n";
    cin >> var;
    return var;

}

int main(){
    DynamicArray<int> arr1{1 ,2 ,3};
    DynamicArray<int> arr2{1 , 2, 3};
    arr1 = arr2;
    return 0;
}
