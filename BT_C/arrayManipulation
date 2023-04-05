#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

//mang bat ky vd arr[] = {1, 7, 8, 2, 3, 8, 3, 7, 6, 7, 8, 8, 2}
// sap xep mang theo thu tu tang dan
// liet ke cac phan tu co so lan xuat hien vd: 1 xuat hien 1 lan
//                                             7 xuat hien 2 lan
//                                             8 xuat hien 3 lan

typedef struct{
    uint8_t size;
    uint8_t *firstAdd;
}typeArray;

int randomA(int minN, int maxN){
 return minN + rand() % (maxN + 1 - minN);
}

void randomArray(typeArray *value, uint8_t length){
    srand((int)time(0));

    value->size = length;

    value->firstAdd = (uint8_t *)malloc(sizeof(uint8_t)*value->size);
    int r;
    for(int i = 0; i < value->size; ++i){
        value->firstAdd[i] = randomA(0,10);
    }    
}

// Hàm sắp xếp các phần tử trong mảng tăng dần
// Input: một con trỏ tới một kiểu dữ liệu typeArray
// typeArray chứa thông tin về mảng và kích thước của mảng
 void sortArray(typeArray *value){ 
        // Duyệt qua tất cả các phần tử trong mảng
    for(int i = 0; i < value->size ; i++){
        // Duyệt qua tất cả các phần tử còn lại của mảng
        for(int j = 0; j < value->size ; j++){ 
            if(value->firstAdd[j] > value->firstAdd[j+1]){  // nếu giá trị j lớn hơn giá trị tiếp theo thì hoán đổi vị trí  cho nhau nếu phần tử hiện tại lớn hơn phần tử tiếp theo
                // Hoán đổi vị trí của hai phần tử này cho nhau
                int temp = value->firstAdd[j];  //
                value->firstAdd[j] = value->firstAdd[j+1];
                value->firstAdd[j+1] = temp;
            }
        }
    }
}
// void count(typeArray *value){
//     for(int i = 0; i < 11; ++i){
//         int count = 0;
//         for(int j = 0; j < value->size; ++j){
//             if(value->firstAdd[j] == i){
//                 count++;
//             }
//         }
//             printf("số %d xuất hiện : %d lần\n",i, count);
//     }
// }


// Hàm đếm số lần xuất hiện của các phần tử trong mảng
void count1(typeArray *value){
    int count[11] = {0};   // khởi tạo 1 mảng count có kích thước 11 (vì ramdom 0 đến 10) có gía trị =0 
                           // {0,0,0,0,0,0,0,0,0,0,0}
    // Duyệt lần lượt các phần tử trong mảng value
    for(int i = 0; i < value->size; ++i){
        // Tăng giá trị tương ứng của phần tử đó trong mảng count lên 1
        count[value->firstAdd[i]] = count[value->firstAdd[i]] + 1;  
    }
    // In ra kết quả đếm số lần xuất hiện của các phần tử
    for(int i = 0; i < 11; ++i){
        printf("số %d xuất hiện : %d lần\n", i, count[i]);
    }   
}




int main(int argc, char const *argv[])
{
    typeArray arr;

    randomArray(&arr, 20);

    for (int i = 0; i < arr.size; i++)
    {
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }

    sortArray(&arr);
    printf("-------------------------------------\n");
    printf("Sorted array:\n");
    for (int i = 0; i < arr.size; i++){
        printf("arr[%d] = %d\n",i, arr.firstAdd[i]);
    }

    printf("-------------------------------------\n");
    count1(&arr);
    
    
    
    return 0;
}
