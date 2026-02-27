#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class LibraryItem {
public:
    virtual void display() const = 0;  
    virtual ~LibraryItem() {}
};

// Book class
class Book : public LibraryItem 
{
private:
    string title;
    string author;
    int pages;

public:
    Book() : title(""), author(""), pages(0) {}
    Book(string t, string a, int p) : title(t), author(a), pages(p) {}

    string getTitle() const { return title; }
    int getPages() const { return pages; }

    void display() const override {
        cout << "Book: " << title << " by " << author << ", Pages: " << pages << endl;
    }
};

// Newspaper class
class Newspaper : public LibraryItem
{
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() : name(""), date(""), edition("") {}
    Newspaper(string n, string d, string e) : name(n), date(d), edition(e) {}

    string getName() const { return name; }
    string getEdition() const { return edition; }

    void display() const override {
        cout << "Newspaper: " << name << ", Date: " << date << ", Edition: " << edition << endl;
    }
};

// Library class
class Library
{
private:
    Book books[10];          
    Newspaper newspapers[10]; 
    int bookCount;
    int newspaperCount;

public:
    Library() : bookCount(0), newspaperCount(0) {}

    void addBook(const Book& b)
    {
        if (bookCount < 10) 
        {
            books[bookCount++] = b;
        }
    }

    void addNewspaper(const Newspaper& n) 
    {
        if (newspaperCount < 10)
        {
            newspapers[newspaperCount++] = n;
        }
    }

    void displayCollection() const {
        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }

        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = 0; j < newspaperCount - 1 - i; j++) {
                if (newspapers[j].getEdition() > newspapers[j + 1].getEdition()) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - 1 - i; j++) {
                if (books[j].getPages() > books[j + 1].getPages()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(const string& title) {
        for (int i = 0; i < bookCount; i++) 
        {
            if (books[i].getTitle() == title) return &books[i];
        }
        return nullptr;
    }

    Newspaper* searchNewspaperByName(const string& name) {
        for (int i = 0; i < newspaperCount; i++) 
        {
            if (newspapers[i].getName() == name) return &newspapers[i];
        }
        return nullptr;
    }
};

// Main function
int main() {
    // Create book objects
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    // Create newspaper objects
    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    // Create a library object
    Library library;

    // Add books and newspapers to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    // Display the entire collection
    cout << "Library Collection:\n";
    library.displayCollection();

    // Sort books by pages and newspapers by edition
    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();


    // Search for a book by title
    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    // Search for a newspaper by name
    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}
