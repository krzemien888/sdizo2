// sdizo2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "controllers\appController\AppController.h"

#include "structures\utilities\matrixGraph\MatrixGraph.h"

int main()
{
	AppController app;

	MatrixGraph m;

	m.addPoint(Point());
	m.addPoint(Point());
	m.addPoint(Point());

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

