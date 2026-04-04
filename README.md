# 🎹 MotionKeys — Contactless Piano for Accessible Music

> A gesture-based contactless piano built in C/C++ using OpenCV, designed for people with motor impairments.

![GitHub repo size](https://img.shields.io/github/repo-size/TanyaPaulA/motionkeys)
![GitHub contributors](https://img.shields.io/github/contributors/TanyaPaulA/motionkeys)
![GitHub last commit](https://img.shields.io/github/last-commit/TanyaPaulA/motionkeys)

---

## 🎯 Problem Statement

Over 1.3 billion people worldwide live with motor disabilities. Traditional musical instruments require precise touch, grip strength, and bilateral coordination — making music completely inaccessible to many.

**MotionKeys solves this.** By using just a webcam and a printed piano sheet, anyone can play music without touching anything. No expensive hardware. No special equipment. No AI. No datasets. Just a camera and a piece of paper.

---

## 💡 What is MotionKeys?

MotionKeys is a **contactless, camera-based piano** built in C/C++ using the OpenCV 4.13 library. It uses pure mathematical HSV color masking and geometric coordinate detection — no machine learning involved.

- Print a piano keyboard on A4 paper
- Place it flat on your desk
- Point your webcam at it
- Hover your finger over any key
- The note plays instantly 🎵

---

## 🌟 What Makes This Novel?

- **No AI or ML** — unlike similar projects built in Python using MediaPipe or TensorFlow, MotionKeys uses only pure math and color detection
- **Built in C/C++** — rare for computer vision projects, most are Python-based
- **Printed paper as instrument** — zero hardware cost beyond a webcam
- **Accessibility-first design** — Dwell Mode for tremor patients, One-Hand Mode for single-limb users
- **Music therapy ready** — session recording and melody export for therapeutic use

---

## ✨ Features

| Feature | Description |
|---|---|
| 🎵 Free Play | Hover finger over key and note plays instantly |
| ⏱ Dwell Mode | Hold finger 1 second and it plays, tremor-safe |
| 🤚 One-Hand Mode | Full octave on one side for single-limb users |
| ⏺ Record | Press R to record your melody |
| ▶ Playback | Press P to replay what you played |
| 💾 Export | Press S to save melody as melody.txt |
| 📊 BPM Display | Live beats-per-minute shown as you play |
| 🔧 Zone Resize | Press + or - to grow or shrink key zones |

---

## 🏗️ Project Architecture

Camera Feed → HSV Skin Masking → Fingertip Detection → Key Mapping → Audio Output

| Module | File | Language | Description |
|---|---|---|---|
| Integration | main.c | C++ | Webcam loop, display, keyboard controls |
| Skin Detection | detector.c and detector.h | C++ OpenCV | HSV masking, contour detection, fingertip localization |
| Key Mapping and Audio | piano.c and piano.h | Pure C | Key regions, note frequencies, Beep() playback |
| Recording | recorder.c and recorder.h | Pure C | Record, playback, BPM, melody export |
| Website | web/index.html | HTML CSS JS | Project landing page on GitHub Pages |

---

## 🛠️ Tech Stack

- Language — C and C++ with OpenCV C++ API for camera and Pure C for all logic
- Library — OpenCV 4.13
- Audio — Beep() on Windows
- Build — G++ and Makefile with mingw32-make on Windows
- Version Control — Git and GitHub

---

## ⚙️ Setup and Installation

### Prerequisites
- MSYS2 on Windows or GCC on Linux
- OpenCV 4.x

### Windows using MSYS2
- Install MSYS2 from msys2.org
- Open MSYS2 terminal and run:

pacman -Syu
pacman -S mingw-w64-x86_64-opencv mingw-w64-x86_64-gcc mingw-w64-x86_64-pkg-config mingw-w64-x86_64-make mingw-w64-x86_64-qt6-base

- Add your MSYS2 mingw64 bin folder to system PATH
- Copy required Qt6 and OpenCV DLLs to project folder

### Linux
sudo apt-get install libopencv-dev gcc

---

## 🚀 How to Run

Clone the repo:
git clone https://github.com/TanyaPaulA/motionkeys.git
cd motionkeys

Compile on Windows:
mingw32-make

Compile on Linux:
make

Run:
./motionkeys.exe

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

motionkeys/
├── src/
│   ├── main.c
│   ├── piano.c and piano.h
│   ├── detector.c and detector.h
│   └── recorder.c and recorder.h
├── web/
│   └── index.html
├── assets/
│   └── piano_template.png
├── Makefile
└── README.md

---

## 👥 Team

| Name | Role | Module |
|---|---|---|
| Tanya Paul A | Team Lead | main.c — Integration |
| Sharmistha M | Member | detector.c — Skin Detection |
| Monish Kumar Thasma Omprakash | Member | piano.c — Key Mapping and Audio |
| Papireddy Shreejani | Member | recorder.c — Recording and Playback |
| Sanjay Thandeeswaran | Member | web/index.html — Website |

---

## 🎓 About

Course — Structured and Object Oriented Programming in C Language

Institution — VIT Vellore

Project Type — Case Study — Real World Accessibility Tool

---

## 🌐 Website

View Project Website: https://tanyapaula.github.io/motionkeys

---

Made with ❤️ by Team MotionKeys — VIT Vellore

