// sdizo2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "controllers\appController\AppController.h"

#include "structures\utilities\matrixGraph\MatrixGraph.h"
#include "structures\utilities\listGraph\listGraph.h"
#include "structures\array\Array.h"


int main()
{
	//AppController app;

	listGraph m;


	Point p1(0);
	Point p2(1);
	Point p3(2);
	m.addPoint(p1);
	m.addPoint(p2);
	m.addPoint(p3);


	Edge e1(1, p1, p2);
	//Edge e2(1, p2, p3);
	//Edge e3(1, p1, p3);

	m.addEdge(e1);
	//m.addEdge(e2);
	//m.addEdge(e3);


	m.print();

	system("pause");
	/*
	try {
		app.Run();
	}
	catch (...)
	{
		std::cout << "Critical error, application shutdown.\n";
		system("pause");
	}
	*/
    return 0;
}

