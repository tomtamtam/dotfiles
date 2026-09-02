#include <print>

#include "escapes.hpp"

#include "sync/Manager.h"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::println("[{}] no valid args, please provide the path to the json config", Escapes::ColoredText("ERROR", Escapes::RED));
		return -1;
	}
	Sync::Manager manager {argv[1]};
	return 0;
}
