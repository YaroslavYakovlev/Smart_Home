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

  std::string movements;
  std::string light;

  int temperatureInside;
  int temperatureOuside; 
  int timeHour = 0;
  int state = 0;
  int colorTemperature = 5000;
  for(int i = 0; i < 48; i++){
    std::cout << "Enter the data: outside temperature, inside temperature, movement (yes/no), light (on/off), time" << std::endl;
    std::getline(std::cin, data);
    std::cout << "data " << data << std::endl;
    parsData << data;

    std::cout << "parsData " << parsData.str() << std::endl;
    parsData >> temperatureOuside >> temperatureInside >> movements >> light >> timeHour;

      std::cout << "temperatureOuside " << temperatureOuside << std::endl;
      std::cout << "temperatureInside " << temperatureInside << std::endl;

      std::cout << "movements " << movements.c_str() << std::endl;
      std::cout << "light " << light.c_str() << std::endl;
      std::cout << "timeHour " << timeHour << std::endl;


    if(temperatureOuside < 0){
      state |= HEATING_WATER_SUPPLY_SYSTEM;
      std::cout << "Water supply heating is included" << std::endl;
    }else if(temperatureOuside > 5){
      state &= ~HEATING_WATER_SUPPLY_SYSTEM;  
      std::cout << "The water supply heating is turned off" << std::endl;
    }

    if(temperatureInside < 22){
      state |= ROOM_HEATING;
      std::cout << "Indoor heating is on" << std::endl;
    }else if(temperatureInside >= 25){
      state &= ~ROOM_HEATING;
      std::cout << "The heating in the room is turned off" << std::endl;
    }else if(temperatureInside >= 30){
      state |= INDOOR_AIR_CONDITIONING;
      std::cout << "The air conditioner is on" << std::endl;
    }else if(temperatureInside <= 25){
      state &= ~INDOOR_AIR_CONDITIONING;
      std::cout << "The air conditioner is turned off" << std::endl;
    }

    if(((timeHour >= 16) && (timeHour <= 24) || (timeHour >= 0) && (timeHour < 5))
        && (movements == "yes")){
      state |= LIGHT_FROM_OUTSIDE;
      std::cout << "The light outside is on" << std::endl;
    }else{
      state &= ~LIGHT_FROM_OUTSIDE;
    }

    if((light == "on") && ((timeHour >= 16) && (timeHour <=20))){
      state |= THE_LIGHT_INSIDE;
      std::cout << "The lighting in the house is turned on" << std::endl;
      colorTemperature -= (1300 / 4);
      std::cout << "Lamp temperature - " << colorTemperature << std::endl;
    }

    if(timeHour == 0){
      colorTemperature = 5000;
    }

  }

  return 0;
}
