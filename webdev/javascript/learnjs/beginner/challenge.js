let john = ['john', 89, 120, 103];
let mike = ['mike', 116, 123, 203];
let mary = ['mary', 97, 134, 105];

function teamAverage(array){
    let sum;
    sum = array[1] + array[2] + array[3];
    sum /= 3;
    return sum;
}
let avJohn = teamAverage(john);
let avMike = teamAverage(mike);
let avMary = teamAverage(mary);

switch (true){
    case (avJohn > avMike) && (avJohn > avMary) :
    console.log('the winner is: ' + john[0] + ' with average ' + avJohn);
    break;
    case (avJohn < avMike) && (avMike > avMary) :
    console.log('the winner is: ' + mike[0] + ' with average ' + avMike);
    break;
    case (avMary > avMike) && (avJohn < avMary) :
    console.log('the winner is: ' + mary[0] + ' with average ' + avMary);
    break;
    case (avMary === avMike) && (avJohn === avMary) :
    console.log('all the average are same', avJohn, avMary, avMike);
    default:
    console.log("wrong entry");
}

//seconde solution

averageJohn = (89 + 120 + 103)/ 3;
averageMike = (166 + 123 + 34) / 3;
averageMary = (97 + 134 + 105) / 3;

if(averageJohn > averageMike && averageJohn > averageMary)
    console.log('John is the winner with', averageJohn, 'points');
else if(averageMike > averageJohn && averageMike > averageMary)
    console.log('Mike is the winner with', averageMike, 'points');
else if (averageMary > averageJohn && averageMary > averageMike)
    console.log('Mary is the winner with', averageMary, 'points');
else
    console.log("all the average are same");
/* 
let lamine = {
    name : 'Lamine',
    lastName : 'kaba',
    yearofBirth : 1997,
    job: 'student',
    isMarried : false
};
console.log(lamine);
let val = 'job';
console.log(lamine[val]);
lamine['job'] = 'programmer';
console.log(lamine);

let marietou = new Object();
marietou.name = 'marietou';
marietou.lastName = 'bah';
marietou.yearofBirth = 2000;
marietou['job'] = 'student';
console.log(marietou); */

let lamine = {
    name : 'lamine',
    lastName : 'kaba',
    yearOfBirth : 1997,
    familly : ['Mamoudou', 'Malick', 'Sory', 'Moussa', 'fanta', 'Zenabou', 'Tenin'],
    calculateYear: function(){
        this.age = 2018 - this.yearOfBirth;
    },
    job : 'Coding',
};

console.log(lamine);
lamine.calculateYear();
console.log(lamine);
for(let i = -1; ++i < lamine.familly.length; ){
    console.log(lamine.familly[i]);
}
console.log('\n\n');
for(let i = lamine.familly.length; i > 0; i--){
    console.log(lamine.familly[i - 1]);
}



let array = [1,2,3,4,5,1,1]

let newArr = array.map(item => item += 2)
                    .reduce((acc, item) => acc + item);

console.log(newArr);

function tipCalculator(bills){
    let i, tips = [], total = [];
    for(i = 0; i < bills.length; i++)
    {
        if(bills[i] < 50)
        {
            tips[i] = bills[i] * 0.2;
            total[i] = tips[i] + bills[i];
        }
        else if(bills[i] <= 200)
        {
            tips[i] = bills[i] * 0.15;
            total[i] = tips[i] + bills[i];
        }
        else if(bills[i] > 200)
        {
            tips[i] = bills[i] * 0.10;
            total[i] = tips[i] + bills[i];
        }
    }
    console.log('tips = ' + tips);
    console.log('total = ' + total);
}


let johnTips = {
    firstName : 'John',
    bills : [124, 48, 268, 180, 42],
    tips : [],
    total : [],
    tipCalculator : function(){
        for(let i = 0; i < this.bills.length; i++){
            if(this.bills[i] < 50)
            {
                this.tips[i] = this.bills[i] * 0.2;
                this.total[i] = this.tips[i] + this.bills[i];
            }
            else if(this.bills[i] <= 200)
            {
                this.tips[i] = this.bills[i] * 0.15;
                this.total[i] = this.tips[i] + this.bills[i];
            }
            else if(this.bills[i] > 200)
            {
                this.tips[i] = this.bills[i] * 0.10;
                this.total[i] = this.tips[i] + this.bills[i];
            }
        }
    },
};

let markTips = {
    firstName : 'Mark',
    bills : [77, 475, 110, 45],
    tips : [],
    total : [],
    tipCalculator : function(){
        for(let i = 0; i < this.bills.length; i++){
            if(this.bills[i] < 100)
            {
                this.tips[i] = this.bills[i] * 0.2;
                this.total[i] = this.tips[i] + this.bills[i];
            }
            else if(this.bills[i] <= 300)
            {
                this.tips[i] = this.bills[i] * 0.1;
                this.total[i] = this.tips[i] + this.bills[i];
            }
            else if(this.bills[i] > 300)
            {
                this.tips[i] = this.bills[i] * 0.25;
                this.total[i] = this.tips[i] + this.bills[i];
            }
        }
    },
};

console.log(johnTips.tipCalculator());
console.log(markTips.tipCalculator());

function average(object){
    let sum = 0;
    for(let i = 0; i < object.tips.length; i++){
        sum += object.tips[i];
    }
    return(sum / object.tips.length);
}


let sumJohn = average(johnTips);
let sumMark = average(markTips);
console.log("sum john = " + sumJohn, "sum Mark = " + sumMark);
if(sumJohn > sumMark)
    console.log("John paid more tips with " + (sumJohn - sumMark) + " difference");
else
    console.log("Mark paid more tips with " + (sumMark - sumJohn)  + " difference");