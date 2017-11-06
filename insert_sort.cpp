//
//  main.cpp
//  Insert_sort
//
//  Created by 张海童 on 2017/10/30.
//  Copyright © 2017年 张海童. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void insertSort(vector<int> arr)
{
    int j, key;
    for (int i = 1; i < arr.size(); i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0;i<arr.size();i++)
    {
        cout << arr[i];
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> zz ={5,2,4,6,1,3};
    insertSort(zz);
    return 0;
}
