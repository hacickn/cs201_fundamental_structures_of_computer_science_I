/*
 Hacı Çakın
 Section 01
 21802641
 28.11.2020
 */
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void firstWay(int* arr1, int* arr2, const int size) {
    int arr3[2 * size];
    int m;
    int a = 0;
    double duration;
    clock_t startTime = clock();
    for (int i = 0; i < size; i++) {
        arr3[i] = arr1[i];
    }

    while (a < size) {
        m = 0;
        while (m < size + a) {
            if (arr3[m] < arr2[a] || arr3[m] == arr2[a]) {
                m++;
                continue;
            } else {
                for (int l = size + a; l > m; l--) {
                    arr3[l] = arr3[l - 1];
                }
                arr3[m] = arr2[a];
                m = m + size + a + 1;
            }

        }
        a++;
    }
    duration =  double( clock() - startTime ) * 1000 / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << " This is for the first algorithm with size " << size << endl;
    /*
    //printing the array
    for (int k = 0; k < 2 * size; k++) {
        cout << arr3[k] << " ";
    }
     */

}

void secondWay(int* arr1, int* arr2, const int size) {
    int x = 0;
    int y = 0;
    int third[size * 2];

    double duration;
    clock_t startTime = clock();
    while (x < size || y < size) {
        if (x < size && y < size) {
            if (arr1[x] > arr2[y] && y < size) {
                third[x + y] = arr2[y];
                y++;

            } else if (arr1[x] <= arr2[y] && x < size) {
                third[x + y] = arr1[x];
                x++;
            }
        } else {
            if (x == size) {
                third[x + y] = arr2[y];
                y++;
            } else if (y == size) {
                third[x + y] = arr1[x];
                x++;
            }
        }
    }
    duration =  double( clock() - startTime ) * 1000 / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << " This is for the second algorithm with size " << size << endl;
    /*
    //for printing
    for (int k = 0; k < 2 * size; k++) {
        cout << third[k] << " ";
    }
     */
}

//it randoms and sorts that there is no such ordering between these arrays
void randomAndSortFirst(int* arr1, int* arr2, int size) {
    for (int a = 0; a < size; a++) {
        arr1[a] = rand() % 10000 + 1;
        arr2[a] = rand() % 10000 + 1;
    }

    sort(arr1, arr1 + size);
    sort(arr2, arr2 + size);
}

//it randoms and sorts all numbers in arr1 are smaller than arr2
void randomAndSortSecond(int* arr1, int* arr2, int size) {
    for (int a = 0; a < size; a++) {
        arr1[a] = rand() % 10000 + 1;
        arr2[a] = rand() % 10000 + 20001;
    }

    sort(arr1, arr1 + size);
    sort(arr2, arr2 + size);
}


int main() {
    int list1[1000];
    int list2[1000];
    int list3[2000];
    int list4[2000];
    int list5[3000];
    int list6[3000];
    int list7[4000];
    int list8[4000];
    int list9[5000];
    int list10[5000];
    int list11[6000];
    int list12[6000];
    int list13[7000];
    int list14[7000];
    int list15[8000];
    int list16[8000];
    int list17[9000];
    int list18[9000];
    int list19[10000];
    int list20[10000];


    //all numbers in arr1 are smaller than arr2
    randomAndSortSecond(list1,list2,1000);
    randomAndSortSecond(list3,list4,2000);
    randomAndSortSecond(list5,list6,3000);
    randomAndSortSecond(list7,list8,4000);
    randomAndSortSecond(list9,list10,5000);
    randomAndSortSecond(list11,list12,6000);
    randomAndSortSecond(list13,list14,7000);
    randomAndSortSecond(list15,list16,8000);
    randomAndSortSecond(list17,list18,9000);
    randomAndSortSecond(list19,list20,10000);


    cout << "A) For the all numbers in arr1 are smaller than arr2 " << endl<< endl;

    cout << "A.1) For the first algorithm" << endl;
    firstWay(list1,list2,1000);
    firstWay(list3,list4,2000);
    firstWay(list5,list6,3000);
    firstWay(list7,list8,4000);
    firstWay(list9,list10,5000);
    firstWay(list11,list12,6000);
    firstWay(list13,list14,7000);
    firstWay(list15,list16,8000);
    firstWay(list17,list18,9000);
    firstWay(list19,list20,10000);
    cout  << endl << endl;
    cout << "A.2) For the second algorithm" << endl ;
    secondWay(list1,list2,1000);
    secondWay(list3,list4,2000);
    secondWay(list5,list6,3000);
    secondWay(list7,list8,4000);
    secondWay(list9,list10,5000);
    secondWay(list11,list12,6000);
    secondWay(list13,list14,7000);
    secondWay(list15,list16,8000);
    secondWay(list17,list18,9000);
    secondWay(list19,list20,10000);
    cout << "**********************************************************************************************************" << endl;
    cout << "**********************************************************************************************************" << endl << endl;

    // all numbers in arr2 are smaller than arr1(they are same lists with previous trials but their order are different
    // instead of list1 - list2 it is list2-list1)
    cout << "B) For the all numbers in arr2 are smaller than arr1 " << endl<< endl;

    cout << "B.1) For the first algorithm" << endl;
    firstWay(list2,list1,1000);
    firstWay(list4,list3,2000);
    firstWay(list6,list5,3000);
    firstWay(list8,list7,4000);
    firstWay(list10,list9,5000);
    firstWay(list12,list11,6000);
    firstWay(list14,list13,7000);
    firstWay(list16,list15,8000);
    firstWay(list18,list17,9000);
    firstWay(list20,list19,10000);

    cout  << endl << endl;
    cout << "B.2) For the second algorithm" << endl;
    secondWay(list2,list1,1000);
    secondWay(list4,list3,2000);
    secondWay(list6,list5,3000);
    secondWay(list8,list7,4000);
    secondWay(list10,list9,5000);
    secondWay(list12,list11,6000);
    secondWay(list14,list13,7000);
    secondWay(list16,list15,8000);
    secondWay(list18,list17,9000);
    secondWay(list20,list19,10000);

    cout << "**********************************************************************************************************" << endl;
    cout << "**********************************************************************************************************" << endl << endl;

    //For the there is no such ordering between these array
    randomAndSortFirst(list1,list2,1000);
    randomAndSortFirst(list3,list4,2000);
    randomAndSortFirst(list5,list6,3000);
    randomAndSortFirst(list7,list8,4000);
    randomAndSortFirst(list9,list10,5000);
    randomAndSortFirst(list11,list12,6000);
    randomAndSortFirst(list13,list14,7000);
    randomAndSortFirst(list15,list16,8000);
    randomAndSortFirst(list17,list18,9000);
    randomAndSortFirst(list19,list20,10000);

    cout << "C) For the there is no such ordering between these array " << endl<< endl;

    cout << "C.1) For the first algorithm" << endl ;
    firstWay(list1,list2,1000);
    firstWay(list3,list4,2000);
    firstWay(list5,list6,3000);
    firstWay(list7,list8,4000);
    firstWay(list9,list10,5000);
    firstWay(list11,list12,6000);
    firstWay(list13,list14,7000);
    firstWay(list15,list16,8000);
    firstWay(list17,list18,9000);
    firstWay(list19,list20,10000);

    cout  << endl << endl;
    cout << "C.2) For the second algorithm" << endl;
    secondWay(list1,list2,1000);
    secondWay(list3,list4,2000);
    secondWay(list5,list6,3000);
    secondWay(list7,list8,4000);
    secondWay(list9,list10,5000);
    secondWay(list11,list12,6000);
    secondWay(list13,list14,7000);
    secondWay(list15,list16,8000);
    secondWay(list17,list18,9000);
    secondWay(list19,list20,10000);

    return 0;
}
