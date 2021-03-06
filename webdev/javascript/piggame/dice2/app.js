/*
GAME RULES:

- The game has 2 players, playing in rounds
- In each turn, a player rolls a dice as many times as he whishes. Each result get added to his ROUND score
- BUT, if the player rolls a 1, all his ROUND score gets lost. After that, it's the next player's turn
- The player can choose to 'Hold', which means that his ROUND score gets added to his GLBAL score. After that, it's the next player's turn
- The first player to reach 100 points on GLOBAL score wins the game

//console.log(dice);
//document.querySelector('#current-0').textContent = dice;
//document.querySelector('#current-' + activePlayer).textContent = dice;
//console.log(document.querySelector('#score-0').textContent);
//document.querySelector('.player-0-panel').classList.remove('active');
//document.querySelector('.player-1-panel').classList.add('active');
*/

let scores, activePlayer, roundScore, gamePlaying, numSix, prevScores, maxscore;


init();

document.querySelector('#setscore').addEventListener('click', () => {
    //document.querySelector('')
    maxscore = parseInt(document.getElementById("maxscore").value);
    console.log(maxscore);
    document.querySelector(".winscore").style.display = "none";
});

document.querySelector('.btn-roll').addEventListener('click', function () {
    if(gamePlaying){

        let dice = Math.floor(Math.random() * 6 ) + 1;
        //display the result
        let diceDom = document.querySelector('.dice');
        diceDom.style.display = 'block';
        diceDom.src = 'dice-' + dice + '.png';
        console.log(dice);
        numSix += dice === 6 ? 1 : 0;
        if(dice !== 9 && numSix !== 2){
            roundScore += dice;
            document.querySelector('#current-' + activePlayer).textContent = roundScore;
        }
        else{
            if(numSix === 2){
                scores[activePlayer] = 0;
                document.querySelector('#score-' + activePlayer).textContent = 0;
            }
            numSix = 0;
            nextPlayer();
        }
    }
});

document.querySelector('.btn-hold').addEventListener('click', function() {
    if(gamePlaying) {
        scores[activePlayer] += roundScore;
        document.getElementById('score-' + activePlayer).textContent = scores[activePlayer];
        let max;
        max = maxscore ? maxscore : 20;
        console.log(max);
        if(scores[activePlayer] >= max){
            document.querySelector('#name-' + activePlayer).textContent = 'WINNER!';
            document.querySelector('.dice').style.display = 'none';
            document.querySelector('.player-' + activePlayer + '-panel').classList.add('winner');
            document.querySelector('.player-' + activePlayer + '-panel').classList.remove('active');
            gamePlaying = false;
        }
        else{
            nextPlayer();
        }
    }
});

function nextPlayer(){
    activePlayer = activePlayer === 0 ? 1 : 0
    roundScore = 0;
    document.getElementById('current-0').textContent = 0;
    document.querySelector('#current-1').textContent = 0;
    document.querySelector('.player-0-panel').classList.toggle('active');
    document.querySelector('.player-1-panel').classList.toggle('active');
    document.querySelector('.dice').style.display = 'none';
}

document.querySelector('.btn-new').addEventListener('click', init) ;

function init() {
    scores = [0, 0];
    prevScores = [0, 0];
    numSix = 0;
    activePlayer = 0;
    roundScore = 0;
    gamePlaying = true;
    document.querySelector('.dice').style.display = 'none';
    document.getElementById('score-0').textContent = 0;
    document.getElementById('score-1').textContent = 0;
    document.getElementById('current-0').textContent = 0;
    document.getElementById('current-1').textContent = 0;
    document.querySelector('#name-0').textContent = "Player 1";
    document.getElementById('name-1').textContent = "Player 2";  
    
    //document.getElementById('name-1').classList.add('player-name'); 
    document.querySelector('.player-0-panel').classList.remove('winner');
    document.querySelector('.player-0-panel').classList.remove('active');
    document.querySelector('.player-1-panel').classList.remove('winner');
    document.querySelector('.player-1-panel').classList.remove('active');
    document.querySelector('.player-0-panel').classList.add('active');
    document.querySelector(".winscore").style.display = "block";
}