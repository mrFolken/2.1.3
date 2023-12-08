#include "main.h"

using namespace std;

void main()
{
	setupRusLang();
	vector<Planet> sunSystem;
	createSunSystemFromFile(sunSystem);
	printPlanetSystem(sunSystem);
}

string enterFileName()
{
	string fileName = "Планеты1";//Имя файла

	cout << "Введите имя файла для загрузки - ";
	cin >> fileName;

	fileName += ".txt";//добавляем формат файла
	return fileName;
}

void setupRusLang()
{
	setlocale(LC_ALL, "RUS");//русификация
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);//русификация для ввода-вывода имени файла
}

void createSunSystemFromFile(vector<Planet> &sunSystem)
{
start:
	system("cls");
	ifstream fin(enterFileName());//создаём объект класса ifstream для записи и связываем его с файлом
	Planet bufPlanet;
	string bufStr;

	bufPlanet.ErrorSearcher.fileOpenChecker(fin.is_open());	
	if (bufPlanet.ErrorSearcher.haveError)
		goto start;
	while (!fin.eof() && !bufPlanet.ErrorSearcher.haveError)
	{
		fin >> bufStr;
		bufPlanet.setNamePlanet(bufStr);
		if (bufPlanet.ErrorSearcher.haveError)
			goto start;
		
		fin >> bufStr;
		bufPlanet.setOpenDate(stringToTm(bufStr));
		if (bufPlanet.ErrorSearcher.haveError)
			goto start;
		
		fin >> bufStr;
		bufPlanet.setRadius(stod(bufStr));
		if (bufPlanet.ErrorSearcher.haveError)
			goto start;
		
		sunSystem.push_back(bufPlanet);
	}
	fin.close();//закрываем файл
	
}

tm stringToTm(string buf)
{
	tm bufOpenDate;
	if (buf.size() == 10)
	{
		bufOpenDate.tm_year = stoi(buf.substr(0, 4));
		bufOpenDate.tm_mon = stoi(buf.substr(5, 7));
		bufOpenDate.tm_mday = stoi(buf.substr(8, 9));
	}
	else
	{
		bufOpenDate.tm_year = 0;
		bufOpenDate.tm_mon = 0;
		bufOpenDate.tm_mday = 0;
	}
	return bufOpenDate;
}

void printPlanetSystem(vector<Planet> &sunSystem)
{
	cout << "Название планеты | Дата открытия | Радиус" << endl;
	for (int i = 0; i < sunSystem.size(); i++)
	{
		cout << setw(18) << left << sunSystem[i].getNamePlanet() << " "
			<< setw(4) << right << sunSystem[i].getOpenDate().tm_year << "." << setw(2) << sunSystem[i].getOpenDate().tm_mon << "." << setw(2) << sunSystem[i].getOpenDate().tm_mday << setw(6) << " "
			<< setw(10) << left << sunSystem[i].getRadius() << endl;
	}
}