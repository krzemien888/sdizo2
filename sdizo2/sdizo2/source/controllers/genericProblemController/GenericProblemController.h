#pragma once
#include "C:\Users\krzem\Source\Repos\sdizo2\sdizo2\sdizo2\source\controllers\genericController\GenericController.h"
class GenericProblemController :
	public GenericController
{
public:
	GenericProblemController() = default;
	virtual ~GenericProblemController() = default;

	virtual void loadFromFile() = 0;
};

