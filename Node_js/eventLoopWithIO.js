const fs = require("fs");

console.log("Start");

// Simulating an async I/O operation
fs.readFile("test.txt", () => {
    console.log("File read callback");

    setTimeout(() => {
        console.log("setTimeout callback");
    }, 0);

    setImmediate(() => {
        console.log("setImmediate callback");
    });
});

console.log("End");
