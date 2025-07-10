#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

class bank{

    char name[100], address[100], type;
    int balance;

    public: 
        void open_account();
        void deposite_money();
        void withdraw_money();
        void display_account();
};

void bank::open_account(){
    cout<<"Enter your full name: ";
    cin.ignore();
    cin.getline(name, 100);

    cout<<"Enter your address: ";
    cin.ignore();
    cin.getline(address, 100);

    cout<<"What type of account do you want to open: saving (s) or current (c): ";
    cin>>type;

    cout<<"Enter amount for deposite: ";
    cin>>balance;
    cout<<"Your account is created!\n";
}

void bank::deposite_money(){

    float deposite_amount;

    do{
        cout<<"Enter amount of money you want to deposite: ";
        cin>>deposite_amount;
        if(deposite_amount>0){
            cout<<"You successfully deposited "<<deposite_amount<<" money.\n";
            balance+=deposite_amount;
            cout<<"Total balance is now:\t"<<balance<<"\n";
        }
        else{
            cout<<"You can not deposite negative amount!\n";
        }
    }while(deposite_amount<0);

}

void bank::withdraw_money(){
    float withdraw_amount;

    do{
        cout<<"Enter amount of money you want to deposite: ";
        cin>>withdraw_amount;
        if(withdraw_amount>0 && withdraw_amount<balance){
            cout<<"You successfully withdraw "<<withdraw_amount<<" money\n";
            balance-=withdraw_amount;
            cout<<"Total balance is now:\t"<<balance<<".\n";
        }
        else{
            cout<<"You can not withdraw negative amount or amount greater than balance!\n";
        }
    }while(withdraw_amount<0);

}

void bank::display_account(){
    cout<<"Full name:\t"<<name<<"\n";
    cout<<"Address:\t"<<address<<"\n";
    if(type=='s'){
        cout<<"Type of account:\tsaving\n";
    }
    else{
        cout<<"Type of account:\tcurrent\n";
    }
    cout<<"Current balance:\t"<<balance<<"\n";
}



int main(){

    int selected_option;
    char x;
    bank object;

    do{
        cout<<"1) Open account\n";
        cout<<"2) Deposit money\n";
        cout<<"3) Withdraw money\n";
        cout<<"4) Display account\n";
        cout<<"5) Exit\n\n";
        cout<<"Select from options above:\t";
        cin>>selected_option;


        switch(selected_option){
            case 1:
                cout<<"1) Open account\n";
                object.open_account();
                break;

            case 2:
                cout<<"2) Deposit money\n";
                object.deposite_money();
                break;

            case 3:
                cout<<"3) Withdraw money\n";
                object.withdraw_money();
                break;

            case 4:
                cout<<"4) Display account\n";
                object.display_account();
                break;

            case 5:
                cout<<"5) Exit\n";
                exit(1);

            default: 
                cout<<"Error occurred. Try again.\n";
        }



        cout<<"\nIf you want to continue press (y):\n";
        cout<<"If yo want to exit press (n)\n";
        cout<<"Enter y/n:\t";
        
        cin>>x;

        if(x=='n'||x=='N'){
            exit(0);
        }

    }while(x=='y' || x=='Y');
    
    
    getch();
    return 0;
}
