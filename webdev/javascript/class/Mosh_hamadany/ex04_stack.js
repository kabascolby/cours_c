const _tab = new WeakMap([]);

class Stack {
    constructor() {
       _tab.set(this, []);
    }

    peak() {
        let items = _tab.get(this);
        if(!items.length)
            throw new Error('The Stack is empty');
        return items[items.length - 1];
    }
    
    get count() {
        return _tab.get(this).length;
    }

    push(val) {
        _tab.get(this).push(val);
        console.log('after push ->', _tab.get(this));
    }

    pop() {
        if(!_tab.get(this).length)
            throw new Error('cannot remove from empty Stack');
        _tab.get(this).pop();
        console.log('after pop ->', _tab.get(this));
    }
}

let s = new Stack();