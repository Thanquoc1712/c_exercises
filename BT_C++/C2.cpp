#include <stdio.h>
#include <stdint.h>
#include <cmath>
using namespace std;

class HinhChuNhat {
    private:
        double chieuDai;
        double chieuRong;

    public:
        HinhChuNhat(double dai, double rong) {
            chieuDai = dai;
            chieuRong = rong;
        }
        void setChieuDai(double dai) ;
        void setChieuRong(double rong) ;
        double getChieuDai() ;
        double getChieuRong() ;
        double tinhChuVi() ;
        double tinhDienTich() ;
        double tinhDuongCheo();
        bool laHinhVuong();
};

void HinhChuNhat::setChieuDai(double dai){
    chieuDai = dai;
}

void HinhChuNhat::setChieuRong(double rong){
    chieuRong = rong;
}

double HinhChuNhat::getChieuDai() {
    return chieuDai;
}

double HinhChuNhat::getChieuRong() {
    return chieuRong;
}

double HinhChuNhat::tinhChuVi() {
    return 2 * (chieuDai + chieuRong);
}

double HinhChuNhat::tinhDienTich() {
    return chieuDai * chieuRong;
}

double HinhChuNhat::tinhDuongCheo() {
    return sqrt(pow(chieuDai, 2) + pow(chieuRong, 2));
}

bool HinhChuNhat::laHinhVuong() {
    return chieuDai == chieuRong;
}

int main() {
    double dai, rong;
    printf("Nhap chieu dai: ");
    scanf("%lf", &dai);
    printf("Nhap chieu rong: ");
    scanf("%lf", &rong);

    HinhChuNhat hcn(dai, rong);

    printf("Chu vi: %.2lf\n",  hcn.tinhChuVi());
    printf("Dien tich: %.2lf\n", hcn.tinhDienTich());
    printf("Duong cheo: %.2lf\n", hcn.tinhDuongCheo());

    if (hcn.laHinhVuong() == 1 ){
        printf("La hinh vuong");
    }
    else {
        printf("La hinh chu nhat");
    }
    return 0;
}
