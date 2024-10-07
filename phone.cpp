#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Person an abstract class
class Person {
protected:
    string name;
public:
    Person(string name) {
        this->name = name;
    }
    string getName() const {
        return name;
    }
    void setName(const string& name) {
        this->name = name;
    }

   // Pure virtual function (abstract method)
    virtual void displayInfo() const = 0;
};

class Contact : public Person {
private:
    string phoneNumber;
    string email;
    string address;
    string companyName;  // New member variable for company name
    string jobTitle;     // New member variable for job title

    // Static variable to keep track of the total number of contacts created
    static int totalContacts;

public:

    // Constructor
    Contact(string name, string phoneNumber, string email, string address, string companyName, string jobTitle) : Person(name) {
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->address = address;
        this->companyName = companyName;  // Initialize company name
        this->jobTitle = jobTitle;        // Initialize job title
        totalContacts++;  // Increment totalContacts whenever a new contact is created
    }

    // Destructor
    ~Contact() {
        totalContacts--;  // Decrement totalContacts when a contact is deleted
    }

    //Accessors(getters)
    string getPhoneNumber() const {
        return phoneNumber;
    }
    string getEmail() const {
        return email;
    }
    string getAddress() const {
        return address;
    }
    string getCompanyName() const {  // Getter for company name
        return companyName;
    }
    string getJobTitle() const {  // Getter for job title
        return jobTitle;
    }

    //Mutators(setters)
    void setPhoneNumber(const string& phoneNumber) {
        this->phoneNumber = phoneNumber;
    }
    void setEmail(const string& email) {
        this->email = email;
    }
    void setAddress(const string& address) {
        this->address = address;
    }
    void setCompanyName(const string& companyName) {  // Setter for company name
        this->companyName = companyName;
    }
    void setJobTitle(const string& jobTitle) {  // Setter for job title
        this->jobTitle = jobTitle;
    }

    // Function to display contact details
    void displayInfo() const override { // Override the pure virtual function
        cout << "Name: " << getName() << endl;
        cout << "Phone Number: " << getPhoneNumber() << endl;
        cout << "Email: " << getEmail() << endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Company Name: " << getCompanyName() << endl;  // Display company name
        cout << "Job Title: " << getJobTitle() << endl;        // Display job title
    }

    // Overloaded updateContact functions
    void updateContact(string name, string phoneNumber, string email, string address) {
        setName(name);
        setPhoneNumber(phoneNumber);
        setEmail(email);
        setAddress(address);
    }

    void updateContact(string name, string phoneNumber, string email, string address, string companyName, string jobTitle) {
        setName(name);
        setPhoneNumber(phoneNumber);
        setEmail(email);
        setAddress(address);
        setCompanyName(companyName);
        setJobTitle(jobTitle);
    }

    // Static member function to display the total number of contacts created
    static void displayTotalContacts() {
        cout << "Total Contacts Created: " << totalContacts << endl;
    }
};

// Initialize static variable for Contact
int Contact::totalContacts = 0;

// Derived class: BusinessContact (Multilevel Inheritance from Contact)
class BusinessContact : public Contact {
public:
    // Constructor
    BusinessContact(string name, string phoneNumber, string email, string address, string companyName, string jobTitle)
        : Contact(name, phoneNumber, email, address, companyName, jobTitle) {  // Initialize base class constructor
    }

    // Overriding the displayContact function to add business contact details
    void displayInfo() const override { // Override the pure virtual function
        Contact::displayInfo();  // Call parent class function to display basic contact details
    }
};

class Phonebook {
private:
    vector<Contact*> contacts;

    // Static variable to keep track of the number of Phonebook instances created
    static int phonebookCount;

public:

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
    vector<Contact*> getContacts() const {
        return contacts;
    }

    //Mutator (Setter)
    void setContact(vector<Contact*>& contacts) {
        this->contacts = contacts;
    }

    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    void displayAllContacts() const {
        for (Contact* contact : contacts) {
            contact->displayInfo();
            cout << endl;
        }
    }

    static void displayStats() {
        cout << "Total Phonebooks Created: " << phonebookCount << endl;
        // Call static member function of Contact class
        Contact::displayTotalContacts();
    }
};

// Initialize static variable for Phonebook
int Phonebook::phonebookCount = 0;

int main() {
    // Dynamically allocating memory for Contact objects
    Contact* contact1 = new Contact("Prema", "1234567890", "prema@example.com", "123 Main St", "Tech Corp", "Manager");
    Contact* contact2 = new BusinessContact("Priya", "9876543210", "priya@example.com", "456 Elm St", "Innovate Inc", "Developer");

    // Creating Phonebook object
    Phonebook phonebook;

    // Adding contacts to the phonebook
    phonebook.addContact(contact1);
    phonebook.addContact(contact2);

    // Displaying all contacts in the phonebook
    phonebook.displayAllContacts();

    // Demonstrate function overloading
    cout << "Updating contact1 with new details..." << endl;
    contact1->updateContact("Prema Updated", "1111111111", "prema_updated@example.com", "789 Maple St");
    contact1->displayInfo();  // Display updated contact1

    cout << "Updating contact2 with all details..." << endl;
    contact2->updateContact("Priya Updated", "2222222222", "priya_updated@example.com", "456 Oak St", "Tech Innovations", "Lead Developer");
    contact2->displayInfo();  // Display updated contact2

    // Displaying statistics
    Phonebook::displayStats();

    // Clean up memory for dynamically allocated contacts
    delete contact1; // It's already deleted in Phonebook's destructor
    delete contact2;

    return 0;
}
