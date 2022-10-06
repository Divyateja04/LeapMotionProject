import { SerialPort } from 'serialport';
import { ReadlineParser } from '@serialport/parser-readline'
const port = new SerialPort({ path: 'COM6', baudRate: 9600 });
const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

import express from 'express'
import cors from 'cors'
const app = express();
let num = 0;

app.use(cors())
app.use(express.json())

app.get('/direction', (req, res) => {
    console.log(req.query.direction)
    res.send("Direction Saved")
    
    port.write(req.query.direction, (err) => {
        if (err) {
            return console.log('Error on write: ', err.message);
        }
        console.log('Message Written to the Bot' + (++num));
    });
})


port.on("open", () => {
    console.log('Serial Port Open');
});

app.listen(3001, () => {
    console.log("Server is up and running");
})