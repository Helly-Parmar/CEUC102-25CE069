#include <iostream>
#include <string>
using namespace std;

class libManagement {
public:
    void addnew_book();
    int issue_book(long int);
    int return_book(long int);
    int display_allbook(long int);

private:
    long int book_id;
    string title;
    string author;
    long long available_copies;
};

void libManagement::addnew_book() {
    cout << "Enter Book ID : ";
    cin >> book_id;
    cout << "Enter Book Title : ";
    cin >> title;
    cout << "Enter Author Name : ";
    cin >> author;
    cout << "Enter Number of Copies : ";
    cin >> available_copies;
}

int libManagement::issue_book(long int x) {
    if (book_id == x) {
        if (available_copies > 0) {
            available_copies--;
            cout << "Book Issued Successfully\n";
            return 1;
        } else {
            cout << "ERROR: No copies available\n";
            return -1;
        }
    }
    return 0;
}

int libManagement::return_book(long int x) {
    if (book_id == x) {
        available_copies++;
        cout << "Book Returned Successfully\n";
        return 1;
    }
    return 0;
}

int libManagement::display_allbook(long int x) {
    if (book_id == x) {
        cout << "\nBook ID : " << book_id;
        cout << "\nTitle : " << title;
        cout << "\nAuthor : " << author;
        cout << "\nAvailable Copies : " << available_copies << endl;
        return 1;
    }
    return 0;
}

int main() {
    libManagement A[25];
    int ch, last = 0, i;
    long int bid;

M:
    cout << "\n1:Add new books | 2:Issue book | 3:Return book | 4:Display book details | 5:Exit --> ";
    cin >> ch;

    switch (ch) {
    case 1:
        A[last].addnew_book();
        last++;
        goto M;

    case 2:
        cout << "Enter Book ID : ";
        cin >> bid;
        for (i = 0; i < last; i++) {
            int res = A[i].issue_book(bid);
            if (res == 1 || res == -1)
                break;
        }
        if (i == last)
            cout << "ERROR: Book not found\n";
        goto M;

    case 3:
        cout << "Enter Book ID : ";
        cin >> bid;
        for (i = 0; i < last; i++) {
            if (A[i].return_book(bid) == 1)
                break;
        }
        if (i == last)
            cout << "ERROR: Book not found\n";
        goto M;

    case 4:
        cout << "Enter Book ID : ";
        cin >> bid;
        for (i = 0; i < last; i++) {
            if (A[i].display_allbook(bid) == 1)
                break;
        }
        if (i == last)
            cout << "ERROR: Book not found\n";
        goto M;

    case 5:
        break;

    default:
        cout << "ERROR: Invalid Choice\n";
        goto M;
    }

    return 0;
}

// Name : Helly Parmar
//ID : 25CE069
