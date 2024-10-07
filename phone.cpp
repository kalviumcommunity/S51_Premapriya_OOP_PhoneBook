#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Base class
class Person{
    protected:
        string name;
    public:
        Person(string name){
            this->name=name;
        }
        string getName()const{
            return name;
        }
        void setName(const string& name) {
        this->name = name;
        }

        void displayPerson() const {
            cout << "Name: " << name << endl;
        }
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
    Contact(string name, string phoneNumber, string email, string address , string companyName, string jobTitle) : Person(name) {
        
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

    string getPhoneNumber()const{
        return phoneNumber;
    }
    string getEmail()const{
        return email;
    }
    string getAddress()const{
        return address;
    }
    string getCompanyName() const {  // Getter for company name
        return companyName;
    }

    string getJobTitle() const {  // Getter for job title
        return jobTitle;
    }

    //Mutators(setters)

    void setPhoneNumber(const string& phoneNumber){
        this->phoneNumber=phoneNumber;
    }
    void setEmail(const string& email){
        this->email=email;
    }
    void setAddress(const string& address){
        this->address=address;
    }
    void setCompanyName(const string& companyName) {  // Setter for company name
        this->companyName = companyName;
    }

    void setJobTitle(const string& jobTitle) {  // Setter for job title
        this->jobTitle = jobTitle;
    }

    void displayContact() const {
        displayPerson(); // Call base class function to display name
        cout << "Phone Number: " << getPhoneNumber() << endl;
        cout << "Email: " << getEmail()<< endl;
        cout << "Address: " << getAddress() << endl;
        cout << "Company Name: " << getCompanyName() << endl;  // Display company name
        cout << "Job Title: " << getJobTitle() << endl;        // Display job title
    }

    void updateContact(string name, string phoneNumber, string email, string address) {
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
private:
    string companyName;
    string jobTitle;

public:
    // Constructor
    BusinessContact(string name, string phoneNumber, string email, string address, string companyName, string jobTitle)
        : Contact(name, phoneNumber, email, address,companyName, jobTitle) {  // Initialize base class constructor
        this->companyName = companyName;
        this->jobTitle = jobTitle;
    }

    // Accessor (getter)
    string getCompanyName() const {
        return companyName;
    }
    string getJobTitle() const {
        return jobTitle;
    }

    // Mutator (setter)
    void setCompanyName(const string& companyName) {
        this->companyName = companyName;
    }
    void setJobTitle(const string& jobTitle) {
        this->jobTitle = jobTitle;
    }

    // Overriding the displayContact function to add business contact details
    void displayContact() const {
        Contact::displayContact();  // Call parent class function to display basic contact details
        cout << "Company Name: " << getCompanyName() << endl;
        cout << "Job Title: " << getJobTitle() << endl;
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
    Contact* contact1 = new Contact("Prema", "1234567890", "prema@example.com", "123 Main St", "Tech Corp", "Manager");
    Contact* contact2 = new Contact("Priya", "9876543210", "priya@example.com", "456 Elm St", "Innovate Inc", "Developer");


    // Creating Phonebook object
    Phonebook phonebook;

    // Adding contacts to the phonebook
    phonebook.addContact(contact1);
    phonebook.addContact(contact2);

    // Displaying all contacts in the phonebook
    phonebook.displayAllContacts();

    // Displaying statistics
    Phonebook::displayStats();

    return 0;
}
