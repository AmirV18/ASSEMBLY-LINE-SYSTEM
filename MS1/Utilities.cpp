/*
	NAME: AMIR VASSELL
	SENECA EMAIL: ARVASSELL@MYSENECA.CA
	STUDENT ID: 154737209
	DATE: November 13. 2022
	NOTE: I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <string>
#include "Utilities.h"

using namespace std;
namespace sdds {

	char Utilities::m_delimiter = ' ';

	string Utilities::extractToken(const string& str, size_t& next_pos, bool& more)
	{
		string token{};
		string space = " ";
		size_t indexChecker{}, indexChecker2{};
		size_t index = str.find(m_delimiter, next_pos);
		token = str.substr(next_pos, index - next_pos);
		indexChecker = (token.find(space));
		if (index == next_pos)
		{
			more = false;
			throw " Error: o token. \n";
		}

		if ((int)indexChecker != -1) {
			do {
				indexChecker = token.find(space, indexChecker);
				if (indexChecker == 0)// first position of the string
					token.erase(indexChecker, indexChecker + 1);
				else if ((indexChecker == token.length() - 1))// end of string
					token.erase(indexChecker);
				else if (indexChecker2 == indexChecker - 1 && (indexChecker2 != 0)) {
					token.erase(indexChecker);
					indexChecker--;
				}
				else if (indexChecker < token.length() && ((int)indexChecker != -1)) {
					indexChecker2 = indexChecker;
					indexChecker++;
				}
			} while ((int)indexChecker != -1);
		}

		if ((int)index == -1) {
			more = false;
		}
		

		if (token.length() > m_widthField) {
			m_widthField = token.length();
		}
			

		next_pos = index+1;

		return token;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	};
	
	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	};

	void Utilities::setDelimiter(char newDelimiter){
		m_delimiter = newDelimiter;
	}

	char Utilities::getDelimiter(){
		return m_delimiter;
	}
}



