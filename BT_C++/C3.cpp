#include <stdio.h>
#include <stdint.h>
#include <cmath>
using namespace std;

class HinhChon {
    private:
        double banKinh;

    public:
        HinhChon(double bk) {
            banKinh = bk;
        }
        void setBanKinh(double bk);
        double getBanKinh();
        double tinhChuVi();
        double tinhDienTich();
};
void HinhChon::setBanKinh(double bk){
    banKinh = bk;
}
double HinhChon::getBanKinh() {
    return banKinh;
}

double HinhChon::tinhChuVi() {
    return 2 * 3.14 * banKinh;
}

double HinhChon::tinhDienTich() {
    return 3.14 * pow(banKinh, 2);
}

int main() {
    double bk;
    printf("Nhap ban kinh: ");
    scanf("%lf", &bk);

    HinhChon hc(bk);

    printf("Chu vi: %.2lf\n",  hc.tinhChuVi());
    printf("Dien tich: %.2lf\n", hc.tinhDienTich());

    return 0;
}