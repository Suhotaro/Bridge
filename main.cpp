#include "stdafx.h"

#include <memory>
#include <iostream>

#include "app.h"

int main(int argc, char **argv)
{

	argc = 2;
	argv[2] = "data.txt";

	std::unique_ptr<App::Application> Application = std::make_unique<App::Application>();
	if (Application->Init(argc, argv))
		Application->Start();

	std::cout << "Max Root Path Cost: " << Application->Result() << std::endl;

	return 0;
}
