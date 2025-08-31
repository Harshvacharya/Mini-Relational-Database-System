# Mini Relational Database System (C++)

This project is a **lightweight implementation of a Relational Database** using C++.  
It supports the **core relational algebra operations** and provides a simple **console-based UI** for table management and query execution.  

The project is structured into modular components with separate files for the API, attribute types, relational operators, join, and user interface.  

---

## 📂 Project Structure

```
.
├── rdb.h              # Header file with all library API declarations
├── rdb-basics.cpp     # Implementation of basic relational algebra operators
├── rdb-join.cpp       # Implementation of natural join operator
├── rdb-attr.cpp       # Implementations of supported attribute types (int, float, string, etc.)
└── rdb-main.cpp       # Console-based UI for interacting with the database
```

---

## ✨ Features

- **Relational Algebra Operations**
  - Union  
  - Difference  
  - Cartesian Product  
  - Projection  
  - Selection (using DNF formula)  
  - Rename  
- **Additional Operator**
  - Natural Join (built using primitive operations)  
- **Attribute Types**
  - Integer, Float, and String attributes with overloaded comparison operators  
- **Console UI**
  - Create new empty tables with schema  
  - Delete existing tables  
  - Add records to tables  
  - Print tables in a formatted manner  
  - Perform relational algebra operations interactively  

---

## ⚙️ Compilation & Execution

### 1. Clone the Repository
```bash
git clone https://github.com/your-username/mini-rdbms.git
cd mini-rdbms
```

### 2. Compile
Use `g++` (or any modern C++ compiler) to build:
```bash
g++ rdb-basics.cpp rdb-join.cpp rdb-attr.cpp rdb-main.cpp -o rdbms
```

### 3. Run
```bash
./rdbms
```

---

## 🖥️ Example Usage

- **Create a Table**  
  Enter schema interactively (attribute names and types).  

- **Insert Records**  
  Add rows to the table via console prompts.  

- **Perform Queries**  
  Use the menu options to run union, difference, projection, selection, Cartesian product, or natural join on tables.  

- **Print Results**  
  Query results are displayed in a formatted table.  

---

## 📖 References

- [Relational Database (Wikipedia)](https://en.wikipedia.org/wiki/Relational_database)  
- [Relational Algebra (Wikipedia)](https://en.wikipedia.org/wiki/Relational_algebra)  

---
