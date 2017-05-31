#pragma once
#include "controllers\genericProblemController\GenericProblemController.h"
#include "stdafx.h"
#include "structures\array\Array.h"

class AppController :
	public GenericController
{
	public:
		AppController();
		virtual ~AppController() = default;
		virtual void parseInput(const std::string &input);

		virtual void init();	
	private:

		std::unique_ptr<GenericProblemController> controller;
		std::unique_ptr<Array<int>> arr;
};
