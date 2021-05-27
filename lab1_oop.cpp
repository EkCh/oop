#include "container_atd.h"
#include <iostream>
#include <fstream>
using namespace std;
using namespace animals;

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container c;
	c.in(ifst);
	ofst << "Filled container. " << endl;
	c.out(ofst);
	cout << "Sorted container. " << endl;
	c.sort();
	c.out(ofst);
	ofst << "Filtered container. " << endl;
	c.output_fish(ofst);
	c.clear();
	ofst << "Empty container. " << endl;
	c.out(ofst);
	cout << "Stop" << endl;
	return 0;
}