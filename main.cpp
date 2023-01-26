#include <iostream>
#include <vector>

using namespace std;

std::vector<int> mergeSortedArrays(std::vector<int> array1, std::vector<int> array2);

std::vector<int> mergeSortedArrays(std::vector<int> array1, std::vector<int> array2) {
    std::vector<int> mergedArray {};
    int array1Item = array1[0];
    int array2Item = array2[0];
    int i = 1;
    int j = 1;
    
    // Check input
    if (array1.size() == 0) {
        return array2;
    }
    
    if (array2.size() == 0) {
        return array1;
    }
    
    while (array1Item || array2Item) {
        if (mergedArray.size() == (array1.size() + array2.size()))
            break;
        
        if (!array2Item || array1Item < array2Item) {
            mergedArray.push_back(array1Item);
            array1Item = array1[i];
            i++;
        } else {
            mergedArray.push_back(array2Item);
            array2Item = array2[j];
            j++;
        }
    }
    
    return mergedArray;
}


int main(){
    for (auto item: mergeSortedArrays({0, 3, 4, 31}, {4, 6, 30}))
        cout << item << " ";
    cout << endl;
    return 0;
}