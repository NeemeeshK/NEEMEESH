#include <iostream>
#include <string>
using namespace std;

class bank
{
    private:
    string name;
    string address;
    int p[6];

    public:
    void opennewaccount();
    void depositeamout();
    void withdrawtheamount();
    void balanceenquiry();
    void closingaccount();
    void modifyingaccount();
    void complaint();
    void loan();
    void Exit();
};

    void bank :: opennewaccount()
    {
        cout<<"Thank you for trusting on us.Welcome to Our bank service.";
        cout<<"Please fill the below information";
        cout<<"Enter your full name";
        cin>>name;
        cout<<"Enter your Address";
        cin>>address;
        cout<<"Enter your Pin code";
        for(int i=0;i<6;i++){
            cin>>p[i];
        }
    }