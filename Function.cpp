#include "Function.h"
#include <string>
#include <fstream>

using namespace std;

void SaveData(string name, double rate, double discount) {
	ofstream file("Data.txt");
	file << name << " " << rate << " " << discount << endl;
	file.close();
}

string lineName(string line) {
	int c = 0;
	string rt = "";
	while (line[c] != ' ') {
		rt += line[c];
		c++;
	}
	return (rt);
}

double lineRate(string line) {
	int c = -1, cond = 0;
	string r = "";
	while (cond != 2) {
		c++;
		if (line[c] == ' ')
			cond++;
		if (cond == 1)
			r += line[c];
	}
	double ret = stod(r);
	return (ret);
}

double lineDiscount(string line) {
	int c = -1, cond = 0;
	string r = "";
	while (c+1 < line.length()) {
		c++;
		if (cond == 2)
			r += line[c];
		if (line[c] == ' ')
			cond++;
	}
	double ret = stod(r)/100;
	return (ret);
}