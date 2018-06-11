#include "stdafx.h"
#include "genericTestController.h"

using namespace std;


void genericTestController::saveToFile(int testSize, double time)
{
	file.open(filename, std::ios::out | std::ios::app);
	if (file.good())
	{
		try {
			file << testSize << ";" << time << endl;
		}
		catch (...)
		{
			cout << "Gotcha!" << endl;
			system("pause");
		}
	}
	else
	{
		cout << "Test file error occured!" << endl;
		system("pause");
	}
	file.close();
}

void genericTestController::saveToFile(std::string message)
{
	file.open(filename, std::ios::out | std::ios::app);
	if (file.good())
		file << message << endl;
	else
	{
		cout << "Test file error occured!" << endl;
		system("pause");
	}
	file.close();
}

void genericTestController::saveToFile(std::string algorithm, std::string representation, float density, int vertexCount, double totalTime)
{
	std::string message = "";
	message.append(algorithm + ";");
	message.append(representation + ";");
	message.append(std::to_string(density) + ";");
	message.append(std::to_string(vertexCount) + ";");
	message.append(std::to_string(totalTime));
	this->saveToFile(message);
}
