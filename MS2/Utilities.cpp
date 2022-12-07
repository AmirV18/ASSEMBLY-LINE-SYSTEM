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

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
    {
        string result = "";
        size_t first_pos = next_pos;

        next_pos = str.find(m_delimiter, first_pos);

        if (first_pos == next_pos)
        {
            more = false;
            throw "   ERROR: No token.\n";
        }
        else if (next_pos == string::npos)
        {
            result = str.substr(first_pos);
            more = false;
        }
        else
        {
            result = str.substr(first_pos, next_pos - first_pos);
            more = true;
        }

        m_widthField = max(result.length(), m_widthField);
        next_pos++;

        return result;
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



