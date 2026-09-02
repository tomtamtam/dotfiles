#pragma once

#include <string>

namespace Sync
{
	struct Sync
	{
		std::string origin {};
		std::string destination {};

		[[nodiscard]]
		bool Create();
	};
}
