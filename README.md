# 🖥️ cpp-sysmon
A lightweight, cross-platform system resource monitor written in C++ that interacts directly with the Operating System kernel.

## 🚀 Features
- **Auto-Detection:** Automatically detects whether you are running on Windows, Linux, or macOS.
- **Hardware Interaction:** Fetches real-time physical RAM data using native system calls.
- **Professional Standards:** Written without `using namespace std` to follow industry best practices.

## 🛠️ Requirements
- **Linux:** GCC/G++ compiler (sudo dnf install gcc-c++)
- **Windows:** MSVC or MinGW
- **macOS:** Xcode Command Line Tools

## 💻 How to Run

1. **Clone the repository:**
`git clone https://github.com/andraokta/cpp-sysmon.git`

2. **Compile the source code:**
`g++ main.cpp -o sysmon`

3. **Execute the program:**
`./sysmon`

## 🧠 Technical Overview
This project utilizes **C++ Preprocessor Directives** to handle cross-platform compatibility at compile-time:

- **On Linux:** It uses `sys/sysinfo.h` to access the kernel's memory statistics.
- **On Windows:** It calls `GlobalMemoryStatusEx` from the Windows API.
- **On macOS:** It employs `sysctl` to fetch hardware information from the Apple kernel.

---
*Created by [Andra Okta](https://github.com/andraokta) - Informatics Engineering Student.*