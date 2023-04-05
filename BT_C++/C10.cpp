#include <stdio.h>
#include <string.h>
#include <stdint.h>

class Book {
private:
    char bookTitle[30];
    char bookAuthor[30];
    int publishingYear;
    int numberOfBooks;

public:
    Book(char title[30], char author[30], int year, int number);

    void setBookTitle(char title[30]);
    void setBookAuthor(char author[30]);
    void setPublishingYear(int year);
    void setNumberOfBooks(int number);

    char* getBookTitle();
    char* getBookAuthor();
    int getPublishingYear();
    int getNumberOfBooks();

    void printBookInformation();
    void borrowBooks(int numberOfBooksToBorrow);
    void giveBookBack(int numberOfBooksReturned);
};

Book::Book(char title[30], char author[30], int year, int number) {
    strcpy(bookTitle, title);
    strcpy(bookAuthor, author);
    publishingYear = year;
    numberOfBooks = number;
}

void Book::setBookTitle(char title[30]) {
    strcpy(bookTitle, title);
}

void Book::setBookAuthor(char author[30]) {
    strcpy(bookAuthor, author);
}

void Book::setPublishingYear(int year) {
    publishingYear = year;
}

void Book::setNumberOfBooks(int number) {
    numberOfBooks = number;
}

char* Book::getBookTitle() {
    return bookTitle;
}

char* Book::getBookAuthor() {
    return bookAuthor;
}

int Book::getPublishingYear() {
    return publishingYear;
}

int Book::getNumberOfBooks() {
    return numberOfBooks;
}

void Book::printBookInformation() {
    printf("Book Title: %s\n", bookTitle);
    printf("Book Author: %s\n", bookAuthor);
    printf("Publishing Year: %d\n", publishingYear);
    printf("Number of Books: %d\n", numberOfBooks);
}

void Book::borrowBooks(int numberOfBooksToBorrow) {
    if (numberOfBooks >= numberOfBooksToBorrow) {
        numberOfBooks -= numberOfBooksToBorrow;
        printf("Book borrowed successfully!\n");
    }
    else {
        printf("Book is out of stock!\n");
    }
}

void Book::giveBookBack(int numberOfBooksReturned) {
    numberOfBooks = numberOfBooks+ numberOfBooksReturned;
    printf("Book returned successfully!\n");
}

int main(int argc, char const *argv[]) {
    char bookTitle[30];
    char bookAuthor[30];
    int publishingYear;
    int numberOfBooks;
    int numberOfBooksToBorrow;
    int numberOfBooksReturned;
    
    int choice = 0;
    
    printf("Please enter the title of the book: ");
    scanf(" %s", &bookTitle);

    printf("Please enter the author of the book: ");
    scanf(" %s", &bookAuthor);

    printf("Please enter the publication year of the book: ");
    scanf("%d", &publishingYear);

    printf("Please enter the number Of Books  ");
    scanf("%d", &numberOfBooks);

  

    Book book1(bookTitle, bookAuthor, publishingYear, numberOfBooks);


    do {
        printf("\n");
        printf("Please select an option:\n");
        printf("1 - Print book information\n");
        printf("2 - Borrow book\n");
        printf("3 - Return book\n");
        printf("4 - Exit\n");
        printf("\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                book1.printBookInformation();
                break;
            case 2:
              printf("Please enter the number Of Books ToBorrow: ");
              scanf("%d", &numberOfBooksToBorrow);
                book1.borrowBooks(numberOfBooksToBorrow);
                break;
            case 3:
                printf("Please enter the number of books returned: ");
                scanf("%d", &numberOfBooksReturned);
                book1.giveBookBack(numberOfBooksReturned);
                break;
            case 4: 
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
