#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <istream>

std::string path = "D:\\Example Code\\C++\\IO";

int outputFile1() {
	std::ofstream myfile(path + "\\example.txt");
	if (myfile.is_open())
	{
		myfile << "10\t2\n";
		myfile << "30\t6\n";
		myfile << "END";
		myfile.close();
	}
	else std::cout << "Unable to open file";
	return 0;
}

int readFile1() {
	std::string line;
	std::ifstream myfile(path + "\\example.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			std::cout << line << std::endl;
		}
		myfile.close();
	}

	else std::cout << "Unable to open file";

	return 0;
}

void readFile2(std::string filePath) {
	std::ifstream f(filePath.c_str(), std::ifstream::in);
	if (f.fail()) {
		std::cout << "Was unable to open file" << std::endl;
		throw (std::string) "IOException in parseFile()";
	}
	std::istringstream instream;       // Declare an input string stream 
	std::string line;
	int lineNum = 0;
	while (getline(f, line)) {
		bool useLine = !(line.substr(0, 1) == "#" || line.substr(0, 1) == "!");
		if (useLine) {
			instream.clear();          // Reset from possible previous errors 
			instream.str(line);        // Use line as source of input 
			double x, y;
			lineNum++;
			instream >> x >> y;
			std::cout << x << "\t" << y << std::endl;
		}
	}
	f.close();
}


int main() {
	outputFile1();
	readFile2(path + "\\example.txt");
}