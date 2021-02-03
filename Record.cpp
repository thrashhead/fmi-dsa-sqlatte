#include "Record.hpp"

Record::Record()
	:row(std::vector<std::string>()){}

Record::Record(std::vector<std::string> _row)
	:row(_row) {}

const std::string& Record::operator[](size_t index) const
{
	if ( !(index >= 0 && index < row.size()) ) 
		throw std::exception("Record: Invalid index");

	return row[index];
}

bool Record::operator==(const Record& other) const
{
	if (this->row.size() != other.row.size()) return false;
	for (int i = 0; i < row.size(); ++i)
		if (this->row[i] != other.row[i]) return false;

	return true;	
}

bool Record::operator!=(const Record& other) const
{
	return !(*this == other);
}

size_t Record::data() const
{
	size_t total = 0;
	for (const std::string& elem : row)
		total += elem.size();

	return total;
}

void Record::print(const std::vector<size_t>& cols) const
{
	std::cout << "|";
	for (size_t i : cols)
		std::cout << row[i] << "|";
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Record& record)
{
	os << '|';
	for (const std::string& entry : record.row) 
		os << '\t' << entry << '|';
	os << '\n';

	return os;
}

std::ofstream& operator<<(std::ofstream& out, const Record& record)
{
	write_vector(out, record.row);

	return out;
}

std::ifstream& operator>>(std::ifstream& in, Record& record)
{
	std::vector<std::string> row;
	read_vector(in, row);

	record = Record(row);
	return in;
}
