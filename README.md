# 🕹️ Odisseia Temporal - 2D Platform Game

![Irmãos de Punho Logo](https://github.com/HunterNicky/Odisseia/raw/main/path_to_logo.png)  
*(Replace with actual logo path)*

A C++ platform game developed for the Programming Techniques course, implementing advanced OOP concepts and physics simulations in a time-traveling adventure.

## 🌟 Features
- **2 Unique Phases**: Medieval plains & lava castle environments
- **Local Multiplayer Support**: 1-2 players simultaneously
- **3 Enemy Types**: Warrior, Time Traveler (projectile-based), and Samurai Boss
- **Interactive Obstacles**: Slime (slowdown), Lava (damage), Crates
- **Save/Load System**: Persistent game state management
- **Dynamic Physics**: Verlet integration for movement calculations
- **STL Integration**: Custom template-based data structures
- **SFML Graphics**: Smooth animations and collision handling

## 🛠️ Technologies
**Core Programming:**
- C++17
- OOP Concepts:  
  - Polymorphism & Abstract Classes
  - Templates & Operator Overloading
  - Persistent Object Serialization
  - STL Containers

**Libraries:**
- SFML 2.6.2 (Graphics/Audio)
- Custom Physics Engine
- Quadtree Collision Detection

**Software Engineering:**
- UML Class Diagrams
- Design Patterns:  
  - State | Observer | Singleton | Strategy | Mediator

## 📥 Installation
1. **Prerequisites:**
   - SFML library installed
   - C++17 compatible compiler

2. **Build & Run:**
```bash
git clone https://github.com/HunterNicky/Odisseia.git
cd Odisseia
mkdir build && cd build
cmake ..
make
cd bin
./ODISSEIA_TEMPORALIS.exe
```

## 🎮 Gameplay
### **Controls:**
  - Player 1: AS (movement) | W (jump) | Space (attack)
  - Player 2: Arrow Keys (movement) | Up Arrow (jump) | Numpad Enter (attack)

### Phase 1: Medieval Plains ⚔️
  - Enemies: Warriors (Swordsmen) & Time Travelers (lasers)
  - Obstacles: Slime Puddles (slowdown effect) & Crates
  - Objective: Reach the portal at the end of the level

<img src="https://github.com/HunterNicky/Odisseia/blob/main/Castle.png?raw=true" width="400">

<img src="https://github.com/HunterNicky/Odisseia/blob/main/Castle%202.png?raw=true" width="400">

### Phase 2: Lava Castle 🌋🏰
  - Enemies: Samurai Boss (Invisible) & Time Travelers (lasers)
  - Obstacles: Lava Pits (damage effect) & Crates
  - Objective: Defeat the boss

<img src="https://github.com/HunterNicky/Odisseia/blob/main/Castle.png?raw=true" width="400">

<img src="https://github.com/HunterNicky/Odisseia/blob/main/Castle%202.png?raw=true" width="400">

### Key Mechanics:
  - Special jump: Hold jump key
  - Attack: Space (Player 1) | Numpad Enter (Player 2)
  - Stamina management
  - Score-based system

## 📊 UML Design

<img src="https://github.com/HunterNicky/Odisseia/blob/main/ClassDiagram.png?raw=true" width="800">

## ✅ Implemented Requirements

| Category | Implemented Features | Status |
|-------------|-------------|-------------|
| Game Modes | Single/Multiplayer, Phase Selection | ✅ |
| Enemies | 3 Unique Types (Warrior, Time Traveler, Samurai Boss) | ✅ |
| Physics | Gravity, Verlet Integration, Collision Detection | ✅ |
| Persistence	| Save/Load Game State, Score System | ✅ |
| Collision	| Quadtree Implementation | ✅ |

## OPP Concepts
- **Polymorphism**: Abstract classes for game entities
- **Inheritance**: Enemy classes inherit from Entity
- **Templates**: Custom data structures (Quadtree, Observer)
- **Serialization**: Save/Load game state

## 📚 Academic Context
Developed for *Programming Techniques* course, desmonstrating:
  - UML Design
  - Design Patterns
  - 90% functional coverage
