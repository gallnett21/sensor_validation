#include "sensor.h"
#include <stdio.h>

const char* get_status_string(SensorStatus status) {
    switch (status) {
        case SENSOR_OFF:
            return "OFF";
        case SENSOR_OK:
            return "OK";
        case SENSOR_WARNING:
            return "WARNING";
        case SENSOR_ERROR:
            return "ERROR";
        default:
            return "UNKNOWN";
    }
}

void update_sensor(Sensor *sensor, int temperature, int voltage) {
    sensor->temperature = temperature;
    sensor->voltage = voltage;
    if (sensor->temperature <= 0) {
        sensor->status = SENSOR_OFF;
    } else if (sensor->temperature >= 1 && sensor->temperature <= 70) {
        sensor->status = SENSOR_OK;
    } else if (sensor->temperature > 70 && sensor->temperature <= 100) {
        sensor->status = SENSOR_WARNING;
    } else {
        sensor->status = SENSOR_ERROR;
    }

}

void print_sensor(const Sensor *sensor){
    printf("Temperature: %d\n", sensor->temperature);
    printf("Voltage: %d\n", sensor->voltage);
    printf("Status: %s\n", get_status_string(sensor->status));
}