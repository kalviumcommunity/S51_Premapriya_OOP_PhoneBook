#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name;
    double phoneNumber;
    string email;
    string address;

    // Static variable to keep track of the total number of contacts created
    static int totalContacts;

    // Constructor
    Contact(string name, double phoneNumber, string email, string address) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->address = address;
        totalContacts++;  // Increment totalContacts whenever a new contact is created
    }

    // Destructor
    ~Contact() {
        totalContacts--;  // Decrement totalContacts when a contact is deleted
    }

    //Accessors(getters)

    string getName()const{
        return name;
    }
    double getPhoneNumber()const{
        return phoneNumber;
    }
    string getEmail()const{
        return email;
    }
    string getAddress()const{
        return address;
    }

    //Mutators(setters)

    void setName(const string& name){
        this->name=name;
    }
    void setPhoneNumber(const double& phoneNumber){
        this->phoneNumber=phoneNumber;
    }
    void setEmail(const string& email){
        this->email=email;
    }
    void setAddress(const string& address){
        this->address=address;
    }

    void displayContact() const {
        cout << "Name: " << getName() << endl;
        cout << "Phone Number: " << getPhoneNumber() << endl;
        cout << "Email: " << getEmail()<< endl;
        cout << "Address: " << getAddress() << endl;
    }

    void updateContact(string name, int phoneNumber, string email, string address) {
        setName(name);
        setPhoneNumber(phoneNumber);
        setEmail(email);
        setAddress(address);
    }

    // Static member function to display the total number of contacts created
    static void displayTotalContacts() {
        cout << "Total Contacts Created: " << totalContacts << endl;
    }
};

// Initialize static variable for Contact
int Contact::totalContacts = 0;

class Phonebook {
private:
    vector<Contact*> contacts;
public:
    // Static variable to keep track of the number of Phonebook instances created
    static int phonebookCount;

    // Constructor
    Phonebook() {
        phonebookCount++;  // Increment phonebookCount whenever a new phonebook is created
    }

    // Destructor
    ~Phonebook() {
        for (Contact* contact : contacts) {
            delete contact;
        }
    }

    // Accessor (Getter)
    vector<Contact*> getContacts()const{
        return contacts;
    }
    //Mutator (Setter)
    void setContact(vector<Contact*>& contacts){
        this->contacts=contacts;
    }

    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    void displayAllContacts() const {
        for (Contact* contact : contacts) {
            contact->displayContact();
            cout << endl;
        }
    }

    static void displayStats() {
       cout << "Total Phonebooks Created: " << phonebookCount << endl;
        // Call static member function of Contact class
        Contact::displayTotalContacts();    }
};

// Initialize static variable for Phonebook
int Phonebook::phonebookCount = 0;

int main() {
    // Dynamically allocating memory for Contact objects
    Contact* contact1 = new Contact("Prema", 1234567890, "prema@example.com", "123 Main St");
    Contact* contact2 = new Contact("Priya", 9876543210, "priya@example.com", "456 Elm St");


    // Creating Phonebook object
    Phonebook phonebook;

    // Adding contacts to the phonebook
    phonebook.addContact(contact1);
    phonebook.addContact(contact2);

    vector<Contact*> contacts = phonebook.getContacts();
    for (Contact* contact : contacts) {
        contact->displayContact();
        cout << endl;
    }

    // Displaying all contacts in the phonebook
    phonebook.displayAllContacts();

    // Displaying statistics
    Phonebook::displayStats();

    return 0;
}
