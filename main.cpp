#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;



struct Mail{
    string subject;
    string text;
    bool status{};
    bool star{};
    int mailId{};
    int from{};
    int to{};
};
struct User{
    string name;
    string lastName;
    char age[2]{};
    int id{};
    enum Gender{Male , Female};
    int NumberOfGender{};
    Gender jens = (Gender)NumberOfGender;
};
struct Account{
    User user1;
    int userId{};
    string username;
    string password;
    Mail inbox{};
    Mail sentMails{};
    Mail drafts{};
    Mail starredMails{};
    Mail trash{};
};




User user[100];
Account acc[100];
Mail mail[200];
int size = 0;
int sizeMail = 0;
int k = 0;
string username , password;




void WelcomeBanner();
void MainMenu();
void filesRead();
void signUpBanner();
void SignUp(char ChooseNumber);
void loginBanner();
void login();
void loginMenuBanner();
void loginMenu();
void loginMenu2IfNoUserFound();
void EditProfileBanner();
void ShowProfile();
void EditProfile(char ChooseNumber);
void ComposeNewMessageBanner();
void ComposeNewMessage();
void MessageListBanner();
void MessageListMenu();
void DeleteAccount1();
void DeleteAccount2();
void filesWrite();



void filesRead(){
    string line;
    ifstream Id , USer , Account , Mails;

    Mails.open("MailsData.txt");
    while (getline(Mails , line))
        sizeMail++;
    Mails.close();


    Id.open("IdData.txt");
    while (getline(Id , line))
        size++;
    Id.close();

    Id.open("IdData.txt");
    for (int i = 0; i < size; ++i) {
        Id>>user[i].id>>mail[i].mailId;
    }
    Id.close();



    USer.open("UserData.txt");
    for (int i = 0; i < size; i++) {
        USer>>user[i].name>>user[i].lastName>>user[i].age>>user[i].id>>user[i].NumberOfGender;
    }
    USer.close();



    Account.open("AccountData.txt");
    for (int i = 0; i < size; ++i) {
        Account>>acc[i].userId>>acc[i].username>>acc[i].password;
    }
    Account.close();

    string from , to , mailId;
    Mails.open("MailsData.txt");
    for (int i = 0; i < sizeMail; ++i) {
        getline(Mails , mail[i].subject , '|');
        getline(Mails , mail[i].text , '|');
        getline(Mails , from , '|');
        mail[i].from = stoi(from);
        getline(Mails , to , '|');
        mail[i].to = stoi(to);
        getline(Mails , mailId , '|');
        mail[i].mailId = stoi(mailId);
    }
    Mails.close();
}



void WelcomeBanner(){
    cout<<" __        _______ _     ____ ___  __  __ _____ \n"
          " \\ \\      / | ____| |   / ___/ _ \\|  \\/  | ____|\n"
          "  \\ \\ /\\ / /|  _| | |  | |  | | | | |\\/| |  _|  \n"
          "   \\ V  V / | |___| |__| |__| |_| | |  | | |___ \n"
          "    \\_/\\_/  |_____|_____\\____\\___/|_|  |_|_____|\n"
          "                                                "<<endl;
    cout<<"\n***************************************************"<<endl;
}



void MainMenu(){    //MainMenu
    cout<<"1.Sign Up"<<endl;
    cout<<"2.Log In"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"***************************************************"<<endl;
    cout<<"Enter Number : ";
}



void signUpBanner(){ // Sign up Menu
    cout<<"\n***************************************************"<<endl;
    cout<<"  ____  _               _   _       \n"
          " / ___|(_) __ _ _ __   | | | |_ __  \n"
          " \\___ \\| |/ _` | '_ \\  | | | | '_ \\ \n"
          "  ___) | | (_| | | | | | |_| | |_) |\n"
          " |____/|_|\\__, |_| |_|  \\___/| .__/ \n"
          "          |___/              |_|    ";
    cout<<"\n***************************************************"<<endl;
}



void SignUp(char ChooseNumber){  // Sign Up Function
    int i , a = 49 , b = 57;
    cout<<"\n            *** Pay Attention ***";
    cout<<"\n*** This program does not support 2-part names ***";
    cout<<"\nEnter You're Name : ";
    cout<<flush;
    cin.ignore();
    main1:
    i = 0;
    cin>>user[size].name;
    for (;i < size;++i){
        if (user[size].name == user[i].name) {
            cout << "\nThere is an account with this name , Type New Name : ";
            goto main1;
        }
    }
    cout<<"\nEnter You're LastName : ";
    cin>>user[size].lastName;
    main2:
    cout<<"\nEnter You're Age : ";
    i = 0;
    for (;i < 2;++i)
        cin>>user[size].age[i];
    if ( int(user[size].age[0])  < a) {
        cout<<"\nError, Don't Type Letters (Valid Example : 18)";
        goto main2;
    }
    else if ( int(user[size].age[0]) > a){
        if ( int(user[size].age[0]) > b ){
            cout<<"\nError, Don't Type Letters (Valid Example : 18)";
            goto main2;
        }
    }
    else if ( int(user[size].age[1])  < a) {
        cout<<"\nError, Don't Type Letters (Valid Example : 18)";
        goto main2;
    }
    else if ( int(user[size].age[1]) > a){
        if ( int(user[size].age[1]) > b ){
            cout<<"\nError, Don't Type Letters (Valid Example : 18)";
            goto main2;
        }
    }
    srand(time(0));
    user[size].id = rand();
    acc[size].userId = user[size].id;
    main3:
    cout<<"\n~~~~~ Choose You're Gender ~~~~~\n1.Male       2.Female\n";
    cout<<"\nEnter Number : ";
    cin>>ChooseNumber;
    if (int(ChooseNumber) == 49) {
        user[size].jens = User::Male;
    } else if (int(ChooseNumber) == 50) {
        user[size].jens = User::Female;
    }
    else{
        cout<<"\nError , Don't Type Letters (Valid Example : 1 Or 2)";
        goto main3;
    }
    cout<<"\nEnter You're Username : ";
    i = 0;
    main4:
    cin>>acc[size].username;
    for (;i < size;++i){
        if (acc[size].username == acc[i].username){
            cout<<"\nError , There is an Account with this Username , Type New Username : ";
            goto main4;
        }
    }
    cout<<"\nEnter You're Password : ";
    cin>>acc[size].password;
    size++;
}



void loginBanner(){
    cout<<"\n***************************************************"<<endl;
    cout<<"  _                _       \n"
          " | |    ___   __ "
          "_(_)_ __  \n"
          " | |   / _ \\ / _` | | '_ \\ \n"
          " | |__| (_) | (_| | | | | |\n"
          " |_____\\___/ \\__, |_|_| |_|\n"
          "             |___/         ";
    cout<<"\n***************************************************"<<endl;
}



void login(){
    k = 0;
    cout<<"\nEnter you're Username : ";
    cin>>username;
    cout<<"\nEnter you're Password : ";
    cin>>password;
    for (; k < size; k++) {
        if (username == acc[k].username && password == acc[k].password){
            break;
        }
    }
}



void loginMenuBanner(){
    cout<<"  __  __       _         __  __                  \n"
          " |  \\/  | __ _(_)_ __   |  \\/  | ___ _ __  _   _ \n"
          " | |\\/| |/ _` | | '_ \\  | |\\/| |/ _ | '_ \\| | | |\n"
          " | |  | | (_| | | | | | | |  | |  __| | | | |_| |\n"
          " |_|  |_|\\__,_|_|_| |_| |_|  |_|\\___|_| |_|\\__,_|\n"
          "                                                 ";
}



void loginMenu(){
    cout<<"\n***************************************************";
    cout<<"\n1.Edit Profile";
    cout<<"\n2.Compose New Message";
    cout<<"\n3.Message list";
    cout<<"\n4.Delete Account";
    cout<<"\n5.Sign Out";
    cout<<"\n***************************************************";
    cout<<"\nEnter Number : ";
}



void loginMenu2IfNoUserFound(){
    cout<<"\n***************************************************";
    cout<<"\nError, no username and password found";
    cout<<"\n1.Main Menu";
    cout<<"\n2.Login Again";
    cout<<"\n***************************************************";
    cout<<"\nEnter Number : ";
}



void EditProfileBanner(){
    cout<<"\n***************************************************"<<endl;
    cout<<"  _____    _ _ _     ____             __ _ _      \n"
          " | ____|__| (_| |_  |  _ \\ _ __ ___  / _(_| | ___ \n"
          " |  _| / _` | | __| | |_) | '__/ _ \\| |_| | |/ _ \\\n"
          " | |__| (_| | | |_  |  __/| | | (_) |  _| | |  __/\n"
          " |_____\\__,_|_|\\__| |_|   |_|  \\___/|_| |_|_|\\___|\n"
          "                                                  ";
    cout<<"\n***************************************************"<<endl;
}



void ShowProfile(){
    cout<<"\nPersonality Information";
    cout<<"\n| Name : "<<user[k].name;
    cout<<" | Lase Name : "<<user[k].lastName;
    cout<<" | Age : "<<user[k].age;
    cout<<" | ID : "<<user[k].id<<" (*~ Unchangeable ~*) ";
    if (user[k].NumberOfGender == 0)
        cout<<" | Gender : Male";
    if (user[k].NumberOfGender == 1)
        cout<<" | Gender : Female";
}



void EditProfile(char ChooseNumber){
    int i , a = 49 , b = 57;
    cout<<"\n***************************************************";
    cout<<"\nEnter You're Name : ";
    main1:
    i = 0;
    cin>>user[k].name;
    for (;i < size;++i){
        if (i == k){
            break;
        }
        else if (user[k].name == user[i].name) {
            cout << "\nThere is an account with this name , Type New Name : ";
            goto main1;
        }
    }
    cout<<"\nEnter You're LastName : ";
    cin>>user[k].lastName;
    main2:
    cout<<"\nEnter You're Age : ";
    i = 0;
    for (;i < 2;++i)
        cin>>user[k].age[i];
    if ( int(user[k].age[0])  < a){
        cout<<"\nError, Don't Type Letters (Valid Example : 18)";
        goto main2;
    }
    else if ( int(user[k].age[0]) > a){
        if ( int(user[k].age[0]) > b ){
            cout<<"\nError, Don't Type Letters (Valid Example : 18)";
            goto main2;
        }
    }
    else if ( int(user[k].age[1])  < a) {
        cout<<"\nError, Don't Type Letters (Valid Example : 18)";
        goto main2;
    }
    else if ( int(user[k].age[1]) > a){
        if ( int(user[k].age[1]) > b ){
            cout<<"\nError, Don't Type Letters (Valid Example : 18)";
            goto main2;
        }
    }
    main3:
    cout<<"\n~~~~~ Choose You're Gender ~~~~~\n1.Male       2.Female\n";
    cout<<"\nEnter Number : ";
    cin>>ChooseNumber;
    if (int(ChooseNumber) == 49) {
        user[k].jens = User::Male;
    } else if (int(ChooseNumber) == 50) {
        user[k].jens = User::Female;
    }
    else{
        cout<<"\nError , Don't Type Letters (Valid Example : 1 Or 2)";
        goto main3;
    }
}



void ComposeNewMessageBanner(){
    cout<<"\n***************************************************"<<endl;
    cout<<"   ____                                       _   _                 __  __                               \n"
          "  / ___|___  _ __ ___  _ __   ___  ___  ___  | \\ | | _____      __ |  \\/  | ___ ___ ___  __ _  __ _  ___ \n"
          " | |   / _ \\| '_ ` _ \\| '_ \\ / _ \\/ __|/ _ \\ |  \\| |/ _ \\ \\ /\\ / / | |\\/| |/ _ / __/ __|/ _` |/ _` |/ _ \\\n"
          " | |__| (_) | | | | | | |_) | (_) \\__ |  __/ | |\\  |  __/\\ V  V /  | |  | |  __\\__ \\__ | (_| | (_| |  __/\n"
          "  \\____\\___/|_| |_| |_| .__/ \\___/|___/\\___| |_| \\_|\\___| \\_/\\_/   |_|  |_|\\___|___|___/\\__,_|\\__, |\\___|\n"
          "                      |_|                                                                     |___/      ";
    cout<<"\n***************************************************";
}


void ComposeNewMessage(){
    string usernameDestination;
    int i ;
    if (size >= 2) {
        main1:
        i = 0;
        cout << "\nTo : ";
        cin >> usernameDestination;
        for (; i < size; ++i) {
            if (usernameDestination == acc[i].username)
                break;
        }
        if (usernameDestination == acc[i].username) {
            srand(time(0));
            mail[sizeMail].mailId = rand();
            mail[sizeMail].from = acc[k].userId;
            mail[sizeMail].to = acc[i].userId;
            cout<<flush;
            cin.ignore();
            cout << "\nSubject : ";
            getline(cin, mail[sizeMail].subject);
            main2:
            cout << "\nText : " << endl;
            getline(cin, mail[sizeMail].text);
            if (mail[sizeMail].text.size() == 1){
                cout<<"\nError , can't send empty message";
                goto main2;
            }
        } else {
            cout << "\nError , No username found";
            goto main1;
        }
        ++sizeMail;
    }
    else{
        cout<<"\nError , There's no mail to sent message";
    }
}



void MessageListBanner(){
    cout<<"\n***************************************************"<<endl;
    cout<<"  __  __                                 _     _     _   \n"
          " |  \\/  | ___ ___ ___  __ _  __ _  ___  | |   (_)___| |_ \n"
          " | |\\/| |/ _ / __/ __|/ _` |/ _` |/ _ \\ | |   | / __| __|\n"
          " | |  | |  __\\__ \\__ | (_| | (_| |  __/ | |___| \\__ | |_ \n"
          " |_|  |_|\\___|___|___/\\__,_|\\__, |\\___| |_____|_|___/\\__|\n"
          "                            |___/                        ";
    cout<<"\n***************************************************";
}



void MessageListMenu(){
    cout<<"\n1.Inbox";
    cout<<"\n2.Sent Mails";
    cout<<"\n3.Drafts";
    cout<<"\n4.Starred Mails";
    cout<<"\n5.Trash";
    cout<<"\n6.Back";
    cout<<"\n***************************************************";
    cout<<"\nEnter Number : ";
}



void DeleteAccount1(){
    cout<<"\n***************************************************";
    cout<<"\nAre you sure you want to delete you're Account ? \n1.Yes          2.No";
    cout<<"\n***************************************************";
    cout<<"\nEnter Number : ";
}



void DeleteAccount2(){
    if (size < 2)
        size = 0;
    else{
        --size;
    }
        for (; k < size; ++k) {
            user[k].name = user[k + 1].name;
            user[k].lastName = user[k + 1].lastName;
            user[k].age[0] = user[k + 1].age[0];
            user[k].age[1] = user[k + 1].age[1];
            user[k].id = user[k + 1].id;
            user[k].jens = user[k + 1].jens;
            acc[k].userId = acc[k + 1].userId;
            acc[k].username = acc[k + 1].username;
            acc[k].password = acc[k + 1].password;
        }
}



void filesWrite(){
    ofstream Id , User , Account , Mails;
    Id.open("IdData.txt");
    for (int i = 0; i < size; ++i) {
        Id<<user[i].id<<" "<<mail[i].mailId<<endl;
    }
    Id.close();


    User.open("UserData.txt");
    for (int i = 0; i < size; ++i) {
        User<<user[i].name<<" "<<user[i].lastName<<" "<<user[i].age<<"  "<<user[i].id<<"  "<<user[i].jens<<endl;
    }
    User.close();


    Account.open("AccountData.txt");
    for (int i = 0; i < size; ++i) {
        Account<<acc[i].userId<<" "<<acc[i].username<<" "<<acc[i].password<<" "<<endl;
    }
    Account.close();


    Mails.open("MailsData.txt");
    for (int i = 0; i < sizeMail; ++i) {
        Mails<<mail[i].subject<<"|"<<mail[i].text<<"|"<<mail[i].from<<"|"<<mail[i].to<<"|"<<mail[i].mailId<<"|"<<endl;
    }
}



int main() {  // main program
    char ChooseNumber;
    size = 0;
    k = 0;
    sizeMail = 0;
    filesRead();
    while (true) {
        main1:
        WelcomeBanner();
        MainMenu();
        cin >> ChooseNumber;
        if (int(ChooseNumber == 49)) {
            signUpBanner();
            SignUp(ChooseNumber);
        }
        else if (int(ChooseNumber) == 50) {
            main2:
            loginBanner();
            login();
            if (username == acc[k].username && password == acc[k].password){
                main3:
                loginMenuBanner();
                loginMenu();
                cin>>ChooseNumber;
                if (int(ChooseNumber) == 49){
                    EditProfileBanner();
                    ShowProfile();
                    EditProfile(ChooseNumber);
                    goto main3;
                }
                else if (int(ChooseNumber) == 50){
                    ComposeNewMessageBanner();
                    ComposeNewMessage();
                    goto main3;
                }
                else if (int(ChooseNumber) == 51){
                    main3_2:
                    MessageListBanner();
                    MessageListMenu();
                    cin>>ChooseNumber;
                    if (int(ChooseNumber) == 49){}
                    else if (int(ChooseNumber) == 50){}
                    else if (int(ChooseNumber) == 51){}
                    else if (int(ChooseNumber) == 52){}
                    else if (int(ChooseNumber) == 53){}
                    else if (int(ChooseNumber) == 54){
                        goto main3;
                    }
                    else{
                        cout << "\nError , Undefined Number , Don't Enter Letters";
                        goto main3_2;
                    }
                }
                else if (int(ChooseNumber) == 52){
                    main3_1:
                    DeleteAccount1();
                    cin>>ChooseNumber;
                    if (int(ChooseNumber) == 49){
                        DeleteAccount2();
                        goto main1;
                    }
                    else if (int(ChooseNumber) == 50){
                        goto main3;
                    }
                    else{
                        cout<<"\nError , Attention to Letters , Don't Type Numbers";
                        goto main3_1;
                    }
                }
                else if (int(ChooseNumber) == 53){
                    goto main1;
                }
                else {
                    cout << "\nError , Undefined Number , Don't Enter Letters"<<endl;
                    goto main3;
                }
            }
            else if (username != acc[k].username && password != acc[k].password){
                main4:
                loginMenu2IfNoUserFound();
                cin>>ChooseNumber;
                if (int(ChooseNumber) == 49)
                    goto main1;
                else if (int(ChooseNumber) == 50)
                    goto main2;
                else {
                    cout << "\nError , Undefined Number , Don't Enter Letters";
                    goto main4;
                }
            }
        }
        else if (int(ChooseNumber) == 51) {
            filesWrite();
            return 0;
        }
        else {
            cout << "\nError , Undefined Number , Don't Enter Letters"<<endl;
        }
    }
}