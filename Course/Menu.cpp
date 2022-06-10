#include "Menu.h" 
#define CLEARBUF   cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');

using namespace std;

void menus() {
	bool isDeleted = false;
	size_t numberOfElement = 0;
	bool enter = false;
	int ChooseC = 0;
	int months = 0;
	unsigned int id = 0;

	vector<User> AddingClient;
	vector<Coach> personaladd;
	vector<Offers> AddingOffers;
	AddingClient = ReadIn(AddingClient);
	personaladd = ReadInC(personaladd);
	AddingOffers = ReadInO(AddingOffers);

	char menuChoice = 'Z';

	while ((menuChoice != 'Q') && (menuChoice != 'q')) {
		enter = false;
		PrintOutMenu();
		cin >> menuChoice;
		CLEARBUF
			system("CLS");
		char menuChoice2 = 'Z';
		switch (menuChoice) {
		case 'A': case 'a': {
			AddingClient = Registration(AddingClient, numberOfElement);
			system("CLS");

			break;
		}
		case 'P': case 'p': {
			ShowNameDesc(AddingClient);
			system("CLS");
			break;
		}
		case 'O': case 'o': {
			LogIn(AddingClient, id, enter);

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
				CLEARBUF
					system("CLS");
				switch (menuChoice2) {
				case 'A': case 'a': {
					ShowProf(AddingClient, id);

					while ((menuChoice3 != 'Q') && (menuChoice3 != 'q')) {
						MyProfile();
						cin >> menuChoice3;
						CLEARBUF
							system("CLS");
						switch (menuChoice3) {
						case 'A': case 'a': {
							MyContract(AddingClient, personaladd, id);
							break;
						}
						case 'P': case 'p': {
							DeleteAccount(AddingClient, id, isDeleted);
							AddingClient = ReadIn(AddingClient);
							if (isDeleted == true) {
								menuChoice3 = 'Q';
								menuChoice2 = 'Q';
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
					break;
				}
				case 'P': case 'p': {
					while ((menuChoice5 != 'Q') && (menuChoice5 != 'q')) {
						char menuChoice4 = 'Z';
						char menuChoice6 = 'Z';
						OfferMenu();
						cin >> menuChoice5;
						CLEARBUF
							system("CLS");
						switch (menuChoice5) {
						case 'A': case 'a': {
							cout << "Yoga: Every monday,wednesday,friday 19.00-20.00" << endl
								<< "Sport dances: Every tuesday,thursday 9.00-10.00" << endl
								<< "Gymnastic: Every monday,tuesday 18.00-19.00" << endl
								<< "Motivation courses: Every sunday,saturday 14.00-15.00" << endl;
							break;
						}
						case 'P': case 'p': {
							while ((menuChoice6 != 'Q') && (menuChoice6 != 'q')) {
								Contract();
								cin >> menuChoice6;
								CLEARBUF
									system("CLS");
								switch (menuChoice6) {
								case 'A': case 'a': {
									char yORn = 'Z';
									cout << "The common edition contains only a gym pass and access to the equipment." << endl
										<< "You can enter into this contract for a period of one month to a year.26$/month" << endl;
									cout << "If you want to sign this type of a contract press Y,if not enter any other letter" << endl;
									cin >> yORn;
									CLEARBUF
										if ((yORn == 'Y') || (yORn == 'y')) {
											monthsQ(months);
											months--;
											ChooseTerm(AddingClient, AddingOffers, months, id);
											AddingClient = ReadIn(AddingClient);
										}
									system("CLS");
									break;
								}
								case 'P': case 'p': {
									char yORn = 'Z';
									cout << "The gold edition contains a gym pass,access to the equipment and oportunity to visit group exercises." << endl
										<< "You can enter into this contract for a period of one month to a year.32$/month" << endl;
									cout << "If you want to sign this type of a contract press Y,if not enter any other letter" << endl;
									cin >> yORn;
									CLEARBUF
										if ((yORn == 'Y') || (yORn == 'y')) {
											monthsQ(months);
											months += 11;
											ChooseTerm(AddingClient, AddingOffers, months, id);
											AddingClient = ReadIn(AddingClient);
										}
									system("CLS");
									break;
								}
								case 'O': case 'o': {
									char yORn = 'Z';
									cout << "The premium edition containsa gym pass,access to the equipment," << endl
										<< "oportunity to visit group exercises and free water." << endl
										<< "You can enter into this contract for a period of one month to a year.40$/month" << endl;
									cout << "If you want to sign this type of a contract press Y,if not enter any other letter" << endl;
									cin >> yORn;
									CLEARBUF
										if ((yORn == 'Y') || (yORn == 'y')) {
											monthsQ(months);
											months += 23;
											ChooseTerm(AddingClient, AddingOffers, months, id);
											AddingClient = ReadIn(AddingClient);
										}
									system("CLS");
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
							Coaches(personaladd);
							cin >> menuChoice4;
							CLEARBUF
								system("CLS");
							switch (menuChoice4) {
							case 'A': case 'a': {

								ChooseC = 0;
								ChooseCouch(AddingClient, personaladd, ChooseC, id);
								AddingClient = ReadIn(AddingClient);
								system("CLS");
								break;
							}
							case 'P': case 'p': {
								ChooseC = 1;
								ChooseCouch(AddingClient, personaladd, ChooseC, id);
								AddingClient = ReadIn(AddingClient);
								system("CLS");
								break;
							}
							case 'O': case 'o': {
								ChooseC = 2;
								ChooseCouch(AddingClient, personaladd, ChooseC, id);
								AddingClient = ReadIn(AddingClient);
								system("CLS");
								break;
							}
							case 'H': case 'h': {
								ChooseC = 3;
								ChooseCouch(AddingClient, personaladd, ChooseC, id);
								AddingClient = ReadIn(AddingClient);
								system("CLS");
								break;
							}
							default: {
								cout << "Choose a valtype menu option \n";
								break;
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

void PrintOutMenu() {
	cout << "+---+----------------------+ \n"
		<< "| A |    |Registration|    | \n"
		<< "+---+----------------------+ \n"
		<< "| P |   |Print all users|  | \n"
		<< "+---+----------------------+ \n"
		<< "| O |       |Log In|       | \n"
		<< "+---+----------------------+ \n"
		<< "| Q |        |Quit|        | \n"
		<< "+---+----------------------+ \n";
}
void MainMenu() {
	cout << "+---+----------------------+ \n"
		<< "| A |    |Your profile|    | \n"
		<< "+---+----------------------+ \n"
		<< "| P |  |Available Offers|  | \n"
		<< "+---+----------------------+ \n"
		<< "| O |      |About Us|      | \n"
		<< "+---+----------------------+ \n"
		<< "| Q |     |Step back|      | \n"
		<< "+---+----------------------+ \n";
}
void OfferMenu() {
	cout << "+---+----------------------+ \n"
		<< "| A |   |Group ex. time|   | \n"
		<< "+---+----------------------+ \n"
		<< "| P |       |Offers|       | \n"
		<< "+---+----------------------+ \n"
		<< "| O |      |Coaches|       | \n"
		<< "+---+----------------------+ \n"
		<< "| H | |Exercise equipment| | \n"
		<< "+---+----------------------+ \n"
		<< "| Q |      |Step back|     | \n"
		<< "+---+----------------------+ \n";
}
void Contract() {
	cout << "+---+----------------------+ \n"
		<< "| A |   |Common edition|   | \n"
		<< "+---+----------------------+ \n"
		<< "| P |    |Gold edition|    | \n"
		<< "+---+----------------------+ \n"
		<< "| O |   |Premium edition|  | \n"
		<< "+---+----------------------+ \n"
		<< "| Q |      |Step back|     | \n"
		<< "+---+----------------------+ \n";
}
void MyProfile() {
	cout << "+---+-----------------------+ \n"
		<< "| A |     |My contract|     | \n"
		<< "+---+-----------------------+ \n"
		<< "| P | |Delete your Account| | \n"
		<< "+---+-----------------------+ \n"
		<< "| O |   |Give a feedback|   | \n"
		<< "+---+-----------------------+ \n"
		<< "| Q |      |Step back|      | \n"
		<< "+---+-----------------------+ \n";
}
void Filtering() {
	cout << "+---+---------------------------------+ \n"
		<< "| A |  |Filter by names first letter| | \n"
		<< "+---+---------------------------------+ \n"
		<< "| P ||Filter by surnames first letter|| \n"
		<< "+---+---------------------------------+ \n"
		<< "| H |        |Filter by age|          | \n"
		<< "+---+---------------------------------+ \n"
		<< "| Q |     |I dont need filtering|     | \n"
		<< "+---+---------------------------------+ \n";
}
void Coaches(vector<Coach>& personal) {
	cout << "+---+--------------------------------+ \n"
		<< "| A |  |Andris R. 21 y.o|" << personal[0].rating << "   | \n"
		<< "+---+--------------------------------+ \n"
		<< "| P |   |Elena S. 27 y.o|" << personal[1].rating << "   | \n"
		<< "+---+--------------------------------+ \n"
		<< "| O | |Anatolijs D. 34 y.o|" << personal[2].rating << " | \n"
		<< "+---+--------------------------------+ \n"
		<< "| H | |Evgenija G. 29 y.o|" << personal[3].rating << "  | \n"
		<< "+---+--------------------------------+ \n"
		<< "| Q |       Step back                | \n"
		<< "+---+--------------------------------+ \n";
}


