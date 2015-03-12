
#ifndef _SERVER_H
#define _SERVER_H

#include <iostream>

class Server {
public:
	int id;
	int size;
	int cpu;
	int group;

	Server(int _id, int _size, int _cpu, int _group);

	float getRatio();
};

#endif

