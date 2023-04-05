///Tạo một lớp điểm trong hệ tọa độ 2D và viết các phương thức để tính
//khoảng cách giữa hai điểm, tính diện tích của tam giác được tạo bởi ba điểm.


#include <stdio.h>
#include <cmath>
#include <stdint.h>

/**
 * @brief Lớp Point mô tả một điểm trong không gian 2D
 * 
 */
class Point {
  private:
        int8_t ordinate;
        int8_t abscissa;
  public:
    Point(int8_t ordinate =0 , int8_t abscissa = 0) ;
    int8_t getOrdinate() {return Point:: ordinate;};
    int8_t getAbscissa() {return Point:: abscissa;};
};

Point::Point (int8_t ordinate, int8_t abscissa){
    Point::ordinate = ordinate;
    Point::abscissa = abscissa;
}

/*
 * @brief Lớp SpaceMath chứa các phương thức để tính toán trong không gian 2D
 * 
 */

class SpaceMath{
    private:
        Point firstCoordinate;
        Point secondCoordinate;
        Point thirdCoordinate;
        typedef enum{
            DISTANCE,
            AREA_OF_TRIANGLE
        }Math;
        Math math;
    public:
        SpaceMath(Point firstCoordinate,Point secondCoordinate );
        SpaceMath(Point firstCoordinate,Point secondCoordinate, Point thirdCoordinate );
        double calculateDistance();
        double calculateAreaOfTriangle();
};

SpaceMath::SpaceMath(Point firstCoordinate ,Point secondCoordinate ){
    math = DISTANCE;
    SpaceMath::firstCoordinate  = firstCoordinate;
    SpaceMath::secondCoordinate = secondCoordinate;
}

SpaceMath::SpaceMath(Point firstCoordinate ,Point secondCoordinate ,Point thirdCoordinate ){
    math = AREA_OF_TRIANGLE ;
    SpaceMath::firstCoordinate  = firstCoordinate;
    SpaceMath::secondCoordinate = secondCoordinate;
    SpaceMath::thirdCoordinate  = thirdCoordinate;
}

/**
 * @brief Tính khoảng cách giữa hai điểm trong không gian 2D
 *  sqrt ( dx^2 + dy^2)
 * @return double - khoảng cách giữa hai điểm
 */
double SpaceMath::calculateDistance(){
    if (math == DISTANCE){
        double dx = firstCoordinate.getOrdinate() - secondCoordinate.getOrdinate(); // Tính khoảng cách theo tung độ
        double dy = firstCoordinate.getAbscissa() - secondCoordinate.getAbscissa(); // Tính khoảng cách theo hoành độ
        return sqrt(dx*dx + dy*dy);
    }
    else{
        return 0;
    }
}

/**
 * @brief Tính diện tích của tam giác được tạo bởi ba điểm trong không gian 2D
 * cthuc 1/2[x1(y2−y3)+x2(y3−y1)+x3(y1−y2)]
 * a(x1;y1) b (x2;y2) b(x3;y3)
 * @return double - diện tích của tam giác 
 */
double SpaceMath::calculateAreaOfTriangle(){
    if (math == AREA_OF_TRIANGLE){
        double a = firstCoordinate.getAbscissa() *(secondCoordinate.getOrdinate() - thirdCoordinate.getOrdinate());
        double b = secondCoordinate.getAbscissa()*(thirdCoordinate.getOrdinate()  - firstCoordinate.getOrdinate());
        double c = thirdCoordinate.getAbscissa() *(firstCoordinate.getOrdinate()  - secondCoordinate.getOrdinate());
        return 0.5*abs(a + b + c);
    }
    else{
        return 0;
    }
}




int main(int argc, char const *argv[])
{
    // Tạo ra hai điểm A và B và C
    Point A(2, 3);
    Point B(5, 1);
    Point C(7, 8);

    // Tạo ra một đối tượng SpaceMath1 với hai điểm A và B
    SpaceMath spaceMath1(A, B);
    // Tạo ra một đối tượng SpaceMath2 với ba điểm A, B và C
    SpaceMath spaceMath2(A, B, C);

    // Tính khoảng cách giữa hai điểm A và B
    double distance = spaceMath1.calculateDistance();
    // Tính diện tích của tam giác được tạo bởi ba điểm A, B và C
    double area = spaceMath2.calculateAreaOfTriangle();

    // In ra màn hình khoảng cách giữa hai điểm A và B
    printf("Khoang cach giua hai diem A va B la: %.2f\n", distance);
    // In ra màn hình diện tích của tam giác được tạo bởi ba điểm A, B và C
    printf("Dien tich tam giac A, B, C la: %.2f\n", area);

    return 0;
}
