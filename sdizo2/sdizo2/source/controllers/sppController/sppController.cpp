#include "stdafx.h"
#include "sppController.h"
#include "alghoritms\DjikstraAlghoritm.h"
#include "views\spp\sppMenu.h"

using namespace std;

sppController::sppController()
{
	init();
}

void sppController::init()
{
	view = make_unique<sppMenu>();
}

void sppController::parseInput(const std::string & input)
{
	int parsedInput = -1;
	parsedInput = atoi(input.c_str());

	IAlghoritm* alghoritm = nullptr;

	system("cls");
	switch (parsedInput)
	{
	case 0:
		this->Stop();
		break;
	case 1:
		loadFromFile();
		break;
	case 2:
		alghoritm = new DjikstraAlghoritm;
		alghoritm->setParameters(startPoint, 0);
		alghoritm->apply(&m_matrix);
		break;
	case 3:
		
		break;
	case 4:
		m_list.print();
		//m_matrix.print();
		cout << endl;
		system("pause");
		break;
	default:
		throw std::invalid_argument("Unknown controller input");
		break;
	}
	system("cls");
}

void sppController::parseEdgeString(const std::string & edgeString)
{
	int startPoint, endPoint, value;
	istringstream iss(edgeString);
	// 1st and 2nd is amount of points and edges
	iss >> startPoint;
	iss >> endPoint;
	iss >> value;

	Edge e(value, Point(startPoint), Point(endPoint));
	e.setDirected(true);
	m_matrix.addEdge(e);
	m_list.addEdge(e);
}

void sppController::handleAdditionalParameters(const std::string & parametesString)
{
	istringstream iss(parametesString);
	// 1st and 2nd is amount of points and edges
	iss >> amountOfEdges;
	iss >> amountOfPoints;
	iss >> startPoint;

	m_matrix.resize(amountOfPoints);
	m_list.resize(amountOfPoints);
}
