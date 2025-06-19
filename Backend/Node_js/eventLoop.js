console.log("Start");

setTimeout(() => {
    console.log("setTimeout callback");
}, 0);

setImmediate(() => {
    console.log("setImmediate callback");
});

console.log("End");
