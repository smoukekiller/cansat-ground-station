#include "globals.h"

Servo baseservo, antennaservo;

bool panic_mode_reversed = false;
uint8_t panic_mode_angle = 0;
uint64_t panic_mode_timer;
uint64_t last_package_recieve_time = 0;

float base_p;
double longitude = 21.610077;
double altbar = 0;
double latitude = 63.094818;
double delta_x;
double delta_y;
float t;
float p;
float ax;
float ay;
float az;
float gx;
float gy;
float gz;
float light;
