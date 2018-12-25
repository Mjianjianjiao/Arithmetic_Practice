#pragma warning(disable:4996)
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <cstring>
using namespace std;

struct Config{
	int port;
	char ch[20];
};

class ConfigManage{
public:
	ConfigManage(const string& cogn = "test1.config")
		:_configname(cogn)
	{}

	void WriteBin( Config& wr){

		ofstream ofile(_configname, ofstream::binary);
		ofile.write((const char*)&wr, sizeof(wr));
		ofile.close();
	}

	void ReadBin(Config& rd){
		ifstream ifile(_configname, istream::binary);
		ifile.read((char*)&rd, sizeof(rd));
		ifile.close();
	}

	void WriteTxt(Config& wr){
		ofstream ofile(_configname);
		ofile << wr.ch << endl;
		ofile << wr.port << endl;

	}

	void ReadTxt(Config& rd){
		ifstream ifile(_configname);
		ifile >> rd.ch;
		ifile >> rd.port;
		ifile.close();
	}
	
private:
	string _configname;
};


int main(){

	Config wr;
	Config rd;

	strcpy(wr.ch, "127.0.0.001");
	wr.port = 101;

	ConfigManage file("test2.dat");
	file.WriteBin(wr);
	file.ReadBin(rd);
	cout << rd.ch << endl;
	cout << rd.port << endl;
	ConfigManage file2("test3.txt");
	file2.WriteTxt(wr);
	file2.ReadTxt(rd);
	cout << rd.ch<< endl;
	cout << rd.port << endl;
	return 0;
}