#include <iostream>
#include <string>
#include "include/priority_queue_app.h"

using namespace std;

int main(int argc, const char** argv) {
	PriorityQueueApp app;
	std::string output = app(argc, argv);
	std::cout << output.c_str() << std::endl;
	return 0;
}