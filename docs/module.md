### **What is a Module in Node.js?**

A **module** is a **reusable piece of code** that can be imported and exported between different files in a project. Modules help in **code organization, maintainability, and reusability** by breaking large programs into smaller, manageable parts.

---

## **1️⃣ Why Use Modules?**

✅ **Encapsulation** – Prevents variables/functions from polluting the global scope.  
✅ **Reusability** – Write once, use multiple times.  
✅ **Maintainability** – Easier debugging and modifications.  
✅ **Performance** – Loads only when needed, reducing memory usage.

---

## **2️⃣ Types of Modules in Node.js**

Node.js has **three types** of modules:

### **(A) Core Modules (Built-in)**

-   Pre-installed modules in Node.js (e.g., `fs`, `http`, `path`).
-   No need for installation.

**Example: Using the `fs` module**

```javascript
const fs = require("fs"); // CommonJS

fs.writeFileSync("hello.txt", "Hello, Node.js!");
console.log("File created");
```

---

### **(B) Local Modules (User-defined)**

-   Created within a project for custom functionality.
-   Can be exported and reused in multiple files.

**Example: Creating a local module**
**File: `math.js`**

```javascript
module.exports.add = (a, b) => a + b;
module.exports.subtract = (a, b) => a - b;
```

**File: `app.js`**

```javascript
const math = require("./math");

console.log(math.add(5, 3)); // Output: 8
```

---

### **(C) Third-Party Modules (Installed via npm)**

-   External modules from npm (e.g., `express`, `lodash`).
-   Must be installed before use.

**Example: Using `express`**

```javascript
const express = require("express");
const app = express();

app.get("/", (req, res) => res.send("Hello World!"));

app.listen(3000, () => console.log("Server running on port 3000"));
```

> Install using `npm install express` before running the code.

---

## **3️⃣ How Modules Work in Node.js?**

Node.js uses the **CommonJS module system** by default.  
A module works by:

1. **Defining functions/variables** inside a file.
2. **Exporting them using `module.exports` or `exports`.**
3. **Importing them in another file using `require()` (CommonJS) or `import` (ESM).**

---

## **4️⃣ CommonJS vs ESM for Modules**

| Feature                | CommonJS (`require()`)   | ESM (`import`)                        |
| ---------------------- | ------------------------ | ------------------------------------- |
| **Default in Node.js** | ✅ Yes                   | ❌ No (must enable in `package.json`) |
| **Syntax**             | `const x = require('x')` | `import x from 'x'`                   |
| **Export Syntax**      | `module.exports = {...}` | `export default` or `export {}`       |
| **Load Type**          | **Synchronous**          | **Asynchronous**                      |

---

## **5️⃣ How to Use ES Modules?**

To use ECMAScript Modules (ESM) in Node.js, add `"type": "module"` in `package.json`:

```json
{
    "type": "module"
}
```

Then, use `import/export`:

```javascript
// math.mjs
export function add(a, b) {
    return a + b;
}
```

```javascript
// app.mjs
import { add } from "./math.mjs";
console.log(add(5, 3)); // Output: 8
```

---

## **6️⃣ Key Takeaways**

✅ **A module is just a file that exports functions, objects, or variables.**  
✅ **Node.js has Core Modules, Local Modules, and Third-Party Modules.**  
✅ **CommonJS (`require()`) is synchronous, while ESM (`import`) is asynchronous.**

# **Modular System in Node.js**

The **modular system** in Node.js helps organize code into reusable, maintainable pieces. Node.js supports two main module systems:

1. **CommonJS (CJS)** – Default module system in Node.js
2. **ECMAScript Modules (ESM)** – Modern JavaScript module system

---

## **1️⃣ CommonJS (CJS) – Default in Node.js**

-   Uses `require()` for importing modules.
-   Uses `module.exports` or `exports` for exporting.
-   Synchronous module loading.
-   Best for backend applications.

### **How to Use CommonJS?**

**File: `math.js` (Exporting Module)**

```javascript
// Using module.exports
module.exports.add = (a, b) => a + b;
module.exports.subtract = (a, b) => a - b;

// Alternative syntax using exports
exports.multiply = (a, b) => a * b;
```

**File: `app.js` (Importing Module)**

```javascript
const math = require("./math");

console.log(math.add(5, 3)); // Output: 8
console.log(math.multiply(5, 3)); // Output: 15
```

> ✅ **CommonJS is synchronous**, meaning modules are loaded before execution continues.

---

## **2️⃣ ECMAScript Modules (ESM) – Modern Standard**

-   Uses `import`/`export` instead of `require()`.
-   Supports **asynchronous loading** (better for performance).
-   Required for front-end JavaScript.
-   Can be enabled in Node.js by setting `"type": "module"` in `package.json`.

### **How to Use ESM?**

**File: `math.mjs` (Exporting Module)**

```javascript
export function add(a, b) {
    return a + b;
}

export const multiply = (a, b) => a * b;
```

**File: `app.mjs` (Importing Module)**

```javascript
import { add, multiply } from "./math.mjs";

console.log(add(5, 3)); // Output: 8
console.log(multiply(5, 3)); // Output: 15
```

### **Using ESM in Node.js**

1. Add `"type": "module"` in `package.json`
    ```json
    {
        "type": "module"
    }
    ```
2. Use `.mjs` file extension for clarity (optional).

> ✅ **ESM supports asynchronous module loading, making it better for large-scale applications.**

---

## **3️⃣ Types of Modules in JavaScript**

### **(A) Core Modules**

Built-in modules provided by Node.js (e.g., `fs`, `path`, `http`).  
Example:

```javascript
const fs = require("fs"); // CommonJS
import fs from "fs"; // ESM (Only works in ES module mode)
```

### **(B) Local Modules**

Modules created within the project (`math.js`, `app.js`).  
Example:

```javascript
const myModule = require("./myModule");
```

### **(C) Third-Party Modules**

Modules installed via **npm** (e.g., `express`, `lodash`).  
Example:

```javascript
const express = require("express"); // CommonJS
import express from "express"; // ESM
```

---

## **4️⃣ Key Differences: CommonJS vs ESM**

| Feature                       | CommonJS (`require()`)             | ESM (`import`)                        |
| ----------------------------- | ---------------------------------- | ------------------------------------- |
| **Default in Node.js**        | ✅ Yes                             | ❌ No (must enable in `package.json`) |
| **Syntax**                    | `const x = require('x')`           | `import x from 'x'`                   |
| **Export Syntax**             | `module.exports = {...}`           | `export default` or `export {}`       |
| **Load Type**                 | **Synchronous** (Blocks execution) | **Asynchronous** (Non-blocking)       |
| **Used In**                   | Node.js (Backend)                  | Node.js & Browser (Frontend)          |
| **Supports Top-Level Await?** | ❌ No                              | ✅ Yes                                |

---

## **5️⃣ When to Use Which?**

✅ **Use CommonJS** if working on older Node.js projects.  
✅ **Use ESM** if starting a new project or writing modern, scalable code.
