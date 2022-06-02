#include<iostream>
#include<vector>
#include<cmath>
#include<fstream>
#include<limits>
#include<string>
#include<algorithm>

using namespace std;
size_t numberOfElement = 0;
bool enter = false;
unsigned int id = 0;
int ChooseC = 0;

class Offers {
public:
	char time[50];
	char var[50];
	char water[50];
};

class Coach {
public:
	char coachname[50];
	double price;
	int ages;
	char rating[20];
};

class User {
public:
	char name[20];
	char surname[20];
	int age;
	char login[30];
	char password[20];
	char yphone[20];
	char ygmail[50];
	char coachs[50];
};

ostream& operator<<(ostream& os, const User& ad)
{
	os << ad.name << '|' << ad.surname << '|' << ad.age << '|' << ad.login << '|' << ad.password << '|' << ad.yphone << '|' << ad.ygmail << "\n";
	return os;
}
ostream& operator<<(ostream& os, const Coach& ad) {
	os << ad.coachname << '|' << ad.price << '|' << ad.ages << '|' << ad.rating << "\n";
	return os;
}


void PrintOutMenu() {
	cout << "+---+---------------------+ \n"
		<< "| A | Registration         | \n"
		<< "+---+----------------------+ \n"
		<< "| P | Print all users      | \n"
		<< "+---+----------------------+ \n"
		<< "| O | Log In               | \n"
		<< "+---+----------------------+ \n"
		<< "| Q | Quit                 | \n"
		<< "+---+----------------------+ \n";
}
void MainMenu() {
	cout << "+---+---------------------+ \n"
		<< "| A | Your profile         | \n"
		<< "+---+----------------------+ \n"
		<< "| P | Available Offers     | \n"
		<< "+---+----------------------+ \n"
		<< "| O | About Us             | \n"
		<< "+---+----------------------+ \n"
		<< "| Q | Step back            | \n"
		<< "+---+----------------------+ \n";
}
void OfferMenu() {
	cout << "+---+---------------------+ \n"
		<< "| A | Group ex. time       | \n"
		<< "+---+----------------------+ \n"
		<< "| P | Offers               | \n"
		<< "+---+----------------------+ \n"
		<< "| O | Coaches              | \n"
		<< "+---+----------------------+ \n"
		<< "| H | Exercise equipment   | \n"
		<< "+---+----------------------+ \n"
		<< "| Q | Step back            | \n"
		<< "+---+----------------------+ \n";
}
void MyProfile() {
	cout << "+---+---------------------+ \n"
		<< "| A | My contract          | \n"
		<< "+---+----------------------+ \n"
		<< "| P | Delete your Account  | \n"
		<< "+---+----------------------+ \n"
		<< "| Q | Step back            | \n"
		<< "+---+----------------------+ \n";
}
void Coaches() {
	cout << "+---+---------------------+ \n"
		<< "| A | Andris R. 21 y.o     | \n"
		<< "+---+----------------------+ \n"
		<< "| P | Elena S. 27 y.o      | \n"
		<< "+---+----------------------+ \n"
		<< "| O |Anatolijs D. 34 y.o   | \n"
		<< "+---+----------------------+ \n"
		<< "| H |Evgenija G. 29 y.o    | \n"
		<< "+---+----------------------+ \n"
		<< "| Q | Step back            | \n"
		<< "+---+----------------------+ \n";
}
//void Csearch(vector<Coach> personal) {
//	ifstream file("Coaches.bin", ios::binary);
//	Coach ex;
//	personal.clear();
//	numberOfElement = personal.size();
//	while (file)
//	{
//		file.read((char*)(&ex.coachname), sizeof(ex.coachname));
//		file.read((char*)(&ex.price), sizeof(ex.price));
//		file.read((char*)(&ex.ages), sizeof(ex.ages));
//		file.read((char*)(&ex.rating), sizeof(ex.rating));
//
//		if (!file)
//			break;
//		personal.push_back(ex);
//		numberOfElement++;
//	}
//	file.close();
//
//	cout << "Printing out all objects \n";
//	if (personal.size() != 0) {
//		for (int i = 0; i < personal.size(); i++) {
//			cout << personal[i];
//		}
//	}
//
//
//}

void WriteIn(vector<User> AddingUsers) {
	ofstream file("Server.bin", ios::binary);
	for (int i = 0; i < AddingUsers.size(); i++) {
		file.write((char*)(&AddingUsers[i].name), sizeof(AddingUsers[i].name));
		file.write((char*)(&AddingUsers[i].surname), sizeof(AddingUsers[i].surname));
		file.write((char*)(&AddingUsers[i].age), sizeof(AddingUsers[i].age));
		file.write((char*)(&AddingUsers[i].login), sizeof(AddingUsers[i].login));
		file.write((char*)(&AddingUsers[i].password), sizeof(AddingUsers[i].password));
		file.write((char*)(&AddingUsers[i].yphone), sizeof(AddingUsers[i].yphone));
		file.write((char*)(&AddingUsers[i].ygmail), sizeof(AddingUsers[i].ygmail));
		file.write((char*)(&AddingUsers[i].coachs), sizeof(AddingUsers[i].coachs));

	}
	file.close();
}

vector<User> ReadIn(vector<User> AddingUsers) {
	ifstream file("Server.bin", ios::binary);
	User ex;
	AddingUsers.clear();
	while (file)
	{
		file.read((char*)(&ex.name), sizeof(ex.name));
		file.read((char*)(&ex.surname), sizeof(ex.surname));
		file.read((char*)(&ex.age), sizeof(ex.age));
		file.read((char*)(&ex.login), sizeof(ex.login));
		file.read((char*)(&ex.password), sizeof(ex.password));
		file.read((char*)(&ex.yphone), sizeof(ex.yphone));
		file.read((char*)(&ex.ygmail), sizeof(ex.ygmail));
		file.read((char*)(&ex.coachs), sizeof(ex.coachs));

		if (!file)
			break;
		AddingUsers.push_back(ex);
	}
	file.close();
	return AddingUsers;

}
vector<User> DeleteAccount(vector<User> AddingUsers) {
	cout << "Enter password\n";
	string delPas;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, delPas);
	char delPass[30] = "";
	bool isDeleted = false;
	if (delPas.size() > 30) {
		cout << "Too many characters\n";
	}
	else {
		for (int i = 0; i < delPas.size(); i++)
		{
			delPass[i] = delPas.at(i);
		}

		if (strcmp(AddingUsers.at(id).password, delPass) == 0) {
			AddingUsers.erase(AddingUsers.begin() + id);
			isDeleted = true;
			cout << "Successfully deleted account!\n";
			WriteIn(AddingUsers);
		}


		if (isDeleted == false) {
			cout << "Account not found\n";
		}
	}
	return AddingUsers;
}

vector<Coach> ReadInC(vector<Coach> personal) {
	ifstream file("Coaches.bin", ios::binary);
	Coach ex;
	personal.clear();
	while (file)
	{
		file.read((char*)(&ex.coachname), sizeof(ex.coachname));
		file.read((char*)(&ex.price), sizeof(ex.price));
		file.read((char*)(&ex.ages), sizeof(ex.ages));
		file.read((char*)(&ex.rating), sizeof(ex.rating));
		if (!file)
			break;
		personal.push_back(ex);
	}
	file.close();
	return personal;

}

void WriteInC(vector<Coach> personal) {
	ofstream file("Coaches.bin", ios::binary);
	for (int i = 0; i < personal.size(); i++) {
		file.write((char*)(&personal[i].coachname), sizeof(personal[i].coachname));
		file.write((char*)(&personal[i].price), sizeof(personal[i].price));
		file.write((char*)(&personal[i].ages), sizeof(personal[i].ages));
		file.write((char*)(&personal[i].rating), sizeof(personal[i].rating));

	}
	file.close();
}

void search(vector<User> AddingUsers) {

	ReadIn(AddingUsers);

	cout << "Printing out all objects \n";
	if (AddingUsers.size() != 0) {
		for (int i = 0; i < AddingUsers.size(); i++) {
			cout << AddingUsers[i];
		}
	}
}
void ShowNameDesc(vector<User> AddingUsers) {
	sort(AddingUsers.begin(), AddingUsers.end(), [](const User& x, const User& y)
		{
			return strcmp(x.name, y.name) < 0;
		});
	search(AddingUsers);
}

vector<Coach> TRegistration(vector<Coach>personal) {

	numberOfElement = personal.size();
	cout << "Adding new object \n";
	personal.push_back(Coach());
	cout << "Enter coachname \n";
	cin >> personal[numberOfElement].coachname;
	cout << "Enter price: \n";
	cin >> personal[numberOfElement].price;
	cout << "Enter ages \n";
	cin >> personal[numberOfElement].ages;
	cout << "Enter rating \n";
	cin >> personal[numberOfElement].rating;
	numberOfElement++;
	WriteInC(personal);
	return personal;
}

vector<User>ChooseCouch(vector<User> AddingUsers, vector<Coach>personal) {
	string CouchStr;
	char CouchChM[50] = "";
	CouchStr = personal[ChooseC].coachname;

	for (int i = 0; i < CouchStr.size(); i++)
	{
		CouchChM[i] = CouchStr.at(i);
	}
	strcpy_s(AddingUsers.at(id).coachs, 50, CouchChM);
	return AddingUsers;

}

int LogIn(vector<User> AddingUsers) {
	ReadIn(AddingUsers);
	string wlogin;
	string ylogin;
	string ypassword;
	int i = 0;
	cout << "Enter your login \n ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, ylogin);

	for (i; i < AddingUsers.size(); i++) {

		if (AddingUsers[i].login == ylogin) {
			cout << "Enter your password" << endl;

			getline(cin, ypassword);
			if (AddingUsers[i].password == ypassword) {
				cout << "Entrance success" << endl;
				id = i;
				i = INT_MAX;
				enter = true;
			}
			else {

				cout << "Invalid login or password,please try again" << endl;
				i = INT_MAX;
			}

		}

	}
	for (i = 0; i < AddingUsers.size(); i++) {
		if (AddingUsers[i].login == ylogin) {
			ylogin = wlogin;
		}
	}
	if (wlogin != ylogin) {
		cout << "Enter your password" << endl;

		getline(cin, ypassword);
		cout << "Invalid login or password,please try agains" << endl;
	}
	return ::id;
}

void ShowProf(vector<User> AddingUsers) {
	ReadIn(AddingUsers);
	cout << AddingUsers[id].name << " " << AddingUsers[id].surname << endl;
	cout << "Age: " << AddingUsers[id].age << " years old" << endl;
	cout << "Your login: " << AddingUsers[id].login << endl;
	cout << "Your phone: " << AddingUsers[id].yphone << endl;
	cout << "Your e-mail: " << AddingUsers[id].ygmail << endl;

}

vector<User> Registration(vector<User> AddingUsers) {
	numberOfElement = AddingUsers.size();

	cout << "Adding new object \n";
	AddingUsers.push_back(User());
	cout << "Enter name \n";
	cin >> AddingUsers[numberOfElement].name;
	cout << "Enter surname \n";
	cin >> AddingUsers[numberOfElement].surname;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter age: \n";

	cin >> AddingUsers[numberOfElement].age;
	while (true)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error: not an integer" << endl;
			cin >> AddingUsers[numberOfElement].age;
		}
		if (!cin.fail())
			break;
	}
	cout << "Enter login \n";
	cin >> AddingUsers[numberOfElement].login;
	cout << "Enter password: \n";
	cin >> AddingUsers[numberOfElement].password;
	cout << "Enter yphone \n";
	cin >> AddingUsers[numberOfElement].yphone;
	cout << "Enter ygmail \n";
	cin >> AddingUsers[numberOfElement].ygmail;
	numberOfElement++;

	WriteIn(AddingUsers);
	return AddingUsers;
};

int main() {
	vector<User> AddingClient;
	vector<Coach>personaladd;
	vector<Offers> AddingOffers;
	AddingClient = ReadIn(AddingClient);
	personaladd = ReadInC(personaladd);
	char menuChoice = 'Z';

	while ((menuChoice != 'Q') && (menuChoice != 'q')) {
		enter = false;
		PrintOutMenu();
		cin >> menuChoice;
		char menuChoice2 = 'Z';
		switch (menuChoice) {
		case 'A': case 'a': {
			AddingClient = Registration(AddingClient);

			break;
		}
		case 'P': case 'p': {
			ShowNameDesc(AddingClient);
			break;
		}
		case 'O': case 'o': {
			LogIn(AddingClient);

			break;
		}

		case 'Q': case 'q': {
			cout << "Exiting \n";
			break;
		}
		default: {
			cout << "Choose a valtype menu option \n";
			break;
		}

		}
		if (enter == true) {

			while ((menuChoice2 != 'Q') && (menuChoice2 != 'q')) {
				char menuChoice3 = 'Z';
				char menuChoice5 = 'Z';
				MainMenu();
				cin >> menuChoice2;
				switch (menuChoice2) {
				case 'A': case 'a': {
					ShowProf(AddingClient);

					while ((menuChoice3 != 'Q') && (menuChoice3 != 'q')) {
						MyProfile();
						cin >> menuChoice3;
						switch (menuChoice3) {
						case 'A': case 'a': {

							break;
						}
						case 'P': case 'p': {
							DeleteAccount(AddingClient);
							AddingClient = ReadIn(AddingClient);
							menuChoice3 = 'Q';
							menuChoice2 = 'Q';


							break;
						}
						case 'Q': case 'q': {
							cout << "Exiting \n";
							break;
						}
						default: {
							cout << "Choose a valtype menu option \n";
							break;
						}
						}

					}
					break;
				}
				case 'P': case 'p': {
					while ((menuChoice5 != 'Q') && (menuChoice5 != 'q')) {
						char menuChoice4 = 'Z';
						OfferMenu();
						cin >> menuChoice5;
						switch (menuChoice5) {
						case 'A': case 'a': {
							cout << "Yoga: Every monday,wednesday,friday 19.00-20.00" << endl
								<< "Sport dances: Every tuesday,thursday 9.00-10.00" << endl
								<< "Gymnastic: Every monday,tuesday 18.00-19.00" << endl
								<< "Motivation courses: Every sunday,saturday 14.00-15.00" << endl;

							break;
						}
						case 'P': case 'p': {


							break;
						}
						case 'O': case 'o': {
							while ((menuChoice4 != 'Q') && (menuChoice4 != 'q')) {
								Coaches();
								cin >> menuChoice4;
								switch (menuChoice4) {
								case 'A': case 'a': {

									ChooseC = 0;
									ChooseCouch(AddingClient, personaladd);
									break;
								}
								case 'P': case 'p': {
									ChooseC = 1;
									ChooseCouch(AddingClient, personaladd);
									break;
								}
								case 'O': case 'o': {
									ChooseC = 2;
									ChooseCouch(AddingClient, personaladd);
									break;
								}
								case 'H': case 'h': {
									ChooseC = 3;
									ChooseCouch(AddingClient, personaladd);
									break;
								}
								case 'Q': case 'q': {
									cout << "Exiting \n";
									break;
								}

								default: {
									cout << "Choose a valtype menu option \n";
									break;
								}
								}
							}

							break;
						}
						case 'H': case 'h': {

							cout << "1. Training Bench" << endl
								<< "2. Dumbbell Set" << endl
								<< "3. Barbell Set" << endl
								<< "4. Kettlebell Set" << endl
								<< "5. Pull-Up Frame and Bar" << endl
								<< "6. Treadmill" << endl
								<< "7. Stationary Bicycle" << endl
								<< "8. Rowing Machine" << endl
								<< "9. Fitness Ball" << endl;
							break;
						}
						case 'Q': case 'q': {
							cout << "Exiting \n";
							break;
						}
						default: {
							cout << "Choose a valtype menu option \n";
							break;
						}
						}
					}
					break;

				}
				case 'O': case 'o': {
					cout << "Our gym gives you the opportunity to exercise your body. We have a variety " << endl
						<< "of exercise equipment available, such as : a treadmill, a barbell, a bicycle, rowing," << endl
						<< "various simulators for the muscles of the back, arms, legs, and so on." << endl
						<< endl << "Our adress: Slokas iela 31 " << endl
						<< endl << "Our phone: +37123483232 " << endl
						<< endl << "Our e - mail: sportgym@gmail.com" << endl
						<< endl << "We work 7 days at week from 8.00 to 21.00" << endl
						<< endl << "Administration work time:" << endl
						<< "From monday to friday: 8.00 - 21.00" << endl
						<< "Sunday,saturday: 12.00- 19.00" << endl << endl;
					break;
				}
				case 'Q': case 'q': {
					cout << "Exiting \n";
					break;
				}
				default: {
					cout << "Choose a valtype menu option \n";
					break;
				}
				}
			}
		}
	}
}


