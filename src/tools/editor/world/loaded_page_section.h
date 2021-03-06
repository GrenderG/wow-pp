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

#include "page.h"
#include "page_loader_listener.h"
#include "page_neighborhood.h"

namespace wowpp
{
	namespace paging
	{
		class LoadedPageSection : public IPageLoaderListener
		{
		public:

			explicit LoadedPageSection(
				PagePosition center,
				std::size_t range,
				IPageLoaderListener &sectionListener);
			
			void updateCenter(const PagePosition &center);

		private:

			typedef std::unordered_map<Page *, PageNeighborhood> PageMap;

			virtual void onPageLoad(const Page &page) override;
			virtual void onPageAvailabilityChanged(const PageNeighborhood &pages, bool isAvailable) override;
			static void setVisibility(PageMap &map, const PageNeighborhood &pages, bool isVisible);

		private:

			PagePosition m_center;
			const std::size_t m_range;
			IPageLoaderListener &m_sectionListener;
			PageMap m_insideOfSection;
			PageMap m_outOfSection;
		};
	}
}
