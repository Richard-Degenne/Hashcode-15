
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
	int nbGroups;
	std::vector<Row*> rows;
	std::vector<Server*> servers;
};

#endif
