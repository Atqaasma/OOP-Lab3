#include <iostream>
#include <map>
#include <string>
using namespace std;

class ContactManager {
private:
    map<string, string> contacts;

public:
    void addContact(const string& name, const string& number) {
        contacts[name] = number;
    }

    void findContact(const string& name) {
        if (contacts.find(name) != contacts.end()) {
            cout << "Number: " << contacts[name] << endl;
        } else {
            cout << "Contact not found." << endl;
        }
    }

    void displayContacts() {
        for (auto& contact : contacts) {
            cout << "Name: " << contact.first << ", Number: " << contact.second << endl;
        }
    }
};

int main() {
    ContactManager cm;
    cm.addContact("John Doe", "123-456-7890");
    cm.addContact("Jane Doe", "098-765-4321");

    cout << "Contacts:" << endl;
    cm.displayContacts();

    cout << "\nFinding John Doe:" << endl;
    cm.findContact("John Doe");

    return 0;
}
