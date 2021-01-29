#pragma once
#include <iostream>
#include <list>
#include <string>

#include "Table.hpp"
#include "BinaryQueryTree.hpp"

class DataBase
{
#include "typedefs.ipp"

	std::list<Table*> database;

public:
	DataBase();
	DataBase(const DataBase& other) = delete;
	DataBase& operator=(const DataBase& other) = delete;

	void				create(const std::string& name, const table_row& names, const table_row& types);
	void				drop(const std::string& name);
	void				info(const std::string& name);
	void				list() const;

	void				insert(const std::string& name, const table_row& record);
	void				remove(const std::string& name, const std::string& query);
	void				select(const std::string& name, const std::string& query) const;
	size_t				size_of(const std::string& table);

private:
	list_tableptr_it	find(const std::string& name);
	Table*				find_ptr(const std::string& name) const;
};

