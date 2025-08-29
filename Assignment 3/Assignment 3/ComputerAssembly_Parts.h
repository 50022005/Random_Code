#pragma once
//Muhammad Hashim Rahim
// 23i-0028
// CS-G
// Assignment 3
// OOP
// TA Nouman
// Sir Sheryar
// 
#include <iostream>
#include <string>
using namespace std;
#include"ComputerParts.h"
            class Computer {
            private:
            PhysicalMemory pm;
            MotherBoard mb;
            CPU cpu;
            int price;  // Price 

            public:
            // Default constructor initializes each part with its default constructor
            Computer() : pm(), mb(), cpu(), price(0) {
                System();
            }

            // Overloaded constructor initializes each part with specific objects
            Computer(const PhysicalMemory& pm, const MotherBoard& mb, const CPU& cpu)
                : pm(pm), mb(mb), cpu(cpu), price(0) {
                System();
            }

            // Function to configure system based on user input
            void System() {
        
                string choice;
                    cout << "Do you want to configure a Mac or Windows system? (Mac/Windows): ";
                    getline( cin, choice);

                if (choice == "Mac") {
                    ifMac();
                }
                else if (choice == "Windows") {
                    ifWindows();
                }
                else {
                        cout << "Invalid choice, configuring default settings." <<  endl;
                }
            }

            // Specific configuration for Mac
            void ifMac() {
                // Set specific CPU and MotherBoard settings for Mac
                cpu.setBrand("Apple Silicon");
                cpu.setCPUModel("M1");
                price = 35000;  // Example price 
                    cout << "Configured with Apple Silicon M1 processor. Price:  " << price <<  endl;
            }

            // Specific configuration for Windows
            void ifWindows() {
                // Set specific CPU and MotherBoard settings for Windows
                cpu.setBrand("Intel");
                cpu.setCPUModel("Core i7");
                price = 25000;  // Example price
                    cout << "Configured with Intel Core i7 processor. Price:  " << price <<  endl;
            }

            // Getters
            PhysicalMemory getPhysicalMemory() const { return pm; }
            MotherBoard getMotherBoard() const { return mb; }
            CPU getCPU() const { return cpu; }
            int getPrice() const { return price; }

            // Setters
            void setPhysicalMemory(const PhysicalMemory& pm) { this->pm = pm; }
            void setMotherBoard(const MotherBoard& mb) { this->mb = mb; }
            void setCPU(const CPU& cpu) { this->cpu = cpu; }
            void setPrice(int price) { price = price; }
            };


            class GraphicsCard {
            private:
                string brand;
            int memorySize;  // in GB
            double price;  // in currency unit

            public:
            // Default constructor
            GraphicsCard() : brand("Nvidia"), memorySize(4), price(300.0) {}

            // Overloaded constructor
            GraphicsCard(const  string& br, int memSize, double pr)
                : brand(br), memorySize(memSize), price(pr) {}

            // Getters
                string getBrand() const { return brand; }
            int getMemorySize() const { return memorySize; }
            double getPrice() const { return price; }

            // Setters
            void setBrand(const  string& br) { brand = br; }
            void setMemorySize(int memSize) { memorySize = memSize; }
            void setPrice(double pr) { price = pr; }
            };


            class StorageDevice {
            private:
                string type;  // HDD or SSD
            int capacity;  // in GB
            double price;

            public:
            // Default constructor
            StorageDevice() : type("SSD"), capacity(256), price(100.0) {}

            // Overloaded constructor
            StorageDevice(const  string& t, int cap, double pr)
                : type(t), capacity(cap), price(pr) {}

            // Getters
                string getType() const { return type; }
            int getCapacity() const { return capacity; }
            double getPrice() const { return price; }

            // Setters
            void setType(const  string& t) { type = t; }
            void setCapacity(int cap) { capacity = cap; }
            void setPrice(double pr) { price = pr; }
            };

            class NetworkCard {
            private:
                string type;  // Ethernet or Wi-Fi
            int speed;  // in Mbps
            double price;

            public:
            // Default constructor
            NetworkCard() : type("Ethernet"), speed(1000), price(50.0) {}

            // Overloaded constructor
            NetworkCard(const  string& t, int sp, double pr)
                : type(t), speed(sp), price(pr) {}

            // Getters
                string getType() const { return type; }
            int getSpeed() const { return speed; }
            double getPrice() const { return price; }

            // Setters
            void setType(const  string& t) { type = t; }
            void setSpeed(int sp) { speed = sp; }
            void setPrice(double pr) { price = pr; }
            };


            class PowerSupply {
            private:
            int wattage;  // in Watts
                string efficiencyRating;  // 80 Plus Bronze, etc.
            double price;

            public:
            // Default constructor
            PowerSupply() : wattage(500), efficiencyRating("80 Plus Gold"), price(120.0) {}

            // Overloaded constructor
            PowerSupply(int w, const  string& rating, double pr)
                : wattage(w), efficiencyRating(rating), price(pr) {}

            // Getters
            int getWattage() const { return wattage; }
                string getEfficiencyRating() const { return efficiencyRating; }
            double getPrice() const { return price; }

            // Setters
            void setWattage(int w) { wattage = w; }
            void setEfficiencyRating(const  string& rating) { efficiencyRating = rating; }
            void setPrice(double pr) { price = pr; }
            };

            class Battery {
            private:
            int capacity;  // in mAh

            public:
            // Default constructor
            Battery() : capacity(5000) {}  // Typical battery capacity

            // Overloaded constructor
            Battery(int cap) : capacity(cap) {}

            // Getters
            int getCapacity() const { return capacity; }

            // Setters
            void setCapacity(int cap) { capacity = cap; }
            };

            class Case {
            private:
                string formFactor;  // ATX, Micro ATX, etc.
                string color;
            // Optional: include a price only for PC cases (not for laptops/tablets)
            double price;

            public:
            // Default constructor
            Case() : formFactor("ATX"), color("Black"), price(0.0) {}  // Default price for non-PC cases

            // Overloaded constructor
            Case(const  string& factor, const  string& col, double pr = 0.0)
                : formFactor(factor), color(col), price(pr) {}

            // Getters
                string getFormFactor() const { return formFactor; }
                string getColor() const { return color; }
            double getPrice() const { return price; }

            // Setters
            void setFormFactor(const  string& factor) { formFactor = factor; }
            void setColor(const  string& col) { color = col; }
            void setPrice(double pr) { price = pr; }
            };
