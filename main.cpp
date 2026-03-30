#include <iostream>

// ==========================================
// 1. Logic for Windows OS
// ==========================================
#ifdef _WIN32
#include <windows.h>

void printMemoryStatus() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    
    DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
    std::cout << "[Windows] Total System RAM: " << totalPhysMem / (1024 * 1024) << " MB" << std::endl;
}

// ==========================================
// 2. Logic for Linux OS 
// ==========================================
#elif __linux__
#include <sys/sysinfo.h>

void printMemoryStatus() {
    struct sysinfo memInfo;
    sysinfo(&memInfo);
    
    long long totalPhysMem = memInfo.totalram;
    totalPhysMem *= memInfo.mem_unit; // Convert to exact bytes
    
    std::cout << "[Linux] Total System RAM: " << totalPhysMem / (1024 * 1024) << " MB" << std::endl;
}

// ==========================================
// 3. Logic for macOS (Apple)
// ==========================================
#elif __APPLE__
#include <sys/types.h>
#include <sys/sysctl.h>

void printMemoryStatus() {
    int mib[2] = { CTL_HW, HW_MEMSIZE };
    int64_t physical_memory = 0;
    size_t length = sizeof(int64_t);
    sysctl(mib, 2, &physical_memory, &length, NULL, 0);
    
    std::cout << "[macOS] Total System RAM: " << physical_memory / (1024 * 1024) << " MB" << std::endl;
}

// ==========================================
// 4. Fallback for Unknown OS
// ==========================================
#else
void printMemoryStatus() {
    std::cout << "Total System RAM: Unsupported Operating System." << std::endl;
}
#endif

// ==========================================
// Main Execution
// ==========================================
int main() {
    std::cout << "--- Universal System Monitor ---" << std::endl;
    printMemoryStatus();
    
    return 0; // Exit successfully
}