#include "../logger/StdoutLogger.hpp"
#include "../logger/DefaultFormatter.hpp"
#include <memory>

int	main()
{
  std::shared_ptr<Log::ALogger> log (new Log::StdoutLogger());
  std::shared_ptr<Log::AFormatter> format(new Log::DefaultFormatter(log));

  log->setFormatter(format);

  log->info("TOTO");
  log->warn("Bla");
}
