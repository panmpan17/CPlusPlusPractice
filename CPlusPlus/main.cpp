//
//  main.cpp
//  CPlusPlus
//
//  Created by Michael Pan on 2023/2/16.
//

#include <iostream>
#include "mathlib.hpp"
#include "sorting.hpp"
#define print(message) std::cout << message << "\n";
#define print_array(array, size) for(int i=0; i<size; i++) std::cout << array[i] << ", "; std::cout << "\n";
#define add(a, b) a + b;

// Declare
struct TestData;
void process_data(TestData* data);
int main(int argc, const char * argv[]);


// Actual implementation
struct TestData {
    int DataA;
    int DataB;
    int Result;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    TestData data;
    data.DataA = 10;
    data.DataB = 3;
    process_data(&data);

//    print(data.Result);

    int array[9] = {104, 1, 3, 2, 9, 40, 129, 15, 10};
//    int array2[9] = { 3, 7, 8, 5, 2, 1, 9, 5, 4 };
//    bubble_sort(array, 9);
//    insert_sort(array, 9);
//    selection_sort(array, 9);
    quick_sort(array, 9);
    print_array(array, 9);

    return 0;
}

void process_data(TestData* data) {
    data->Result = sqaure(data->DataA, data->DataB);
}
