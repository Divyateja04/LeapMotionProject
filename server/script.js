import { SerialPort } from 'serialport';
import { ReadlineParser } from '@serialport/parser-readline'
const port = new SerialPort({ path: 'COM6', baudRate: 9600 });
const parser = port.pipe(new ReadlineParser({ delimiter: '\n' }));

import express from 'express'
import cors from 'cors'
const app = express();

app.use(cors())
app.use(express.json())

app.post('/direction', (req, res) => {
    console.log(req.query.direction)
    
    port.write(req.query.direction, (err) => {
        if (err) {
            return console.log('Error on write: ', err.message);
        }
        console.log('Message Written to the Bot');
    });
})


port.on("open", () => {
    console.log('Serial Port Open');
});

app.listen(3001, () => {
    console.log("Server is up and running");
})