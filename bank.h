//
// Created by National Cyber City on 11/4/2022.
//
#include "iostream"
using namespace std;
#ifndef NCCBANKPROJECT3_BANK_H
#define NCCBANKPROJECT3_BANK_H

namespace N {
    class bank {
    public:
        // loading declaration
        int usernameIndex=0;
        int pwIndex=0;
        string _arrUsername[100];
        string _arrPassword[100];
        //attributes declaration
        string l_username;
        string l_password;
        // method declaration
        void welcome();
        void mainMenu();
        int Register();
        int login();
        int _nameloading();
        int userNameExit(string username);
        int exchange();
        void showAllData();

    private:


    };
}

#endif //NCCBANKPROJECT3_BANK_H
