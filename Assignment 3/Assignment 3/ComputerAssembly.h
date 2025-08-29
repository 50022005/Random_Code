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
#include"ComputerAssembly_Parts.h"
        class ComputerAssembly {
        private:
            Computer computer;
            GraphicsCard gpu;
            StorageDevice storage;
            NetworkCard network;
            PowerSupply psu;
            Battery battery;
            Case CASE;
            double totalPrice;

        public:
            // Default constructor initializes components with default values and calculates total price
            ComputerAssembly()
                : computer(), gpu(), storage(), network(), psu(), battery(), CASE() {
                calculateTotalPrice();
            }

            // Overloaded constructor to initialize components with specific values
            ComputerAssembly(const Computer& c, const GraphicsCard& g,
                const StorageDevice& s, const NetworkCard& n, const PowerSupply& p,
                const Battery& b, const Case& case_)
                : computer(c), gpu(g), storage(s), network(n), psu(p), battery(b), CASE(case_) {
                calculateTotalPrice();
            }

            // Function to calculate the total price of all components
            void calculateTotalPrice() {
                totalPrice = computer.getPrice() + gpu.getPrice() +
                    storage.getPrice() + network.getPrice() + psu.getPrice() +
                    +CASE.getPrice();
            }

            // Getters
            Computer getComputer() const { return computer; }
            GraphicsCard getGraphicsCard() const { return gpu; }
            StorageDevice getStorageDevice() const { return storage; }
            NetworkCard getNetworkCard() const { return network; }
            PowerSupply getPowerSupply() const { return psu; }
            Battery getBattery() const { return battery; }
            Case getCase() const { return CASE; }
            double getTotalPrice() const { return totalPrice; }

            // Setters
            void setComputer(const Computer& c) { computer = c; calculateTotalPrice(); }
            void setGraphicsCard(const GraphicsCard& g) { gpu = g; calculateTotalPrice(); }
            void setStorageDevice(const StorageDevice& s) { storage = s; calculateTotalPrice(); }
            void setNetworkCard(const NetworkCard& n) { network = n; calculateTotalPrice(); }
            void setPowerSupply(const PowerSupply& p) { psu = p; calculateTotalPrice(); }
            void setBattery(const Battery& b) { battery = b; calculateTotalPrice(); }
            void setCase(const Case& case_) { CASE = case_; calculateTotalPrice(); }
        };
