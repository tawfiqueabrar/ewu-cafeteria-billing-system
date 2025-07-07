# 🍽️ EWU Cafeteria Billing System

A terminal-based C program for East West University Cafeteria that allows customers to place orders, generate printed receipts, and view their previous bill history. It simulates a simple point-of-sale system for food items categorized into breakfast, lunch, snacks, beverages, and specials.

## 🚀 Features

- 👤 Customer name input
- 🧾 Category-wise food menu display
- ✅ Select and order multiple items
- 💰 Automatic total calculation
- 📄 Receipt generation (saved to `receipt.txt`)
- 🕘 View previous bill anytime

---

## 🏷️ Categories & Menu

### 🥐 Breakfast
- Toasted Bread with Jelly & Butter — Tk 25
- Paratha/Rooti Combo — Tk 42.5
- Boiled Egg — Tk 15

### 🍛 Lunch & Dinner
- Rice + Vegetable — Tk 50  
- Rice + Egg — Tk 72.5  
- Chicken Tehari — Tk 100  
- Biriyani/Polao — Tk 135  
_(and more...)_

### 🍟 Snacks
- Singara/Samucha/Egg Chop — Tk 15  
- Chicken Pasta — Tk 100  
- Rolls/Burgers — Tk 45

### ☕ Beverages
- Tea, Coffee, Cold Coffee, Milkshakes  
- Prices range from Tk 10–75

### 🍔 Smokey Dine Specials
- Mini & Medium Set Menus, Special Burgers, Lollipop/Wings

---

## 🛠️ How to Compile & Run

### Step 1: Compile the program
```bash
gcc main.c -o cafeteria
