# File System - fs module

#### Basic import

```js
const fs = require("fs");
```

#### Synchronous I/O

```js
/**
 * Synchronous file system
 * 1. fs.readFileSync
 * 2. fs.writeFileSync
 */

// Reading a file
const fileText = fs.readFileSync("test.txt", "utf-8");

// Write a file
const writeFile = fs.writeFileSync("test.txt", fileText + " Hello World");

console.log(fileText);
```

#### Asynchronous I/O

```js
/**
 * Asynchronous file system
 * 1. fs.readFile
 * 2. fs.writeFile
 */

fs.readFile("test.txt", "utf-8", (err, data) => {
    if (err) {
        throw Error("An error occured while reading the file", err);
    }
    console.log(data);

    // Write a file
    fs.writeFile("test.txt", data + "Hello World", (err) => {
        if (err) {
            throw Error("An error occured while writing the file", err);
        }
        console.log("File written successfully");
    });
});

console.log("Async file system");
```
