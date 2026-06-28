#include "iostream"
#include "string"

using namespace std;


// Address class
class Address {

    private:
        int postal_code;
        string city;
        string country;

    public:
        Address() : postal_code(0), city(""), country("")
        {}

        Address(int code, string city, string country) : postal_code(code), city(city), country(country)
        {}


        void showDetail() const {
            cout << "PostalCode: " << postal_code << endl;
            cout << "City: " << city << endl;
            cout << "Country: " << country << endl;
        }

        int getPostalCode() const{
            return postal_code;
        }

        string getCity() const {
            return city;
        }

        string getCountry() const {
            return country;
        }


};

// User class
class User
{

private:
    int user_id;
    string name;
    string email;

    // has-a Address class
    Address address;

public:

    User() : user_id(0), name(""), email("")
    {}

    User(int id, string name, string email) : user_id(id), name(name), email(email)
    {}

    // setter for address
    void setAddress(Address add){
        this->address = add;
    }

    void showUserInfo() const
    {
        cout << "User infomation ==========" << endl;
        cout << "Id: " << user_id << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "City: " << address.getCity() << endl;
        cout << "Postal Code: " << address.getPostalCode() << endl;
        cout << "Country: " << address.getCountry() << endl;
    }
};


int main () {


    Address address(55100, "Lahore", "Pakistan");

    User user(101, "Usman", "usman@gmail.com");

    user.setAddress(address);

    user.showUserInfo();


    return 0;
}