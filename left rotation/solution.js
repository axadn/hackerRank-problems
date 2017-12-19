process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////
class rotatableArray{
    constructor(arr = []){
      this.store  = arr;
      this.startIdx = 0;
    }
    _storeIdx(idx){
        return (this.startIdx + idx) % this.store.length;
    }
    get(idx){
        return this.store[this._storeIdx(idx)];
    }
    set(idx, val){
        this.store[this._storeIdx(idx)] = val;
    }
    getLength(){
        return this.store.length;
    }
    rotate(places){
        this.startIdx = (this.startIdx + places) % this.store.length;
    }
    toString(){
        let result = "";
        for(let i = 0; i < this.getLength(); ++ i){
            if(i === this.getLength - 1){
                result += `${this.get(i)}`;
            }
            else{
                result += `${this.get(i)} `;
            }

        }
        return result;
    }
}

function main() {
    var n_temp = readLine().split(' ');
    var n = parseInt(n_temp[0]);
    var d = parseInt(n_temp[1]);
    a = new rotatableArray(readLine().split(' ').map(Number));
    a.rotate(d);
    console.log(a.toString());
}
