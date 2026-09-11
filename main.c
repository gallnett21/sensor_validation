#include "sensor.h"
#include <stdio.h>

typedef struct {
    int temperature;
    SensorStatus expected_status;
} TestCase;

int main() {
    Sensor sensor = {0, 0, SENSOR_OFF};

    TestCase tests[] = {
        {-5, SENSOR_OFF},
        {0, SENSOR_OFF},
        {1, SENSOR_OK},
        {70, SENSOR_OK},
        {71, SENSOR_WARNING},
        {100, SENSOR_WARNING},
        {101, SENSOR_ERROR},
    };

    int failed_tests = 0;

    for(size_t
         i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        update_sensor(&sensor, tests[i].temperature, 3200);
        if(sensor.status == tests[i].expected_status) {
            printf("Test %zu passed: temperature=%d, expected_status=%d, actual_status=%d\n", i, tests[i].temperature, tests[i].expected_status, sensor.status);
        } else {
            printf("Test %zu failed: temperature=%d, expected_status=%d, actual_status=%d\n", i, tests[i].temperature, tests[i].expected_status, sensor.status);
            failed_tests ++;
        }
    }

    if(failed_tests == 0) {
        printf("All test cases passed - CI AUTOMATION\n");
        return 0;
    }
    else{
        printf("%d test case failed", failed_tests);
        return 1;
    }
    
}