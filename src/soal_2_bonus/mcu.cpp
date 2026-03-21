#include "mcu.hpp"
// [TODO] : Implementasikan class robot di file cpp ini
// [TIPS] : Gunakan MCU::<nama methode> untuk mendefinisikan class-nya

MCU::MCU(float cpu_speed, int memory, string os, string name, int volt){
    this->cpu_speed = cpu_speed;
    this->memory = memory;
    this->os = os;
    this->name = name;
    this->volt = volt;

    cout << "[KONSTRUKTOR MCU] : Objek " << name << " berhasil dibuat." << endl;
}

void MCU::showSpek() {
    cout << "[BASE MCU] : " << name << " | CPU: " << cpu_speed 
         << "GHz | RAM: " << memory << "MB | OS: " << os 
         << " | Volt: " << volt << "V" << endl;
}

void MCU::nambah_volt(int penambahan_voltase){
    volt += penambahan_voltase;
    cout << "Voltase " << name << " berhasil dinaikkan ke: " << volt << "V" << endl;
}

void MCU::ganti_os(string new_os){
    os = new_os;
    cout << "[BASE MCU UPDATE] : " << name << " migrasi OS ke " << os << endl;
}

MCU::~MCU(){
    cout << "[DESTRUKTOR MCU] : Objek base " << name << " dibersihkan." << endl;
}