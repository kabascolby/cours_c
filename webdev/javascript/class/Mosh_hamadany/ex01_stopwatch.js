// import { clearInterval } from "timers";

function Stopwatch(){
    var currentTime = 0;
    var waitInterval = 1;
    var timer = undefined;

    this.start = function (){
        if(timer)
            throw new Error('Start watch has already started.');
        timer =  setInterval( function () {
            currentTime += waitInterval;
        }, waitInterval);        
    }
    
    this.stop = function () {
        if(!timer)
            throw new Error('You have to start  the timer first.');
        clearInterval(timer);
        timer = undefined;
    }
    
    this.reset = function () {
        clearInterval(timer);
        timer = false;
        currentTime = 0;
    }

    Object.defineProperty(this, 'duration', {
        get: function() {
            return parseFloat(currentTime/1000);
        }
    })

}
let sw = new Stopwatch();

sw.start();
