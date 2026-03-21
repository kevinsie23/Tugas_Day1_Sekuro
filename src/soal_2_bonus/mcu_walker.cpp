#include "mcu_walker.hpp"
//[TODO]: Implementasikan kelas mcu_walker dibawah ini

mcu_walker::mcu_walker(float cpu_speed, int memory, string os, string name, int volt, int motor_speed, int rotation) 
    : MCU(cpu_speed, memory, os, name, volt){
        this->motor_speed = motor_speed;
        this->rotation = rotation;
        
        cout << "[KONSTRUKTOR WALKER] : Sistem gerak " << name << " telah diinisiasi." << endl;
}


void mcu_walker::rotate(int rotation){
    this->rotation = rotation;
    cout << "[WALKER] :  "  << name << " berputar ke arah " << rotation << " derajat." << endl;
}

void mcu_walker::increase_speed(int speed){
    motor_speed += speed;
    cout << "[WALKER] : Kecepatan motor " << name << " naik menjadi " << motor_speed << " rpm." << endl;
}

void mcu_walker::showSpek(){
    cout << "[SPEK MCU_WALKER] : " << name << endl;
    cout << "- CPU      : " << cpu_speed << " GHz" << endl;
    cout << "- RAM      : " << memory << "MB" << endl;
    cout << "- OS       : " << os << endl;
    cout << "- Volt     : " << volt << " V" << endl;
    cout << "- Speed    : " << motor_speed << " RPM" << endl;
    cout << "- Rotation : " << rotation << " Deg" << endl;
}

void mcu_walker::ganti_os(string new_os){
    os = new_os;
    cout << "[WALKER UPDATE] : " << name << " migrasi OS ke " << os << endl;
}

mcu_walker::~mcu_walker(){
    cout << "[DESTRUKTOR WALKER] : Komponen walker " << name << " telah dimatikan." << endl;
}
