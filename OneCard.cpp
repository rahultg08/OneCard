#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define cost 10;
#define car 75;
#define truck 200;
#define bus 150;
#define bike 50;

class OneCard{
    string id1="100"+to_string(1+(rand()%100));
    string id2="200"+to_string(1+(rand()%100));
    string id3="300"+to_string(1+(rand()%100));
    int cvv=1+rand()%1000;
    string name;
    int limit=2000, c, amount;
    int boarding, destination, expend, charge;
    public:
        OneCard(){
            cout<<"Enter the user name:"<<endl;
            cin>>name;
        }
        OneCard(string name){
            this->name = name;
        }
        void returnID(){
            cout<<"User Name: "<<name<<endl;
            cout<<"Metro Card ID: "<<id1<<endl;
            cout<<"FasTag ID: "<<id2<<endl;
            cout<<"Credit Card ID: "<<id3<<endl;
        }
        string returnMetroID(){
            return id1;
        }
        string returnFasTagID(){
            return id2;
        }
        string returnCreditID(){
            return id3;
        }
        void displayLimit(){
            cout<<"Remaining Limit: "<<limit<<endl;
        }
        void returnCVV(){
            cout<<"Attention! confidential data is disclosed"<<endl;
            char flag;
            cout<<"You want to display CVV(Y/N):"<<endl;
            cin>>flag;
            if(tolower(flag)=='y')
                cout<<cvv<<endl;
            else
                cout<<"Your data is not disclosed!"<<endl;
        }
        
        void metroEntry(int boarding){
            this->boarding = boarding;
            if(limit>=100)
                cout<<"Entry succeeded"<<endl;
            else{
                cout<<"Can't proceed! Card limit exceeded"<<endl;
                cout<<"Please Topup to proceed:)"<<endl;
            }
        }
        void metroExit(int destination){
            this->destination = destination;
            int dist = abs(destination - boarding);
            int tot = dist * cost;
            limit -= tot;
            cout<<"Charges charged! You can exit"<<endl;
        }
        
        void atToll(int v){
            switch(v){
                case 1:
                    charge = bike;
                    if(charge>limit){
                        cout<<"Can't proceed! Card limit exceeded"<<endl;
                        cout<<"Please Topup to proceed:)"<<endl;   
                    }
                    else{
                        limit-=charge;
                        cout<<"Charges charged! You can exit"<<endl;
                    }
                    break;
                case 2:
                    charge = car;
                    if(charge>limit){
                        cout<<"Can't proceed! Card limit exceeded"<<endl;
                        cout<<"Please Topup to proceed:)"<<endl;   
                    }
                    else{
                        limit-=charge;
                        cout<<"Charges charged! You can exit"<<endl;
                    }
                    break; 
                case 3:
                    charge = bus;
                    if(charge>limit){
                        cout<<"Can't proceed! Card limit exceeded"<<endl;
                        cout<<"Please Topup to proceed:)"<<endl;   
                    }
                    else{
                        limit-=charge;
                        cout<<"Charges charged! You can exit"<<endl;
                    }
                    break; 
                case 4:
                    charge = truck;
                    if(charge>limit){
                        cout<<"Can't proceed! Card limit exceeded"<<endl;
                        cout<<"Please Topup to proceed:)"<<endl;   
                    }
                    else{
                        limit-=charge;
                        cout<<"Charges charged! You can exit"<<endl;
                    }
                    break; 
                case 5:
                    cout<<"Try Again! Input the correct type of your vehicle: "<<endl;
                    break;
            }
        }
        
        bool validateCVV(){
            cout<<"Enter CVV: "<<endl;
            cin>>c;
            if(c==cvv)
                return true;
            else
                return false;
        }
        void creditcard(int expend){
            this->expend = expend;
            if(expend>limit){
                cout<<"Can't proceed! Card limit exceeded"<<endl;
                cout<<"Please Topup to proceed:)"<<endl;   
            }
            else{
                if(validateCVV()){
                    limit-=expend;
                    cout<<"Your money has been debited"<<endl;
                }
                else{
                    cout<<"CVV mismatch! Transaction failed"<<endl;
                    cout<<"Try Again"<<endl;
                }
            }
        }
        
        void topUp(int amount){
            this->amount = amount;
            limit+=amount;
        }
};
int main(){
    // OneCard one1;
    string name;
    cout<<"Enter the name of user: "<<endl;
    cin>>name;
    OneCard one(name);
    int choice, expend, amount;
    string s;
    bool flag = true;
    do{
    cout<<"Enter the choice, how you want to use the OneCard as: "<<endl;
    cout<<"1) Metro Card"<<endl<<"2) FasTag"<<endl<<"3) Credit Card"<<endl<<"4) Return Credentials"<<endl<<"5) TopUp"<<endl<<"6) Exit"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
            s = one.returnMetroID();
            if (s.rfind("100", 0) == 0) {                   // NFC established for Metro Card Usage
                cout<<"Metro Card Detected!"<<endl;
                int boarding, destination;
                cout<<"Enter the Station number you are boarding at: "<<endl;
                cin>>boarding;
                one.metroEntry(boarding);
                cout<<"Enter the Deboarded Station number: "<<endl;
                cin>>destination;
                one.metroExit(destination);
                one.displayLimit();
            }
            break;
        case 2:
            s = one.returnFasTagID();
            if (s.rfind("200", 0) == 0) {                   // RFID detected by the sensor as FasTag
                cout<<"FasTag RFID Detected!"<<endl;
                one.displayLimit();
                cout<<"Enter type of your vehicle: "<<endl;
                cout<<"1) Bike"<<endl<<"2) Car or Auto"<<endl<<"3) Bus"<<endl<<"4) Truck"<<endl<<"5) None"<<endl;
                int vehicle;
                cin>>vehicle;
                one.atToll(vehicle);
                one.displayLimit();
            }
            break;
        case 3:
            s = one.returnCreditID();
            if (s.rfind("300", 0) == 0) {                   // EMV Detected for Credit Card Usage
                cout<<"Enter the amount to be debited: "<<endl;
                cin>>expend;
                one.creditcard(expend);
                one.displayLimit();
            }           
            break;
        case 4:
            one.returnID();
            one.displayLimit();
            one.returnCVV();
            break;
        case 5:
            one.displayLimit();
            cout<<"Enter the TopUp amount: "<<endl;
            cin>>amount;
            one.topUp(amount);
            cout<<"ToppedUp ";
            one.displayLimit();
            break;
        case 6:
            flag = false;
            break;
        default:
            cout<<"Try again! Go with other choice"<<endl;
    }
    }while(flag);
    return 0;
}