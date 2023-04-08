#include <stdio.h>
#include <string.h>
#include <stdint.h>

using namespace std;

class Fraction {
    private:
        uint8_t numerator;
        uint8_t denominator;
    public:
        Fraction(int num =0 , int den=1);
        void input();
        void output();
        Fraction add(Fraction other);
        Fraction subtract(Fraction other);
        Fraction multiply(Fraction other);
        Fraction divide(Fraction other);
};


Fraction::Fraction(int num, int den) {
    numerator = num;
    denominator = den;
}

void Fraction::input() {
    printf("Enter numerator: ");
    scanf("%hhu", &numerator);

    printf("Enter denominator: ");
    scanf("%hhu", &denominator);
}

void Fraction::output() {
    printf("%hhu/%hhu", numerator, denominator);
}

Fraction Fraction::add(Fraction other) {
    Fraction result;

    result.numerator = numerator * other.denominator + other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction::subtract(Fraction other) {
    Fraction result;

    result.numerator = numerator * other.denominator - other.numerator * denominator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction::multiply(Fraction other) {
    Fraction result;

    result.numerator = numerator * other.numerator;
    result.denominator = denominator * other.denominator;
    return result;
}

Fraction Fraction::divide(Fraction other) {
    Fraction result;

    result.numerator = numerator * other.denominator;
    result.denominator = denominator * other.numerator;
    return result;
}

int main(int argc, char const *argv[])
{
    Fraction a, b, c;
    printf("Nhap phan so thu 1: \n");
    a.input();
    printf("Phan so thu 1: ");
    a.output();

    printf("\nNhap phan so thu 2: \n");
    b.input();
    printf("Phan so thu 2: ");
    b.output();

    c = a.add(b);
    printf("\nTong hai phan so: ");
    c.output();

    c = a.subtract(b);
    printf("\nHieu hai phan so: ");
    c.output();

    c = a.multiply(b);
    printf("\nTich hai phan so: ");
    c.output();

    c = a.divide(b);
    printf("\nThuong hai phan so: ");
    c.output();

    return 0;
}
