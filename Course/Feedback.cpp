#include "Feedback.h"
#define CLEARBUF   cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std;

void ReadInF(vector<Feedback>& feedbacks)
{
	ifstream file("Users.bin", ios::binary);
	Feedback temp;
	feedbacks.clear();
	while (!file.eof())
	{
		file.read((char*)(&temp.userAge), sizeof(temp.userAge));
		file.read((char*)(&temp.userFeedback), sizeof(temp.userFeedback));
		file.read((char*)(&temp.userName), sizeof(temp.userName));
		file.read((char*)(&temp.userSurname), sizeof(temp.userSurname));
		if (!file)
			break;
		feedbacks.push_back(temp);
	}
	file.close();
}

void WriteInF(vector<Feedback>& feedbacks)
{
	ofstream file("Feedback.bin", ios::binary);
	for (auto& i : feedbacks) {
		file.write(reinterpret_cast<char*>(&i), sizeof(Feedback));
	}
	file.close();
}

vector<Feedback>GivingFeedback(vector<Feedback>& feedbacks, size_t& numberOfElement, vector<User> AddingClient, unsigned int& id)
{
	numberOfElement = feedbacks.size()
		feedbacks.push_back(Offers());
	feedbacks[numberOfElement].namefeedback = AddingUsers[id].name
		feedbacks[numberOfElement].surnamefeedback = AddingUsers[id].surname
		feedbacks[numberOfElement].agefeedback = AddingUsers[id].age
		и получаем feedbacks[numberOfElements].feedback

		numberOfElement++;
	WriteInO(feedback);
	return feedback;
}

void search(vector<Feedback>& feedbacks, vector<User>& AddingUsers) {
	char FilterChoice = 'Z';
	char Filter;
	int FilterAge = 0;
	ReadIn(AddingUsers);

	cout << "Printing out clients \n\n";
	for (const auto& i : AddingUsers) {
		cout << i.name << " / "
			<< i.surname << " / "
			<< i.age << endl;
	}
	cout << endl << "Amount of clients: " << AddingUsers.size();
	cout << endl << endl;
	while ((FilterChoice != 'Q') && (FilterChoice != 'q')) {
		Filtering();
		cin >> FilterChoice;
		CLEARBUF
			system("CLS");
		switch (FilterChoice) {
		case 'A': case 'a': {
			cout << "Filter by names first letter. Enter the letter: " << endl;
			cin >> Filter;
			CLEARBUF
				for (const auto& i : AddingUsers) {
					if (Filter == i.name[0]) {
						cout << i.name << " / "
							<< i.surname << " / "
							<< i.age << endl;
					}
				}
			break;
		}
		case 'P': case 'p': {
			cout << "Filter by surnames first letter. Enter the letter: " << endl;
			cin >> Filter;
			CLEARBUF
				for (const auto& i : AddingUsers) {
					if (Filter == i.surname[0]) {
						cout << i.surname << " / "
							<< i.name << " / "
							<< i.age << endl;
					}
				}

			break;
		}
		case 'H': case 'h': {
			cout << "Filter by age. See clients over: " << endl;
			cin >> FilterAge;
			while (true)
			{
				if (cin.fail())
				{
					CLEARBUF
						cout << "Error: not an integer" << endl;
					cin >> FilterAge;
				}
				if (!cin.fail())
					break;
			}
			for (const auto& i : AddingUsers) {
				if (FilterAge <= i.age) {
					sort(AddingUsers.begin(), AddingUsers.end(), [](const auto& x, const auto& y)
						{
							return x.age < y.age;
						});
					cout << i.age << " / "
						<< i.name << " / "
						<< i.surname << endl;
				}
			}

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

void ShowNameDesc(vector<Feedback>& feedbacks, vector<User>& AddingUsers) {
	sort(AddingUsers.begin(), AddingUsers.end(), [](const User& x, const User& y)
		{
			return strcmp(x.name, y.name) < 0;
		});
	search(AddingUsers);
}