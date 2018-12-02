var now, johnYear, markYear;

now = 2018;
johnYear = now - 28;
markYear = now - 35;
console.log(johnYear + ' ' + markYear);

var johnolder = johnYear > markYear;
console.log(johnolder);
console.log(typeof johnolder + ' ' + typeof markYear);

var massJohn, massMark, heightJohn, heightMark, bmiJohn, bmiMark;

massJohn = prompt('Input John Mass in kg');
heightJohn = prompt('Input John Height in meter');
massMark = prompt('Input Mark height in kg');
heightMark = prompt('Input Mark height in meter');

bmiJohn = massJohn / (heightJohn ^ 2);
bmiMark = massMark / (heightMark * heightMark);
console.log( 'John BMI = ' + bmiJohn +  '\nMark BMI = ' + bmiMark + '\nIs Jhon BMI greater :',bmiJohn > bmiMark);

let age = 26;
let name = "John";

function categorie_type(name, age)
{
    switch (true)
    {
        case age < 13 :
            console.log(name, "is a boys");
            break;
        case age >= 13 && age < 20 :
            console.log(name, "is a tennager");
            break;
        case age >= 20 && < 30 :
            console.log(name, "is a young man");
        default :
        console.log(name, "is a man");
    }
}

categorie_type("John", 26);