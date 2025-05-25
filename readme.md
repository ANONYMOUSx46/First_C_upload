# System Information Retrieval

A lightweight **C** program to retrieve **OS version** and **hostname** for both **Windows** and **Linux** environments.

## 📌 Features
- Detects and displays the **Operating System** version.
- Retrieves and prints the **hostname** of the device.
- Supports both **Windows** and **Linux** platforms.
- Uses native system API calls for **efficient execution**.

## 🚀 Installation & Compilation

### **Windows**
Ensure you have `gcc` installed (via MinGW or similar). Compile using:

```bash
gcc quick_sysinfo2.c -o system_info.exe
```
### Run with
```bash
system_info.exe
```

### **Linux**
Compile using:

```bash
gcc quick_sysinfo2.c -o system_info
```

Run with:
```bash
./system_info
```
