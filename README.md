# 🎮 DSA World — Advanced C++ Algorithm Visualizer

> **4th Year Resume-Ready Project** | Interactive DSA Learning Platform with Mario Pixel Art Theme

[![Live Demo](https://img.shields.io/badge/Live-Demo-brightgreen)](https://dsa-world.vercel.app)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?logo=html5&logoColor=white)
![CSS3](https://img.shields.io/badge/CSS3-1572B6?logo=css3&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?logo=javascript&logoColor=black)
![C++17](https://img.shields.io/badge/C++-17-00599C?logo=cplusplus&logoColor=white)

---

## 🌟 Features

### 11 Interactive DSA Worlds
| World | Topic | Complexity |
|-------|-------|-----------|
| W01 | Linked List | O(1) front |
| W02 | Stack & Queue | O(1) all ops |
| W03 | Binary Search Tree | O(log n) |
| W04 | **AVL Self-Balancing Tree** ★ | O(log n) guaranteed |
| W05 | **Graph + Dijkstra's Algorithm** ★ | O((V+E) log V) |
| W06 | **Min/Max Heap + Heap Sort** ★ | O(log n) |
| W07 | **Hash Map with Chaining** ★ | O(1) average |
| W08 | **Trie Prefix Tree** ★ | O(m) per op |
| W09 | Sorting x6 Algorithms | Step-through mode |
| W10 | Linear + Binary Search | Step-through mode |
| W11 | Dynamic Programming (4 problems) | Memoization + Tabulation |

### 3 Bonus AI-Powered Features
- **Quiz Mode** — 20 DSA questions with timer, streak bonuses, S/A/B/C/D ranking
- **AI Code Generator** — Generate C++ / Python / Java code for any DS (Claude AI)
- **DSA AI Chatbot** — Ask anything about algorithms, complexity, viva questions

### Authentication System
- Sign Up / Login with localStorage persistence
- Session restore (24hr auto-login)
- Guest login
- Password strength meter + live validation

---

## 🚀 Deployment

### Vercel (Recommended)
1. Fork this repo
2. Go to [vercel.com](https://vercel.com) → New Project → Import repo
3. Framework: **Other** | Root: `/`
4. Deploy ✓

### GitHub Pages
1. Go to repo Settings → Pages
2. Source: **Deploy from branch** → `main` → `/root`
3. Live at `https://yourusername.github.io/dsa-world`

---

## 📁 File Structure
```
dsa-world/
├── index.html              # Login & platform showcase page
├── DSA_World_Final.html    # Main game — all 14 worlds
├── dsa_cpp_project.cpp     # C++17 source code (compilable)
├── DSA_CPP_Viva_Guide.pdf  # Viva preparation guide
└── README.md               # This file
```

---

## 🛠️ Run Locally
```bash
# Clone
git clone https://github.com/yourusername/dsa-world.git
cd dsa-world

# Just open in browser — no build tools needed!
open index.html

# Or compile the C++ separately
g++ -std=c++17 -O2 -o dsa dsa_cpp_project.cpp && ./dsa
```

---

## 💻 Tech Stack
- **Frontend:** Pure HTML5 + CSS3 + Vanilla JavaScript (zero frameworks)
- **C++ Backend:** C++17 with templates, recursion, RAII memory management
- **AI Features:** Claude Sonnet API (claude-sonnet-4-20250514)
- **Theme:** Press Start 2P + VT323 pixel art fonts
- **Auth:** localStorage-based session management
- **Deployment:** Static site — works on any CDN

---

## 📊 Project Stats
- **14 Worlds** (11 DSA + 3 Bonus)
- **20+ Algorithms** implemented from scratch
- **102 KB** main app — single HTML file, zero dependencies
- **3 AI Tools** powered by Claude API
- **C++17** compiled binary included

---

## 🎓 Resume Bullets

**SDE / Backend:**
> Engineered advanced DSA platform implementing 11 data structures from scratch in C++17 including self-balancing AVL tree, min/max heap, hash map with chaining collision resolution, and trie for prefix search. Implemented Dijkstra's shortest path with priority queue optimization.

**Frontend / Full-Stack:**
> Built interactive algorithm visualizer with step-through execution, live performance metrics, and custom user input. Features dual visualization modes, speed-controlled animations, and gamified pixel-art UI in pure vanilla JS — zero frameworks, 102KB single-file application.

---

## ⚠️ Notes
- **AI features** (Code Generator, Chatbot) require Claude API access — work natively in Claude.ai artifact viewer
- **Authentication** uses browser localStorage — demo-grade, not production auth
- **C++ source** compiles with `g++ -std=c++17` on any system

---

*Built with ❤️ as a 4th Year CS Project | DSA World v2.0*
