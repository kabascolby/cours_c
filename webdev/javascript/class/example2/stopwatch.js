// import { clearInterval } from "timers";

function Stopwatch(){
    var currentTime = 0;
    var waitInterval = 1;
    var timer;
    var state = false;

    this.start = function (){
        if(!state){
            state = true;
            timer =  setInterval( function () {
                currentTime += waitInterval;
            }, waitInterval);
        }
        else
        throw new Error('Start watch has already started.');
        
    }
    
    this.stop = function () {
        if(state === true){
            state = false;
            clearInterval(timer);
        }
        else
            throw new Error('You have to start  the timer first.');
        
    }
    
    this.reset = function () {
        clearInterval(timer);
        state = false;
        currentTime = 0;
    }

    Object.defineProperty(this, 'duration', {
        get: function() {
            console.log(currentTime/1000);
        }
    })

}
let sw = new Stopwatch();

