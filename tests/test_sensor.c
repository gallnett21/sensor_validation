#include "sensor.h"
#include <stdio.h>
#include <string.h>

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

    //Add tests for sensor status
    if (strcmp(get_status_string(SENSOR_OFF), "OFF") == 0){
        printf("Status string test OFF passed\n");
    }
    else{
        printf("Status string test OFF failed\n");
        failed_tests++;
    }

    if (strcmp(get_status_string(SENSOR_OK), "OK") == 0){
        printf("Status string test OK passed\n");
    }
    else{
        printf("Status string test OK failed\n");
        failed_tests++;
    }

    if (strcmp(get_status_string(SENSOR_WARNING), "WARNING") == 0){
        printf("Status string test WARNING passed\n");
    }
    else{
        printf("Status string test WARNING failed\n");
        failed_tests++;
    }

    if (strcmp(get_status_string(SENSOR_ERROR), "ERROR") == 0){
        printf("Status string test ERROR passed\n");
    }
    else{
        printf("Status string test ERROR failed\n");
        failed_tests++;
    }

    if (strcmp(get_status_string((SensorStatus)99), "UNKNOWN") == 0) {
        printf("Status string test UNKNOWN passed\n");
    } else {
    printf("Status string test UNKNOWN failed\n");
        failed_tests++;
    }

    if(failed_tests == 0) {
        printf("All test cases passed - CI AUTOMATION\n");
        return 0;
    }
    else{
        printf("%d test case failed", failed_tests);
        return 1;
    }

    printf("Artifacts added succesffully");
    
}