// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// // Base class: Person
// class Person {
// protected:
//     string name;  // Common attribute for all persons
// public:
//     Person(string name) {
//         this->name = name;
//     }

//     string getName() const {
//         return name;
//     }

//     void setName(const string& name) {
//         this->name = name;
//     }

//     void displayPerson() const {
//         cout << "Name: " << name << endl;
//     }
// };

// // Derived class: Contact (Single Inheritance from Person)
// class Contact : public Person {
// private:
//     double phoneNumber;
//     string email;
//     string address;

//     // Static variable to keep track of the total number of contacts created
//     static int totalContacts;

// public:
//     // Constructor
//     Contact(string name, double phoneNumber, string email, string address) 
//         : Person(name) {  // Initialize base class constructor
//         this->phoneNumber = phoneNumber;
//         this->email = email;
//         this->address = address;
//         totalContacts++;  // Increment totalContacts whenever a new contact is created
//     }

//     // Destructor
//     ~Contact() {
//         totalContacts--;  // Decrement totalContacts when a contact is deleted
//     }

//     // Accessors (getters)
//     double getPhoneNumber() const {
//         return phoneNumber;
//     }
//     string getEmail() const {
//         return email;
//     }
//     string getAddress() const {
//         return address;
//     }

//     // Mutators (setters)
//     void setPhoneNumber(const double& phoneNumber) {
//         this->phoneNumber = phoneNumber;
//     }
//     void setEmail(const string& email) {
//         this->email = email;
//     }
//     void setAddress(const string& address) {
//         this->address = address;
//     }

//     void displayContact() const {
//         displayPerson(); // Call base class function to display name
//         cout << "Phone Number: " << getPhoneNumber() << endl;
//         cout << "Email: " << getEmail() << endl;
//         cout << "Address: " << getAddress() << endl;
//     }

//     void updateContact(string name, double phoneNumber, string email, string address) {
//         setName(name);
//         setPhoneNumber(phoneNumber);
//         setEmail(email);
//         setAddress(address);
//     }

//     // Static member function to display the total number of contacts created
//     static void displayTotalContacts() {
//         cout << "Total Contacts Created: " << totalContacts << endl;
//     }
// };

// // Initialize static variable for Contact
// int Contact::totalContacts = 0;

// // Derived class: BusinessContact (Multilevel Inheritance from Contact)
// class BusinessContact : public Contact {
// private:
//     string companyName;
//     string jobTitle;

// public:
//     // Constructor
//     BusinessContact(string name, double phoneNumber, string email, string address, string companyName, string jobTitle)
//         : Contact(name, phoneNumber, email, address) {  // Initialize base class constructor
//         this->companyName = companyName;
//         this->jobTitle = jobTitle;
//     }

//     // Accessor (getter)
//     string getCompanyName() const {
//         return companyName;
//     }
//     string getJobTitle() const {
//         return jobTitle;
//     }

//     // Mutator (setter)
//     void setCompanyName(const string& companyName) {
//         this->companyName = companyName;
//     }
//     void setJobTitle(const string& jobTitle) {
//         this->jobTitle = jobTitle;
//     }

//     // Overriding the displayContact function to add business contact details
//     void displayContact() const {
//         Contact::displayContact();  // Call parent class function to display basic contact details
//         cout << "Company Name: " << getCompanyName() << endl;
//         cout << "Job Title: " << getJobTitle() << endl;
//     }
// };

// // Class: Phonebook
// class Phonebook {
// private:
//     vector<Contact*> contacts;

//     // Static variable to keep track of the number of Phonebook instances created
//     static int phonebookCount;
    
// public:
//     // Constructor
//     Phonebook() {
//         phonebookCount++;  // Increment phonebookCount whenever a new phonebook is created
//     }

//     // Destructor
//     ~Phonebook() {
//         for (Contact* contact : contacts) {
//             delete contact;
//         }
//     }
 
//     // Accessor (Getter)
//     vector<Contact*> getContacts() const {
//         return contacts;
//     }

//     // Mutator (Setter)
//     void setContact(vector<Contact*>& contacts) {
//         this->contacts = contacts;
//     }

//     void addContact(Contact* contact) {
//         contacts.push_back(contact);
//     }

//     void displayAllContacts() const {
//         for (Contact* contact : contacts) {
//             contact->displayContact();
//             cout << endl;
//         }
//     }

//     static void displayStats() {
//         cout << "Total Phonebooks Created: " << phonebookCount << endl;
//         Contact::displayTotalContacts();  // Call static member function of Contact class
//     }
// };

// // Initialize static variable for Phonebook
// int Phonebook::phonebookCount = 0;

// int main() {
//     // Dynamically allocating memory for Contact and BusinessContact objects
//     Contact* contact1 = new Contact("Prema", 1234567890, "prema@example.com", "123 Main St");
//     BusinessContact* contact2 = new BusinessContact("Priya", 9876543210, "priya@example.com", "456 Elm St", "Tech Corp", "Manager");

//     // Creating Phonebook object
//     Phonebook phonebook;

//     // Adding contacts to the phonebook
//     phonebook.addContact(contact1);
//     phonebook.addContact(contact2);

//     // Displaying all contacts in the phonebook
//     phonebook.displayAllContacts();

//     // Displaying statistics
//     Phonebook::displayStats();

//     return 0;
// }
