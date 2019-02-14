/* 
	If the match succeeds, the exec() method returns an array and updates properties of the
	regular expression object. The returned array has the matched text as the first item,
	and then one item for each capturing parenthesis that matched containing the text that was captured.

	If the match fails, the exec() method returns null. 
*/

const [all, year, month, day] =
    /^(\d\d\d\d)-(\d\d)-(\d\d)$/
    .exec('2999-12-31');
console.log(all, year, month, day);


// You can also destructure in a for-of loop:

const arr = ['a', 'b'];
for (const [index, element] of arr.entries()) {
    console.log(index, element);
}


const obj = { a: [{ foo: 123, bar: 'abc' }, {}], b: true };
const { a: [{foo: f}] } = obj; // f = 123
