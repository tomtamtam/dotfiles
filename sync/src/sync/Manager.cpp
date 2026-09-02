#include <print>

#include <filesystem>
#include <fstream>

#include "Manager.h"

#include "Syncs.h"
#include "escapes.hpp"

#include "nlohman/json/json.hpp"

using json = nlohmann::json;

namespace Sync
{
	Manager::Manager(std::string jsonPath)
	{
		if(!std::filesystem::exists(jsonPath))
		{
			std::println("{} Path to json config: '{}' is no valid path", Escapes::ColoredText("ERROR: ", Escapes::RED), jsonPath);
		}

		json j;
		std::ifstream f(jsonPath);
		f >> j;

		for(auto d : j["directories"])
		{
			Sync dir;
			dir.origin = d["origin"];
			dir.destination = d["dest"];
			if(!dir.Create()) continue;
			m_SyncDirs.push_back(dir);
		}

		for(auto f : j["files"])
		{
			Sync s;
			s.origin = f["origin"];
			s.destination = f["dest"];
			if(!s.Create()) continue;
			m_Syncs.push_back(s);
		}
	}
}
