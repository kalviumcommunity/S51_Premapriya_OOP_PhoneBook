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

    void displayContact() const {
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
    vector<Contact* > contacts;

    // Destructor to free dynamically allocated memory
    Phonebook(){
        for (Contact* contact:contacts){
            delete contact;
        }
    }

    // Member functions
    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    void displayAllContacts() {
        for (Contact* contact : contacts) {
            contact->displayContact();
            cout << endl;
        }
    }
};

int main() {
    // Dynamically allocating memory for Contact objects
    Contact* contact1 = new Contact("Prema", "123-456-7890", "prema@example.com", "123 Main St");
    Contact* contact2 = new Contact("Priya", "987-654-3210", "priya@example.com", "456 Elm St");

    contact1 -> displayContact();
    cout<<endl;
    contact2->displayContact();
    cout<<endl;
    
    // Creating Phonebook object
    Phonebook phonebook;

    phonebook.addContact(contact1);
    phonebook.addContact(contact2);

    // Displaying all contacts in the phonebook
    phonebook.displayAllContacts();

    return 0;
}
