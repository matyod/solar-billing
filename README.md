> **Note:** This is a legacy academic project from 2023.
> > It is preserved here to demonstrate fundamental knowledge of programming learned during finishing this coursework.

# Solar Billing - Energy Consumption Calculator

This is a terminal-based C++ application for calculating energy bills for residential and commercial customers. The program allows users to enter account details, select consumption codes, input energy usage, and receive a calculated bill. Multiple bills can be processed in one session. This project was developed as part of the academic coursework for **UNITAR International University**.

---

## Academic Context

| Attribute       | Details                                                    |
| :-------------- | :--------------------------------------------------------- |
| **Institution** | UNITAR International University, Malaysia                  |
| **Programme**   | Bachelor of Information Technology                         |
| **Major**       | Software Engineering                                       |
| **Course**      | ITWB2033: Programming Principles and Techniques (May 2023) |
| **Assignment**  | Assignment 1                                               |

## Features

* Enter account number, consumption code, and kWh usage.
* Calculates bill based on usage and code:
  * Residential (`h`): RM 0.218/kWh for first 200 kWh, RM 0.526/kWh after.
  * Commercial (`c`): RM 0.10/kWh for first 10,000 kWh, RM 0.25/kWh after.
* View a summary of all bills and total amount due.

## Quick Start

### Prerequisites
* **Windows:** Download **[MSYS2](https://www.msys2.org/)**. Follow the guide to add the `bin` folder to your PATH.
* **macOS:** Install Xcode Command Line Tools by running: `xcode-select --install`
* **Linux:** Install the build-essential package via your package manager: `sudo apt update && sudo apt install build-essential`

### Running the Program
1. Clone the Repository
    ```sh
    git clone https://github.com/your-username/solar-billing.git
    cd solar-billing
    ```

2. Compile the source code from the root directory:
    ```sh
    g++ main.cpp -o solar-billing
    ./solar-billing
    ```

3. Run:
    ```sh
    ./solar-billing
    ```

Follow the prompts in the terminal to calculate energy bills.
