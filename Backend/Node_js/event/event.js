const EventEmitter = require("events");

class MyEmitter extends EventEmitter {}

const myEmitter = new MyEmitter();

myEmitter.on("call", (from) => {
    console.log("You have a call from ", from);
});

myEmitter.emit("call", "mother");
