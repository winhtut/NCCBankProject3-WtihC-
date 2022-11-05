//
// Created by National Cyber City on 11/4/2022.
//
#include "iostream"
#include "bank.h"
#include "fstream"
using namespace N;
using namespace std;

void bank::welcome(){
    cout<<"Welcome to NCC Bank"<<endl;
    _nameloading();
    showAllData();
    mainMenu();



}

void bank::mainMenu(){
    string mainOption;
    cout<<"Press 1 to Register:"<<endl;
    cout<<"Press 2 to Login:"<<endl;
    cout<<"Press 3 to Quit:"<<endl;
    cin>>mainOption;
    if(mainOption == "1"){
       Register();
    }else if(mainOption=="2"){
        login();
    } else if(mainOption =="3"){
        cout<<"Good Luck!"<<endl;
        exit(1);
    } else{
        cout<<"Invalid Option"<<endl;
        mainMenu();
    }
}

int bank::Register() {
    cout<<"This is Register:"<<endl;


}

int bank::login() {
    cout<<"This is Login:"<<endl;
    cout<<"Enter username:"<<endl;
    cin>>l_username;
    int result = userNameExit(l_username);
    if(result!=-1){
        cout<< l_username <<"is valid Enter password:";
        cin>>l_password;
        if(l_password == _arrPassword[result]){
            cout<<"Login Success:"<<endl;
            cout<<"Welcome :"<<l_username<<endl;
            exchange();

        } else{
            cout<<"Wrong Password"<<endl;
            login();
        }

    } else{
        cout<<"Invalid Username:"<<endl;
        login();
    }


}

int bank::userNameExit(string username){
    for(int i=0 ; i<usernameIndex ;i++){
        if(_arrUsername[i] == username){
            return i;
        }
    }
    return -1;

}

int bank::_nameloading() {
    // username.txt   password.txt
    cout<<"Loading Processing is Running..\n.\n.\n."<<endl;
    string username="username.txt";
    string password="password.txt";
//    ofstream usernamefile;
//    ofstream passwordfile;
//    usernamefile.open(username,ios::app);
//    passwordfile.open(password,ios::app);

    string data;
    string dataPassword;
    ifstream userfile(username);
    if(userfile.is_open()){
        while (getline(userfile,data)){
            _arrUsername[usernameIndex] = data;
            usernameIndex++;
        }
        userfile.close();
    } else{
        cout<<"Unable to open file:"<<endl;
    }
    ifstream psfile(password);
    if(psfile.is_open()){
        while (getline(psfile,dataPassword)){
            _arrPassword[pwIndex] = dataPassword;
            pwIndex++;
        }
        psfile.close();
    } else{
        cout<<"Unable to open file:"<<endl;
    }

}

int bank::exchange() {
    cout<<"This is Exchange page"<<endl;
}

void bank::showAllData(){
    for(int i ; i<usernameIndex ; i++){
        cout<<"Username:"<<_arrUsername[i]<<": Password:"<<_arrPassword[i]<<endl;
    }

}
