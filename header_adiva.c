#include "header_adiva.h"

#define PI 3.14159265

void Largest3(int *arr_data, int N, int arr_largest[3]){
    int temp;
    int maks;
    int min;

    for(int i = 0 ; i < N-1; i++){
        for(int j = 0; j < N-1; j++){
            if(arr_data[j] <= arr_data[j+1]){
                temp = arr_data[j];
                arr_data[j] = arr_data[j+1];
                arr_data[j+1] = temp;
            }
        }
    }

    if(N == 1){
        for(int i = 0; i <= 2; i++){
            arr_largest[i] = arr_data[0];
        }
    }
    else if(N == 2){
        if(arr_data[0] > arr_data[1]){
            maks = arr_data[0];
            min = arr_data[1];
        }
        else{
            maks = arr_data[1];
            min = arr_data[0];
        }

        arr_largest[0] = maks;
        arr_largest[1] = maks;
        arr_largest[2] = min;
    }
    else{
        for(int i = 0; i < N; i++){
            arr_largest[i] = arr_data[i];
        }
    }
}

float Tabung(int h, int r, char jenis){
    if(jenis == 'V'){
        float volume;

        volume = PI * r  * r * h;
        
        return volume;
    }
    else{
        float luas_permukaan;

        luas_permukaan = (2 * PI * r * r ) + (2 * PI * r * h);
        
        return luas_permukaan;
    }
}
