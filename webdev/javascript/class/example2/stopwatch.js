// import { clearInterval } from "timers";

function Stopwatch(){
    var currentTime = 0;
    var waitInterval = 1;
    var timer;
    var state = false;

    this.start = function (){
        if(state)
            throw new Error('Start watch has already started.');
        state = true;
        timer =  setInterval( function () {
            currentTime += waitInterval;
        }, waitInterval);        
    }
    
    this.stop = function () {
        if(!state)
            throw new Error('You have to start  the timer first.');
        state = false;
        clearInterval(timer);
        
    }
    
    this.reset = function () {
        clearInterval(timer);
        state = false;
        currentTime = 0;
    }

    Object.defineProperty(this, 'duration', {
        get: function() {
            return currentTime/1000;
        }
    })

}
let sw = new Stopwatch();

sw.start();

