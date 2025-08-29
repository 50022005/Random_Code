#pragma once
//Muhammad Hashim Rahim
// 23i-0028
// CS-G
// Assignment 3
// OOP
// TA Nouman
// Sir Sheryar
// 
#include<iostream>
using namespace std;



        class ALU {
        private:
            int NoOfAdders;
            int NoOfSubtractors;
            int NoOfRegisters;
            int sizeOfRegisters;

        public:
            // Default constructor
            ALU() : NoOfAdders(1), NoOfSubtractors(1), NoOfRegisters(8), sizeOfRegisters(32) {}

            // Overloaded constructor
            ALU(int adders, int subtractors, int registers, int size)
                : NoOfAdders(adders), NoOfSubtractors(subtractors), NoOfRegisters(registers), sizeOfRegisters(size) {}

            // Getters
            int getNoOfAdders() const { return NoOfAdders; }
            int getNoOfSubtractors() const { return NoOfSubtractors; }
            int getNoOfRegisters() const { return NoOfRegisters; }
            int getSizeOfRegisters() const { return sizeOfRegisters; }

            // Setters
            void setNoOfAdders(int adders) { NoOfAdders = adders; }
            void setNoOfSubtractors(int subtractors) { NoOfSubtractors = subtractors; }
            void setNoOfRegisters(int registers) { NoOfRegisters = registers; }
            void setSizeOfRegisters(int size) { sizeOfRegisters = size; }
        };


        class ControlUnit {
        private:
            float clock;

        public:
            // Default constructor
            ControlUnit() : clock(1.0f) {}

            // Overloaded constructor
            ControlUnit(float clk) : clock(clk) {}

            // Getters
            float getClock() const { return clock; }

            // Setters
            void setClock(float clk) { clock = clk; }
        };

        class CPU {
        private:
            ALU alu;
            ControlUnit cu;
            string Brand;
            string CPUModel;

        public:
            // Default constructor
            CPU() : alu(), cu() {}

            // Overloaded constructor
            CPU(const ALU& a, const ControlUnit& c) : alu(a), cu(c) {}

            // Getters
            ALU getALU() const { return alu; }
            ControlUnit getControlUnit() const { return cu; }
            string getBrand() const { return Brand; }
            string getCPUModel() const { return CPUModel; }

            // Setters
            void setALU(const ALU& a) { alu = a; }
            void setControlUnit(const ControlUnit& c) { cu = c; }
            void setBrand(const string& brand) { Brand = brand; }
            void setCPUModel(const string& model) { CPUModel = model; }
        };

        class MainMemory {
        private:
            int capacity;             // in megabytes
             string technologyType;  // Semiconductor or Silicon

        public:
            // Default constructor
            MainMemory() : capacity(1024), technologyType("Semiconductor") {}

            // Overloaded constructor
            MainMemory(int cap,  string techType) : capacity(cap), technologyType(techType) {}

            // Getters
            int getCapacity() const { return capacity; }
             string getTechnologyType() const { return technologyType; }

            // Setters
            void setCapacity(int cap) { capacity = cap; }
            void setTechnologyType( string techType) { technologyType = techType; }
        };


        class Port {
        private:
             string type;    // VGI Port, I/O Port, USB Port, HDMI Port, etc.
            int baud_rate;       // Communication speed

        public:
            // Default constructor
            Port() : type("USB Port"), baud_rate(9600) {}

            // Overloaded constructor
            Port( string t, int baud) : type(t), baud_rate(baud) {}

            // Getters
             string getType() const { return type; }
            int getBaudRate() const { return baud_rate; }

            // Setters
            void setType( string t) { type = t; }
            void setBaudRate(int baud) { baud_rate = baud; }
        };


        class MotherBoard {
        private:
            static const int MAX_PORTS = 4;  // Maximum number of ports
            MainMemory mm;
            Port* ports[MAX_PORTS];  // Array of pointers to Port, which are not owned by MotherBoard

        public:
            // Default constructor
            MotherBoard() : mm() {
                // Initialize port pointers to nullptr, assuming actual Port objects are managed externally
                for (int i = 0; i < MAX_PORTS; i++) {
                    ports[i] = nullptr;
                }
            }

            // Overloaded constructor that accepts external port pointers
            MotherBoard(const MainMemory& memory, Port* portArray[], int numPorts = 4) : mm(memory) {
                for (int i = 0; i < MAX_PORTS && i < numPorts; i++) {
                    ports[i] = portArray[i];  // Assign provided port pointers
                }
            }

            // Destructor
            ~MotherBoard() {
                // No need to delete ports here since MotherBoard does not own them
            }

            // Getters
            MainMemory getMainMemory() const { return mm; }
            Port* getPort(int index) const {
                if (index >= 0 && index < MAX_PORTS) {
                    return ports[index];
                }
                else {
                    return nullptr;  // Return null if index is out of range
                }
            }

            // Setters
            void setMainMemory(const MainMemory& memory) { mm = memory; }
            void setPort(Port* port, int index) {
                if (index >= 0 && index < MAX_PORTS) {
                    ports[index] = port;
                }
            }
        };


        class PhysicalMemory {
        private:
            int capacity;  // Capacity in GB

        public:
            // Default constructor with a default capacity value
            PhysicalMemory() : capacity(8) {}  // Default to 8 GB

            // Overloaded constructor for setting a specific capacity
            PhysicalMemory(int cap) : capacity(cap) {}

            // Getter
            int getCapacity() const { return capacity; }

            // Setter
            void setCapacity(int cap) { capacity = cap; }
        };


