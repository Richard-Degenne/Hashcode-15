
#include "Server.hpp"

using namespace std;


/**
 * Default constructor
 */
Server::Server(int _size, int _cpu, int _group): size(_size), cpu(_cpu), group(_group) {
	cout << "Constructing server..." << endl;
}
