// sdizo2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "controllers\appController\AppController.h"

#include "structures\utilities\listGraph\listGraph.h"

int main()
{
	AppController app;

	try {
		app.Run();
	}
	catch (...)
	{
		std::cout << "Critical error, application shutdown.\n";
		system("pause");
	}
	
    return 0;
}

