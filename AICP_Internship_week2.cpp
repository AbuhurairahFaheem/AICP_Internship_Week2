#include<iostream>
#include<string>
using namespace std;

void record(string arr[], float amount_paid[], int no_of_citizens, float& total_AmountPaid,int no_of_carers) {
	for (int i = 0; i < no_of_carers; i++) {
		
		arr[i] = "Carer" + to_string(i+1);
		amount_paid[i] = 0; total_AmountPaid += amount_paid[i];

	}
	cout << "NOW, Let's enter the data(name and amount paid(PER PERSON)) of each citizen(one by one):\n";
	for (int i = 0+ no_of_carers; i < no_of_citizens+ no_of_carers; i++) {
		cout << "Enter name of citizen (" << i + 1- no_of_carers << "): ";
		cin.ignore();
		getline(cin, arr[i]);
		cout << "Enter amount($) in numbers paid by citizen (" << arr[i] << "): ";
		cin >> amount_paid[i]; total_AmountPaid += amount_paid[i];
		cout << endl;
		
	}
	cout << endl;
}

void add(string arr[], float amount_paid[], int no_of_citizens,int temp, float& total_AmountPaid, int & total_people, int no_of_carers) {
	int l= 0; 
	cout << "**************************************************************************************************************\n";
	cout << "NOW, Let's enter the data(name and amount paid(PER PERSON)) of each additional person(one by one):\n";
	cout << "**************************************************************************************************************\n";
	for (int i = no_of_citizens+ no_of_carers; i < no_of_citizens+temp; i++) {
		cout << "Enter name of person (" << i + 1- no_of_citizens << "): ";
		cin >> ws;
		getline(cin, arr[i]);
		cout << "Enter amount($) paid by person (" << arr[i] << "): ";
		cin >> amount_paid[i]; total_AmountPaid += amount_paid[i]; total_people++;
		cout << "Want to add more persons ??, (if yes,'enter 1', 'or else enter 0'): "; cin >> l;
		if (l != 1)break;
	}
	cout << "\n**************************************************************************************************************\n";
	cout << endl;
}


int main() {
	int no_of_citizens = 0, min = 10, max = 36, no_of_carers = 2, coach_cost = 0;
	float meal_cost = 0, theaterTicket_cost = 0, total_AmountPaid=0, estimated_total=0;
	string arr[39] = { " "}; float amount_paid[39] = {};
	//TASK 1
	cout << "Welcome to Citizen's club data(for an outing)!\n";
	cout << "Enter the number of citizens going(10-36): ";
	cin >> no_of_citizens;
	while(no_of_citizens<min || no_of_citizens>max) {
		cout << "Please enter valid number of citizens going(10 to 36): ";
		cin >> no_of_citizens;
	}
	if (no_of_citizens > 24) no_of_carers++;
	int total_people = no_of_citizens + no_of_carers;
	float total_cost = 0, costPerPerson=0;
	if(total_people>=27) coach_cost = 225, meal_cost = 13.00,theaterTicket_cost = 19.00,estimated_total= coach_cost+ meal_cost+ theaterTicket_cost;
	else if (total_people >= 17) coach_cost = 190, meal_cost = 13.50,theaterTicket_cost = 20.00,estimated_total = coach_cost + meal_cost + theaterTicket_cost;
	else if (total_people >= 12) coach_cost = 150, meal_cost = 14.00, theaterTicket_cost = 21.00,estimated_total = coach_cost + meal_cost + theaterTicket_cost;
	cout << "__________________________________________________________________________________________________________________\n";
	total_cost = (coach_cost + meal_cost + theaterTicket_cost); cout << "\nTotal Cost: " << total_cost << endl;;
	costPerPerson = (coach_cost + meal_cost + theaterTicket_cost) / no_of_citizens; cout << "Cost per person: " << costPerPerson<<endl;
	cout << "__________________________________________________________________________________________________________________\n";
	//TASK 2
	record(arr, amount_paid, no_of_citizens, total_AmountPaid, no_of_carers);
	if (total_people >= 27 && total_people < 39) {
		cout << "Spare place left on the couch!!\n",
	    cout << 39 - total_people << " person(s) can be added while paying charges same as citizens,(Enter 1 to add people)";
		int temp = 0; cin >> temp;
		if (temp == 1) add(arr, amount_paid, no_of_citizens, 39 - total_people, total_AmountPaid, total_people, no_of_carers);
	}
	else if (total_people >= 17 && total_people < 26) {
		cout << "Spare place left on the couch!!\n",
		cout << 26 - total_people << " person(s) can be added while paying charges same as citizens,(Enter 1 to add people)";
		int temp = 0; cin >> temp; 
		if (temp == 1) add(arr, amount_paid, no_of_citizens, 26 - total_people, total_AmountPaid, total_people, no_of_carers);
	}
	else if (total_people >= 12 && total_people < 16) {
		cout << "Spare place left on the couch!!\n",
		cout << 16 - total_people << " person(s) can be added while paying charges same as citizens,(Enter 1 to add people)";
		int temp = 0; cin >> temp; 
		if (temp == 1) add(arr, amount_paid, no_of_citizens, 16 - total_people, total_AmountPaid, total_people, no_of_carers);
	}
	cout << "**************************************************************************************************************\n";
	cout << "Now Let's see the total amount paid: \n" << "Total Amount paid = " << total_AmountPaid << "$\n";
	cout << "**************************************************************************************************************\n";
	cout << "HERE IS A LIST OF ALL PERSONS GOING FOR OUTING: \n";
	for (int i = 0; i < total_people; i++) {
		cout << i + 1 << "." << " " << arr[i] << " : " << amount_paid[i] << "$" << endl;
	}
	cout << "**************************************************************************************************************\n";
	cout << "______________________________________________________________________________________________________________\n";
	//TASK 3
	cout << "Now Let's see if outing is a profit or a break-even:\n";
	cout << "Estimated total Amount= " << estimated_total<<endl;
	cout << "Total Amont collected = " << total_AmountPaid << endl;
	cout << "Profit= " << total_AmountPaid - estimated_total << endl;
	if (total_AmountPaid - estimated_total > 0) cout << "Got a PROFIT from OUTING!!" << endl;
	else cout << "Got a LOSS from OUTING!!" << endl;
	cout << "______________________________________________________________________________________________________________\n";
	cout << "**************************************************************************************************************\n";
	cout << "\n---------------------------------------------------------\n";
	cout << "           Wish you all the best for outing " << char(1) << "!!"<<endl;
	cout << "---------------------------------------------------------\n";


	return 0;
}