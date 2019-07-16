function HtmlElement() {
    this.click = function() {
        console.log('click');
    };
};

HtmlElement.prototype.focus = function() {
    console.log('focus');
}

function extendInstance(Child, Parent) {
    Child.prototype = new Parent();
    Child.prototype.constructor = Child;
    // before
    // HtmlSelectElement.prototype = new HtmlElement();
    // HtmlSelectElement.constructor = HtmlSelectElement;
}


function HtmlSelectElement(items) {
    let render = (() => {
        let str = '';
        if(Array.isArray(items) && items.length){
            str = '\n';
            items.forEach( (x) => {
                str = str +`  <option>${x}</option>\n` 
            })
        }
        return str;
    })()
    
    this.items = items;
    
    this.addItem = function (item) {
        this.items.push(item);
    };
    
    this.removeItem = function (item) {
        let index = this.items.indexOf(item);
        if(index > -1)
            this.items.splice(index, 1);
    }

    this.render = function () {
        return `<select>${render}</select>`
    }
}

extendInstance(HtmlSelectElement, HtmlElement);

function HtmlImageElement(src){
    this.render = function () {
        return `<img src="${this.src}" />`
    }
    this.src = src || undefined;
    // HtmlSelectElement.call(this);
}

extendInstance(HtmlImageElement, HtmlElement);

const elements = [
    new HtmlSelectElement([1,2,3]),
    new HtmlImageElement("http://")
  ]
  
  for(let element of elements)
    console.log(element.render());
    
  let c = new HtmlSelectElement([1,2,3]);
  c.render();
  let img = new HtmlImageElement("http//");