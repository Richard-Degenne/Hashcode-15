#include "Datacenter.hpp"
#include <sstream>
#include <fstream>
#include <algorithm>

#include "Server.hpp"
#include "Row.hpp"
#include "Slot.hpp"

using namespace std;

Datacenter::Datacenter(string const& path)
{
	//cerr<<"Construction du Datacenter"<<endl;
	ifstream f(path);
	string line;
	getline(f, line, ' ');
	int nbRows = stoi(line);
	getline(f, line, ' ');
	int nbSlots = stoi(line);
	getline(f, line, ' ');
	int nbBroken = stoi(line); 
	getline(f, line, ' ');
	int nbGroups = stoi(line);
	getline(f, line);
	int nbServs = stoi(line);
	
	//cerr<<nbRows<<" "<<nbSlots<<" "<<nbBroken<<" "<<nbGroups<<" "<<nbServs<<endl;	

	//cerr<<"Rows"<<endl;
	rows.resize(nbRows);
	for(int i=0; i<nbRows; ++i)
	{
		rows[i] = new Row();
		rows[i]->slots.resize(nbSlots);
		for(int j=0; j<nbSlots; ++j)
			rows[i]->slots[j] = new Slot(FREE, NULL);
	}

	//cerr<<"Broken"<<endl;
	for(int i =0; i<nbBroken; ++i)
	{
		int x, y;
		getline(f, line, ' ');
		x = stoi(line);
		getline(f, line);
		y = stoi(line);
		rows[x]->slots[y]->state = BROKEN;	
	}
	//cerr<<"Servers"<<endl;
	
	servers.resize(nbServs);
	for(int i=0; i<nbServs; ++i)
	{
		getline(f, line, ' ');
		int size = stoi(line);
		getline(f, line);
		int cpu = stoi(line);
		servers[i] = new Server(i, size, cpu, -1);
	}
	//cerr<<"Construction du Datacenter finie"<<endl;
}

/**
 * Sorts every servers by their ratio, best ratio first.
 */
void Datacenter::solve1()
{
	int currentRow = 0;
	int unplaced = 0;
	int nbPlaced = 0;

	auto l =  [] (Server* s1, Server* s2){
	float const r1 = static_cast<float>(s1->cpu)/s1->size;
	float const r2 = static_cast<float>(s2->cpu)/s2->size;
	return r1>r2;
	};
	sort(servers.begin(), servers.end(), l);
	// Servers sorted
	
	for(auto server : servers) { // ! server => Server*
		int firstRow = currentRow;
		bool placed = false;
		
		do {
			//cerr << "Row " << currentRow << ": First slot " << rows[currentRow]->getFirstFreeSlot() << endl;
			if(!rows[currentRow]->canPlace(server, rows[currentRow]->getFirstFreeSlot())) {
				//cerr << "Not enough space..." << endl;
			}
			else {
				rows[currentRow]->place(server, rows[currentRow]->getFirstFreeSlot());
				server->row = currentRow;
				placed = true;
				nbPlaced++;
			}
			if(++currentRow == rows.size()) {
				currentRow = 0;
			}
			
		} while (!placed && currentRow != firstRow);
		if(!placed) {
			//cerr << "SERVER NOT PLACED!" << endl;
			unplaced++;
		}
	}
	//cerr << "Totals: Placed " << nbPlaced << " / Unplaced " << unplaced << endl;
	int currentGroup = 0;
	for(auto row : rows) {
		for(auto slot : row->slots) {
			if(slot->state == OCCUPIED && slot->server->group == -1) {
				//cerr << "Group: " << currentGroup << endl;
				slot->server->group = currentGroup;
				currentGroup = (currentGroup+1) % nbGroups;
			}
		}
	}
}

void Datacenter::print()
{
	for(int i =0; i<rows.size(); ++i)
	{
		for(int j=0; j<rows[i]->slots.size(); ++j)
		{
			int const state = rows[i]->slots[j]->state;
			char c;
			switch(state) {
				case FREE:
					c='.';
					break;
				case OCCUPIED:
					c= (rows[i]->slots[j]->server->group%10) + 48;
					break;
				case BROKEN:
					c='#';
					break;
			}
			cerr<<c; 
		}
		cerr<<endl;
	}
}

void Datacenter::out() {
	//retri
	auto l =  [] (Server* s1, Server* s2){
		return s1->id<s2->id;	
	};
	sort(servers.begin(), servers.end(), l);

	//Affichage
	for (auto s : servers)
	{
		if(s->slot!=-1)
			cout<<s->row<<" "<<s->slot<<" "<<s->group<<endl;
		else
			cout<<'x'<<endl;
	}
}
