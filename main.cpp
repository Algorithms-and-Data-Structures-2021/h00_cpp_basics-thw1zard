#include <iostream>  // cout

#include "tasks.hpp"

using namespace std;

int main() {
    // можете написать сюда свой код для отладки программы и дополнительного тестирования функций
    vector<int> array = {1,-2,3,-4};
    vector <int> koko = find_odd_numbers(array);
    for(int i = 0; i < koko.size(); i++){
        cout << koko.at(i) << " " << endl;
    }
    return 0;
}