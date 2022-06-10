#pragma once
#include<iostream>
#include<vector>
#include <cmath>
#include <fstream>
#include <limits>
#include <string>
#include <algorithm>
#include "Offers.h"
#include "Coach.h"
#include "Menu.h"
#include "User.h"
#include "Validation.h"
#include "Feedback.h"




void menus();
void PrintOutMenu();
void MainMenu();
void OfferMenu();
void Contract();
void MyProfile();
void Filtering();
void Coaches(std::vector<Coach>& personal);

