function HtmlElement() {
    this.click = function() {
        console.log('click');
    };
};

HtmlElement.prototype.focus = function() {
    console.log('focus');
}

HTMLHtmlElement.prototype.render = function(){
    let render = () => {
        let str = '';
        if(this.items.length){
            str = '\n';
            this.items.forEach(element => {
                str = str + `<option>${element}</option\n`
            });
        }
        return str;
    }
    return `<select>${render}</select>`
}

function HtmlImageElement(src) {
    
}


function HtmlSelectElement(...items) {
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

  
  // HtmlSelectElement.prototype = HtmlElement.prototype;
// HtmlSelectElement.prototype = Object.create(HtmlElement.prototype);
HtmlSelectElement.prototype = new HtmlElement();
HtmlSelectElement.constructor = HtmlSelectElement;
