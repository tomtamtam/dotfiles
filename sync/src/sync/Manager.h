#pragma once

#include <string>
#include <vector>

#include "Syncs.h"

namespace Sync
{
	class Manager
	{
	public:
		Manager(std::string jsonPath);

	private:
		std::vector<Sync> m_Syncs;
		std::vector<Sync> m_SyncDirs;
	};

}
