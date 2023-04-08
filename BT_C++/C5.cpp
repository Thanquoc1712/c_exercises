#include <stdio.h>
#include <string.h>
#include <stdint.h>

using namespace std;

class People{
private:
    char name[20];
    uint8_t age;
    char address[30];
public:
    People( char name [], uint8_t age, char address[]);
    void setName(char name []);
    void setAge(uint8_t);
    void setAdress(char address[]);

    uint8_t getAge();
    char *getName();
    char *getAdress();
};


People::People(char name[], uint8_t age, char address[]) {
    setName(name);
    setAge(age);
    setAdress(address);
}

void People::setName(char name[]) {
strcpy(this->name, name);
}

void People::setAge(uint8_t age) {
this->age = age;
}

void People::setAdress(char address[]) {
strcpy(this->address, address);
}

char *People::getName() {
return this->name;
}

uint8_t People::getAge() {
return this->age;
}

char *People::getAdress() {
return this->address;
}

void printInfo(People person) {
printf("Name: %s\n", person.getName());
printf("Age: %d\n", person.getAge());
printf("Address: %s\n", person.getAdress());
}

int main() {
    char name[20];
    uint8_t age;
    char address[30];

    printf("Enter name: ");
    scanf("%s", name);

    printf("Enter age: ");
    scanf("%hhu", &age);

    printf("Enter address: ");
    scanf("%s", address);

    People person(name, age, address);

    printInfo(person);

    return 0;
}