#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Abstract class for Person
class Person {
protected:
    string name;
public:
    Person(string name) : name(name) {}

    string getName() const {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    virtual void displayInfo() const = 0;
};

// Contact class: manages individual contact details only
class Contact : public Person {
private:
    string phoneNumber;
    string email;
    string address;
    string companyName;
    string jobTitle;

public:
    Contact(string name, string phoneNumber, string email, string address, string companyName, string jobTitle)
        : Person(name), phoneNumber(phoneNumber), email(email), address(address), companyName(companyName), jobTitle(jobTitle) {}

    // Getters
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }
    string getCompanyName() const { return companyName; }
    string getJobTitle() const { return jobTitle; }

    // Setters
    void setPhoneNumber(const string& phoneNumber) { this->phoneNumber = phoneNumber; }
    void setEmail(const string& email) { this->email = email; }
    void setAddress(const string& address) { this->address = address; }
    void setCompanyName(const string& companyName) { this->companyName = companyName; }
    void setJobTitle(const string& jobTitle) { this->jobTitle = jobTitle; }

    void displayInfo() const override {}
};

// ContactDisplay class: responsible for displaying contact information
class ContactDisplay {
public:
    static void displayContactInfo(const Contact& contact) {
        cout << "Name: " << contact.getName() << endl;
        cout << "Phone Number: " << contact.getPhoneNumber() << endl;
        cout << "Email: " << contact.getEmail() << endl;
        cout << "Address: " << contact.getAddress() << endl;
        cout << "Company Name: " << contact.getCompanyName() << endl;
        cout << "Job Title: " << contact.getJobTitle() << endl;
    }
};

// ContactUpdater class: responsible for updating contact information
class ContactUpdater {
public:
    static void updateContact(Contact& contact, string name, string phoneNumber, string email, string address) {
        contact.setName(name);
        contact.setPhoneNumber(phoneNumber);
        contact.setEmail(email);
        contact.setAddress(address);
    }

    static void updateContact(Contact& contact, string name, string phoneNumber, string email, string address, string companyName, string jobTitle) {
        contact.setName(name);
        contact.setPhoneNumber(phoneNumber);
        contact.setEmail(email);
        contact.setAddress(address);
        contact.setCompanyName(companyName);
        contact.setJobTitle(jobTitle);
    }
};

// Phonebook class: manages a list of contacts
class Phonebook {
private:
    vector<Contact*> contacts;

public:
    Phonebook() {}

    ~Phonebook() {
        for (Contact* contact : contacts) {
            delete contact;
        }
    }

    void addContact(Contact* contact) {
        contacts.push_back(contact);
    }

    vector<Contact*> getContacts() const {
        return contacts;
    }

    void displayAllContacts() const {
        for (Contact* contact : contacts) {
            ContactDisplay::displayContactInfo(*contact);
            cout << endl;
        }
    }
};

// PhonebookStatistics class: responsible for tracking phonebook and contact statistics
class PhonebookStatistics {
private:
    static int totalContacts;
    static int phonebookCount;

public:
    static void incrementContactCount() { totalContacts++; }
    static void decrementContactCount() { totalContacts--; }
    static void incrementPhonebookCount() { phonebookCount++; }

    static void displayStats() {
        cout << "Total Contacts Created: " << totalContacts << endl;
        cout << "Total Phonebooks Created: " << phonebookCount << endl;
    }
};

// Initialize static variables
int PhonebookStatistics::totalContacts = 0;
int PhonebookStatistics::phonebookCount = 0;

// BusinessContact class: inherits from Contact for multilevel inheritance demonstration
class BusinessContact : public Contact {
public:
    BusinessContact(string name, string phoneNumber, string email, string address, string companyName, string jobTitle)
        : Contact(name, phoneNumber, email, address, companyName, jobTitle) {}
};

// Main function
int main() {
    PhonebookStatistics::incrementPhonebookCount();  // Increment phonebook count when a new phonebook is created

    // Dynamically creating contacts
    Contact* contact1 = new Contact("Prema", "1234567890", "prema@example.com", "123 Main St", "Tech Corp", "Manager");
    Contact* contact2 = new BusinessContact("Priya", "9876543210", "priya@example.com", "456 Elm St", "Innovate Inc", "Developer");

    // Incrementing contact count for each new contact
    PhonebookStatistics::incrementContactCount();
    PhonebookStatistics::incrementContactCount();

    // Creating phonebook and adding contacts
    Phonebook phonebook;
    phonebook.addContact(contact1);
    phonebook.addContact(contact2);

    // Display all contacts
    phonebook.displayAllContacts();

    // Update contact information using ContactUpdater
    cout << "Updating contact1 with new details..." << endl;
    ContactUpdater::updateContact(*contact1, "Prema Updated", "1111111111", "prema_updated@example.com", "789 Maple St");
    ContactDisplay::displayContactInfo(*contact1);

    cout << "Updating contact2 with all details..." << endl;
    ContactUpdater::updateContact(*contact2, "Priya Updated", "2222222222", "priya_updated@example.com", "456 Oak St", "Tech Innovations", "Lead Developer");
    ContactDisplay::displayContactInfo(*contact2);

    // Display statistics
    PhonebookStatistics::displayStats();

    return 0;
}
