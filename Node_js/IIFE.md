# **Immediately Invoked Function Expression (IIFE) in JavaScript**

## **What is IIFE?**

An **IIFE (Immediately Invoked Function Expression)** is a JavaScript function that **runs as soon as it is defined**.

### **Syntax of IIFE**

```javascript
(function () {
    console.log("IIFE executed!");
})();
```

Here, the function **executes immediately** after its definition.

---

## **1️⃣ Why Use IIFE?**

✅ **Avoid Global Scope Pollution** – Variables inside an IIFE are **not accessible outside**, preventing conflicts.  
✅ **Encapsulation** – Keeps logic private and prevents accidental modification.  
✅ **Asynchronous Code** – Commonly used in modern JavaScript to **handle async operations**.  
✅ **Module Pattern** – Used to create **self-contained modules**.

---

## **2️⃣ Example of IIFE Usage**

### **(A) Basic IIFE Example**

```javascript
(function () {
    console.log("This runs immediately!");
})();
```

🔹 **Output:**

```
This runs immediately!
```

---

### **(B) IIFE with Parameters**

```javascript
(function (name) {
    console.log(`Hello, ${name}!`);
})("Tanvir");
```

🔹 **Output:**

```
Hello, Tanvir!
```

---

### **(C) IIFE with Return Value**

```javascript
const sum = (function (a, b) {
    return a + b;
})(5, 3);

console.log(sum); // Output: 8
```

---

### **(D) Arrow Function IIFE**

```javascript
(() => {
    console.log("Arrow function IIFE executed!");
})();
```

---

### **(E) IIFE for Private Variables (Encapsulation)**

```javascript
const counter = (function () {
    let count = 0; // Private variable

    return {
        increment: function () {
            count++;
            console.log(count);
        },
        decrement: function () {
            count--;
            console.log(count);
        },
    };
})();

counter.increment(); // Output: 1
counter.increment(); // Output: 2
counter.decrement(); // Output: 1
```

🔹 **Why?**

-   `count` is **not directly accessible** outside the function.
-   Only `increment()` and `decrement()` can modify `count`.

---

## **3️⃣ IIFE vs Regular Function**

| Feature       | IIFE                 | Regular Function            |
| ------------- | -------------------- | --------------------------- |
| **Execution** | Runs immediately     | Runs when called            |
| **Scope**     | Encapsulated (local) | Can create global variables |
| **Use Case**  | One-time execution   | Reusable function           |

---

## **4️⃣ Real-World Use Cases of IIFE**

✔ **Avoid polluting the global scope** in large applications.  
✔ **Create private variables** (e.g., counters, state management).  
✔ **Immediately execute async functions** in modern JavaScript.

Example with `async/await`:

```javascript
(async function () {
    const data = await fetch(
        "https://jsonplaceholder.typicode.com/posts/1"
    ).then((res) => res.json());
    console.log(data);
})();
```

---

## **5️⃣ Key Takeaways**

✅ **IIFE is a function that executes immediately after definition.**  
✅ **Prevents global variable pollution and ensures encapsulation.**  
✅ **Useful for private variables, async functions, and modular code.**

# **How Node.js Modular System Works with IIFE**

Node.js primarily uses the **CommonJS module system**, where each file acts as a **separate module**.  
Internally, **Node.js wraps every module inside an IIFE** to provide encapsulation.

---

## **1️⃣ How Node.js Uses IIFE in Modules**

When you create a module in Node.js, **Node automatically wraps the code inside an IIFE** like this:

### **Example: `math.js`**

```javascript
console.log("Math module loaded");

module.exports.add = (a, b) => a + b;
```

### **Example: `app.js`**

```javascript
const math = require("./math");
console.log(math.add(5, 3)); // Output: 8
```

**Internally, Node.js wraps `math.js` like this:**

```javascript
(function (exports, require, module, __filename, __dirname) {
    console.log("Math module loaded");

    module.exports.add = (a, b) => a + b;
});
```

> **Why?**  
> This ensures that **variables inside a module do not leak into the global scope**, maintaining encapsulation.

---

## **2️⃣ How the IIFE Works in Node.js Modules**

Each module in Node.js follows this structure:

```javascript
(function (exports, require, module, __filename, __dirname) {
    // Module code here
});
```

### **Breakdown of Parameters:**

| Parameter    | Description                                    |
| ------------ | ---------------------------------------------- |
| `exports`    | Object used to **export** functions/variables. |
| `require`    | Function used to **import modules**.           |
| `module`     | Reference to the current **module**.           |
| `__filename` | Absolute path of the **current module file**.  |
| `__dirname`  | Absolute path of the **module's directory**.   |

---

## **3️⃣ Example of Node.js Module System with IIFE**

### **(A) Without IIFE (Leaking Variables)**

```javascript
// badModule.js
let secret = "This is a secret";

module.exports.getSecret = () => secret;
```

```javascript
// app.js
const badModule = require("./badModule");
console.log(badModule.getSecret()); // Output: This is a secret
console.log(secret); // ❌ Error: secret is not defined (because of the module wrapper)
```

🔹 **The variable `secret` is private due to the IIFE wrapper.**

---

### **(B) Manually Using IIFE in Node.js Modules**

You can also **explicitly use IIFE** in Node.js for more control:

#### **Example: Using IIFE to Encapsulate Code**

```javascript
// counter.js
const counter = (function () {
    let count = 0; // Private variable

    return {
        increment: function () {
            count++;
            console.log(count);
        },
        decrement: function () {
            count--;
            console.log(count);
        },
    };
})();

module.exports = counter;
```

```javascript
// app.js
const counter = require("./counter");

counter.increment(); // Output: 1
counter.increment(); // Output: 2
counter.decrement(); // Output: 1
```

🔹 **The `count` variable is completely private, ensuring better encapsulation.**

---

## **4️⃣ Key Takeaways**

✅ **Node.js automatically wraps each module inside an IIFE for encapsulation.**  
✅ **This prevents variables from leaking into the global scope.**  
✅ **You can still use IIFE explicitly in your own modules for better control.**
