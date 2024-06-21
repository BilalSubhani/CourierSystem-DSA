#include <iostream>
#include <string>
#include "Customer.h"
#include "Graph.h"

using namespace std;

int main()
{
	int distance, input = 10;
	CustomerDetails receiver;
	CustomerDetails sender;
	string name, house, area, city;
	string name1, house1, area1, city1;

	graph G;
	G.addEdge("Gawadar", "Karachi", 12);
	G.addEdge("Karachi", "Hyderabad", 3);
	G.addEdge("Karachi", "Quetta", 17);
	G.addEdge("Karachi", "Sukhur", 10);
	G.addEdge("Hyderabad", "Islamabad", 29);
	G.addEdge("Hyderabad", "Multan", 19);
	G.addEdge("Hyderabad", "Bahawalpur", 14);
	G.addEdge("Islamabad", "Abbotabad", 9);
	G.addEdge("Islamabad", "Peshawar", 2);
	G.addEdge("Islamabad", "Lahore", 8);
	G.addEdge("Islamabad", "Faisalabad", 7);
	G.addEdge("Islamabad", "Multan", 19);
	G.addEdge("Abbotabad", "Peshawar", 11);
	G.addEdge("Lahore", "Faisalabad", 3);
	G.addEdge("Lahore", "Multan", 5);
	G.addEdge("Faislabad", "Multan", 4);
	G.addEdge("Multan", "Bahawalpur", 4);
	G.addEdge("Sukhur", "Hyderabad", 7);
	G.addEdge("Sukhur", "Bahawalpur", 8);
	G.addEdge("Quetta", "Bahawalpur", 13);


	do
	{
		cout << " ___________________________________________________\n " << endl;
		cout << " \t  Courier Management System\n";
		cout << " ___________________________________________________ " << endl;
		cout << " \t\tMAIN MENU" << endl;
		cout << " PRESS 1: To Print The Graph" << endl;
		cout << " Press 2: To enter sender and receiver details" << endl;
		cout << " Press 3: To print sender and receiver details" << endl;
		cout << " PRESS 4: To check whether path is available or not " << endl;
		cout << " PRESS 5: To Find shortest path " << endl;
		cout << " PRESS 0: To Exit" << endl;
		cout << " Enter Option: ";
		cin >> input;

		switch (input)
		{
		case 1:
			G.print();
			break;
		case 2:
			cout << "\n\n";
			cout << " Enter details of Sender:" << endl;
			cin.ignore();
			cout << " Enter Name: ";
			getline(cin, name);
			cout << " Enter House: ";
			getline(cin, house);
			cout << " Enter Area: ";
			getline(cin, area);
			cout << " Enter City: ";
			getline(cin, city);
			sender.setCustomerDetails(name, area, city, house);

			cout << "\n Enter details of Receiver:" << endl;
			cout << " Enter Name: ";
			getline(cin, name1);
			cout << " Enter House: ";
			getline(cin, house1);
			cout << " Enter Area: ";
			getline(cin, area1);
			cout << " Enter City: ";
			getline(cin, city1);
			receiver.setCustomerDetails(name1, area1, city1, house1);
			break;
		case 3:
			cout << "\n __________________________________________" << endl;
			cout << " Details of Receiver: " << endl;
			receiver.details();
			cout << "\n __________________________________________" << endl;
			cout << " Details of Sender: " << endl;
			sender.details();
			cout << " __________________________________________" << endl;
			break;
		case 4:
		{
			G.dijkstras(city, city1, distance);

			if (distance)
				cout << " The path exists between the cities." << endl;
			else
				cout << " The path does not exist between the cities." << endl;
			break;
		}
		case 5:
		{
			G.dijkstras(city, city1, distance);
			cout << " Shortest distance between " << city << " to " << city1 << " is: " << distance << endl;
			break;
		}
		default:
			break;
		}
		system("pause");
		system("CLS");
	} while (input != 0);

	
	return 0;
 }
