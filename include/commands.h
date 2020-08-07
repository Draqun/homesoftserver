#ifndef COMMANDS_H
#define COMMANDS_H

enum Command {
    CHANGE_CAMERA_ANGLES,
    GET_DEVICE_LAST_ERROR,
    GET_DEVICES_STATUS,
    GET_SENSORS_STATUS,
};

enum DeviceType {
    CAMERA,
    SENSOR,
};

#endif // COMMANDS_H
