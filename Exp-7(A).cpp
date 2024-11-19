#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    const string aadharCard;
    const string panCard;
    string address;
    string contactNumber;

public:
    Person(string aadhar, string pan, string add, string contact)
        : aadharCard(aadhar), panCard(pan), address(add), contactNumber(contact)
    {
        cout << "Person object created!" << endl;
    }

    string getAadharCard() const
    {
        return aadharCard;
    }

    string getPanCard() const
    {
        return panCard;
    }

    string getAddress() const
    {
        return address;
    }

    void setAddress(string add)
    {
        address = add;
    }

    string getContactNumber() const
    {
        return contactNumber;
    }

    void setContactNumber(string contact)
    {
        contactNumber = contact;
    }
};

int main()
{

    Person person1("1234-5678-9012", "ABCD34", "123 JAIPUR", "028232676");

    cout << "Aadhar Card: " << person1.getAadharCard() << endl;
    cout << "PAN Card: " << person1.getPanCard() << endl;

    cout << "Address: " << person1.getAddress() << endl;
    cout << "Contact Number: " << person1.getContactNumber() << endl;

    person1.setAddress("456 Another Street");
    person1.setContactNumber("1234567890");

    cout << "Updated Address: " << person1.getAddress() << endl;
    cout << "Updated Contact Number: " << person1.getContactNumber() << endl;

    return 0;
}
