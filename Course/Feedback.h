#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<limits>
#include<string>
#include<algorithm>
#include"User.h"


class Feedback
{
public:
	char userName[50] = " ";
	char userSurname[50] = " ";
	int userAge = 0;
	std::string userFeedback;
};


std::vector<Feedback> ReadInF(std::vector<Feedback>& feedbacks);

void WriteInF(std::vector<Feedback>& feedbacks);

std::vector<Feedback>GivingFeedback(std::vector<Feedback>& feedbacks,size_t& numberOfElement, std::vector<User> AddingClient, unsigned int& id);

void search(std::vector<Feedback>& feedbacks);

void ShowNameDesc(std::vector<Feedback>& feedbacks);

