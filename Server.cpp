
#include "Server.hpp"

using namespace std;


/**
 * Default constructor
 */
Server::Server(int _id, int _size, int _cpu, int _group): id(_id), size(_size), cpu(_cpu), group(_group) {
	row = -1;
	slot = -1; 
}



/**
 * Computes a server's CPU/size ratio.
 */
float Server::getRatio() {
	return ((float) cpu)/size;
}
