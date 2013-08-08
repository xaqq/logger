#include "../logger/StdoutLogger.hpp"
#include "../logger/DefaultFormatter.hpp"
#include "../logger/DefaultFilter.hpp"
#include <memory>
#include <sstream>


class Test
{
public:
  Test(): _age(1337)
  {}
  int	_age;
};

std::ostream &operator<<(std::ostream &os, const Test &t)
{
  os << t._age;
  return os;
}

int	main(int, char **)
{
  std::shared_ptr<Log::ALogger> log (new Log::StdoutLogger());
  std::shared_ptr<Log::AFormatter> format(new Log::DefaultFormatter(log));
  std::shared_ptr<Log::DefaultFilter> filter(new Log::DefaultFilter({Log::LogLevel::WARN,
	  Log::LogLevel::INFO}));

  Test obj;

  log->registerFilter(filter);
  Log::LogMgr::registerLogger("default", log);
  Log::LogMgr::registerLogger("secondary", log);
  log->setFormatter(format);

  int b = 21;
  
  INFO("UNE INFO OMFG. Added some fun:" << b << "and hey, why not a custom class?: " << obj); // logged twice
  INFO("INFO TO SPECIFIC LOGGER.", {"default"});
  WARN("UN WARNING"); //logged twice
  ERROR("UNE ERROR"); // not displayed
}
