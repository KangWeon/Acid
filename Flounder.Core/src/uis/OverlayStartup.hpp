﻿#pragma once

#include "../events/events.hpp"
#include "../events/eventtime.hpp"
#include "../visual/driverslide.hpp"

#include "uis.hpp"

namespace Flounder
{
	class overlaystartup :
		public UiObject
	{
	private:
		gui *m_guiBackground;
		gui *m_guiLogo;
		text *m_textCopyright;
		bool m_starting;
	public:
		overlaystartup(UiObject *parent);

		~overlaystartup();

		void UpdateObject() override;

		bool isStarting() const { return m_starting; }

		void setStarting(const bool &starting) { m_starting = starting; }
	};
}