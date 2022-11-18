/*
	NAME: AMIR VASSELL
	SENECA EMAIL: ARVASSELL@MYSENECA.CA
	STUDENT ID: 154737209
	DATE: November 13. 2022
	NOTE: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
#include <iostream>
namespace sdds {
	class Station {

		int m_id{};
		std::string m_itemName{};
		std::string m_stationDescription{};
		size_t m_nextSerialNumber{};
		size_t m_numOfInStockItems{};

		static size_t m_widthField;
		static size_t id_generator;

	public:
		Station(const std::string& record);

		const std::string& getItemName() const;

		size_t getNextSerialNumber();

		size_t getQuantity() const;

		void updateQuantity();

		void display(std::ostream& os, bool full) const;
	};
}

#endif // ! SDDS_STATION_H
