#include <stdio.h>
#include <string.h>
#include <stdint.h>

class Date {
private:
    uint8_t day, month;
    uint16_t year, yearNow;
public:
    Date(uint8_t d, uint8_t m, uint16_t y, uint16_t yn);
    void setDay(uint8_t d);
    void setMonth(uint8_t m);
    void setYear(uint16_t y);
    void setYearNow(uint16_t yn);

    uint8_t getDay();
    uint8_t getMonth();
    uint16_t getYear();
    uint16_t getYearNow();

    uint8_t getAge();
    bool isHoliday();
};

Date::Date(uint8_t d, uint8_t m, uint16_t y, uint16_t yn) {
    day = d;
    month = m;
    year = y;
    yearNow = yn;
}

void Date::setDay(uint8_t d) {
    day = d;
}

void Date::setMonth(uint8_t m) {
    month = m;
}

void Date::setYear(uint16_t y) {
    year = y;
}

void Date::setYearNow(uint16_t yn) {
    yearNow = yn;
}

uint8_t Date::getDay() {
    return day;
}

uint8_t Date::getMonth() {
    return month;
}

uint16_t Date::getYear() {
    return year;
}

uint16_t Date::getYearNow() {
    return yearNow;
}

uint8_t Date::getAge() {
    uint8_t age = yearNow - year;
    return age;
}

bool Date::isHoliday() {
    uint8_t holidays[2][2] = {{30, 4}, {1, 5}};
    for (int i = 0; i < 2; i++) {
        if (day == holidays[i][0] && month == holidays[i][1]) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    uint8_t day, month;
    uint16_t year, yearNow;

    printf("Enter day: ");
    scanf("%hhu", &day);

    printf("Enter month: ");
    scanf("%hhu", &month);

    printf("Enter year: ");
    scanf("%hu", &year);

    printf("Enter current year: ");
    scanf("%hu", &yearNow);

    Date d(day, month, year, yearNow);

    printf("Date: %d/%d/%d\n", d.getDay(), d.getMonth(), d.getYear());
    printf("Age: %d\n", d.getAge());

    if (d.isHoliday()) {
        printf("This day is a holiday.\n");
    } else {
        printf("This day is not a holiday.\n");
    }

    return 0;
}
