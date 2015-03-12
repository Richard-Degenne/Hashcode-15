
#ifndef _DATACENTER_H
#define _DATACENTER_H

#include <iostream>
#include <string>
#include <vector>

class Server;
class Row;

class Datacenter {

public:
	Datacenter(std::string const& path);

	void print();
	void solve1();	

	int nbGroups;
	std::vector<Row*> rows;
	std::vector<Server*> servers;
};

#endif
