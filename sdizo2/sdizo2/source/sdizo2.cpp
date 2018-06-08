// sdizo2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "controllers\appController\AppController.h"

#include "structures\queue\Queue.h"
#include "structures\stack\Stack.h"
#include <exception>
int main()
{
	AppController app;

	try {
		app.Run();
	}
	catch (exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Critical error, application shutdown.\n";
		system("pause");
	}
	
    return 0;
}

