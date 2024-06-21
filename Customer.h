#pragma once
#include <iostream>
#include <string>
using namespace std;

class address
{
private:
	string houseNo;
	string area;
	string city;
public:
	address();
	address(string, string, string);
	void setHouseNo(string);
	void setCity(string);
	void setArea(string);
	string getArea();
	string getHouseNo();
	string getCity();
	void print();
};
address::address()
{
	houseNo = " ";
	area = " ";
	city = " ";

}
address::address(string a, string b, string c)
{
	houseNo = a;
	area = b;
	city = c;
}
void address::setArea(string a)
{
	area = a;
}
void address::setCity(string c)
{
	city = c;
}
void address::setHouseNo(string h)
{
	houseNo = h;
}
string address::getArea()
{
	return area;
}
string address::getCity()
{
	return city;
}
string address::getHouseNo()
{
	return houseNo;
}
void address::print()
{
	cout << " Address: " << houseNo << ", " << area << ", " << city << endl;
}
class CustomerDetails
{
private:
	string name;
	address Address;
public:
	CustomerDetails();
	CustomerDetails(string, string, string, string);
	void setCustomerDetails(string, string, string, string);
	string getName();
	string getArea();
	string getHouse();
	string getCity();
	void details();
};
CustomerDetails::CustomerDetails()
{
	name = " ";
}
CustomerDetails::CustomerDetails(string n, string area, string city, string house)
{
	name = n;
	Address.setArea(area);
	Address.setHouseNo(house);
	Address.setCity(city);
}
void CustomerDetails::setCustomerDetails(string n, string area, string city, string house)
{
	name = n;
	Address.setArea(area);
	Address.setHouseNo(house);
	Address.setCity(city);
}
string CustomerDetails::getName()
{
	return name;
}
string CustomerDetails::getArea()
{
	return Address.getArea();
}
string CustomerDetails::getCity()
{
	return Address.getCity();
}
string CustomerDetails::getHouse()
{
	return Address.getHouseNo();
}
void CustomerDetails::details()
{
	cout << "\n Name: " << name << endl;
	Address.print();
}
/////////////////////////////////////////////////////////////
