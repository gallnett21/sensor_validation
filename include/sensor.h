typedef enum {
    SENSOR_OFF,
    SENSOR_OK,
    SENSOR_WARNING,
    SENSOR_ERROR
} SensorStatus;

typedef struct {
    int temperature;
    int voltage;
    SensorStatus status;
} Sensor;

const char* get_status_string(SensorStatus status);
void update_sensor(Sensor *sensor, int temperature, int voltage);
void print_sensor(const Sensor *sensor);