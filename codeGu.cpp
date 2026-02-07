#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

// Global variables
string food;
int Num;
int table = 0;
int price[6];
int menu;
int more;

// เก็บออเดอร์โดยใช้ array
string orderList[50];
int orderPrice[50]; 
int orderCount = 0;
int totalPrice = 0;

// --- prototypes ---
void home();
void employ();
void menuu();
void customer();
void moree();
void selectTable();
void showBill();

void home(){
    cout << "---------------Please select--------------"<<endl;
    cout << "CUSTOMER : 1"<< setw(16) <<"EMPLOYEE : 2"<< setw(14) <<"HOST : 3 "<<endl;
    cout << ": ";
    cin >> Num;
}

void employ(){
    cout << "-----------------EMPLOYEE-----------------"<<endl;

    cout << "Last Order Summary" << endl;
    cout << "Table : " << table << endl;

    if(orderCount == 0){
        cout << "No orders yet" << endl;
        return;
    }

    for(int i=0; i < orderCount; i++){
        cout << i+1 << ". " << orderList[i] 
             << " - " << orderPrice[i] << " Baht" << endl;
    }

    cout << "Total price : " << totalPrice << " Baht" << endl;
}

void menuu(){
    int size;

    if(menu==1){
        cout << "size : 1.normal 45 / 2.extra 55 "<<endl;
        cout << "select size : ";
        cin >> size;
        food = "Khao man Gai"; 
        price[menu] = (size==1 ? 45 : 55);
    }

    else if(menu==2){
        cout << "size : 1.normal 45 / 2.extra 55 "<<endl;
        cout << "select size : ";
        cin >> size;
        food = "Khao ka Moo"; 
        price[menu] = (size==1 ? 45 : 55);
    }

    else if(menu==3){
        food = "Wagyu A5";
        price[menu] = 990;
    }

    else if(menu==4){
        food = "Salmon Sashimi";
        price[menu] = 150;
    }

    else if(menu==5){
        food = "Tom Yum Kung";
        price[menu] = 99;
    }

    // ---- เก็บเมนูลง array ----
    orderList[orderCount] = food;
    orderPrice[orderCount] = price[menu];
    orderCount++;

    totalPrice += price[menu];

    cout << "Added : " << food << " - " << price[menu] << " Baht" << endl;
}

void selectTable(){
    cout << "-----------------CUSTOMER-----------------"<<endl;
    cout << "Select Table (1-5): "<<endl;

    for(int i=1; i<=5 ;i++)
        cout << i << " : Table " << i << endl;

    cout << ": ";
    cin >> table;
}

void customer(){

    if(table == 0){
        selectTable();
    }

    cout << "-----------------MENU-----------------"<<endl;
    cout << "1. Khao man Gai (45/55)" << endl;
    cout << "2. Khao ka Moo (45/55)" << endl;
    cout << "3. Wagyu A5 (990)" << endl;
    cout << "4. Salmon Sashimi (150)" << endl;
    cout << "5. Tom Yum Kung (99)" << endl;
    cout << "Select menu : ";
    cin >> menu;

    menuu();
    moree();
}

void moree(){
    cout << "More order? 1.yes / 2.no : ";
    cin >> more;

    if(more == 1){
        customer();
    }
    else {
        showBill();
        home();
    }
}

void showBill(){
    cout << "\n-----------total-----------\n";
    cout << "Table : " << table << endl;

    for(int i=0; i < orderCount; i++){
        cout << i+1 << ". " << orderList[i] 
             << " - " << orderPrice[i] << " Baht" << endl;
    }
    cout << "Total Price : " << totalPrice << " Baht" << endl;
    cout << "----------------------------\n\n";
}

int main(){
    home();

    if(Num == 1){
        customer();
    }
    
    if(Num == 2){
        string password;
        cout << "-----------------EMPLOYEE-----------------"<<endl;
        cout << "password : ";
        cin >> password;

        if(password=="Employ898")
            employ();
        else 
            cout << "______wrong password!!!______";
    }
}
