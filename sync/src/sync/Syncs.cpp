#include <escapes.hpp>
#include <print>

#include <filesystem>
#include <iostream>

#include "Syncs.h"


namespace Sync
{
	[[nodiscard]]
	bool Sync::Create()
	{
		if(!std::filesystem::exists(origin))
		{
			std::println("[{}] origin path of Sync: '{}' is no valid path", Escapes::ColoredText("ERROR", Escapes::RED), origin);
			return false;
		}

		if(std::filesystem::is_symlink(destination))
		{
			std::println("[{}] '{}' is already a symlink", Escapes::ColoredText("SKIPPED", Escapes::YELLOW), destination); 
			return false;
		}

		if(std::filesystem::exists(destination))
		{
			std::println("[{}] '{}' already exists, although not as symlink\nDo you want to delete '{}' and create a new symlink, or skip [d/S]", Escapes::ColoredText("QUESTION", Escapes::CYAN), destination, destination); 
			std::string input {};
			bool skip { true };
			std::cin >> input;
			skip = input != "d";

			if(skip)
			{
				std::println("[{}] '{}'", Escapes::ColoredText("SKIPPED", Escapes::YELLOW), destination); 
				return false;
			}

			std::filesystem::remove_all(destination);
			std::println("[{}] '{}'", Escapes::ColoredText("DELETED", Escapes::MAGENTA), destination); 
		}

		std::error_code ec {};
		std::filesystem::create_symlink(origin, destination, ec);
		if(ec)
		{
			std::println("[{}] Whilst Creating Symlink: {}", Escapes::ColoredText("ERROR", Escapes::RED), ec.message());
			return false;
		}
		std::println("[{}] Created symlink, origin: '{}', destination: '{}'", Escapes::ColoredText("SUCCESS", Escapes::GREEN), origin, destination);
		return true;
	}
}
