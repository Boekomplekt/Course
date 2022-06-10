#pragma once
#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<limits>
#include<string>
#include<algorithm>

class Offers {
public:
	int Month;
	char var[50];
};
void WriteInO(std::vector<Offers>& offering);
std::vector<Offers> ReadInO(std::vector<Offers>& offering);
std::vector<Offers> OfRegistration(std::vector<Offers>offering, size_t& numberOfElement);

