import { useState } from 'react';
import './App.css';

function App() {
    const [direction, setDirection] = useState("______");

    const changeDirection = (direction) => {
        switch (direction) {
            case "F":
                setDirection("Forward");
                break;
            case "B":
                setDirection("Backward");
                break;
            case "L":
                setDirection("Left");
                break;
            case "R":
                setDirection("Right");
                break;
        }

        console.log(direction);
        fetch('http://localhost:3001/direction?direction=' + direction, {
            method: "Post",
        })
            .then(response => response.json)
            .catch(err => console.log(err));
    }


    return (
        <div style={{ width: "100%", height: "100%" }}>
            <div className="container">
                <div className="buttonDiv">
                    <button className="button" id="left" style={{ backgroundColor: "#D2386C" }} />
                    <img src="./images/ButtonHighlight.png" alt="box" className="highlight"></img>
                </div>
                <div className="buttonDiv">
                    <button className="button" id="up" style={{ backgroundColor: "#ADD8E6" }} onClick={() => changeDirection('F')} />
                    <img src="./images/ButtonHighlight.png" alt="box" className="highlight"></img>
                </div>
                <div className="buttonDiv">
                    <button className="button" id="right" style={{ backgroundColor: "#D2386C" }} />
                    <img src="./images/ButtonHighlight.png" alt="box" className="highlight"></img>
                </div>
            </div>


            <div className="container">
                <div className="buttonDiv">
                    <button className="button" id="rotateLeft" style={{ backgroundColor: "#ADD8E6" }} onClick={() => changeDirection('L')} />
                    <img src="./images/ButtonHighlight.png" alt="box" className="highlight"></img>
                </div>
                <div className="buttonDiv">
                    <button className="button" id="output" style={{ backgroundColor: "#ADD8E6" }}>Moving {direction}</button>
                </div>
                <div className="buttonDiv">
                    <button className="button" id="rotateRight" style={{ backgroundColor: "#ADD8E6" }} onClick={() => changeDirection('R')} />
                    <img src="./images/ButtonHighlight.png" alt="box" className="highlight"></img>
                </div>
            </div>

            <div className="container">
                <div className="buttonDiv">
                    <button className="button" id="rotateLeft" style={{ backgroundColor: "#D2386C" }} />
                    <img src="./images/ButtonHighlight.png" alt="box" className="highlight"></img>
                </div>
                <div className="buttonDiv">
                    <button className="button" id="bottom" style={{ backgroundColor: "#ADD8E6" }} onClick={() => changeDirection('B')} />
                    <img src="./images/ButtonHighlight.png" alt="box" className="highlight"></img>
                </div>
                <div className="buttonDiv">
                    <button className="button" id="rotateRight" style={{ backgroundColor: "#D2386C" }} />
                    <img src="./images/ButtonHighlight.png" alt="box" className="highlight"></img>
                </div>
            </div>
        </div>
    );
}

export default App;
