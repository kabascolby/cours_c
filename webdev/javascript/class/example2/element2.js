function HtmlElement() {
    this.click = function() {
        console.log('click');
    };
};

HtmlElement.prototype.focus = function() {
    console.log('focus');
}


function HtmlSelectElement(items) {
    this.items = items;
    
    this.addItem = function (item) {
        this.items.push(item);
    };
    
    this.removeItem = function (item) {
        let index = this.items.indexOf(item);
        if(index > -1)
            this.items.splice(index, 1);
    }
}


HtmlSelectElement.prototype = new HtmlElement();
HtmlSelectElement.constructor = HtmlSelectElement;

function HtmlImageElement (items, src){
    this.src = src || undefined;
  // this.prototype = HtmlSelectElement.constructor(items)
    this.render = function () {
      let render = (() => {
          let str = '';
                console.log(items);
          if(items.length){
              str = '\n';
              items.forEach( (x ) => {
                  str = str +`  <option>${x}</option>\n` 
              })
          }
          return str;
  
      })()
      return `<select> ${render}</select>`
  }
    // HtmlSelectElement.call(this, ...items);
    // this.prototype = Object.create(new HtmlSelectElement(items));
}

HtmlImageElement.prototype = new HtmlSelectElement;
HtmlImageElement.constructor = HtmlImageElement;

  
let e = new HtmlImageElement(['1', '2']);


e.focus()
e.click()
console.log(e.items)
console.log(e.render());

