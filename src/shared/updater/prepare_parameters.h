//
// This file is part of the WoW++ project.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// World of Warcraft, and all World of Warcraft or Warcraft art, images,
// and lore are copyrighted by Blizzard Entertainment, Inc.
//

#pragma once

namespace wowpp
{
	namespace updating
	{
		struct IPrepareProgressHandler;
		struct IUpdateSource;


		struct PrepareParameters
		{
			std::unique_ptr<IUpdateSource> source;
			std::set<std::string> conditionsSet;
			bool doUnpackArchives;
			IPrepareProgressHandler &progressHandler;


			PrepareParameters(
			    std::unique_ptr<IUpdateSource> source,
			    std::set<std::string> conditionsSet,
			    bool doUnpackArchives,
			    IPrepareProgressHandler &progressHandler);
			~PrepareParameters();
		};
	}
}
