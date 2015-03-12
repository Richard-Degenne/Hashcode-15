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
	cout<<"Construction du Datacenter"<<endl;
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
	
	cout<<nbRows<<" "<<nbSlots<<" "<<nbBroken<<" "<<nbGroups<<" "<<nbServs<<endl;	

	cout<<"Rows"<<endl;
	rows.resize(nbRows);
	for(int i=0; i<nbRows; ++i)
	{
		rows[i] = new Row();
		rows[i]->slots.resize(nbSlots);
		for(int j=0; j<nbSlots; ++j)
			rows[i]->slots[j] = new Slot(FREE, NULL);
	}

	cout<<"Broken"<<endl;
	for(int i =0; i<nbBroken; ++i)
	{
		int x, y;
		getline(f, line, ' ');
		x = stoi(line);
		getline(f, line);
		y = stoi(line);
		rows[x]->slots[y]->state = BROKEN;	
	}
	cout<<"Servers"<<endl;
	
	servers.resize(nbServs);
	for(int i=0; i<nbServs; ++i)
	{
		getline(f, line, ' ');
		int size = stoi(line);
		getline(f, line);
		int cpu = stoi(line);
		servers[i] = new Server(i, size, cpu, -1);
	}
	cout<<"Construction du Datacenter finie"<<endl;
}

void Datacenter::solve1()
{
	auto l =  [] (Server* s1, Server* s2){
	float const r1 = static_cast<float>(s1->cpu)/s1->size;
	float const r2 = static_cast<float>(s2->cpu)/s2->size;
	return r1<r2;
	};
	sort(servers.begin(), servers.end(), l);
}

void Datacenter::print()
{
	for(int i =0; i<rows.size(); ++i)
	{
		for(int j=0; j<rows[i]->slots.size(); ++j)
		{
			int const state = rows[i]->slots[j]->state;
			char c = (state) ? ((state == 1) ? '##': '##' ) : '.';
			cout<<c; 
		}
		cout<<endl;
	}
}


