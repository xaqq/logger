#include <iostream>
#include <stdexcept>
#include "../includes/Log.hpp"

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

  Log::defaultConfig();
  std::shared_ptr<Log::ALogger> stdout2 (new Log::StdoutLogger(new Log::DefaultFormatter()));
  Log::LogMgr::registerLogger("secondary", stdout2);

  Test obj;
  int b = 21;
  
  /* Logged twice: by the stdout logger (initialized in defaultConfig()) and our logger, stdout2 */
  INFO("Information message ! With some number, and an object:" << b << ", " << obj);
  WARN("Hey, I'm a warning");
  ERROR("Ouch, this is bad, an error %s");

  try
    {
      INFO("This goes to specific logger, so it will be logged once.", {"default"});
    }
  catch (std::exception &e)
    {
      std::cerr << e.what() << std::endl;
    }
}
