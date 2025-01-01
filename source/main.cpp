#include <iostream>

#include "lib.hpp"
#include "temp_conv.hpp"

auto main() -> int
{
  auto const lib = library {};
  auto const message = "Hello from " + lib.name + "!";
  const auto* const version = "1.0.0";

  std::cout << message << '\n';
  std::cout << "Version: " << version << '\n';

  temp_conv_main();

  return 0;
}
