const http = require("http");
const fs = require("fs");

const server = http.createServer();

server.on("request", (req, res) => {
    const fileReadStream = fs.createReadStream(
        process.cwd() + "/text.txt",
        "utf-8"
    );

    fileReadStream.on("data", (buffer) => {
        res.write(buffer);
    });

    fileReadStream.on("end", () => {
        res.end("=======");
    });
});

server.listen(5001, () => {
    console.log("Server is listening in port 5000");
});
