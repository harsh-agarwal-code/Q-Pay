#include<iostream>
#include<fstream>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

using namespace std;

void logo();


class AccountType
{
    string AccType;

public:

    void setdata(char n)
    {
        switch(n)
        {
            case 's':
                AccType = "Saving\'s";
                break;

            case 'c':
                AccType = "Current";
                break;

            case 'f':
                AccType = "Fixed";
                break;
        }
    }

};

class Accounts : public AccountType
{
    unsigned int AccountNo;
    char Name[50],PhoneNo[50],Password[50];
    unsigned int Balance;
    char BackupQuestion[100];
    char BackupAns[50];

public:

    void LogIn();
    void SignIn();

};

void Accounts ::    LogIn()
{
    system("cls");
        logo();
        cout<<"\n\n\t\t\t\t\t\tLog - In";
        cout<<"\n\t\t\t\t\t-------------------------"<<endl;

        cout<<"\n\t\t\t\t\tEnter Your Account No. : ";
        int AccNo;
        cin>>AccNo;

        cout<<"\n\t\t\t\t\tEnter Your Password    : ";
        string Pass;
        cin>>Pass;

        // needs testing

        ifstream fin;
        fin.open("Database.dat",ios_base::in | ios_base::binary);

            if(!fin)
                cout<<"\n\n\t\t\t\t\t\tFile Not Found !!!";
            else
            {
                fin.read((char*)this,sizeof(*this));
                while(!fin.eof())
                {
                    bool found = false;
                    if(AccountNo == AccNo && Password == Pass)
                        {
                            cout<<"\n\n\t\t\t\tWelcome "<<Name;
                            found = true;
                        }
                    fin.read((char*)this,sizeof(*this));
                    if(found = false)
                        cout<<"\n\n\t\t\t\tUsername and Password Does not Match";
                }
            }

        fin.close();

}

void Accounts ::    SignIn()
{
    system("cls");
    logo();
    cout<<"\n\n\t\t\t\t\t\tSign - In";
    cout<<"\n\t\t\t\t\t-------------------------"<<endl;

    cout<<"\n\t\t\t\t\tEnter your First Name : ";
    cin.getline(Name,sizeof(Name));
    cin.ignore();

    cout<<"\n\t\t\t\t\tEnter your Phone No. : ";
    cin.getline(PhoneNo,sizeof(PhoneNo));
    cin.ignore();

    cout<<"\n\t\t\t\t\tEnter your Password : ";
    cin.getline(Password,sizeof(Password));
    cin.ignore();

    cout<<"\n\t\t\t\t\tEnter your Backup Question : ";
    cin.getline(BackupQuestion,sizeof(BackupQuestion));
    cin.ignore();

    cout<<"\n\t\t\t\t\tEnter your Backup Answer : ";
    cin.getline(BackupAns,sizeof(BackupAns));
    cin.ignore();

    cout<<"\n\t\t\t\t\tEnter the Opening Balance : ";
    cin>>Balance;

    srand(time(0));
    AccountNo = rand()% 100;

    cout<<"\n\t\t\t\t\tYour Account No. is "<<AccountNo;
    system("pause");
}


int main()
{
    Accounts Acc;

    int choice = 0;
    while(choice != 3)
    {
        system("cls");
        logo();
        cout<<"\n\n\t\t\t\t\t\tMain Menu";
        cout<<"\n\t\t\t\t\t\t---------"<<endl;

        cout<<"\n\t\t\t\t\t       1. Sign - In"<<endl;
        cout<<"\n\t\t\t\t\t       2. Log  - In"<<endl;
        cout<<"\n\t\t\t\t\t       3. Exit"<<endl;

        cout<<"\n\t\t\t\t\t  ---> ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                Acc.SignIn();
                break;

            case 2:
                Acc.LogIn();
                break;

        }

    }
}

void logo()
{
    int n=114;

    cout<<"\n\n\t\t\t\t\t\tQ - Pay"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"_";
    }

}
