

/*!
 * @file WeatherUnderground.h
 *
 *
 */

#ifndef __WEATHER_UNDERGROUND_H__
#define __WEATHER_UNDERGROUND_H__

//#include <HTTPClient.h>
#include <string.h>
#include <tools.h>
#include <TimeLib.h>
#include <ArduinoJson.h>
#include <ArduinoHttpClient.h>
#include <WiFi.h>

//windspeed [km/h]
//windgust [km/h]
//temp [°F]
//baro 

class WeatherUnderground {
public:
  typedef struct {
    bool bWind;
    float lat;
    float lon;
    float height;
    float winddir;
    float windspeed;
    float windgust;
    float humidity;
    float temp;
    float pressure;
    bool bRain;
    float rain1h;
    float raindaily;
  } wData;

    WeatherUnderground(); //constructor
    bool sendData(String ID,String KEY,wData *data); //send Data to WU with Station-ID and Station-Key
    bool getData(String ID,String KEY,wData *data); //get Data from WU with Station-ID and API-Key
    void setClient(Client *_client);
    void setMutex(SemaphoreHandle_t *_xMutex);

protected:
private:
    //HTTPClient http;
    //HttpClient http;
    bool checkKeyExists();
    bool _windsensor;
    bool _rainsensor;
    Client *client;
    SemaphoreHandle_t *xMutex;    
};
#endif