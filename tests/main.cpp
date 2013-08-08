#include "../logger/StdoutLogger.hpp"
#include "../logger/DefaultFormatter.hpp"
#include "../logger/DefaultFilter.hpp"
#include <memory>

int	main(int, char **)
{
  std::shared_ptr<Log::ALogger> log (new Log::StdoutLogger());
  std::shared_ptr<Log::AFormatter> format(new Log::DefaultFormatter(log));
  std::shared_ptr<Log::DefaultFilter> filter(new Log::DefaultFilter({Log::LogLevel::WARN,
	  Log::LogLevel::INFO}));

  log->registerFilter(filter);
  Log::LogMgr::registerLogger("default", log);
  Log::LogMgr::registerLogger("secondary", log);
  log->setFormatter(format);

  INFO("UNE INFO OMFG"); // logged twice
  INFO("INFO TO SPECIFIC LOGGER", {"default"});
  WARN("UN WARNING"); //logged twice
  ERROR("UNE ERROR"); // not displayed
}
