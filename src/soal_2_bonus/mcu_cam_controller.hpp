#pragma once

#include "mcu.hpp"

class mcu_cam_controller:public MCU{
private:
    string obj_detected;
public:
    static int count_detected_obj;
    mcu_cam_controller(float cpu_speed,int memory,string os,string name,int volt,string obj_detected);
    void detect_other_object(string other, bool moving);
    void showSpek() override;
    void ganti_os(string new_os) override;
    ~mcu_cam_controller();
};