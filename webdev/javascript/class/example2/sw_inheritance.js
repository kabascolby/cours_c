// import { clearInterval } from "timers";


/* 
function Stopwatch(){
    var _timer = undefined;
    var _currentTime = 0;
    
    Object.defineProperties(this, {
        'timer': {
            value : _timer,
            writable: true,
        },
    
        'currentTime': {
            value : _currentTime,
            writable: true,
        }
    });

    Object.defineProperty(this, 'duration', {
        get: function () {
            return this.currentTime / 1000;
        },
    });
};

Stopwatch.prototype.start = function () {
    if(this.timer)
        throw new Error('Start watch has already started.');
    var waitInterval = 1; 
    this.timer = setInterval(() => {
        this.currentTime += waitInterval;
    }, waitInterval);
}

Stopwatch.prototype.stop = function () {
    if(!this.timer)
        throw new Error('You have to start  the timer first.');
    this.timer = undefined;
    clearInterval(this.timer);
}

Stopwatch.prototype.reset = function () {
    clearInterval(this.timer);
    this.timer = undefined;
    this.currentTime = 0;
}

 */

// BLOCK SCOPE, leave the bracket alone!
{
    let timer = undefined;
    let currentTime = 0;
    function Stopwatch(){
    
        Object.defineProperty(this, 'duration', {
            get: function () {
                return currentTime / 1000;
            },
        });
    };
    
    Stopwatch.prototype.start = function () {
        if(timer)
            throw new Error('Start watch has already started.');
        var waitInterval = 1; 
        timer = setInterval(() => {
            currentTime += waitInterval;
        }, waitInterval);
    }
    
    Stopwatch.prototype.stop = function () {
        if(!timer)
            throw new Error('You have to start  the timer first.');
        timer = undefined;
        clearInterval(timer);
    }
    
    Stopwatch.prototype.reset = function () {
        clearInterval(timer);
        timer = undefined;
        currentTime = 0;
    }
}

let sw = new Stopwatch();

sw.start();