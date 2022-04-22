#pragma once
#include<iostream>

class ExceptionError{
private:
    int id;
public:
    ExceptionError(int){
        this -> id = 0;
        std::cout << "IndexOutOfRange";
    }
};