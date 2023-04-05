#include <stdio.h>
#include <string.h>
#include <stdint.h>

using namespace std;

class Animal {
    private:
        char nameAnimal[50];
        uint8_t ageAnimal;
        double weightAnimal;
        double heightAnimal;

    public:
        Animal(char name[], uint8_t age, double weight,double height);
        void setNameAnimal(char name[]);
        void setAgeAnimal(uint8_t age);
        void setWeightAnimal(double weight);
        void setHeightAnimal(double height);


        char* getNameAnimal();
        uint8_t getAgeAnimal();
        double getWeightAnimal();
        double getHeightAnimal();


        double calculateBMI();
        void compareAge(Animal other);
        void compareWeight(Animal other);
};

Animal::Animal(char name[], uint8_t age, double weight,double height) {
    setNameAnimal(name);
    setAgeAnimal(age);
    setWeightAnimal(weight);
    setHeightAnimal(height);
}

void Animal::setNameAnimal(char name[]) {
    strcpy(nameAnimal, name);
}

void Animal::setAgeAnimal(uint8_t age) {
    ageAnimal = age;
}

void Animal::setWeightAnimal(double weight) {
    weightAnimal = weight;
}
void Animal::setHeightAnimal(double height) {
    heightAnimal = height;
}

char* Animal::getNameAnimal() {
    return nameAnimal;
}
uint8_t Animal::getAgeAnimal() {
    return ageAnimal;
}

double Animal::getWeightAnimal() {
    return weightAnimal;
}
double Animal::getHeightAnimal() {
    return heightAnimal;
}



double Animal::calculateBMI() {
    return weightAnimal / (heightAnimal * heightAnimal);
}

void Animal::compareAge(Animal other) {
    if (ageAnimal < other.ageAnimal) {
        printf("%s is younger than %s\n", nameAnimal, other.getNameAnimal());
    }
    else if (ageAnimal > other.ageAnimal) {
        printf("%s is older than %s\n", nameAnimal, other.getNameAnimal());
    }
    else {
        printf("%s and %s are the same age\n", nameAnimal, other.getNameAnimal());
    }
}

void Animal::compareWeight(Animal other) {
    if (weightAnimal < other.weightAnimal) {
        printf("%s weighs less than %s\n", nameAnimal, other.getNameAnimal());
    }
    else if (weightAnimal > other.weightAnimal) {
        printf("%s weighs more than %s\n", nameAnimal, other.getNameAnimal());
    }
    else {
        printf("%s and %s weigh the same\n", nameAnimal, other.getNameAnimal());
    }
}

int main() {
    
    Animal dog("dog", 3, 8.2,6.5);
    Animal cat("cat", 2, 4.5 ,3.7);
     printf("%s's BMI is %f\n", dog.getNameAnimal(), dog.calculateBMI());
    printf("%s's BMI is %f\n", cat.getNameAnimal(), cat.calculateBMI());
    dog.compareAge(cat);
    cat.compareWeight(dog);
   
    return 0;
}
