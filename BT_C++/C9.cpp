#include <stdio.h>
#include <string.h>
#include <stdint.h>

class Car {
    private:
        char color [30];
        char modem [30];
        double kmDriven;
    public:
        Car ( char  cl [], char md[] , double km);
        void setColor(char  cl [] );
        void setModem(char md[]);
        void setKmDriven(double Km);

        char *getColor();
        char *getModem();
        double getKmDriven();

        void printVehicleInformation();
        void checkKm();
        double maintenanceCost(double limitKm);
};

Car::Car (  char  cl [], char md[] , double km ){
    strcpy(color, cl);
    strcpy(modem, md);
    kmDriven = km;
}


void Car::setColor(char cl[]) {
    strcpy(color, cl);
}

void Car::setModem(char md[]) {
    strcpy(modem, md);
}

void Car::setKmDriven(double km) {
    kmDriven = km;
}

char* Car::getColor() {
    return color;
}

char* Car::getModem() {
    return modem;
}

double Car::getKmDriven() {
    return kmDriven;
}

void Car::printVehicleInformation() {
    printf("Color: %s\n", color);
    printf("Engine Type: %s\n", modem);
}

void Car::checkKm() {
   printf("Kilometers Driven: %.2f\n", kmDriven);
}

double Car::maintenanceCost(double limitKm) {

    double cost = 0;

    if (kmDriven >= limitKm) {
            printf("Maintenance required.\n");
        if (kmDriven < (limitKm + 10000)) {
            cost = 100;
        } else if ( (kmDriven >= (limitKm + 10000)) &&
                    (kmDriven <= (limitKm + 50000)) ) {
            cost = 500;
        } else {
            cost = 1000;
        }
          return cost;
    }
    else{
        printf("Maintenance not required.\n");
    }
    return 0;
}

int main() {
    char color [30];
    char modem [30];
    double kmDriven;
    double limitKm ;

    printf("Hay nhap mau sac: ");
    scanf(" %s",&color);

    printf("Hay nhap modem: ");
    scanf(" %s",&modem);

    printf("Hay nhap so Km: ");
    scanf("%lf",&kmDriven);

 

    Car myCar(color, modem, kmDriven);

    printf("Hay nhap so Km gioi han: ");
    scanf("%lf",&limitKm);

    myCar.printVehicleInformation();
    myCar.checkKm();

    printf("Maintenance cost: %.2f\n", myCar.maintenanceCost(limitKm));
    return 0;
}