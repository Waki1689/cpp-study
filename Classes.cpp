#include <iostream>
#include <string>
using namespace std;

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

    // Overloaded constructor
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

    // Setters
    void setFirstName(string first)
    {
        firstName = first;
    }

    void setLastName(string last)
    {
        lastName = last;
    }

    void setPhoneNumber(string phone)
    {
        phoneNumber = phone;
    }

    // Overloaded equality operator
    bool operator==(const Contact& other) const
    {
        return phoneNumber == other.phoneNumber;
    }
};


int main()
{
    Contact contact1("John", "Doe", "123-456-7890");
    Contact contact2("Jane", "Smith", "123-456-7890");
    Contact contact3("Alice", "Johnson", "987-654-3210");

    if (contact1 == contact2)
    {
        cout << "Contact 1 and Contact 2 are the same." << endl;
    }
    else
    {
        cout << "Contact 1 and Contact 2 are different." << endl;
    }

    if (contact1 == contact3)
    {
        cout << "Contact 1 and Contact 3 are the same." << endl;
    }
    else
    {
        cout << "Contact 1 and Contact 3 are different." << endl;
    }

    return 0;
}