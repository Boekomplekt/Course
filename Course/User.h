#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<limits>
#include<string>
#include<algorithm>
#include"Offers.h"
#include"Coach.h"
#include"Menu.h"


class User {
public:
	char name[50];
	char surname[50];
	int age;
	char login[30];
	char password[20];
	char yphone[20];
	char ygmail[50];
	char coachs[50];
	int monthCon;
	char conEdition[50];
};

std::ostream& operator<<(std::ostream& os, const User& ad);

void WriteIn(std::vector<User>& AddingUsers);

std::vector<User> ReadIn(std::vector<User>& AddingUsers);

std::vector<User> DeleteAccount(std::vector<User>& AddingUsers, unsigned int& id,bool& isDeleted);

void search(std::vector<User>& AddingUsers);

void ShowNameDesc(std::vector<User>& AddingUsers);

std::vector<User>ChooseCouch(std::vector<User>& AddingUsers, std::vector<Coach>& personal, int& ChooseC, unsigned int& id);

std::vector<User>ChooseTerm(std::vector<User>& AddingUsers, std::vector<Offers>& offering, int& months, unsigned int& id);

void MyContract(std::vector<User>& AddingUsers,std::vector<Coach>& personal, unsigned int& id);

int LogIn(std::vector<User>& AddingUsers, unsigned int& id, bool& enter);

void ShowProf(std::vector<User>& AddingUsers, unsigned int& id);

std::vector<User> Registration(std::vector<User>& AddingUsers, size_t& numberOfElement);
