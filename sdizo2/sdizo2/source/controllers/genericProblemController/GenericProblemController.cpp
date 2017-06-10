#include "stdafx.h"
#include "GenericProblemController.h"

using namespace std;

void GenericProblemController::loadFromFile()
{
	string userInput = "";
	string line = "";

	cout << "Podaj nazwê pliku: ";
	cin >> userInput;
	m_list.clear();
	m_matrix.clear();

	ifstream fileStream(userInput);

	if (!fileStream.is_open())
	{
		cout << "Nie mo¿na otworzyæ pliku. " << endl;
		system("pause");
		return;
	}

	getline(fileStream, line);
	handleAdditionalParameters(line);

	while (getline(fileStream, line))
	{
		if (!line.empty())
			parseEdgeString(line);
	}
}

void GenericProblemController::parseEdgeString(const string &line)
{
	istringstream iss(line);
	int startPoint, endpoint, edgeValue;
	iss >> startPoint;
	iss >> endpoint;
	iss >> edgeValue;
	Point start(startPoint);
	Point end(endpoint);
	Edge edge(edgeValue, start, end);

	m_matrix.addPoint(start);
	m_matrix.addPoint(end);

	m_list.addPoint(start);
	m_list.addPoint(end);

	m_matrix.addEdge(edge);
	m_list.addEdge(edge);

}

void GenericProblemController::print()
{
	std::cout << "Reprezentacja macierzowa: " << std::endl;
	m_matrix.print();
	std::cout << "\nReprezentacja listowa\n";
	m_list.print();
}
