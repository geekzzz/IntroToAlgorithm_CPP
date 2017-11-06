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

void insertSort(int arr[], int length)
{
    int j, key;
    for (int i = 1; i < length; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for (int i = 0;i<6;i++)
    {
        cout << arr[i];
    }
}

int main(int argc, const char * argv[]) {
    int zz[] ={5,2,4,6,1,3};
    insertSort(zz, 6);
    return 0;
}
