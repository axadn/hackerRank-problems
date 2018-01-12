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

function bigSorting(arr) {
    let num1, num2;
    return arr.sort((s1, s2)=>{ 
        if(s1.length < s2.length){
            return -1;
        }
        else if(s2.length < s1.length){
            return 1;
        }
        else{
            for(let i = 0; i < s1.length; ++i){
                num1 = parseInt(s1[i]);
                num2 = parseInt(s2[i]);
                if(num1 < num2){
                    return -1;
                }
                else if (num1 > num2){
                    return 1;
                }
            }
            return 0;
        }
    });
}

function main() {
    var n = parseInt(readLine());
    var arr = [];
    for(var arr_i = 0; arr_i < n; arr_i++){
       arr[arr_i] = readLine();
    }
    var result = bigSorting(arr);
    console.log(result.join("\n"));



}

