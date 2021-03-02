#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (lhs && rhs) {
        int buffer = *lhs;
        *lhs = *rhs;
        *rhs = buffer;
    }
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_rows < 1 || num_cols < 1) {
        return nullptr;
    }

    int **necessary_array = new int *[num_rows];

    for (int row_index = 0; row_index < num_rows; ++row_index) {
        necessary_array[row_index] = new int[num_cols];
        for(int col_index = 0; col_index < num_cols; col_index++){
            necessary_array[row_index][col_index] = init_value;
        }
    }

    return necessary_array;

}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if(arr_2d_source && arr_2d_target && num_rows > 0 && num_cols > 0){
        for(int row_index = 0; row_index < num_rows; row_index++){
            for(int col_index = 0; col_index < num_cols; col_index++){
                arr_2d_source[row_index][col_index] = arr_2d_target[row_index][col_index];
            }
        }
        return true;
    }
    return false;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    for(int index = 0; index < arr.size()/2; index++){
        int buffer = arr.at(index);
        arr[index]=arr[arr.size()-index-1];
        arr[arr.size()-index-1] = buffer;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if(arr_begin && arr_end){
        for(;arr_begin < arr_end; arr_begin++, arr_end--){
            swap_args(arr_begin,arr_end);
        }
    }

}

// Задание 6
int *find_max_element(int *arr, int size) {
    if(arr && size>=0){
        int *max = arr;
        for(int i = 0; i<size; i++){
            if(*arr>*max){
                max = arr;
            }
            arr+=1;
        }
        return max;
    }
    return nullptr;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
//    vector<int> *array = &arr;
    vector<int> unpackedArray = *(&arr);
    vector<int> oddsArray;
    for(int i = 0; i<unpackedArray.size(); i++ ){
        if(unpackedArray.at(i) % 2 != 0){
            oddsArray.push_back(unpackedArray.at(i));
        }
    }
    return oddsArray;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    vector<int> unpackedFirst = *(&arr_a);
    vector<int> unpackedSecond = *(&arr_b);

    vector<int> arrayWithCommonElements;


    for(int i = 0; i < unpackedFirst.size(); i++){
        for(int j = 0; j < unpackedSecond.size(); j++){
            if(unpackedFirst.at(i) == unpackedSecond.at(j)){
                arrayWithCommonElements.push_back(unpackedFirst.at(i));
            }
        }
    }
    return arrayWithCommonElements;
}
