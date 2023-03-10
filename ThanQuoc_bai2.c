#include <stdio.h>
#include <stdint.h>
// nhap vao ban phim 7 so in ra chu 


void readUnits(uint8_t num) {
    switch (num) {
        case 0:
            printf("khong ");
            break;
        case 1:
            printf("mot ");
            break;
        case 2:
            printf("hai ");
            break;
        case 3:
            printf("ba ");
            break;
        case 4:
            printf("bon ");
            break;
        case 5:
            printf("nam ");
            break;
        case 6:
            printf("sau ");
            break;
        case 7:
            printf("bay ");
            break;
        case 8:
            printf("tam ");
            break;
        case 9:
            printf("chin ");
            break;
        default:
            printf("khong hop le ");
            break;
        
    }
}

void readDec(uint8_t num) {
    switch (num) {
        case 0:
            printf("trieu ");
            break;
        case 1:
        case 4:
            printf("tram ");
            break;
        case 2:
        case 5:
            printf("muoi ");
            break;
        case 3:
            printf("nghin ");
            break;
        
        
    }
}


void readNumber(uint8_t numArr[]) {
    
    for (int i = 0; i < 7; i++) { //vong lap duyet qua cac phan tu torng mang
        if (numArr[i] != 0) // truong hop khac 0 thi doc units roi doc dec 
        {
            readUnits(numArr[i]);
            readDec(i);
        } 
        else if (((numArr[1] == 0) && (numArr[2] == 0 )&& (numArr[3] == 0) ) || ((numArr[4] == 0) && (numArr[5] == 0 )&& (numArr[6] == 0)) )
        {   
            //truong hop 3 so 0 lien tiep tai vi tri 123 hoac 456 thi bo qua 
                continue;
        }
        
        // cac truong hop co so 0 trong 7 so 
        else { 
            if ( (i == 2 ) || (i == 5)  ){ //truong hop bang khong tai vi tri 2 hoac 5 in them chu linh
                printf(" linh ");
            }
            if (i == 1 || i == 4) { // truong hop bang 0 tai vi tri 1 hoac 4 (1012013)
                readUnits(numArr[i]);
                readDec(i);
            } 
            else if (i == 3 && numArr[2] != 0) { // truong hop 123056 in ra dc 30 nghin
                readDec(i);   
            }
            
            
        }
    }
}

int main() {
    uint32_t num;
    printf("Nhap so co 7 chu so: ");
    scanf("%d", &num);

    uint8_t numArr[7];

    //tach cac so  ra va gan lan luot vao mang numArr  tu hang don vi den hang trieu 
    for (int i = 6; i >= 0; i--) {
        numArr[i] = num % 10;
        num /= 10;
    }

    printf("\n So doc la: ");
    readNumber(numArr);

    return 0;
}
