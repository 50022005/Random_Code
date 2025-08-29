#include <iostream>
#include <string>
using namespace std;
#include"ComputerAssembly.h"
//Muhammad Hashim Rahim
// 23i-0028
// CS-G
// Assignment 3
// OOP
// TA Nouman
// Sir Sheryar
// 
// Function to display Computer specifications
                                    void displayComputer(const Computer& comp) {
                                        cout << "ALU: " << endl;
                                        cout << "   Number of Adders: " << comp.getCPU().getALU().getNoOfAdders() << endl;
                                        cout << "   Number of Subtractors: " << comp.getCPU().getALU().getNoOfSubtractors() << endl;
                                        cout << "   Number of Registers: " << comp.getCPU().getALU().getNoOfRegisters() << endl;
                                        cout << "   Size of Registers: " << comp.getCPU().getALU().getSizeOfRegisters() << " bits" << endl;
                                        cout << "Control Unit: " << endl;
                                        cout << "   Clock: " << comp.getCPU().getControlUnit().getClock() << " GHz" << endl;
                                    }

                                    // Function to display GraphicsCard specifications
                                    void displayGraphicsCard(const GraphicsCard& gpu) {
                                        cout << "Brand: " << gpu.getBrand() << endl;
                                        cout << "Memory Size: " << gpu.getMemorySize() << " GB" << endl;
                                        cout << "Price: " << gpu.getPrice()*200 << "  Rs" << endl;
                                    }

                                    // Function to display StorageDevice specifications
                                    void displayStorageDevice(const StorageDevice& storage) {
                                        cout << "Type: " << storage.getType() << endl;
                                        cout << "Capacity: " << storage.getCapacity() << " GB" << endl;
                                        cout << "Price: " << storage.getPrice()*200 << "  Rs" << endl;
                                    }

                                    // Function to display NetworkCard specifications
                                    void displayNetworkCard(const NetworkCard& network) {
                                        cout << "Type: " << network.getType() << endl;
                                        cout << "Speed: " << network.getSpeed() << " Mbps" << endl;
                                        cout << "Price: " << network.getPrice()*200 << "  Rs" << endl;
                                    }

                                    // Function to display PowerSupply specifications
                                    void displayPowerSupply(const PowerSupply& psu) {
                                        cout << "Wattage: " << psu.getWattage() << " Watts" << endl;
                                        cout << "Efficiency Rating: " << psu.getEfficiencyRating() << endl;
                                        cout << "Price: " << psu.getPrice()<< "  Rs" << endl;
                                    }

                                    // Function to display Battery specifications
                                    void displayBattery(const Battery& battery) {
                                        cout << "Capacity: " << battery.getCapacity() << " mAh" << endl;
                                    }

                                    // Function to display Case specifications
                                    void displayCase(const Case& case_) {
                                        cout << "Form Factor: " << case_.getFormFactor() << endl;
                                        cout << "Color: " << case_.getColor() << endl;
                                        cout << "Price: " << case_.getPrice()*200 << " Rs" << endl;
                                    }

                                    int main() {
                                        // Gather specifications for ComputerAssembly
                                        ComputerAssembly assembly;

                                        // Gather specifications for Computer
                                        cout << "Configuring the computer: " << endl;
                                        PhysicalMemory pm;
                                        MotherBoard mb;
                                        CPU cpu;
                                        int pmCapacity, mbCapacity;
                                        string cpuBrand, cpuModel;
                                        cout << "Enter Physical Memory capacity (in GB): ";
                                        cin >> pmCapacity;
                                        pm.setCapacity(pmCapacity);
                                        cout << "Enter Main Memory capacity (in MB): ";
                                        cin >> mbCapacity;
                                        mb.getMainMemory().setCapacity(mbCapacity);
  
                                        // Gather specifications for GraphicsCard
                                        GraphicsCard gpu;
                                        if (cpu.getCPUModel() != "M1") {
                                            cout << "Configuring the graphics card: " << endl;
       
                                            string gpuBrand;
                                            int gpuMemorySize;
                                            cout << "Enter Graphics Card Brand: ";
                                            cin >> gpuBrand;
                                            gpu.setBrand(gpuBrand);
                                            cout << "Enter Graphics Card Memory Size (in GB): ";
                                            cin >> gpuMemorySize;
                                            gpu.setMemorySize(gpuMemorySize);
                                        } 
                                        else{
        
                                            gpu.setBrand("Apple");
                                            gpu.setMemorySize(4);

    
                                        }
    
                                        // Gather specifications for StorageDevice
                                        cout << "Configuring the storage device: " << endl;
                                        StorageDevice storage;
                                        string storageType;
                                        int storageCapacity;
                                        cout << "Enter Storage Device Type (HDD/SSD): ";
                                        cin >> storageType;
                                        storage.setType(storageType);
                                        cout << "Enter Storage Device Capacity (in GB): ";
                                        cin >> storageCapacity;
                                        storage.setCapacity(storageCapacity);

                                        // Gather specifications for NetworkCard
                                        cout << "Configuring the network card: " << endl;
                                        NetworkCard network;
                                        string networkType;
                                        int networkSpeed;
                                        cout << "Enter Network Card Type (Ethernet/Wi-Fi): ";
                                        cin >> networkType;
                                        network.setType(networkType);
                                        cout << "Enter Network Card Speed (in Mbps): ";
                                        cin >> networkSpeed;
                                        network.setSpeed(networkSpeed);

                                        // Gather specifications for PowerSupply
                                        cout << "Configuring the power supply: " << endl;
                                        PowerSupply psu;
                                        int psuWattage;
                                        string psuRating;
                                        cout << "Enter Power Supply Wattage (in Watts): ";
                                        cin >> psuWattage;
                                        psu.setWattage(psuWattage);
                                        cout << "Enter Power Supply Efficiency Rating: ";
                                        cin >> psuRating;
                                        psu.setEfficiencyRating(psuRating);

                                        // Gather specifications for Battery
                                        cout << "Configuring the battery: " << endl;
                                        Battery battery;
                                        int batteryCapacity;
                                        cout << "Enter Battery Capacity (in mAh): ";
                                        cin >> batteryCapacity;
                                        battery.setCapacity(batteryCapacity);

                                        // Gather specifications for Case
                                        cout << "Configuring the case: " << endl;
                                        Case case_;
                                        string caseFormFactor, caseColor;
                                        cout << "Enter Case Form Factor: ";
                                        cin >> caseFormFactor;
                                        case_.setFormFactor(caseFormFactor);
                                        cout << "Enter Case Color: ";
                                        cin >> caseColor;
                                        case_.setColor(caseColor);
                                        Computer c(pm, mb, cpu);
                                        // Set gathered specifications for ComputerAssembly
                                        assembly.setComputer(c);
                                        assembly.setGraphicsCard(gpu);
                                        assembly.setStorageDevice(storage);
                                        assembly.setNetworkCard(network);
                                        assembly.setPowerSupply(psu);
                                        assembly.setBattery(battery);
                                        assembly.setCase(case_);

                                        // Display the specifications and total price
                                        cout << "\nComputer Assembly Specifications: " << endl;
                                        cout << "---------------------------------" << endl;
                                        cout << "Computer: " << endl;
                                        displayComputer(assembly.getComputer());
                                        cout << endl << "Graphics Card: " << endl;
                                        displayGraphicsCard(assembly.getGraphicsCard());
                                        cout << endl << "Storage Device: " << endl;
                                        displayStorageDevice(assembly.getStorageDevice());
                                        cout << endl << "Network Card: " << endl;
                                        displayNetworkCard(assembly.getNetworkCard());
                                        cout << endl << "Power Supply: " << endl;
                                        displayPowerSupply(assembly.getPowerSupply());
                                        cout << endl << "Battery: " << endl;
                                        displayBattery(assembly.getBattery());
                                        cout << endl << "Case: " << endl;
                                        displayCase(assembly.getCase());
                                        cout << endl << "Total Price: " << assembly.getTotalPrice()*1000 << "  Rs" << endl;

                                        return 0;
                                    }