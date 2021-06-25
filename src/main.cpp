#include <iostream>
#include <vector>
#include <sstream>

enum switches{
  ELECTRICITY_AT_HOME = 1,          // Электричество дома
  MAIN_SOCKETS = 2,                 // Основные розетки
  THE_LIGHT_INSIDE = 4,             // Свет внутри
  LIGHT_FROM_OUTSIDE = 8,           // Свет снаружи
  ROOM_HEATING = 16,                // Отопление помещения
  HEATING_WATER_SUPPLY_SYSTEM = 32, // Отопление водопровода
  INDOOR_AIR_CONDITIONING = 64      // Кондиционер в помещении
};

int main(){
  std::cout << "Smart home" << std::endl;
  std::stringstream parsData;
  std::string data;
  int temperatureOuside; 
  int state = 0;

  std::cin >> data;
  parsData << data;

  parsData >> temperatureOuside;

  if(temperatureOuside < 0){
    state |= HEATING_WATER_SUPPLY_SYSTEM;
    std::cout << "Water supply heating is included" << std::endl;
  }else if(temperatureOuside > 5){
    state &= ~HEATING_WATER_SUPPLY_SYSTEM;  
    std::cout << "The water supply heating is turned off" << std::endl;
  }else{
    std::cout << "The water supply heating is turned off" << std::endl;
  }

  return 0;
}
