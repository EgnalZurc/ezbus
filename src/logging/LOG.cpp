#include "LOG.h"

void logging::LOG(logLevel level)
{
	std::ostringstream os;
	os << NowTime();
	os << " " << ToString(level) << ": ";
	os << std::string(level > WARNING ? 0 : level - WARNING, '\t');
	os << std::endl;
	fprintf(stderr, "%s", os.str().c_str());
	fflush(stderr);
}
