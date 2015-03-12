
#include "Server.hpp"

using namespace std;


/**
 * Default constructor
 */
Server::Server(int _id, int _size, int _cpu, int _group): id(_id), size(_size), cpu(_cpu), group(_group) {
	cout << "Constructing server..." << endl;
}



/**
 * Computes a server's CPU/size ratio.
 */
float Server::getRatio() {
	return ((float) cpu)/size;
}
