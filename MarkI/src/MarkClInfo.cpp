/********************************************************************************
 * MarkClInfo.cpp                                                                     *
 * Copyright (C) 2011-09-15 Andreev Slava                                       *
 *                                                                              *
 * Contact information:                                                         *
 *   Email  - buugman@gmail.com                                                 *      
 *   ICQ    - 460912209                                                         *
 *   Skype  - timebanditx                                                       * 
 *   WWW    - http://bungman.cyberblogger.ru/                                   *
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
 *                                                                              *
 * You should have received a copy of the GNU General Public License            *
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.        *
 *                                                                              *
 ********************************************************************************/
 
 #include <MarkClInfo.h>
 #include <fcntl.h>
 #include <sys/sysinfo.h>
 #include <unistd.h>
 #include <sys/types.h>
 #include <openssl/md5.h>
 #include <cstring>
 #include <stdio.h>
 
 MarkClInfo_t::MarkClInfo_t():MGuid("\0"),MCoreNumber(0), MFreeMemory(0), MCPUFrequency(0)

 {
 }
 
 MarkClInfo_t::~MarkClInfo_t()
 {
 }

//***************Getters**********************************

unsigned long int MarkClInfo_t::Get_MTotalMemory() const
{
	return MTotalMemory;
}
unsigned int MarkClInfo_t::Get_MCoreNumber() const

 {
		return MCoreNumber;     
 }
 
 unsigned long int MarkClInfo_t::Get_MFreeMemory() const
 {
    	return MFreeMemory; 
 }
 
unsigned long int MarkClInfo_t::Get_MCPUFrequency() const 
 {
	 return MCPUFrequency;
 }
 
 string MarkClInfo_t::Get_MGuid() const
 {
  return MGuid;
 }

	unsigned int MarkClInfo_t::Get_MUpTime() const 
	{
		return MUpTime;
	}

//*******************************************************

//****************Implementation*************************
unsigned int MarkClInfo_t::MarkGetCoreNumber()
{
	unsigned int CoreNum = 0;

	CoreNum = sysconf(_SC_NPROCESSORS_ONLN);
	
	cout<<"Core Numbers		: "<<CoreNum<<endl;
	return CoreNum;
}

unsigned long int MarkClInfo_t::MarkGetFreeMemory()
{
	unsigned long int FreeMem = 0;
	struct sysinfo info;
	sysinfo(&info);
	FreeMem =  info.mem_unit*info.freeram/(1024*1024);
	cout<<"FreeMemory		: "<<FreeMem<<" Mb"<<endl;
	return FreeMem;
}

unsigned long int MarkClInfo_t::MarkGetTotalMemory()
{
	unsigned long int TotalMem = 0;
	struct sysinfo info;
	sysinfo(&info);
	TotalMem = info.mem_unit*info.totalram/(1024*1024);
	cout<<"Total Memory		: "<<TotalMem<<" Mb"<<endl;
	return TotalMem;
}

unsigned long int MarkClInfo_t::MarkGetCPUFrequency()
{
	unsigned long int Freq;
	char line[100], *result, *end;
	string s;
	
	FILE* fp = fopen("/proc/cpuinfo","r");
	do
	{
		result = fgets(line,100,fp);
	}while(strncmp(result, "cpu MHz",7));
	fclose(fp);
	
	s = (char*)result;
	s.erase(0,11);
	Freq = strtoul(s.c_str(),&end,0);
	cout<<"CPU Frequency		: "<<Freq<<" MHz"<<endl;
	return Freq;
}

string MarkClInfo_t::MarkGetGuid()
{
	int i;
	unsigned int rndfd;
	unsigned char hash[MD5_DIGEST_LENGTH];
	char rndname[100];
	char hashstring[100];
	string uuidValue;


	rndfd = open("/dev/random", O_RDONLY);
	read(rndfd,rndname,100);
	close(rndfd);

	MD5((const unsigned char *)rndname,100, hash);

	for (i = 0; i < MD5_DIGEST_LENGTH; i++) 
	{
		sprintf(hashstring,"%02x",hash[i]);
		uuidValue.append((char*)hashstring);
	}
	cout<<"Generated ID		: "<<uuidValue<<endl;
	return uuidValue;
}

unsigned int MarkClInfo_t::MarkGetUpTime()
{
	unsigned int upTime;

	struct sysinfo info;
	sysinfo(&info);

	upTime = info.uptime/60;
	cout<<"Uptime			: "<<upTime<<" Min"<<endl;
	return upTime;
}

//**********************************************************

void MarkClInfo_t::MInitClientInfo()
{
	MCoreNumber = MarkClInfo_t::MarkGetCoreNumber();
	MFreeMemory = MarkClInfo_t::MarkGetFreeMemory();
	MCPUFrequency = MarkClInfo_t::MarkGetCPUFrequency();
	MTotalMemory = MarkClInfo_t::MarkGetTotalMemory();
	MUpTime = MarkClInfo_t::MarkGetUpTime();
	MGuid = MarkClInfo_t::MarkGetGuid();
}
//*********************************************************

























