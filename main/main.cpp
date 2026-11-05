#include <iostream>;
#include <cmath>;
using namespace std;

int susceptible = 80;
int infected = 10;
int recovered = 10;
int day = 0;
int total = 100;
double infectionRate = 0.20;
double recoveryRate = 0.10;
void showPopulation(int day, int susceptible, int infected, int recovered);
void menu();
void simulateDay();
int checkPopulation(int susceptible, int infected, int recovered);
void changeParameters();

int main() {
	showPopulation(day, susceptible, infected, recovered);
	cout << "" << endl;
	menu();
}

void showPopulation(int day, int susceptible, int infected, int recovered) {
	cout << "Day: " << day << endl;
	cout << "Susceptible: " << susceptible << endl;
	cout << "Infected: " << infected << endl;
	cout << "Recovered: " << recovered << endl;
	total = susceptible + infected + recovered;
	cout << "Total: " << total << endl;
}

void menu() {
	int choice;
	cout << "=== Epidemic Simulator ===" << endl;
	cout << "1.Simulate next day" << endl;
	cout << "2. Change model parameters" << endl;
	cout << "3. Exit" << endl;
	cout << "Your choice: ";
	cin >> choice;
	cout << "" << endl;
	switch (choice) {
	case 1:
		simulateDay();
		break;
	case 2:
		changeParameters();
		break;
	case 3:
		cout << "Exiting..." << endl;
		exit(0);
	default:
		cout << "Invalid choice. Please try again." << endl;
		cout << "" << endl;
		menu();
	}
}

void simulateDay() {
	int newInfected = infected * infectionRate;
	int newRecovered = infected * recoveryRate;
	newInfected = min(newInfected, susceptible);
	newRecovered = min(newRecovered, infected);
	infected = floor(infected + newInfected - newRecovered);
	recovered = floor(recovered + newRecovered);
	susceptible = floor(susceptible - newInfected);
	day++;
	checkPopulation(susceptible, infected, recovered);
}

int checkPopulation(int susceptible, int infected, int recovered) {
	total = susceptible + infected + recovered;
	if (total != 100) {
		cout << "Error: Total population is not equal to 100." << endl;
		return 0;
	}
	if (susceptible < 0 || infected < 0 || recovered < 0) {
		cout << "Error: Population cannot be negative." << endl;
		return 0;
	}
	cout << "" << endl;
	main();
}

void changeParameters() {
	double newInfectionRate;
	double newRecoveryRate;
	cout << "Enter new infection rate [0.0 - 1.0]: ";
	cin >> newInfectionRate;
	if (newInfectionRate < 0 || newInfectionRate > 1) {
		cout << "Error: Invalid infection rate." << endl;
	}
	else {
		cout << "Parameter updated." << endl;
		infectionRate = newInfectionRate;
	}
	cout << "Enter new recovery rate [0.0 - 1.0]: ";
	cin >> newRecoveryRate;
	if (newRecoveryRate < 0 || newRecoveryRate > 1) {
		cout << "Error: Invalid recovery rate." << endl;
	}
	else {
		cout << "Parameter updated." << endl;
		recoveryRate = newRecoveryRate;
	}
	cout << "" << endl;
	main();
}