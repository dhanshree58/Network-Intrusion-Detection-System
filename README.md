# Network Intrusion Detection System (NIDS)

A **real-time Network Intrusion Detection System (NIDS)** developed in **C++** that monitors network traffic, detects common cyber attacks, and provides an interactive response mechanism. The system captures live packets using **libpcap**, analyzes network traffic, identifies suspicious activities, and allows administrators to block malicious IP addresses.

---

## Features

- 🚀 Real-time packet capture using **libpcap**
- 🔍 Detection of **DDoS attacks**
- 💉 Detection of **SQL Injection** payloads
- 📈 Traffic spike detection using a sliding time window
- 🌲 Trie-based signature matching for attack detection
- 🖥️ Interactive terminal dashboard
- 🛡️ Manual IP blocking through firewall integration
- ⚡ Lightweight and efficient implementation in C++

---

## Project Structure

```
NIDS/
├── detector.cpp          # Attack detection logic
├── detector.h
├── live_capture.cpp      # Live packet capture using libpcap
├── live_capture.h
├── prevention.cpp        # IP blocking implementation
├── prevention.h
├── simulator.cpp         # Simulated attack traffic
├── simulator.h
├── trie.cpp              # Trie implementation for payload matching
├── trie.h
├── ui.cpp                # Console dashboard
├── ui.h
├── main.cpp
└── README.md
```

---

## Detection Techniques

### 1. DDoS Detection

Tracks the number of requests received from each source IP.

- Maintains request count per IP
- Flags an IP when requests exceed the configured threshold
- Prompts the administrator for action

---

### 2. SQL Injection Detection

Uses a **Trie** to efficiently search for malicious payload signatures.

Example signatures:

- `DROP`
- `SELECT`
- `admin`

Payloads matching these signatures are reported as potential SQL Injection attacks.

---

### 3. Traffic Spike Detection

Uses a **sliding time window** to monitor incoming packets.

- Records packet timestamps
- Removes outdated entries
- Detects abnormal traffic surges within a short duration

---

## Workflow

```
Live Network Traffic
          │
          ▼
   Packet Capture (libpcap)
          │
          ▼
 Packet Analysis Engine
          │
 ┌────────┼─────────┐
 │        │         │
 ▼        ▼         ▼
DDoS   SQL Injection Traffic Spike
 │        │         │
 └────────┼─────────┘
          ▼
 Alert Generation
          │
          ▼
 Administrator Action
          │
 ┌────────┼─────────┐
 │        │         │
Block   Ignore   Monitor
```

---

## Technologies Used

| Technology | Purpose |
|------------|---------|
| C++ | Core implementation |
| libpcap | Live packet capture |
| STL | Data structures |
| Trie | Signature matching |
| Linux Firewall (iptables) | IP blocking |

---

## Algorithms & Data Structures

- Trie
- Hash Map (`unordered_map`)
- Queue / Deque
- Sliding Window Algorithm
- Signature-based Detection

---

## How It Works

1. Capture packets from the network interface.
2. Extract the source IP address.
3. Analyze packet data.
4. Detect malicious behavior.
5. Display attack alerts.
6. Allow administrator to:
   - Block IP
   - Ignore
   - Continue monitoring

---

## Building the Project

### Install Dependencies

Ubuntu/Debian

```bash
sudo apt update
sudo apt install libpcap-dev
```

### Compile

```bash
g++ *.cpp -o nids -lpcap
```

### Run

```bash
sudo ./nids
```

> Root privileges are required for live packet capture.

---

## Sample Output

```
Capturing real traffic...

ALERT: DDoS Attack
Source IP : 192.168.1.10

1. Block IP
2. Ignore
3. Monitor

Choice:
```

---

## Learning Outcomes

This project demonstrates practical implementation of:

- Network Security
- Intrusion Detection Systems
- Packet Sniffing
- Real-time Traffic Analysis
- Signature-based Detection
- Firewall Integration
- Efficient Data Structures
- Linux Networking
- C++ System Programming

---
