# RPG Character Management System

**Course:** CS 1337 – Summer 2026  
**Project Title:** Term Project - RPG Character Management System  

---

## 📋 Overview

The **RPG Character Management System** is a console-based C++ application designed to manage and simulate interactions between fantasy characters. The application emphasizes Object-Oriented Programming (OOP) design, data management, dynamic memory handling, file I/O operations, and basic searching and sorting algorithms.

---

## 📑 Table of Contents

- [Features](#-features)
- [Class Hierarchy & Architecture](#-class-hierarchy--architecture)
- [Program Requirements & Functionality](#-program-requirements--functionality)
- [File I/O & Data Structure](#-file-io--data-structure)
- [Getting Started](#-getting-started)
  - [Prerequisites](#prerequisites)
  - [Compilation & Execution](#compilation--execution)
- [File Organization & Submission](#-file-organization--submission)
- [License / Academic Integrity](#-license--academic-integrity)

---

## ✨ Features

- **Character Creation:** Choose from three unique classes (Knight, Mage, Doctor) with initialized base attributes.
- **Character Roster:** Display all active characters along with detailed stats and statuses.
- **Training System:** Upgrade character stats (Level, HP, Attack, Defense) through training sessions.
- **Turn-Based Battle Simulation:** Simulate battles using character stats and specialized combat calculations with dynamic turn actions.
- **Healing System:** Allow Doctor characters to restore Health Points (HP) of other party members.
- **Character Management:** Delete characters or search/sort them by Level, Name, or Attack Power.
- **Data Persistence:** Save and Load character states using standard file stream operations (`characters.txt`).

---

## 🏗 Class Hierarchy & Architecture

The application relies on inheritance and dynamic polymorphism to execute class-specific abilities:

```
               [ Character ]  (Base Class)
              /      |      \
             /       |       \
     [ Knight ]  [ Mage ]  [ Doctor ]
```

### Character Class Attributes
Each character tracks the following core attributes:
- **Name** (`std::string`)
- **Level** (`int`)
- **Health Points (HP)** (`int`)
- **Attack Power** (`int`)
- **Defense** (`int`)
- **Experience Points (EXP)** (`int`)
- **Status** (`Alive` / `Defeated`)

### Special Class Skills (Polymorphic)
Each subclass overrides the `virtual void specialSkill()` method:
- 🛡️ **Knight:** `Shield Block` – Reduces incoming damage during combat.
- 🔥 **Mage:** `Fireball` – Unleashes high-damage magic attacks with a critical hit multiplier chance.
- 🩺 **Doctor:** `Heal` – Restores HP to targeted team members.

---

## 🛠 Program Requirements & Functionality

### Main Menu Interface
```text
=========================
RPG CHARACTER MANAGER
=========================
1. Create Character
2. View Characters
3. Train Character
4. Battle Simulation
5. Heal Character
6. Delete Character
7. Save Game
8. Load Game
9. Exit
```

### Technical Specifications
- **Functions:** Implements at least 12 distinct functions (e.g., `displayMenu()`, `createCharacter()`, `viewCharacters()`, `battle()`, `heal()`, `train()`, `saveFile()`, `loadFile()`, `findCharacter()`, `deleteCharacter()`, `levelUp()`, `calculateDamage()`).
- **Dynamic Array & Pointers:** Manages character instances using polymorphic dynamically allocated pointers stored in an array:
  ```cpp
  Character* party[10];
  ```
- **Sorting & Searching:** Includes utility modules to sort party members by Level, Name, or Attack Power, and search by Name or Class.

---

## 💾 File I/O & Data Structure

Characters are persisted to a plain text file named `characters.txt`. The system serializes character traits upon selection of the **Save Game** option and reconstructs derived objects (Knight, Mage, or Doctor) upon choosing **Load Game**.

---
