#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact{
    public:
        string name;
        string phoneNumber;
        string email;
        string address;

        Contact(string name, string phoneNumber, string email, string address){
            this -> name = name;
            this -> phoneNumber = phoneNumber;
            this -> email = email;
            this -> address = address;

        }
            

        void displayContact(){
            cout<< "Name: " << name <<endl;
            cout<< "Phone Number: " << phoneNumber <<endl;
            cout<< "Email: " << email <<endl;
            cout<< "Address: " << address <<endl;
        }
        void updateContact(string name, string phoneNumber, string email, string address){
           this -> name=name;
            this -> phoneNumber=phoneNumber;
            this -> email=email;
            this -> address=address;
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

int main()
{
    // Creating Contact objects
    Contact contact1("Prema", "123-456-7890", "prema@example.com", "123 Main St");
    Contact contact2("Priya", "987-654-3210", "priya@example.com", "456 Elm St");

    // Displaying contact details
    cout << "\nContact 1 Details:" << endl;
    contact1.displayContact();
    cout << endl;

    cout << "Contact 2 Details:" << endl;
    contact2.displayContact();
    cout << endl;

    // Creating Phonebook object
    Phonebook phonebook;

    // Adding contacts to phonebook
    phonebook.addContact(contact1);
    phonebook.addContact(contact2);

    // Displaying all contacts in the phonebook
    cout << "\nPhonebook Contacts:" << endl;
    phonebook.displayAllContacts();

    return 0;
}