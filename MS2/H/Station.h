//==============================================
// Name:           Jungjoo Kim
// Student Number: 162 641 195
// Email:          jkim594@myseneca.ca
// Section:        NAA
// Date:           July 12, 2021
// Workshop:       Project 2
// Ownership:
// I have completed all the coding by myself and
// copied only the code provided by the professor to submit my assignment.
//==============================================
// Station.h

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds
{
  class Station
  {
    int m_id            { 0 }; // the id of the station
    std::string m_name  { "" }; // the name of the item handled by the station
    std::string m_desc  { "" }; // the description of the station
    size_t m_serial_num { 0u }; // the next serial number to be assigned to an item at this station
    size_t m_curr_items { 0u }; // the number of items currently in stock

    // Class Variables
    static size_t m_widthField;
    static size_t id_generator;

  public:
    Station(const std::string& src);

    // returns the name of the current Station object
    const std::string &getItemName() const;

    // returns the next serial number
    size_t getNextSerialNumber();

    // returns the remaining quantity of items
    size_t getQuantity() const;

    // subtracts 1 from the available quantity
    void updateQuantity();

    // display information about the current object
    void display(std::ostream &os, bool full) const;
  };
}
#endif // !SDDS_STATION_H

string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
{
	string _tem{};
	string _tempSpace = " ";
	int index2{};
	int index3{};
	int index4{};
	int index = str.find(m_delimiter, next_pos);

	_tem = str.substr(next_pos, index - next_pos);

	index2 = _tem.find_first_of(_tempSpace);
	if (index == static_cast<int>(next_pos))
	{
		more = false;
		throw " Error: no token. \n";
	}
	while ((index2) != -1)
	{
		index2 = _tem.find_first_of(_tempSpace, index4);
		index3 = _tem.find_last_of(_tempSpace);
		if (index2 == 0)//first position
			_tem.erase(index2, 1);
		else if (index3 == (static_cast<int>(_tem.length())) - 1)//last position
			_tem.erase(index3);
		else if ((index2 < static_cast<int>(_tem.length()) - 1) && (index2 > 0))
		{
			index4 = index2;
			index2 = _tem.find_first_of(_tempSpace, index4 + 1);
			if (index2 - 1 == index4)
				_tem.erase(index4, index2);
			else
				index4++;
		}
	}
	if (index == -1)
		more = false;
	if (_tem.length() > m_widthField)
		m_widthField = _tem.length();
	next_pos = index + 1;
	return _tem;
}