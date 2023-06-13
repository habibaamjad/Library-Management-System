#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
private:
    string id;
    string name;
    string author;
    int issueNumber;

protected:
    LibraryItem(string, string, string);

public:
    string getId();
    string getName();
    string getAuthor();
    int getIssueNumber();

    void setId(string);
    void setName(string);
    void setAuthor(string);
    void setIssueNumber(int);

    virtual void checkOut() = 0;
    virtual void checkIn() = 0;
    virtual void displayItemInfo() = 0;
};

class Book : public LibraryItem
{
private:
    int numPages;
    int releaseYear;

public:
    Book(string, string, string, int, int);
    int getNumPages();
    int getReleaseYear();
    void setNumPages(int);
    void setReleaseYear(int);
    void checkOut();
    void checkIn();
    void displayItemInfo();
};

class Magazine : public LibraryItem
{
private:
    int numPages;
    string genre;

public:
    Magazine(string, string, string, int, string);
    int getNumPages();
    string getGenre();
    void setNumPages(int);
    void setGenre(string);
    void checkOut();
    void checkIn();
    void displayItemInfo();
};

class Movie : public LibraryItem
{
private:
    int runningTime;
    string genre;
    int releaseYear;

public:
    Movie(string, string, string, int, string, int);
    int getRunningTime();
    string getGenre();
    int getReleaseYear();
    void setRunningTime(int);
    void setGenre(string);
    void setReleaseYear(int);
    void checkOut();
    void checkIn();
    void displayItemInfo();
};

LibraryItem::LibraryItem(string id, string name, string author)
{
    this->id = id;
    this->name = name;
    this->author = author;
    this->issueNumber = 0;
}

string LibraryItem::getId()
{
    return id;
}

string LibraryItem::getName()
{
    return name;
}

string LibraryItem::getAuthor()
{
    return author;
}

int LibraryItem::getIssueNumber()
{
    return issueNumber;
}

void LibraryItem::setId(string id)
{
    this->id = id;
}

void LibraryItem::setName(string name)
{
    this->name = name;
}

void LibraryItem::setAuthor(string author)
{
    this->author = author;
}

void LibraryItem::setIssueNumber(int issueNumber)
{
    this->issueNumber = issueNumber;
}

Book::Book(string id, string name, string author, int numPages, int releaseYear)
    : LibraryItem(id, name, author)
{
    this->numPages = numPages;
    this->releaseYear = releaseYear;
}

int Book::getNumPages()
{
    return numPages;
}

int Book::getReleaseYear()
{
    return releaseYear;
}

void Book::setNumPages(int numPages)
{
    this->numPages = numPages;
}

void Book::setReleaseYear(int releaseYear)
{
    this->releaseYear = releaseYear;
}

void Book::checkOut()
{
    // getIssueNumber() = 0;
    int issueNum = getIssueNumber();
    issueNum++;
    setIssueNumber(issueNum);
    cout << "Book checked out successfully!\n";
}

void Book::checkIn()
{
    int issueNum = getIssueNumber();
    // cout << getIssueNumber() << endl;
    issueNum--;
    setIssueNumber(issueNum);
    cout << "Book checked in successfully!\n";
}

void Book::displayItemInfo()
{
    cout << "Book ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Author: " << getAuthor() << endl;
    cout << "Number of Pages: " << numPages << endl;
    cout << "Release Year: " << releaseYear << endl;
}

Magazine::Magazine(string id, string name, string author, int numPages, string genre)
    : LibraryItem(id, name, author)
{
    this->numPages = numPages;
    this->genre = genre;
}

int Magazine::getNumPages()
{
    return numPages;
}

string Magazine::getGenre()
{
    return genre;
}

void Magazine::setNumPages(int numPages)
{
    this->numPages = numPages;
}

void Magazine::setGenre(string genre)
{
    this->genre = genre;
}

void Magazine::checkOut()
{
    int issueNum = getIssueNumber();
    issueNum++;
    setIssueNumber(issueNum);
    cout << "Magazine checked out successfully!\n";
}

void Magazine::checkIn()
{
    int issueNum = getIssueNumber();
    issueNum--;
    setIssueNumber(issueNum);
    cout << "Magazine checked in successfully!\n";
}

void Magazine::displayItemInfo()
{
    cout << "Magazine ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Author: " << getAuthor() << endl;
    cout << "Number of Pages: " << numPages << endl;
    cout << "Genre: " << genre << endl;
}

Movie::Movie(string id, string name, string author, int runningTime, string genre, int releaseYear)
    : LibraryItem(id, name, author)
{
    this->runningTime = runningTime;
    this->genre = genre;
    this->releaseYear = releaseYear;
}

int Movie::getRunningTime()
{
    return runningTime;
}

string Movie::getGenre()
{
    return genre;
}

int Movie::getReleaseYear()
{
    return releaseYear;
}

void Movie::setRunningTime(int runningTime)
{
    this->runningTime = runningTime;
}

void Movie::setGenre(string genre)
{
    this->genre = genre;
}

void Movie::setReleaseYear(int releaseYear)
{
    this->releaseYear = releaseYear;
}

void Movie::checkOut()
{
    int issueNum = getIssueNumber();
    issueNum++;
    setIssueNumber(issueNum);
    cout << "Movie checked out successfully!\n";
}

void Movie::checkIn()
{
    int issueNum = getIssueNumber();
    issueNum--;
    setIssueNumber(issueNum);
    cout << "Movie checked in successfully!\n";
}

void Movie::displayItemInfo()
{
    cout << "Movie ID: " << getId() << endl;
    cout << "Name: " << getName() << endl;
    cout << "Author: " << getAuthor() << endl;
    cout << "Running Time (in minutes): " << runningTime << endl;
    cout << "Genre: " << genre << endl;
    cout << "Release Year: " << releaseYear << endl;
}

int main()
{
    LibraryItem *libraryItems[100];
    int currSize = 0;

    // The main menu of the library system
    int choice;
    do
    {
        cout << "***Main Menu***\n";
        cout << "1. Create new item\n";
        cout << "2. Check out item\n";
        cout << "3. Check in item\n";
        cout << "4. List all items\n";
        cout << "5. List all checked out items\n";
        cout << "6. Search for item by Name or Author\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // Creating new item
            cout << "What type of item do you want to create?\n";
            cout << "1. Book\n";
            cout << "2. Magazine\n";
            cout << "3. Movie\n";
            cout << "Enter your choice: ";
            int itemChoice;
            cin >> itemChoice;

            string id;
            string name;
            string author;
            int numPages;
            string genre;
            int releaseYear;
            int runningTime;

            // Take inputs
            cout << "Enter the ID (Book format : BK0001 , Magazine format : MG0001 , Movie format : MV0001 and numbers should be between 0001 and 9999): ";
            cin >> id;
            // Check for duplicates
            bool duplicate = false;
            for (int i = 0; i < currSize; i++)
            {
                if (libraryItems[i]->getId() == id)
                {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate)
            {
                cout << "Item with ID " << id << " already exists!" << endl;
                break;
            }
            cout << "Enter the name: ";
            cin.ignore();
            getline(cin, name);
            // Check for duplicates
            for (int i = 0; i < currSize; i++)
            {
                if (libraryItems[i]->getName() == name)
                {
                    duplicate = true;
                    break;
                }
            }
            if (duplicate)
            {
                cout << "Item with name " << name << " already exists!" << endl;
                break;
            }
            cout << "Enter the author: ";
            getline(cin, author);

            switch (itemChoice)
            {
            case 1:
            {
                cout << "Enter the number of pages: ";
                cin >> numPages;
                cout << "Enter the release year: ";
                cin >> releaseYear;
                libraryItems[currSize] = new Book(id, name, author, numPages, releaseYear);
                break;
            }
            case 2:
            {
                cout << "Enter the number of pages: ";
                cin >> numPages;
                cout << "Enter the genre: ";
                cin.ignore();
                getline(cin, genre);
                libraryItems[currSize] = new Magazine(id, name, author, numPages, genre);
                break;
            }
            case 3:
            {
                cout << "Enter the running time (in minutes): ";
                cin >> runningTime;
                cout << "Enter the genre: ";
                cin.ignore();
                getline(cin, genre);
                cout << "Enter the release year: ";
                cin >> releaseYear;
                libraryItems[currSize] = new Movie(id, name, author, runningTime, genre, releaseYear);
                break;
            }
            default:
                cout << "Invalid choice!\n";
            }
            currSize++;
            cout << "Item created successfully!\n";
        }
        break;

        case 2:
        {
            string id;
            cout << "Enter item ID: ";
            cin >> id;

            // Search for LibraryItem with given ID
            LibraryItem *item = nullptr;
            for (int i = 0; i < currSize; i++)
            {
                if (libraryItems[i]->getId() == id)
                {
                    item = libraryItems[i];
                    break;
                }
            }

            // Check if item is already checked out
            if (item != nullptr)
            {
                if (item->getIssueNumber() == 0)
                {
                    // Check if user has already checked out 5 items
                    int checkedOutCount = 0;
                    for (int i = 0; i < currSize; i++)
                    {
                        if (libraryItems[i]->getIssueNumber() != 0)
                        {
                            checkedOutCount++;
                        }
                    }
                    if (checkedOutCount >= 5)
                    {
                        cout << "You have already checked out 5 items!" << endl;
                    }
                    else
                    {
                        item->checkOut();
                    }
                }
                else
                {
                    cout << "Item has already been checked out!" << endl;
                }
            }
            else
            {
                cout << "Item not found!" << endl;
            }
        }
        break;

        case 3:
        {
            string id;
            cout << "Enter item ID: ";
            cin >> id;

            // Search for LibraryItem with given ID
            LibraryItem *item = nullptr;
            for (int i = 0; i < currSize; i++)
            {
                if (libraryItems[i]->getId() == id)
                {
                    item = libraryItems[i];
                    break;
                }
            }

            // Check in item
            if (item != nullptr)
            {
                if (item->getIssueNumber() != 0)
                {
                    item->checkIn();
                }
                else
                {
                    cout << "Item is not checked out!" << endl;
                }
            }
            else
            {
                cout << "Item not found!" << endl;
            }
        }
        break;

        case 4:
        {
            // List all items
            cout << "List of All Items of the Library: " << endl;
            for (int i = 0; i < currSize; i++)
            {
                libraryItems[i]->displayItemInfo();
                cout << endl;
            }
        }
        break;

        case 5:
        {
            // List all checked out items
            bool checkedOut = false;
            cout << "List of all checked out items: \n";
            for (int i = 0; i < currSize; i++)
            {
                if (libraryItems[i]->getIssueNumber() > 0)
                {
                    libraryItems[i]->displayItemInfo();
                    cout << endl;
                    checkedOut = true;
                }
            }
            if (!checkedOut)
            {
                cout << "None!\n";
            }
        }
        break;

        case 6:
        {
            // Search for item by Name or Author
            string searchTerm;
            cout << "Enter the Name or Author of the item: ";
            cin.ignore();
            getline(cin, searchTerm);
            bool found = false;
            cout << "List of all matched items: \n";
            for (int i = 0; i < currSize; i++)
            {
                string name = libraryItems[i]->getName();
                string author = libraryItems[i]->getAuthor();
                if (name.find(searchTerm) != string::npos || author.find(searchTerm) != string::npos)
                {
                    libraryItems[i]->displayItemInfo();
                    cout << endl;
                    found = true;
                }
            }
            if (!found)
            {
                cout << "No matches found!\n";
            }
        }
        break;

        case 7:
        {
            cout << "You have exited the library system.\n";
            break;
        }

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}