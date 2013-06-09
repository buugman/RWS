/********************************************************************************
 * MarkClient.cpp                                                                     *
 * Copyright (C) 2011-11-03 Andreev Slava                                       *
 *                                                                              *
 * Contact information:                                                         *
 *   Email  - buugman@gmail.com                                                 *      
 *   ICQ    - 460912209                                                         *
 *   Skype  - timebanditx                                                       * 
 *   WWW    - http://buugman.blogspot.com/                                   *
 *                                                                              *
 * This program is free software: you can redistribute it and/or modify         *
 * it under the terms of the GNU General Public License as published by         *
 * the Free Software Foundation, either version 3 of the License, or            *
 * (at your option) any later version.                                          *
 *                                                                              *
 * This program is distributed in the hope that it will be useful,              *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of               *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                *
 * GNU General Public License for more details.                                 *
 * li
 * You should have received a copy of the GNU General Public License            *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.        *
 *                                                                              *
 ********************************************************************************/
 
 #include <MarkClient.h>
 
 MarkClient_t::MarkClient_t()
 {
		 MNetProto = new Protocol();
		 MMSGContent = new MarkMSGTypes_t();
 }
 
 MarkClient_t::~MarkClient_t()
 {
	 delete MMSGContent;
	 delete MNetProto;
 }

 void MarkClient_t::MarkStartClient()
{

	
	MMSGContent->MClientInformation->MInitClientInfo();
	
	MMSGContent->MSet_Masocket(MNetProto->ConnectTCP("localhost","7777"));
	MMSGContent->MarkSend(MMSGContent->MClientInformation,'i',MMSGContent->MGet_Masocket());
	cout<<MMSGContent->CLDONE;
}

  
