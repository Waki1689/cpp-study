
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// ==========================================
// CONTACT CLASS
// ==========================================

class Contact
{
private:
    string firstName;
    string lastName;
    string phoneNumber;

public:

    // Default constructor
    Contact()
    {
        firstName = "";
        lastName = "";
        phoneNumber = "";
    }

    // Parameterized constructor
    Contact(string first, string last, string phone)
    {
        firstName = first;
        lastName = last;
        phoneNumber = phone;
    }

    // Getters
    string getFirstName() const
    {
        return firstName;
    }

    string getLastName() const
    {
        return lastName;
    }

    string getPhoneNumber() const
    {
        return phoneNumber;
    }

    // Compare contacts using phone number
    bool operator==(const Contact& other) const
    {
        return phoneNumber == other.phoneNumber;
    }
};


// ==========================================
// PHONEBOOK CLASS
// ==========================================

class PhoneBook
{
private:

    Contact* contacts;
    int contactCount;
    int arraySize;

    // Add a contact
    void AddContact()
    {
        if (contactCount == arraySize)
        {
            cout << "\nPhoneBook is full!\n";
            return;
        }

        string first, last, phone;

        cout << "\nEnter first name: ";
        getline(cin, first);

        cout << "Enter last name: ";
        getline(cin, last);

        cout << "Enter phone number: ";
        getline(cin, phone);

        Contact newContact(first, last, phone);

        // Check for duplicate phone numbers
        for (int i = 0; i < contactCount; i++)
        {
            if (contacts[i] == newContact)
            {
                cout << "\nA contact with this phone number "
                     << "already exists!\n";
                return;
            }
        }

        contacts[contactCount] = newContact;
        contactCount++;

        cout << "\nContact added successfully!\n";

        if (contactCount == arraySize)
        {
            cout << "PhoneBook is now full!\n";
        }
    }

    // Save contacts to file
    void SaveContactsToFile()
    {
        ofstream file("contacts.txt");

        if (!file.is_open())
        {
            cout << "\nUnable to open file!\n";
            return;
        }

        for (int i = 0; i < contactCount; i++)
        {
            file << "First Name: "
                 << contacts[i].getFirstName() << endl;

            file << "Last Name: "
                 << contacts[i].getLastName() << endl;

            file << "Phone Number: "
                 << contacts[i].getPhoneNumber() << endl;

            file << "----------------------\n";
        }

        file.close();

        cout << "\nContacts saved successfully to contacts.txt!\n";
    }

    // Display all contacts
    void ShowAllContacts()
    {
        if (contactCount == 0)
        {
            cout << "\nNo contacts available!\n";
            return;
        }

        cout << "\n========== ALL CONTACTS ==========\n";

        for (int i = 0; i < contactCount; i++)
        {
            cout << "\nContact " << i + 1 << endl;

            cout << "First Name: "
                 << contacts[i].getFirstName() << endl;

            cout << "Last Name: "
                 << contacts[i].getLastName() << endl;

            cout << "Phone Number: "
                 << contacts[i].getPhoneNumber() << endl;
        }

        cout << "\n==================================\n";
    }

public:

    // Default constructor
    PhoneBook()
    {
        arraySize = 5;
        contactCount = 0;

        contacts = new Contact[arraySize];
    }

    // Destructor
    ~PhoneBook()
    {
        delete[] contacts;
    }

    // Main application menu
    void Run()
    {
        int choice = 0;

        do
        {
            cout << "\n========== PHONEBOOK ==========\n";
            cout << "1. Add Contact\n";
            cout << "2. Show All Contacts\n";
            cout << "3. Save Contacts To File\n";
            cout << "4. Exit\n";

            cout << "\nChoose an option: ";

            if (!(cin >> choice))
            {
                cout << "\nInvalid input! Enter a number.\n";

                cin.clear();
                cin.ignore(10000, '\n');

                continue;
            }

            cin.ignore(10000, '\n');

            switch (choice)
            {
                case 1:
                    AddContact();
                    break;

                case 2:
                    ShowAllContacts();
                    break;

                case 3:
                    SaveContactsToFile();
                    break;

                case 4:
                    cout << "\nExiting PhoneBook...\n";
                    break;

                default:
                    cout << "\nInvalid option! Try again.\n";
            }

        } while (choice != 4);
    }
};


// ==========================================
// MAIN FUNCTION
// ==========================================

int main()
{
    PhoneBook myPhoneBook;

    myPhoneBook.Run();

    return 0;
}
