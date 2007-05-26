/***************************************************************************
 *   Copyright (C) 2005-2007 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

#ifndef FIFE_EVENTCHANNEL_MOUSEEVENT_H
#define FIFE_EVENTCHANNEL_MOUSEEVENT_H

// Standard C++ library includes
//

// 3rd party library includes
//

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
//
#include "../base/ec_inputevent.h"
#include "ec_imouseevent.h"

namespace FIFE {

	/**  Class for mouse events
	 */
	class MouseEvent: public InputEvent, public IMouseEvent {
	public:
        /** Constructor.
         */
		MouseEvent(): 
			InputEvent(), 
			m_eventtype(UNKNOWN_EVENT),
			m_buttontype(UNKNOWN_BUTTON),
			m_x(-1),
			m_y(-1) {}

        /** Destructor.
         */
		virtual ~MouseEvent() {}

		MouseButtonType getButton() const { return m_buttontype; }
		void setButton(MouseButtonType type) { m_buttontype = type; }
	
		MouseEventType getType() const { return m_eventtype; }
		void setType(MouseEventType type) { m_eventtype = type; }
	
		int getX() const { return m_x; }
		void setX(int x) { m_x = x; }
	
		int getY() const { return m_y; }
		void setY(int y) { m_y = y; }

		virtual bool isAltPressed() const { return InputEvent::isAltPressed(); }
		virtual void setAltPressed(bool pressed) { InputEvent::setAltPressed(pressed); }
		virtual bool isControlPressed() const { return InputEvent::isControlPressed(); }
		virtual void setControlPressed(bool pressed) { InputEvent::setControlPressed(pressed); }
		virtual bool isMetaPressed() const { return InputEvent::isMetaPressed(); }
		virtual void setMetaPressed(bool pressed) { InputEvent::setMetaPressed(pressed); }
		virtual bool isShiftPressed() const { return InputEvent::isShiftPressed(); }
		virtual void setShiftPressed(bool pressed) { InputEvent::setShiftPressed(pressed); }

		virtual void consume() { InputEvent::consume(); }
		virtual bool isConsumed() { return InputEvent::isConsumed(); }
		virtual IEventSource* getSource() { return InputEvent::getSource(); }
		virtual void setSource(IEventSource* source) { InputEvent::setSource(source); }
		virtual int getTimeStamp() { return InputEvent::getTimeStamp(); }
		virtual void setTimeStamp(int timestamp ) { InputEvent::setTimeStamp(timestamp); }

		virtual const std::string getName() const {
			return std::string("MouseEvent");
		}
		virtual const std::string getDebugString() const { return InputEvent::getDebugString(); }
		virtual const std::string getAttrStr() const {
			std::stringstream ss;
			ss << InputEvent::getAttrStr() << std::endl;
			ss << "event = " << mouseEventType2str(m_eventtype) << ", ";
			ss << "button = " << mouseButtonType2str(m_buttontype) << ", ";
			ss << "x = " << m_x << ", ";
			ss << "y = " << m_y;
			return  ss.str();
		}


	private:
        MouseEventType m_eventtype;
        MouseButtonType m_buttontype;
		int m_x;
 		int m_y;
	};
} //FIFE

#endif
