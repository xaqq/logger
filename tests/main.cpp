#include "../logger/StdoutLogger.hpp"
#include "../logger/DefaultFormatter.hpp"
#include "../logger/DefaultFilter.hpp"
#include <memory>

int	main()
{
  std::shared_ptr<Log::ALogger> log (new Log::StdoutLogger());
  std::shared_ptr<Log::AFormatter> format(new Log::DefaultFormatter(log));
  std::shared_ptr<Log::DefaultFilter> filter(new Log::DefaultFilter(Log::LogLevel::WARN));

  log->registerFilter(filter);
  Log::LogMgr::registerLogger(log);
  log->setFormatter(format);

  INFO("UNE INFO OMFG");
}
