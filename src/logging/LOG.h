#include <string>
#include <sstream>
#include <iostream>
#include <ctime>

class logging
{
	private:
		static std::string NowTime()
		{
			std::stringstream ss;
			time_t t = time(0);   // get time now
		    struct tm * now = localtime( & t );
		    ss << (now->tm_year + 1900) << '-'
		         << (now->tm_mon + 1) << '-'
		         <<  now->tm_mday << '-'
				 << now->tm_hour << ':'
				 << now->tm_min << ':'
				 << now->tm_sec;
			return ss.str();
		}
	public:
		enum logLevel {ERROR, WARNING, INFO};
		static const char * ToString(int level)
		{
			 switch (level)
			 {
				 case ERROR: return "ERROR";
				 case WARNING: return "WARNING";
				 case INFO: return "INFO";
			 }
			 return "";
		}
		static void LOG(logLevel level);
};
