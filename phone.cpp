#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    string phoneNumber;
    string email;
    string address;

    // Default constructor with default values
    Contact(string name = "", string phoneNumber = "", string email = "", string address = "") {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->address = address;
    }

    void displayContact() {
        cout << "Name: " << this->name << endl;
        cout << "Phone Number: " << this->phoneNumber << endl;
        cout << "Email: " << this->email << endl;
        cout << "Address: " << this->address << endl;
    }

    void updateContact(string name, string phoneNumber, string email, string address) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->address = address;
    }
};

class Phonebook {
public:
    // Member variables
    vector<Contact> contacts;

    // Member functions
    void addContact(Contact contact) {
        contacts.push_back(contact);
    }

    void displayAllContacts() {
        for (Contact contact : contacts) {
            contact.displayContact();
            cout << endl;
        }
    }
};

int main() {
    // Array of Contact objects
    Contact contactArray[2];

    // Populating array with contact information
    contactArray[0].updateContact("Prema", "123-456-7890", "prema@example.com", "123 Main St");
    contactArray[1].updateContact("Priya", "987-654-3210", "priya@example.com", "456 Elm St");

    // Displaying contact details from array
    cout << "\nContact Details from Array:" << endl;
    for (int i = 0; i < 2; i++) {
        contactArray[i].displayContact();
        cout << endl;
    }

    // Creating Phonebook object
    Phonebook phonebook;

    // Adding contacts to phonebook from array
    for (int i = 0; i < 2; i++) {
        phonebook.addContact(contactArray[i]);
    }

    // Displaying all contacts in the phonebook
    cout << "\nPhonebook Contacts:" << endl;
    phonebook.displayAllContacts();

    return 0;
}
