# 🎹 MotionKeys — Contactless Piano for Accessible Music

> A gesture-based contactless piano built in C using OpenCV, designed for people with motor impairments.

![GitHub repo size](https://img.shields.io/github/repo-size/TanyaPaulA/motionkeys)
![GitHub contributors](https://img.shields.io/github/contributors/TanyaPaulA/motionkeys)
![GitHub last commit](https://img.shields.io/github/last-commit/TanyaPaulA/motionkeys)

---

## 🎯 Problem Statement

Over 1.3 billion people worldwide live with motor disabilities. Traditional musical instruments require precise touch, grip strength, and bilateral coordination — making music completely inaccessible to many.

**MotionKeys solves this.** By using just a webcam and a printed piano sheet, anyone can play music without touching anything. No expensive hardware. No special equipment. Just a camera and a piece of paper.

---

## 💡 What is MotionKeys?

MotionKeys is a **contactless, camera-based piano** built entirely in C using the OpenCV library.

- Print a piano keyboard on A4 paper
- Place it flat on your desk
- Point your webcam at it
- Hover your finger over any key
- The note plays instantly 🎵

---

## ✨ Features

| Feature | Description |
|---|---|
| 🎵 Free Play | Hover finger over key → note plays instantly |
| ⏱ Dwell Mode | Hold finger 1 second → plays (tremor-safe) |
| 🤚 One-Hand Mode | Full octave on one side for single-limb users |
| ⏺ Record | Press R to record your melody |
| ▶ Playback | Press P to replay what you played |
| 💾 Export | Press S to save melody as melody.txt |
| 📊 BPM Display | Live beats-per-minute shown as you play |
| 🔧 Zone Resize | Press +/- to grow or shrink key zones |

---

## 🏗️ Project Architecture
```
Camera Feed → HSV Skin Masking → Fingertip Detection → Key Mapping → Audio Output
```

| Module | File | Description |
|---|---|---|
| Integration | main.c | Connects all modules, webcam loop, keyboard controls |
| Skin Detection | detector.c / detector.h | HSV masking, contour detection, fingertip localization |
| Key Mapping & Audio | piano.c / piano.h | Key regions, note frequencies, Beep() playback |
| Recording | recorder.c / recorder.h | Record, playback, BPM, melody export |
| Website | web/index.html | Project landing page hosted on GitHub Pages |

---

## 🛠️ Tech Stack

- **Language** — C (C99)
- **Library** — OpenCV (C API)
- **Audio** — Beep() on Windows / beep on Linux
- **Build** — GCC + Makefile
- **Version Control** — Git + GitHub

---

## ⚙️ Setup & Installation

### Prerequisites
- GCC compiler
- OpenCV 4.x

### Linux
```bash
sudo apt-get install libopencv-dev gcc
sudo apt-get install beep
```

### Windows
- Install MSYS2 from msys2.org
- Open MSYS2 terminal and run:
```bash
pacman -S mingw-w64-x86_64-opencv mingw-w64-x86_64-gcc
```

---

## 🚀 How to Run

### Clone the repo
```bash
git clone https://github.com/TanyaPaulA/motionkeys.git
cd motionkeys
```

### Compile
```bash
make
```

### Run
```bash
./motionkeys
```

---

## ⌨️ Controls

| Key | Action |
|---|---|
| R | Start recording |
| T | Stop recording |
| P | Playback session |
| S | Save melody to melody.txt |
| Q | Quit |

---

## 📁 Folder Structure
```
motionkeys/
├── src/
│   ├── main.c
│   ├── piano.c + piano.h
│   ├── detector.c + detector.h
│   └── recorder.c + recorder.h
├── web/
│   └── index.html
├── assets/
│   └── piano_template.png
├── Makefile
└── README.md
```

---

## 👥 Team

| Name | Role | Module |
|---|---|---|
| Tanya Paul A | Team Lead | main.c — Integration |
| Sharmistha M| Member | detector.c — Skin Detection |
| Monish Kumar Thasma Omprakash | Member | piano.c — Key Mapping & Audio |
| Papireddy Shreejani | Member | recorder.c — Recording & Playback |
| Sanjay Thandeeswaran | Member | web/index.html — Website |

---

## 🎓 About

**Course** — Structured & Object Oriented Programming (C Language)

**Institution** — VIT Vellore

**Project Type** — Case Study — Real World Accessibility Tool

---

## 🌐 Website

👉 [View Project Website](https://TanyaPaulA.github.io/motionkeys)

---

*Made with ❤️ by Team MotionKeys — VIT Vellore*
```