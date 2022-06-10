#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<limits>
#include<string>
#include<algorithm>


class Coach {
public:
	char coachname[50];
	double price;
	int ages;
	char rating[20];
};



std::ostream& operator<<(std::ostream& os, const Coach& ad);

std::vector<Coach> ReadInC(std::vector<Coach>& personal);

void WriteInC(std::vector<Coach>& personal);

