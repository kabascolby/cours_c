/* var name;
var age;
let isMarried;

name = 'Lamine';
age = 22;
isMarried = 'no'
if (isMarried === 'yes')
   console.log(name, 'is married !');
else
    console.log(name, 'will married soon');

let player1, player2, player3, agep1, p1Height, agep2, p2Height, agep3, p3Height, p1score, p2score, p3score;
player1 = prompt('player1 name');
agep1 = prompt('insert player 1 age');
p1Height = prompt('insert player 1 height in cm');
player2 = prompt('input player 2 name');
agep2 = prompt('insert player 2 age');
p2Height = prompt('insert player 2 height in cm');
player3 = prompt('Input player3 Name');
agep3 = prompt('insert player 3 age');
p3Height = prompt('insert player 3 height in cm');

p1score = p1Height + agep1 * 5;
p2score = p1Height + agep2 * 5;
p3score = p1Height + agep3 * 5;

console.log('p1 name is : ' + player1, 'age = ' + agep1, 'height = ' + p1Height, 'score = ' + p1score);
console.log('p2 name is : ' + player2, 'age = ' + agep2, 'height = ' + p2Height, 'score = ' + p2score);
console.log('p3 name is : ' + player3, 'age = ' + agep3, 'height = ' + p3Height, 'score = ' + p3score);

if (p1score > p2score && p1score > p3score)
{
    console.log('player 1 win');
}
else if (p2score > p1score && p2score > p3score)
{
    console.log('player 2 win');
}
else
   console.log('Player 3 win'); */

function calculateAge(yearofbirth)
{
    var age = 2018 - yearofbirth;
    return age;
}

var ageJohn = calculateAge(1998);
var ageBrendan = calculateAge(1990);
var ageNake = calculateAge(1998)

console.log('John age = ' + ageJohn, 'Joh Brendan = ' + ageBrendan, 'John Nake = ' + ageNake);

function retirement(name, yearofbirth)
{
    var age = calculateAge(yearofbirth);
    let num = 65 - age;
    if (num >= 0)
    {
        console.log(name + ' Retiremnent = ' + num);
    }
    else
    console.log(name + ' is Already retired');
}

retirement('brandhon', 1990);
retirement('Nake', 1998);
retirement('Sara', 1945);

function categorie_type(name, age)
{
    switch (true)
    {
        case age < 13:
            console.log(name, "is a boys");
            break;
        case age >= 13 && age < 20:
            console.log(name, "is a tennager");
            break;
        case age >= 20 && age < 30:
            console.log(name, "is a young man");
            break;
        default :
            console.log(name, "is a man");
    }
}

categorie_type("John", 1);
categorie_type("lkaba", 1);