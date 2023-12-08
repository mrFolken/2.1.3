#include "main.h"

using namespace std;

ErrorLogger ErrorSearcher;

void main()
{
	setupRusLang();
	vector<Planet> sunSystem;
	createSunSystemFromFile(enterFileName(), sunSystem);
	printPlanetSystem(sunSystem);
}

string enterFileName()
{
	string fileName = "�������";//��� �����

	//cout << "������� ��� ����� ��� �������� - ";
	//cin >> fileName;

	fileName += ".txt";//��������� ������ �����
	return fileName;
}

void setupRusLang()
{
	setlocale(LC_ALL, "RUS");//�����������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);//����������� ��� �����-������ ����� �����
}

void createSunSystemFromFile(string fileName, vector<Planet> &sunSystem)
{
	ifstream fin(fileName);//������ ������ ������ ifstream ��� ������ � ��������� ��� � ������
	ErrorSearcher.fileOpenChecker(fin.is_open());
	Planet bufPlanet;
	string bufStr;
	while (!fin.eof())
	{
		fin >> bufStr; 
		ErrorSearcher.checkName(bufStr);
		bufPlanet.setNamePlanet(bufStr);
		
		fin >> bufStr;
		ErrorSearcher.checkDate(bufStr);
		ErrorSearcher.checkDate(stringToTm(bufStr));
		bufPlanet.setOpenDate(stringToTm(bufStr));
		
		fin >> bufStr;
		ErrorSearcher.checkRadius(stod(bufStr));
		bufPlanet.setRadius(stod(bufStr));
		
		sunSystem.push_back(bufPlanet);
	}
	fin.close();//��������� ����
}

tm stringToTm(string buf)
{
	tm bufOpenDate;
	bufOpenDate.tm_year = stoi(buf.substr(0, 4));
	bufOpenDate.tm_mon = stoi(buf.substr(5, 7));
	bufOpenDate.tm_mday = stoi(buf.substr(8, 9));
	return bufOpenDate;
}

void printPlanetSystem(vector<Planet> &sunSystem)
{
	cout << "�������� ������� | ���� �������� | ������" << endl;
	for (int i = 0; i < sunSystem.size(); i++)
	{
		cout << setw(18) << left << sunSystem[i].getNamePlanet() << " "
			<< setw(4) << right << sunSystem[i].getOpenDate().tm_year << "." << setw(2) << sunSystem[i].getOpenDate().tm_mon << "." << setw(2) << sunSystem[i].getOpenDate().tm_mday << setw(6) << " "
			<< setw(10) << left << sunSystem[i].getRadius() << endl;
	}
}