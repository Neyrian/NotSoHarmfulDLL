# NotSoHarmfulDLL

## 📌 Overview

`NotSoHarmfulDLL` is a **Windows DLL** that simulates **malware-like behavior** for **cybersecurity research and training**. This module is inspired by the **Pikabot malware campaign** and replicates some of its **anti-analysis techniques**, including:

✅ **Checking system language** (exits if Russian `ru-RU` or Ukrainian `uk-UA` is detected).\
✅ **Ensuring a single instance** by creating a **hardcoded mutex** (`{A77FC435-31B6-4687-902D-24153579C738}`).\
✅ **Designed for educational use** and does **not perform harmful actions**.

🔗 Research References:

- [Trend Micro: Pikabot Spam Wave](https://www.trendmicro.com/en_us/research/24/a/a-look-into-pikabot-spam-wave-campaign.html)
- [MITRE ATT&CK: Pikabot Campaign (C0037)](https://attack.mitre.org/campaigns/C0037/)

---

## ⚠️ Disclaimer

🚨 **This project is for educational purposes only.** It does not contain malicious code but simulates **anti-analysis techniques** used by real malware. Use responsibly in **authorized research environments**.

---

## 🛠 Features

### ✅ **1. Language Check (Pikabot Anti-Analysis Simulation)**

- Uses `GetUserDefaultUILanguage()` to detect **system language**.
- If the system language is **Russian (0x0419) or Ukrainian (0x0422)**, execution is stopped.
- Write output to a text file before exiting.

### ✅ **2. Mutex Lock (Ensures Single Instance)**

- Uses `CreateMutexA()` to **prevent multiple instances** of the DLL from running.
- If another instance is found, execution **immediately exits**.

---

## 🔧 Compilation (Using `x86_64-w64-mingw32-gcc` on Linux)

To compile the DLL on a **Linux system (Kali/WSL)**:

```bash
x86_64-w64-mingw32-gcc -shared -o notsoharmfuldll.dll notsoharmfuldll.c -Wall
```

✔ This generates ``, which can be executed on **Windows**.

---

## 🚀 Running the DLL

To execute the DLL on **Windows**, run:

```powershell
rundll32.exe notsoharmfuldll.dll,RunNotSoHarmful
```

---

## 🛡 Detection & Defense (Blue Team)

### ✅ **Detection (Windows Event Logs & Sysmon)**

- **Monitor Mutex Creation** (`Sysmon Event ID 6`)
- **Detect Rundll32 Execution** (`Sysmon Event ID 1`)
- **Look for Language-Based Evasion** in `Event ID 4104` (PowerShell Script Logging)

### ✅ **Mitigation Strategies**

- Restrict execution of `rundll32` for unsigned DLLs
- **Detect suspicious mutex names** using `Get-Process` in PowerShell:
  ```powershell
  Get-Process | Where-Object { $_.MainWindowTitle -match "Mutex" }
  ```

---

## 🏴‍☠️ Red Team Use Cases

- **Simulate malware behavior** in controlled environments.
- **Test security solutions** (EDR, SIEM) against **Pikabot-like evasion techniques**.
- **Enhance Blue Team detection rules** by observing behavioral patterns.

---

## 📜 License

This project is licensed under the **MIT License**. See `LICENSE` for details.

👨‍💻 Created for **cybersecurity research & education**. Use responsibly! 🚀
