#include "User.h"
#define CLEARBUF   cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std;

ostream& operator<<(ostream& os, const User& ad)
{
	os << ad.name << '|' << ad.surname << '|' << ad.age << '|' << ad.login << '|' << ad.password << '|' << ad.yphone << '|' << ad.ygmail << '|' << ad.coachs << '|' << ad.monthCon << '|' << ad.conEdition << "\n";
	return os;
}

void WriteIn(vector<User>& AddingUsers) {
	ofstream file("Users.bin", ios::binary);
	for (unsigned int i = 0; i < AddingUsers.size(); i++) {
		file.write((char*)(&AddingUsers[i].name), sizeof(AddingUsers[i].name));
		file.write((char*)(&AddingUsers[i].surname), sizeof(AddingUsers[i].surname));
		file.write((char*)(&AddingUsers[i].age), sizeof(AddingUsers[i].age));
		file.write((char*)(&AddingUsers[i].login), sizeof(AddingUsers[i].login));
		file.write((char*)(&AddingUsers[i].password), sizeof(AddingUsers[i].password));
		file.write((char*)(&AddingUsers[i].yphone), sizeof(AddingUsers[i].yphone));
		file.write((char*)(&AddingUsers[i].ygmail), sizeof(AddingUsers[i].ygmail));
		file.write((char*)(&AddingUsers[i].coachs), sizeof(AddingUsers[i].coachs));
		file.write((char*)(&AddingUsers[i].monthCon), sizeof(AddingUsers[i].monthCon));
		file.write((char*)(&AddingUsers[i].conEdition), sizeof(AddingUsers[i].conEdition));

	}
	file.close();
}

vector<User> ReadIn(vector<User>& AddingUsers) {
	ifstream file("Users.bin", ios::binary);
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
		file.read((char*)(&ex.monthCon), sizeof(ex.monthCon));
		file.read((char*)(&ex.conEdition), sizeof(ex.conEdition));

		if (!file)
			break;
		AddingUsers.push_back(ex);
	}
	file.close();
	return AddingUsers;

}

vector<User> DeleteAccount(vector<User>& AddingUsers, unsigned int& id, bool& isDeleted)
{
	cout << "Enter password\n";
	string delPas;
	getline(cin, delPas);
	char delPass[30] = "";
	if (delPas.size() > 30) {
		cout << "Too many characters\n";
	}
	else {
		for (unsigned int i = 0; i < delPas.size(); i++)
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

vector<User>ChooseCouch(vector<User>& AddingUsers, vector<Coach>& personal, int& ChooseC, unsigned int& id) {
	string CouchStr;
	char CouchChM[50] = "";
	CouchStr = personal[ChooseC].coachname;

	for (unsigned int i = 0; i < CouchStr.size(); i++)
	{
		CouchChM[i] = CouchStr.at(i);
	}
	strcpy_s(AddingUsers.at(id).coachs, 50, CouchChM);
	WriteIn(AddingUsers);
	return AddingUsers;

}

vector<User>ChooseTerm(vector<User>& AddingUsers, vector<Offers>& offering, int& months, unsigned int& id) {
	string EditStr;
	char EdirChM[50] = "";
	EditStr = offering[months].var;

	AddingUsers[id].monthCon = offering[months].Month;

	for (unsigned int i = 0; i < EditStr.size(); i++)
	{
		EdirChM[i] = EditStr.at(i);
	}
	strcpy_s(AddingUsers.at(id).conEdition, 50, EdirChM);
	WriteIn(AddingUsers);
	return AddingUsers;


}

void MyContract(vector<User>& AddingUsers, vector<Coach>& personal, unsigned int& id) {

	double priceForMonth = 0;
	double editionCost = 0;
	double coachPrice = 0;

	if (string(AddingUsers.at(id).conEdition) == "Common edition")
	{
		editionCost = 26;
	}
	if (string(AddingUsers.at(id).conEdition) == "Gold edition")
	{
		editionCost = 32;
	}
	if (string(AddingUsers.at(id).conEdition) == "Premium edition")
	{
		editionCost = 40;
	}

	for (const auto& i : personal) {
		if (string(i.coachname) == string(AddingUsers[id].coachs)) {
			coachPrice = i.price;
		}
	}
	priceForMonth = editionCost + coachPrice;

	cout << "This is your contract: " << endl
		<< endl << "You signed contract for " << AddingUsers[id].monthCon << " months" << endl
		<< "Your coach: " << AddingUsers[id].coachs << endl
		<< "Your edition: " << AddingUsers[id].conEdition << '\n'
		<< "Price for month: " << priceForMonth << "$" << '\n';





}

int LogIn(vector<User>& AddingUsers, unsigned int& id, bool& enter) {
	ReadIn(AddingUsers);
	string wlogin;
	string ylogin;
	string ypassword;
	unsigned int i = 0;
	cout << "Enter your login \n ";
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
	return id;
}

void ShowProf(vector<User>& AddingUsers, unsigned int& id) {
	ReadIn(AddingUsers);
	cout << "Name: " << AddingUsers[id].name << endl
		<< "Surname: " << AddingUsers[id].surname << endl
		<< "Age: " << AddingUsers[id].age << " years old" << endl
		<< "Your login: " << AddingUsers[id].login << endl
		<< "Your phone: " << AddingUsers[id].yphone << endl
		<< "Your e-mail: " << AddingUsers[id].ygmail << endl;

}

vector<User> Registration(vector<User>& AddingUsers, size_t& numberOfElement) {
	numberOfElement = AddingUsers.size();

	cout << "Adding new object \n";
	AddingUsers.push_back(User());
	cout << "Enter name \n";
	cin.getline(AddingUsers[numberOfElement].name, 50);
	cout << "Enter surname \n";
	cin.getline(AddingUsers[numberOfElement].surname, 50);
	cout << "Enter age: \n";
	string tage;
	string tmail;
	string tnum;
	while (true)
	{
		cin >> tage;
		CLEARBUF
			if (isvalid_data(tage, R"re(\d{1,2})re"))
			{
				AddingUsers[numberOfElement].age = (short)stoi(tage);
				break;
			}
			else
			{
				cout << "\nIncorrect input(s). Try again!\n";
				cout << "Enter your age: ";
			}
	}
	cout << "Enter login (1 - 30 symbols): \n";
	cin >> AddingUsers[numberOfElement].login;
	CLEARBUF
		cout << "Enter password(1 - 20 symbols): \n";
	cin >> AddingUsers[numberOfElement].password;
	CLEARBUF
		cout << "Enter phone (in 8 number format)  \n";
	string lv{ "+371" };
	while (true)
	{
		cin >> tnum;
		CLEARBUF
			if (isvalid_data(tnum, R"re(\d{8})re"))
			{
				lv += tnum;
				strcpy_s(AddingUsers[numberOfElement].yphone, lv.c_str());
				break;
			}
			else
			{

				cout << "\nIncorrect input(s). Try again!\n";
				cout << "Enter your LV phone number (e.g 22345678): ";
			}
	}
	cout << "Enter e-mail (in format word@word.word) \n";
	while (true)
	{
		cin >> tmail;
		CLEARBUF
			if (isvalid_data(tmail, R"re(^[\w-.]+@([\w-]+.)+[\w-]{2,4}$)re"))
			{
				strcpy_s(AddingUsers[numberOfElement].ygmail, tmail.c_str());
				break;
			}
			else
			{
				cout << "\nIncorrect input(s). Try again!\n";
				cout << "Enter your e-mail: ";
			}
	}

	numberOfElement++;

	WriteIn(AddingUsers);
	return AddingUsers;
};

