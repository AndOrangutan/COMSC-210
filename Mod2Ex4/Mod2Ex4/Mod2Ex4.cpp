#include <fstream>
using namespace std;

int main()
{

	 ofstream fin;
	 fin.open("excel.xls");
	 if (fin.good())
	 {
		  fin << "Part Name\tPart#\tPrice\n";
		  fin << "Spring" << '\t' << "123456" << '\t' << "$12.40" << '\n'
				<< "Lever" << '\t' << "420690" << '\t' << "$11.15" << '\n';
				fin.close(); 

	 }
}