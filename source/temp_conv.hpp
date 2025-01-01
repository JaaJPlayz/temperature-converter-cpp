#include <iostream>

static void temp_menu()
{
  std::cout << "[c] Celsius\n";
  std::cout << "[f] Fahrenheit\n";
  std::cout << "[k] Kelvin\n";
}

static auto logical_temp_conv(char from_unit, char to_unit, double amount)
    -> double
{
  const int fahrenheit_constant = 32;
  const double fahrenheit_multiplier = 1.8;
  const double kelvin_constant = 273.15;

  if (from_unit == 'c' && to_unit == 'f') {
    double result = (amount * fahrenheit_multiplier) + fahrenheit_constant;
    return result;
  }

  if (from_unit == 'f' && to_unit == 'c') {
    double result = (amount - fahrenheit_constant) / fahrenheit_multiplier;
    return result;
  }

  if (from_unit == 'c' && to_unit == 'k') {
    double result = amount + kelvin_constant;
    return result;
  }

  if (from_unit == 'k' && to_unit == 'c') {
    double result = amount - kelvin_constant;
    return result;
  }

  if (from_unit == 'f' && to_unit == 'k') {
    double result = ((amount - fahrenheit_constant) / fahrenheit_multiplier)
        + kelvin_constant;
    return result;
  }

  if (from_unit == 'k' && to_unit == 'f') {
    double result = ((amount - kelvin_constant) * fahrenheit_multiplier)
        + fahrenheit_constant;
    return result;
  }

  return 0;
}

static void temp_conv_data_gatherer()
{
  char from_unit = 0;
  char to_unit = 0;
  double amount = 0;

  temp_menu();
  std::cout << "\nEnter the temperature to convert: ";
  std::cin >> from_unit;

  temp_menu();
  std::cout << "\nEnter the temperature to convert to: ";
  std::cin >> to_unit;

  std::cout << "\nEnter the temperature: ";
  std::cin >> amount;

  double result = logical_temp_conv(from_unit, to_unit, amount);

  std::cout << "From " << from_unit << " to " << to_unit << " is " << result
            << '\n';
}

static void temp_conv_main()
{
  char choice = '0';

  while (choice != '2') {
    std::cout << '\n';
    std::cout << "[1] Convert temperature\n";
    std::cout << "[2] Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    std::cout << '\n';

    if (choice == '1') {
      temp_conv_data_gatherer();
    }
  }
}
